#ifndef CPLAYER_H
#define CPLAYER_H

#include <Windows.h>
#include "IObject.h"
#include <time.h>
class CBall;
class CPlayer : public IObject{
private:
	CBall * Ball;
public:
	CPlayer(CBall * Ball);
	void Move();
};

#endif