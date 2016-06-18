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


	ScreenPrint(0, 0, "��������������������������������������������");
	ScreenPrint(0, 1, "��                                        ��");
	ScreenPrint(0, 2, "��                                        ��");
	ScreenPrint(0, 3, "��                                        ��");
	ScreenPrint(0, 4, "��                                        ��");
	ScreenPrint(0, 5, "��                                        ��");
	ScreenPrint(0, 6, "��                                        ��");
	ScreenPrint(0, 7, "��   (((    ���� ����  ���� Score  ))))   ��");
	ScreenPrint(0, 8, "��                                        ��");
	ScreenPrint(0, 9, "��                                        ��");
	ScreenPrint(0, 10, "��                                        ��");
	ScreenPrint(0, 11, "��           �� ����  :                   ��");
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