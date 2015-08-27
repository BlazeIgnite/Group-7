#include "sound.h"
#include "game.h"

extern short next;

void ambience()
{
	if (next == 0 || next ==99)
	{
		PlaySound(TEXT("sounds/menu.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP);
	}
	else if(next>=1 && next<=5)
	{
		PlaySound(TEXT("sounds/sound1.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP);
	}
	else if (next>=6 && next<=10)
	{
		PlaySound(TEXT("sounds/sound2.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP);
	}
	else if(next>=11 && next<=15)
	{
		PlaySound(TEXT("sounds/sound3.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_NOSTOP);
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
