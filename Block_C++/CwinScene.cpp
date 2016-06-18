#include <conio.h>
#include <Windows.h>
#include <stdio.h>

#include "CWinScene.h"
#include "CGameScene.h"
#include "CInitScene.h"
#include "CReadyScene.h"
#include "ScreenFunc.h"
#include "SoundFunc.h"
#include "CGameData.h"

extern CGameData Data;

CWinScene::CWinScene(){}
CWinScene::~CWinScene(){}

void CWinScene::Update(){

	StartSong(SUCCESS);
	ScreenInit();

	ScreenPrint(0, 0, "旨收收收收收收收收收收收收收收收收收收收收旬");
	ScreenPrint(0, 1, "早      *.                                早");
	ScreenPrint(0, 2, "早              .*            .*          早");
	ScreenPrint(0, 3, "早     *.                        .*       早");
	ScreenPrint(0, 4, "早       *.             .*                早");
	ScreenPrint(0, 5, "早           *.                           早");
	ScreenPrint(0, 6, "早            *.             .*           早");
	ScreenPrint(0, 7, "早     *.      *.旨旬旨旬.*渠    .*       早");
	ScreenPrint(0, 8, "早             旨朴朽曳朴旬欽             早");
	ScreenPrint(0, 9, "早     *.      早收朽曳收早п      .*     早");
	ScreenPrint(0, 10, "早             早收朽曳收早蹂~            早");
	ScreenPrint(0, 11, "早        *.   曲收旭曲收旭               早");
	ScreenPrint(0, 12, "早                                        早");
	ScreenPrint(0, 13, "早                          .*            早");
	ScreenPrint(0, 14, "早  *.           You Win!!          *.    早");
	ScreenPrint(0, 15, "早                                        早");
	ScreenPrint(0, 16, "早                                        早");
	ScreenPrint(0, 17, "早                       *.               早");
	ScreenPrint(0, 18, "早    *.         *.                       早");
	ScreenPrint(0, 19, "早                                 *.     早");
	ScreenPrint(0, 20, "早                      *.                早");
	ScreenPrint(0, 21, "早  *.                             *.     早");
	ScreenPrint(0, 22, "早                                        早");
	ScreenPrint(0, 23, "曲收收收收收收收收收收收收收收收收收收收收旭");

	char string[100];
	sprintf(string, "%d Stage", Data.getStage());
	ScreenPrint(19, 12, string);
	sprintf(string, "識薄: %d", Data.getTotalGrade());
	ScreenPrint(25, 16, string);

	Sleep(2000);
}

void CWinScene::Render(){}
void CWinScene::Clear(){}

IScene * CWinScene::GetNextScene(){
	StopSong(SUCCESS);
	return new CReadyScene();
}

bool CWinScene::IsEnd(){
	return true;
}
