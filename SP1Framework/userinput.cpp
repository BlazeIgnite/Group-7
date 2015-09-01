#include "Framework\console.h"
#include "game.h"
extern Console console;
extern unsigned char level[26][71];
extern bool dooropen;
extern COORD charLocation;
extern COORD charLocation2;
extern short next;
extern int step;
void moveCharacter(move *character1, move*character2,bool *nextlevel,short*levelcount)
{

	//initilize value to xy for each character
	character1->X = charLocation.X;
	character1->Y = charLocation.Y - 1;
	character2->X = charLocation2.X;
	character2->Y = charLocation2.Y - 1;
	// Updating the location of the 1st character based on the key press
	if (isKeyPressed(VK_UP) && charLocation.Y > 0)//up
	{
		if (level[character1->Y - 1][character1->X] == '#');
		else if ((level[character1->Y - 1][character1->X] == '$') && (dooropen == 0));
		else
		{
			charLocation.Y--;
			step++;//counts the number of movement you made
		}
	}
	else if (isKeyPressed(VK_LEFT) && charLocation.X > 0)//left
	{
		if (level[character1->Y][character1->X - 1] == '#');
		else if ((level[character1->Y][character1->X - 1] == '$') && (dooropen == 0));
		else
		{
			charLocation.X--;
			step++;//counts the number of movement you made
		}
	}
	else if (isKeyPressed(VK_DOWN) && charLocation.Y < console.getConsoleSize().Y - 1)//down
	{
		if (level[character1->Y + 1][character1->X] == '#');
		else if ((level[character1->Y + 1][character1->X] == '$') && (dooropen == 0));
		else
		{
			charLocation.Y++;
			step++;//counts the number of movement you made
		}

	}
	else if (isKeyPressed(VK_RIGHT) && charLocation.X < console.getConsoleSize().X - 1)//right
	{
		if (level[character1->Y][character1->X + 1] == '#');
		else if ((level[character1->Y][character1->X + 1] == '$') && (dooropen == 0));
		else
		{
			charLocation.X++;
			step++;//counts the number of movement you made
		}
	}
	//2nd character
	if (isKeyPressed(VK_UP) && charLocation2.Y > 0)
	{
		if (level[character2->Y - 1][character2->X] == '#');
		else if ((level[character2->Y - 1][character2->X] == '$') && (dooropen == 0));
		else
		{
			charLocation2.Y--;
			step++;//counts the number of movement you made
		}
	}
	else if (isKeyPressed(VK_LEFT) && charLocation2.X < console.getConsoleSize().X - 1)
	{
		if (level[character2->Y][character2->X + 1] == '#');
		else if ((level[character2->Y][character2->X + 1] == '$') && (dooropen == 0));
		else
		{
			charLocation2.X++;
			step++;//counts the number of movement you made
		}
	}
	else if (isKeyPressed(VK_DOWN) && charLocation2.Y < console.getConsoleSize().Y - 1)
	{
		if (level[character2->Y + 1][character2->X] == '#');
		else if ((level[character2->Y + 1][character2->X] == '$') && (dooropen == 0));
		else
		{
			charLocation2.Y++;
			step++;//counts the number of movement you made
		}
	}
	else if (isKeyPressed(VK_RIGHT) && charLocation2.X > 0)
	{
		if (level[character2->Y][character2->X - 1] == '#');
		else if ((level[character2->Y][character2->X - 1] == '$') && (dooropen == 0));
		else
		{
			charLocation2.X--;
			step++;//counts the number of movement you made
		}
	}
	if (level[character2->Y][character2->X] == '%' || level[character1->Y][character1->X] == '%')
	{
		dooropen = true;//opens door if player touches the key
	}
	if (level[character2->Y][character2->X] == '@' && level[character1->Y][character1->X] == '@' || (isKeyPressed(VK_LEFT) && isKeyPressed(VK_RETURN)))
	{
		//code for advancing thru checkpoints/admin hax XD.
		switch(next)
		{
		case 5: *levelcount = next;next = 101;charLocation.X = 2; charLocation.Y = 23; charLocation2.X = 68; charLocation2.Y = 23;break;
		case 10:*levelcount = next;next = 101;charLocation.X = 2; charLocation.Y = 23; charLocation2.X = 68; charLocation2.Y = 23;break;
		case 15:*levelcount = next;next = 101;charLocation.X = 2; charLocation.Y = 23; charLocation2.X = 68; charLocation2.Y = 23;break;
		}
		//this switch is needed to force a change in soundtracks.
		if (next<16)
		{
			Beep(1440, 30);
			next++;//beep when touch
		}
		*nextlevel = true;//go to next level
		dooropen = false;//shut all open doors.
		spawnpoints(&charLocation, &charLocation2);//move the spawnpoints of the characters
	}
}