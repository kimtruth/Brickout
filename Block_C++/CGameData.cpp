#include "CGameData.h"

CGameData::CGameData(){
	Init();
}
CGameData::~CGameData(){
	delete [] this->StageInfo;
	delete[] this->BlockState;
}
void CGameData::Init(){
	this->Grade = 0;
	this->Stage = 0;
	this->StageInfo = new STAGE_INFO[3];
	this->StageInfo[0].LimitTime = 60 * 1000;
	this->StageInfo[0].nBlockCount = 30;
	this->StageInfo[1].LimitTime = 2 * 60 * 1000;
	this->StageInfo[1].nBlockCount = 50;
	this->StageInfo[2].LimitTime = 3 * 60 * 1000;
	this->StageInfo[2].nBlockCount = 100;
	this->BlockState = new int[6] { 3, 2, 1, 0, 5, 4 };
	this->BlockCount = 0;
	this->TotalGrade = 0;
}
void CGameData::setStage(int Stage){ this->Stage = Stage; }
void CGameData::setGrade(int Grade){ this->Grade = Grade; }
void CGameData::setTotalGrade(int TotalGrade){ this->TotalGrade = TotalGrade; }
void CGameData::setGameStartTime(clock_t GameStartTime){ this->GameStartTime = GameStartTime; }
void CGameData::setUpdateOldTime(clock_t UpdateOldTime){ this->UpdateOldTime = UpdateOldTime; }
void CGameData::setRemainTime(clock_t RemainTime){ this->RemainTime = RemainTime; }
void CGameData::setBlockCount(int BlockCount){ this->BlockCount = BlockCount; }

int CGameData::getStage(){ return this->Stage; }
int CGameData::getGrade(){ return this->Grade; }
int CGameData::getTotalGrade(){ return this->TotalGrade; }
int * CGameData::getBlockState(){ return this->BlockState; }
int CGameData::getBlockCount(){ return this->BlockCount; }

STAGE_INFO * CGameData::getStageInfo(){ return this->StageInfo; }
clock_t CGameData::getGameStartTime(){ return this->GameStartTime; }
clock_t CGameData::getUpdateOldTime(){ return this->UpdateOldTime; }
clock_t CGameData::getRemainTime(){ return this->RemainTime; }