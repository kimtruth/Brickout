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

	ScreenPrint(0, 0, "��������������������������������������������");
	ScreenPrint(0, 1, "��                                        ��");
	ScreenPrint(0, 2, "��                                        ��");
	ScreenPrint(0, 3, "��                                        ��");
	ScreenPrint(0, 4, "��                                        ��");
	ScreenPrint(0, 5, "��                                        ��");
	ScreenPrint(0, 6, "��                                        ��");
	ScreenPrint(0, 7, "��              S t a g e                 ��");
	ScreenPrint(0, 8, "��                            ��          ��");
	ScreenPrint(0, 9, "��                      �С리��          ��");
	ScreenPrint(0, 10, "��                        �С린          ��");
	ScreenPrint(0, 11, "��                          ������        ��");
	ScreenPrint(0, 12, "��                                        ��");
	ScreenPrint(0, 13, "��                                        ��");
	ScreenPrint(0, 14, "��                                        ��");
	ScreenPrint(0, 15, "��                                        ��");
	ScreenPrint(0, 16, "��                                        ��");
	ScreenPrint(0, 17, "��                                        ��");
	ScreenPrint(0, 18, "��                                        ��");
	ScreenPrint(0, 19, "��                                        ��");
	ScreenPrint(0, 20, "��                                        ��");
	ScreenPrint(0, 21, "��                                        ��");
	ScreenPrint(0, 22, "��                                        ��");
	ScreenPrint(0, 23, "��������������������������������������������");
	
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
