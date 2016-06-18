#ifndef CREADYSCENE_H
#define CREADYSCENE_H

#include "IScene.h"
#include "ScreenFunc.h"
class CReadyScene : public IScene{
public:
	CReadyScene();
	~CReadyScene();

	void Update();
	void Render();
	void Clear();

	IScene * GetNextScene();
	bool IsEnd();
};

#endif