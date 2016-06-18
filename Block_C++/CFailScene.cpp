#include <conio.h>
#include <Windows.h>
#include <stdio.h>

#include "CFailScene.h"
#include "CGameScene.h"
#include "CInitScene.h"
#include "ScreenFunc.h"
#include "SoundFunc.h"
#include "CGameData.h"

extern CGameData Data;

CFailScene::CFailScene(){}
CFailScene::~CFailScene(){}

void CFailScene::Update(){

	StartSong(FAIL);
	ScreenInit();

	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃  ■■■■■■■■■■■■■■■■■■  ┃");
	ScreenPrint(0, 2, "┃  ■■■■■■■■■■■■■■■■■■  ┃");
	ScreenPrint(0, 3, "┃                                        ┃");
	ScreenPrint(0, 4, "┃                                        ┃");
	ScreenPrint(0, 5, "┃                                        ┃");
	ScreenPrint(0, 6, "┃                                        ┃");
	ScreenPrint(0, 7, "┃             *┭┮  ┭┮*               ┃");
	ScreenPrint(0, 8, "┃          *.  ㅣㅣ▽ㅣㅣ   .*           ┃");
	ScreenPrint(0, 9, "┃   ┏ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┓     ┃");
	ScreenPrint(0, 10, "┃   ┃다음 번 기회를 이용해 주세요┃     ┃");
	ScreenPrint(0, 11, "┃   ┗ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┛     ┃");
	ScreenPrint(0, 12, "┃                                        ┃");
	ScreenPrint(0, 13, "┃                                        ┃");
	ScreenPrint(0, 14, "┃    (*⌒⌒*)                            ┃");
	ScreenPrint(0, 15, "┃   ┏O━━━O━━━━━━━━━━┓     ┃");
	ScreenPrint(0, 16, "┃   ┃계속하시겠습니까? <y/n>     ┃     ┃");
	ScreenPrint(0, 17, "┃   ┗━━━━━━━━━━━━━━┛     ┃");
	ScreenPrint(0, 18, "┃                                        ┃");
	ScreenPrint(0, 19, "┃                                        ┃");
	ScreenPrint(0, 20, "┃                                        ┃");
	ScreenPrint(0, 21, "┃  ■■■■■■■■■■■■■■■■■■  ┃");
	ScreenPrint(0, 22, "┃  ■■■■■■■■■■■■■■■■■■  ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━┛");

	while (char ch = getch()){
		if (ch == 'Y' || ch == 'y')
			break;
		else if (ch == 'n' || ch == 'N')
			exit(0);
	}
}

void CFailScene::Render(){}
void CFailScene::Clear(){}

IScene * CFailScene::GetNextScene(){
	StopSong(FAIL);
	return new CInitScene();
}

bool CFailScene::IsEnd(){
	return true;
}
