#include <Windows.h>
#include <stdio.h>

#include "CGameScene.h"
#include "CReadyScene.h"
#include "CFailScene.h"
#include "CWinScene.h"
#include "ScreenFunc.h"
#include "SoundFunc.h"
#include "CGameData.h"
extern CGameData Data;

CGameScene::CGameScene(){
	Data.setBlockCount(0);
	Data.setGrade(0);
	Data.setGameStartTime(clock());
	Data.setStage(Data.getStage() + 1); // 현재 스테이지 도전이니 1증가
	BlockNum = Data.getStageInfo()[Data.getStage() - 1].nBlockCount; // 현재 스테이지의 블럭갯수를 가져옴

	Block = new CBlock[BlockNum];
	Ball = new CBall(Block);
	Player = new CPlayer(Ball);
	Ball->setPlayer(Player);
	SetBlock();

	Object[0] = Player;
	Object[1] = Ball;
	for (int i = 0; i < BlockNum; i++){
		Object[2 + i] = &Block[i];
	}

	StartSong(RUN);
	SetSize(80, 25);


	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                        ┃");
	ScreenPrint(0, 2, "┃                                        ┃");
	ScreenPrint(0, 3, "┃                                        ┃");
	ScreenPrint(0, 4, "┃                                        ┃");
	ScreenPrint(0, 5, "┃                                        ┃");
	ScreenPrint(0, 6, "┃                                        ┃");
	ScreenPrint(0, 7, "┃                                        ┃");
	ScreenPrint(0, 8, "┃                                        ┃");
	ScreenPrint(0, 9, "┃                                        ┃");
	ScreenPrint(0, 10, "┃                                        ┃");
	ScreenPrint(0, 11, "┃                                        ┃");
	ScreenPrint(0, 12, "┃                                        ┃");
	ScreenPrint(0, 13, "┃                                        ┃");
	ScreenPrint(0, 14, "┃                                        ┃");
	ScreenPrint(0, 15, "┃                                        ┃");
	ScreenPrint(0, 16, "┃                                        ┃");
	ScreenPrint(0, 17, "┃                                        ┃");
	ScreenPrint(0, 18, "┃                                        ┃");
	ScreenPrint(0, 19, "┃                                        ┃");
	ScreenPrint(0, 20, "┃                                        ┃");
	ScreenPrint(0, 21, "┃                                        ┃");
	ScreenPrint(0, 22, "┃                                        ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━┛");
}
CGameScene::~CGameScene(){
	for (int i = 0; i < 2; i++)
		delete Object[i];

	delete [] Object[2]; //Blocks
}

void CGameScene::Update(){
	char string[100];
	Data.setGrade(Data.getBlockCount() * 10);
	Data.setRemainTime( (Data.getStageInfo()[Data.getStage()-1].LimitTime - (clock() - Data.getGameStartTime())) / 1000);
	
	sprintf(string, "스테이지 : %d", Data.getStage());
	ScreenPrint(45, 2, string);

	sprintf(string, "생명 : %d ", Ball->getNHP());
	ScreenPrint(45, 4, string);

	sprintf(string, "점수 : %d ", Data.getGrade());
	ScreenPrint(45, 6, string);

	clock_t CurTime = clock();

	sprintf(string, "남은 시간 : %d 분 %d 초", Data.getRemainTime() / 60, Data.getRemainTime() % 60);
	ScreenPrint(45, 8, string);



	for (int i = 0; i < 2; i++)
		Object[i]->Move();
}
void CGameScene::Render(){
	for (int i = 0; i < 2; i++)
		Object[i]->Render();
	for (int i = 2; i < BlockNum+2; i++){
		if ((dynamic_cast<CBlock *>(Object[i])->getNLife()!=0))
			Object[i]->Render();
	}
}
void CGameScene::Clear(){
	for (int i = 0; i <2; i++)
		Object[i]->Clear();
	for (int i = 2; i < BlockNum + 2; i++){
		if ((dynamic_cast<CBlock *>(Object[i])->getNLife() == 0))
			Object[i]->Clear();
	}
}

IScene * CGameScene::GetNextScene(){
	StopSong(RUN);
	Data.setGrade(Data.getBlockCount() * 10);
	Data.setTotalGrade(Data.getTotalGrade() + Data.getGrade());
	if (amiDie)
		return new CFailScene();
	return new CWinScene();
}
bool CGameScene::IsEnd(){
	if ((clock() - Data.getGameStartTime()) > Data.getStageInfo()[Data.getStage() - 1].LimitTime){
		amiDie = true;
		return true;
	}
	if(Data.getBlockCount() == Data.getStageInfo()[Data.getStage() - 1].nBlockCount) {
		amiDie = false;
		return true;
	}
	if (Ball->getNHP() == 0){
		amiDie = true;
		return true;
	}
	return false;
}

bool CGameScene::Search(int nEnd, int x, int y){
	for (int i = 0; i < nEnd; i++) {
		if (Block[i].y == y) {
			if (Block[i].x == x || (Block[i].x + 1) == x ||
				Block[i].x == x + 1 || (Block[i].x + 1) == x + 1)
				return true; // 같은 것이 있으면
		}
	}
	return false; // 같은 것이 없으면 
}
void CGameScene::SetBlock() {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < BlockNum; i++) {
		Block[i].setNLife(1);

		while (1) {
			int x = rand() % 39 + 2; // 2 ~ 40 범위 안에서
			int y = rand() % 10 + 1; // 1 ~ 10 까지의 범위

			if (Search(i, x, y) == 0) {
				Block[i].x = x;
				Block[i].y = y;
				break;
			}
		}
	}
}