#ifndef CBALL_H
#define CBALL_H

#include <time.h>
#include "IObject.h"
#include "CBlock.h"

typedef enum _DIRECT { TOP, LEFT_TOP, LEFT_DOWN, DOWN, RIGHT_DOWN, RIGHT_TOP } DIRECT;
class CPlayer;
class CBall : public IObject {
private :
	CBlock * Block;
	CPlayer * Player;
	int		 nReady;     // 1 이면 준비 상태, 0이면 이동 상태
	int		 nHP;        // 생명
	DIRECT   nDirect;    // 이동 방향
public:
	CBall(CBlock * Block);
	void Set();
	void Move();
	bool Collision(int x, int y);

	void setNReady(int nReady);
	void setNHP(int nHP);
	void setNDirect(DIRECT nDirect);
	void setPlayer(CPlayer * Player);

	int getNReady();
	int getNHP();
	DIRECT getNDirect();
};

#endif