#include "SoundFunc.h"
#include <stdio.h>

FMOD_SYSTEM     *g_System;
FMOD_SOUND		*g_Sound[8];
FMOD_CHANNEL	*g_Channel[8];

void SoundInit() {
	// �ý��� ������Ʈ ������ �ʱ�ȭ
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);

	// �ݺ� ����
	FMOD_System_CreateSound(g_System, "title.wav", FMOD_DEFAULT | FMOD_LOOP_NORMAL, 0, &g_Sound[0]);
	FMOD_System_CreateSound(g_System, "run.wav", FMOD_DEFAULT | FMOD_LOOP_NORMAL, 0, &g_Sound[1]);
	FMOD_System_CreateSound(g_System, "fail.wav", FMOD_DEFAULT | FMOD_LOOP_NORMAL, 0, &g_Sound[2]); // ������ �̰��� ��	

	// ȿ�� ����
	FMOD_System_CreateSound(g_System, "stage.wav", FMOD_DEFAULT, 0, &g_Sound[3]); // �������� ��½� 
	FMOD_System_CreateSound(g_System, "ball_bar_wall_collision.wav", FMOD_DEFAULT, 0, &g_Sound[4]); // ��� ������ ���� �ε��� ��
	FMOD_System_CreateSound(g_System, "block_collision.wav", FMOD_DEFAULT, 0, &g_Sound[5]); // ������ ���� �΋H�� ��
	FMOD_System_CreateSound(g_System, "fire.wav", FMOD_DEFAULT, 0, &g_Sound[6]); // �� �߻�
	FMOD_System_CreateSound(g_System, "success.wav", FMOD_DEFAULT, 0, &g_Sound[7]); // �� �߻�
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