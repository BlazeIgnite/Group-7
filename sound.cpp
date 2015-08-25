#include "sound.h"
#include "game.h"

extern short next;

void ambience()
{
	if(next>=1 && next<=5)
	{
		PlaySound(TEXT("sounds/sound1.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP);
	}
	else if (next>=6 && next<=10)
	{
		PlaySound(TEXT("sounds/sound2.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP);
	}
	else if(next>=11 && next<=15)
	{
		stopsound();
	}

	else if(next==16)
	{
		playwin();
	}
	else
	{
		stopsound();
	}
}

void playwin()
{
	PlaySound(TEXT("sounds/win.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP);
}
void stopsound()
{
	PlaySound(NULL,NULL,0);
}
