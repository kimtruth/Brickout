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
	int		 nReady;     // 1 �̸� �غ� ����, 0�̸� �̵� ����
	int		 nHP;        // ����
	DIRECT   nDirect;    // �̵� ����
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