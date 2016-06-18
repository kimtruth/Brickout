#ifndef CRESULTSCENE_H
#define CRESULTSCENE_H

#include "IScene.h"
#include "ScreenFunc.h"
class CResultScene : public IScene{
public:
	CResultScene();
	~CResultScene();

	void Update();
	void Render();
	void Clear();

	IScene * GetNextScene();
	bool IsEnd();
};

#endif