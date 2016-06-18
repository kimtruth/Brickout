#ifndef CINITSCENE_H
#define CINITSCENE_H

#include "IScene.h"
#include "ScreenFunc.h"
#include <fmod.h>
extern FMOD_SYSTEM     *g_System;
extern FMOD_SOUND		*g_Sound[8];
extern FMOD_CHANNEL	*g_Channel[8];

class CInitScene : public IScene{
public:
	CInitScene();
	~CInitScene();

	void Update();
	void Render();
	void Clear();

	IScene * GetNextScene();
	bool IsEnd();
};

#endif