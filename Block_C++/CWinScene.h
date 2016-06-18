#ifndef CWINSCENE_H
#define CWINSCENE_H

#include "IScene.h"
#include "ScreenFunc.h"
class CWinScene : public IScene{
public:
	CWinScene();
	~CWinScene();

	void Update();
	void Render();
	void Clear();

	IScene * GetNextScene();
	bool IsEnd();
};

#endif