//this file is meant to store the codes for Monster spawning and teleportation.

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
		
			arandom = rand() % 70+2;//generate random X coord
			brandom = rand() % 20+2;//generate random Y coord
			if(arandom == charLocation->X && brandom == charLocation->Y)
			{
				continue;//no spawning on the character.
			}
			d=pow((double)(charLocation->X - arandom),(double)2) + pow((double)(charLocation->Y - brandom),(double)2);
			if(d>400.0)
			{
				continue;//spawn close to the character.
			}
			if( level[brandom][arandom] == ' ')
			{
				break;//spawn only in empty spaces that are not walls.
			}
		}
		*contact = true;
	}
}//spawns monster that attacks red
void activewarp(move * character1 , bool * contact, COORD *charLocation)
{
	if ((brandom == character1->Y) && (arandom == character1->X) && (*contact == true))//if collide
	{
		do
		{
			arandom = rand() % 65+2;//random x
			brandom = rand() % 20+2;//random Y
		} while ((level[brandom][arandom] != ' ') && (brandom != charLocation->X) && (arandom != charLocation->Y) && (arandom>0) && (brandom > 0));
		//teleport the player into empty area, not outside the room, not back to same location.
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
	srand((unsigned int)time(NULL)-10);//will not use the same RNG as warpspawn
	if(next>0 && next<16)
	{
		while(1)
		{
			spawnX=rand()%70+2;//random X
			spawnY=rand()%20+2;//random Y

			if(spawnX==charLocation2->X && spawnY==charLocation2->Y)
			{
				continue;//no teleporting onto player
			}
			d=pow((double)(charLocation2->X - spawnX),(double)2) + pow((double)(charLocation2->Y - spawnY),(double)2);
			if(d>400.0)
			{
				continue;//teleport close to the player
			}
			if(level[spawnY][spawnX] == ' ')
			{
				break;//spawn into empty area that is not wall.
			}
		}
		*contact2 =true;
	}
}//spawns monster that attacks green
void activeswap(COORD * charLocation2 ,COORD *charLocation, bool * contact2)
{
	short tempx = charLocation2->X;//store current coordinates X
	short tempy = charLocation2->Y;//store current coordinates Y
	if(((charLocation2->Y-1)==spawnY) && (charLocation2->X==spawnX))
	{
		charLocation2->X = charLocation->X;//move character 2 to where 1 is.
		charLocation2->Y = charLocation->Y;
		charLocation->X=tempx; //moves character 1 to the former coordinates of 2.
		charLocation->Y=tempy;
		*contact2=false;
	}
	//collision event
}