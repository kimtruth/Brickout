#ifndef CGAMESCENE_H
#define CGAMESCENE_H

#include "IScene.h"
#include "CBall.h"
#include "CBlock.h"
#include "CPlayer.h"

class CGameScene : public IScene{
private:
	CPlayer * Player;
	CBall * Ball;
	CBlock * Block;
	IObject * Object[102];
	int BlockNum;
	bool amiDie;
public:
	CGameScene();
	~CGameScene();

	void Update();
	void Render();
	void Clear();

	IScene * GetNextScene();
	bool IsEnd();

	bool Search(int nEnd, int nX, int nY);
	void SetBlock();
};


#endif