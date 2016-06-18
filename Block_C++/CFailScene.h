#ifndef CFAILSCENE_H
#define CFAILSCENE_H

#include "IScene.h"
#include "ScreenFunc.h"
class CFailScene : public IScene{
public:
	CFailScene();
	~CFailScene();

	void Update();
	void Render();
	void Clear();

	IScene * GetNextScene();
	bool IsEnd();
};

#endif