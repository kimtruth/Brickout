#include "CInitScene.h"
#include "CReadyScene.h"
#include "ScreenFunc.h"
#include <conio.h>
#include <Windows.h>
#include "SoundFunc.h"

CInitScene::CInitScene(){}
CInitScene::~CInitScene(){}

void CInitScene::Update(){

	StartSong(TITLE);
	ScreenInit();

	ScreenPrint(0, 0, "��������������������������������������������");
	ScreenPrint(0, 1, "��                                        ��");
	ScreenPrint(0, 2, "��    �����������������    ��");
	ScreenPrint(0, 3, "��      ���������������      ��");
	ScreenPrint(0, 4, "��        �������������        ��");
	ScreenPrint(0, 5, "��          �����������          ��");
	ScreenPrint(0, 6, "��          ��������������������          ��");
	ScreenPrint(0, 7, "��          ���� ���� ����  �ڦ�          ��");
	ScreenPrint(0, 8, "��          ��������������������          ��");
	ScreenPrint(0, 9, "��              /)/)    �� ��             ��");
	ScreenPrint(0, 10, "��           ��(*'')/                     ��");
	ScreenPrint(0, 11, "��          �����������          ��");
	ScreenPrint(0, 12, "��        �������������        ��");
	ScreenPrint(0, 13, "��      ���������������      ��");
	ScreenPrint(0, 14, "��    �����������������    ��");
	ScreenPrint(0, 15, "��                                        ��");
	ScreenPrint(0, 16, "��                                        ��");
	ScreenPrint(0, 17, "��    �� �����̽�Ű�� �����ּ���!! ��     ��");
	ScreenPrint(0, 18, "��                                        ��");
	ScreenPrint(0, 19, "��     J:��  L:�� K: ���߻� I: �����     ��");
	ScreenPrint(0, 20, "��     ( �� �߻� ���� )                   ��");
	ScreenPrint(0, 21, "��       1: ���� 2: ���� 3: ������        ��");
	ScreenPrint(0, 22, "��                                        ��");
	ScreenPrint(0, 23, "��������������������������������������������");

	while (getch() != VK_SPACE);
}

void CInitScene::Render(){}
void CInitScene::Clear(){}

IScene * CInitScene::GetNextScene(){
	StopSong(TITLE);
	return new CReadyScene();
}

bool CInitScene::IsEnd(){
	return true;
}
