#include "ScreenFunc.h"
#include "SoundFunc.h"
#include "CGameScene.h"
#include "CGameData.h"
extern CGameData Data;

CBall::CBall(CBlock * Block) : IObject(19, 20, "●"){
	this->Block = Block;
	Set();
}

void CBall::Set(){
	this->x = 19;
	this->y = 20;
	this->nHP = 3;
	this->nDirect = TOP;
	this->nReady = 1;
}
void CBall::Move(){
	if (this->nReady == 0){
		switch (this->nDirect) {
		case TOP:
			if (!Collision(this->x, this->y - 1))
				this->y--;
			break;
		case LEFT_TOP:
			if (!Collision(this->x + 1, this->y - 1)) {
				this->x++;
				this->y--;
			}
			break;
		case LEFT_DOWN:
			if (!Collision(this->x + 1, this->y + 1)) {
				this->x++;
				this->y++;
			}
			break;
		case DOWN:
			if (!Collision(this->x, this->y + 1))
				this->y++;
			break;
		case RIGHT_DOWN:
			if (!Collision(this->x - 1, this->y + 1)) {
				this->x--;
				this->y++;
			}
			break;
		case RIGHT_TOP:
			if (!Collision(this->x - 1, this->y - 1)) {
				this->x--;
				this->y--;
			}
			break;
		}
	}
}

bool CBall::Collision(int x, int y){
	int i, nCount = 0; // 충돌 개수

	int g_StateTable[4][6] = { // 벽과 충돌하게 되면 방향 상태
		{ 3, 2, -1, -1, -1, 4 },
		{ -1, 5, 4, -1, -1, -1 },
		{ -1, -1, 1, 0, 5, -1 },
		{ -1, -1, -1, -1, 2, 1 }
	};

	// 공과 벽돌의 충돌
	for (i = 0; i < Data.getStageInfo()[Data.getStage() - 1].nBlockCount; i++)
	{
		if (Block[i].getNLife() == 1)
		{
			if (Block[i].y == y)
			{
				if ((Block[i].x == x || (Block[i].x + 1) == x) ||
					(Block[i].x == (x + 1) || (Block[i].x + 1) == (x + 1)))
				{
					this->nDirect = (DIRECT)Data.getBlockState()[this->nDirect];
					Block[i].setNLife(0);
					Data.setBlockCount(Data.getBlockCount() + 1);
					nCount++;
				}
			}
		}
	}

	// 충돌 체크 
	if (nCount != 0)
	{
		StartSong(BLOCK_COLLISION);
		return true;
	}

	// 공과 막대기 충돌
	for (i = 0; i < 3; i++)
	{
		if (y == Player->y)
		{
			if ((x >= Player->x && x <= (Player->x + 4 + 1)) || ((x + 1) >= Player->x && (x + 1) <= (Player->x + 4 + 1)))
			{
				this->nDirect = (DIRECT)Data.getBlockState()[this->nDirect];
				StartSong(BAR_COLLISION);
				return true;
			}
		}
	}

	// Note: 위쪽  
	if (y < 1)
	{
		this->nDirect = (DIRECT)g_StateTable[0][this->nDirect];
		return true;
	}

	// Note: 오른쪽
	if (x > 39)
	{
		this->nDirect = (DIRECT)g_StateTable[1][this->nDirect];
		return true;
	}

	// Note: 공의 초기화 및 생명 감소
	if (y > 22)
	{
		this->nHP--;

		if (this->nHP != 0){
			this->x = Player->x + 2;
			this->y = Player->y - 1;
			this->nReady = 1;
		}

		return true;
	}

	if (x < 2)
	{
		this->nDirect = (DIRECT)g_StateTable[3][this->nDirect];
		return true;
	}

	return false;
}


void CBall::setNReady(int nReady){ this->nReady = nReady; }
void CBall::setNHP(int nHP){ this->nHP = nHP; }
void CBall::setNDirect(DIRECT nDirect){ this->nDirect = nDirect; }
void CBall::setPlayer(CPlayer * Player){ this->Player = Player; }

int CBall::getNReady(){ return this->nReady; }
int CBall::getNHP(){ return this->nHP; }
DIRECT CBall::getNDirect(){ return this->nDirect; }
