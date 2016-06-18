#include "SoundFunc.h"
#include <stdio.h>

FMOD_SYSTEM     *g_System;
FMOD_SOUND		*g_Sound[8];
FMOD_CHANNEL	*g_Channel[8];

void SoundInit() {
	// 시스템 오브젝트 생성과 초기화
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);

	// 반복 사운드
	FMOD_System_CreateSound(g_System, "title.wav", FMOD_DEFAULT | FMOD_LOOP_NORMAL, 0, &g_Sound[0]);
	FMOD_System_CreateSound(g_System, "run.wav", FMOD_DEFAULT | FMOD_LOOP_NORMAL, 0, &g_Sound[1]);
	FMOD_System_CreateSound(g_System, "fail.wav", FMOD_DEFAULT | FMOD_LOOP_NORMAL, 0, &g_Sound[2]); // 적군이 이겼을 때	

	// 효과 사운드
	FMOD_System_CreateSound(g_System, "stage.wav", FMOD_DEFAULT, 0, &g_Sound[3]); // 스테이지 출력시 
	FMOD_System_CreateSound(g_System, "ball_bar_wall_collision.wav", FMOD_DEFAULT, 0, &g_Sound[4]); // 경계 영역과 공이 부딪힐 때
	FMOD_System_CreateSound(g_System, "block_collision.wav", FMOD_DEFAULT, 0, &g_Sound[5]); // 벽돌과 공이 부딫힐 때
	FMOD_System_CreateSound(g_System, "fire.wav", FMOD_DEFAULT, 0, &g_Sound[6]); // 공 발사
	FMOD_System_CreateSound(g_System, "success.wav", FMOD_DEFAULT, 0, &g_Sound[7]); // 공 발사
}
void StartSong(SOUND index){
	FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[index], 0, &g_Channel[index]);
}
void StopSong(SOUND index){
	FMOD_Channel_Stop(g_Channel[index]);
}
void SoundRelease(){
	for (int i = 0; i < 8; i++)
		FMOD_Sound_Release(g_Sound[i]);

	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}
void SoundUpdate(){
	FMOD_System_Update(g_System);
}