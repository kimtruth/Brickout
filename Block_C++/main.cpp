#include <Windows.h>
#include "CInitScene.h"
#include "ScreenFunc.h"
#include "SoundFunc.h"
#include "CGameData.h"

CGameData Data;

int main(){
	IScene * nowScene = new CInitScene();
	SoundInit();

	while (true){
		nowScene->Update();
		nowScene->Render();
		SoundUpdate();
		Sleep(70);
		nowScene->Clear();
		if (nowScene->IsEnd()) {
			system("cls");
			IScene * nextScene = nowScene->GetNextScene();
			delete nowScene;
			nowScene = nextScene;

			if (dynamic_cast<CInitScene *>(nowScene))
				Data.Init();
		}
	}
}