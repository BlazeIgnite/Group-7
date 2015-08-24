#include "sound.h"
#include "game.h"


void step()
{
	PlaySound(TEXT("sounds/step.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP);
}

void playwin()
{
	PlaySound(TEXT("sounds/win.wav"),NULL,SND_FILENAME|SND_ASYNC);
}
void stopsound()
{
	PlaySound(NULL,NULL,0);
}
