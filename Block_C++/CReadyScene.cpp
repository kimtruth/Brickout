#include <conio.h>
#include <Windows.h>
#include <stdio.h>

#include "CReadyScene.h"
#include "CGameScene.h"
#include "CResultScene.h"
#include "ScreenFunc.h"
#include "SoundFunc.h"
#include "CGameData.h"

extern CGameData Data;

CReadyScene::CReadyScene(){}
CReadyScene::~CReadyScene(){}

void CReadyScene::Update(){

	StartSong(STAGE);
	ScreenInit();

	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收旬");
	ScreenPrint(0, 1, "早                                        早");
	ScreenPrint(0, 2, "早                                        早");
	ScreenPrint(0, 3, "早                                        早");
	ScreenPrint(0, 4, "早                                        早");
	ScreenPrint(0, 5, "早                                        早");
	ScreenPrint(0, 6, "早                                        早");
	ScreenPrint(0, 7, "早              S t a g e                 早");
	ScreenPrint(0, 8, "早                            ≒          早");
	ScreenPrint(0, 9, "早                      Ｂ㏑收早          早");
	ScreenPrint(0, 10, "早                        Ｂ㏑旭          早");
	ScreenPrint(0, 11, "早                          旨朴旬        早");
	ScreenPrint(0, 12, "早                                        早");
	ScreenPrint(0, 13, "早                                        早");
	ScreenPrint(0, 14, "早                                        早");
	ScreenPrint(0, 15, "早                                        早");
	ScreenPrint(0, 16, "早                                        早");
	ScreenPrint(0, 17, "早                                        早");
	ScreenPrint(0, 18, "早                                        早");
	ScreenPrint(0, 19, "早                                        早");
	ScreenPrint(0, 20, "早                                        早");
	ScreenPrint(0, 21, "早                                        早");
	ScreenPrint(0, 22, "早                                        早");
	ScreenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收旭");
	
	char string[100];
	sprintf(string, "%d", Data.getStage() + 1);
	ScreenPrint(13, 7, string);

	Sleep(2500);
}

void CReadyScene::Render(){}
void CReadyScene::Clear(){}

IScene * CReadyScene::GetNextScene(){
	StopSong(STAGE);
	if (Data.getStage() + 1 >= 4)
		return new CResultScene();
	return new CGameScene();
}

bool CReadyScene::IsEnd(){
	return true;
}
