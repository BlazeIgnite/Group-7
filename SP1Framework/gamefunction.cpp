#include <cmath>
#include "time.h"
#include "game.h"
#include "map.h"

extern unsigned char level[24][71];
extern short next;
extern short arandom,brandom;
extern short spawnX,spawnY;

void warpspawn(double *elapsedTime , COORD *charLocation , bool *contact)
{
	double d;
	mapseq(elapsedTime);
	srand((unsigned int)time(NULL));
	if(next>0 && next<16)
	{
		while( 1 )//infinite loop
		{
		
			arandom = rand() % 70+2;
			brandom = rand() % 20+2;
			if(arandom == charLocation->X && brandom == charLocation->Y)
			{
				continue;
			}
			d=pow((double)(charLocation->X - arandom),(double)2) + pow((double)(charLocation->Y - brandom),(double)2);
			if(d>400.0)
			{
				continue;
			}
			if( level[brandom][arandom] == ' ')
			{
				break;
			}
		}
		*contact = true;
	}
}//spawns monster that attacks red
void activewarp(move * character1 , bool * contact, COORD *charLocation)
{
	if ((brandom == character1->Y) && (arandom == character1->X) && (*contact == true))
	{
		do
		{
			arandom = rand() % 65+2;
			brandom = rand() % 20+2;
		} while ((level[brandom][arandom] != ' ') && (brandom != charLocation->X) && (arandom != charLocation->Y) && (arandom>0) && (brandom > 0));
		short a = arandom, b = brandom;
		charLocation->X = a;
		charLocation->Y = b + 1;
		*contact = false;
	}
}//collision function
void swapspawn(double *elapsedTime , COORD *charLocation2 , bool *contact2)
{
	double d;
	mapseq(elapsedTime);
	srand((unsigned int)time(NULL)-10);
	if(next>0 && next<16)
	{
		while(1)
		{
			spawnX=rand()%70+2;
			spawnY=rand()%20+2;

			if(spawnX==charLocation2->X && spawnY==charLocation2->Y)
			{
				continue;
			}
			d=pow((double)(charLocation2->X - spawnX),(double)2) + pow((double)(charLocation2->Y - spawnY),(double)2);
			if(d>400.0)
			{
				continue;
			}
			if(level[spawnY][spawnX] == ' ')
			{
				break;
			}
		}
		*contact2 =true;
	}
}//spawns monster that attacks green
void activeswap(COORD * charLocation2 ,COORD *charLocation, bool * contact2)
{
	short tempx = charLocation2->X;
	short tempy = charLocation2->Y;
	if(((charLocation2->Y-1)==spawnY) && (charLocation2->X==spawnX))
	{
		charLocation2->X = charLocation->X;
		charLocation2->Y = charLocation->Y;
		charLocation->X=tempx;
		charLocation->Y=tempy;
		*contact2=false;
	}
	//collision event
}