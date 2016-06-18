#include "ScreenFunc.h"
#include "SoundFunc.h"
#include "CGameScene.h"

CPlayer::CPlayer(CBall * Ball) : IObject(17, 21, "▣▣▣"){
	this->Ball = Ball;
}
void CPlayer::Move(){
	int tempX = x;
	int tempBX = Ball->x;

	if (GetKeyState('J') & 0x8000){
		if (Ball->getNReady() == 1)
			Ball->x -= 3;
		x -= 3;
	}
	if (GetKeyState('L') & 0x8000){
		if (Ball->getNReady() == 1)
			Ball->x += 3;
		x += 3;
	}
	if (GetKeyState('K') & 0x8000){
		if (Ball->getNReady() == 1){
			Ball->setNReady(0);  // 이동 상태
			StartSong(FIRE);
		}
	}
	if (GetKeyState('I') & 0x8000){
		if (Ball->getNReady() == 0) {
			int x = Ball->x;
			int y = Ball->y;

			if (y == (this->y - 1)) {
				if ((x >= this->x && x <= this->x + 4+1)
					|| ((x + 1) >= this->x && (x + 1) <= this->x + 4+1)){
					Ball->setNReady(1);
				}
			}
		}
	}

	if (GetKeyState('1') & 0x8000){
		if (Ball->getNReady() == 1)
			Ball->setNDirect(RIGHT_TOP);
	}
	if (GetKeyState('2') & 0x8000){
		if (Ball->getNReady() == 1)
			Ball->setNDirect(TOP);
	}
	if (GetKeyState('3') & 0x8000){
		if (Ball->getNReady() == 1)
			Ball->setNDirect(LEFT_TOP);
	}

	if (Ball->x <= 2)
		Ball->x = 2;
	if (x > WIDTH - 8 || x < 2){
		x = tempX;
		Ball->x = tempBX;
	}
}