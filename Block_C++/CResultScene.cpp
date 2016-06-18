#include <conio.h>
#include <Windows.h>
#include <stdio.h>

#include "CResultScene.h"
#include "CGameScene.h"
#include "CInitScene.h"
#include "CReadyScene.h"
#include "ScreenFunc.h"
#include "SoundFunc.h"
#include "CGameData.h"

extern CGameData Data;

CResultScene::CResultScene(){}
CResultScene::~CResultScene(){}

void CResultScene::Update(){

	StartSong(SUCCESS);
	ScreenInit();


	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收旬");
	ScreenPrint(0, 1, "早                                        早");
	ScreenPrint(0, 2, "早                                        早");
	ScreenPrint(0, 3, "早                                        早");
	ScreenPrint(0, 4, "早                                        早");
	ScreenPrint(0, 5, "早                                        早");
	ScreenPrint(0, 6, "早                                        早");
	ScreenPrint(0, 7, "早   (((    漁給 梟晦  啪歜 Score  ))))   早");
	ScreenPrint(0, 8, "早                                        早");
	ScreenPrint(0, 9, "早                                        早");
	ScreenPrint(0, 10, "早                                        早");
	ScreenPrint(0, 11, "早           識 薄熱  :                   早");
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
	sprintf(string, "%d", Data.getTotalGrade());
	ScreenPrint(25, 11, string);
	
	system("pause");
}

void CResultScene::Render(){}
void CResultScene::Clear(){}

IScene * CResultScene::GetNextScene(){
	exit(0);
}

bool CResultScene::IsEnd(){
	return true;
}
