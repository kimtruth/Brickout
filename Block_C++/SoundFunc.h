#ifndef SOUNDFUNC_H
#define SOUNDFUNC_H

#include <fmod.h>
typedef enum _SOUND { TITLE, RUN, FAIL, STAGE, BAR_COLLISION, BLOCK_COLLISION, FIRE, SUCCESS } SOUND;

void SoundInit();
void StartSong(SOUND index);
void StopSong(SOUND index);
void SoundRelease();
void SoundUpdate();
#endif