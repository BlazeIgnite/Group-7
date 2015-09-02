#include "map.h"
#include "game.h"
#include <fstream>
#include <string>

unsigned char level[26][71];
char side[25][10];
short next=0;//current level of map change to access other levels
char checker = 0;
char maps[20][24][70];

extern short levelcount;

void levelPreloader()
{
	std::ifstream inData;
	inData.open("MAPS/Levels.txt");
	char map[24][70];
	std::string line;
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int z = 0;
	while (getline (inData,line))
	{
		if (line[0] == '[')
		{
			while ( getline (inData,line)) //get map line by line into the var line
			{
				if (line[0] == ']' || y == 24)
				{
					break;
				}
				x = 0;
				for (x; x < 70; x++)
				{
					maps[z][y][x] = line[x]; //storing string line into the char array
				}
				y++;
			}
			
		}
		z++;
		y = 0;
		if (line[0] == '!')
		{
			break;
		}
	}
	inData.close();
}

void levelloader(int a)
{
	unsigned int y = 0;
	unsigned int x = 0;
	char levels[24][70];
	for (y = 0; y < 24; y++)
	{
		for (x = 0; x < 70; x++)
		{
			levels[y][x] = maps[a][y][x];
		}
	}
	for(int i=0;i<24;++i)
	{
		for(int c=0;c<70;++c)
		{
			level[i][c] = levels[i][c]; //send data to buffer
		}
	}
}

void levelloader(char a, char b)
{
	if (a == '0')
	{
		switch (b)
		{
			case '1':levelloader(0);break;
			case '2':levelloader(1);break;
			case '3':levelloader(2);break;
			case '4':levelloader(3);break;
			case '5':levelloader(4);break;
			case '6':levelloader(5);break;
			case '7':levelloader(6);break;
			case '8':levelloader(7);break;
			case '9':levelloader(8);break;
		}
	}
	if (a == '1')
	{
		switch (b)
		{
			case '0':levelloader(9);break;
			case '1':levelloader(10);break;
			case '2':levelloader(11);break;
			case '3':levelloader(12);break;
			case '4':levelloader(13);break;
			case '5':levelloader(14);break;
		}
	}
}


void levelselect(char a, char b)
{
	switch (a)
	{
		case '0':levelloader('0', b);break;
		case '1':levelloader('1', b);break;
		case 'M':levelloader(15);break;
		case 'W':levelloader(16);break;
		case 'L':levelloader(17);break;
		case 'H':levelloader(18);break;
		case 'P':levelloader(19);break;
	}
}

void menu()
{
	levelselect('M','N');
}
void sidemenu()
{
        char sidemenu [23][10]={
         {"#########"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
		,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#Time:  #"}
        ,{"#       #"}
        ,{"#Level: #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#       #"}
        ,{"#########"}};
 
        for(int i=0;i<23;++i)
        {
                for(int c=0;c<10;++c)
                {
                        side[i][c] = sidemenu[i][c];
                }
        }
}
void level1()
{
	levelselect('0','1');
}
void level2()
{
	levelselect('0','2');
}
void level3()
{
	levelselect('0','3');
}
void level4()
{
	levelselect('0','4');
}
void level5()
{
	levelselect('0','5');
}//not yet
void level6()
{
	levelselect('0','6');
}//not yet
void level7()
{
	levelselect('0','7');
}//not yet
void level8()
{
	levelselect('0','8');
}//not yet
void level9()
{
	levelselect('0','9');
}
void level10()
{
	levelselect('1','0');
}
void level11()
{
	levelselect('1','1');
}
void level12()
{
	levelselect('1','2');
}
void level13()
{
	levelselect('1','3');
}
void level14()
{
	levelselect('1','4');
}
void level15()
{
	levelselect('1','5');
}
void lose()
{
	levelselect('L','S');
}
void help() 		
{		
	levelselect('H','P');
}
void levelskip(COORD *charLocation , COORD *charLocation2)
{
	if(levelcount==0)
	{
		next=1;
	}
	if(levelcount==15)
	{
		next=16;
		charLocation->X = 2;charLocation->Y = 23;charLocation2->X = 68;charLocation2->Y = 23;
	}
	levelselect('P','S');
}

void win()
{
	//screen for winning, if the player has a highscore.
		if(checker == 0)
		{
			storepoints();
			checker++;
		}
        levelselect('W','N');
}
void spawnpoints(COORD *charLocation , COORD *charLocation2)
{
	//all spawnpoints in the game.
	switch(next)
	{
		case 2: charLocation->X = 2; charLocation->Y = 23; charLocation2->X = 68; charLocation2->Y = 23;break;
		case 3: charLocation->X = 31; charLocation->Y = 4; charLocation2->X = 40; charLocation2->Y = 3;break;
		case 4: charLocation->X = 2; charLocation->Y = 3; charLocation2->X = 67; charLocation2->Y = 3;break;
		case 5: charLocation->X = 4; charLocation->Y = 5; charLocation2->X = 63; charLocation2->Y = 22;break;
		case 6: charLocation->X = 7; charLocation->Y = 3; charLocation2->X = 67; charLocation2->Y = 22;break;
		case 7: charLocation->X = 17; charLocation->Y = 12; charLocation2->X = 53; charLocation2->Y = 12;break;
		case 8: charLocation->X = 3; charLocation->Y = 21; charLocation2->X = 67; charLocation2->Y = 4; break;
		case 9: charLocation->X = 2; charLocation->Y = 14; charLocation2->X = 68; charLocation2->Y = 13; break;
		case 10: charLocation->X = 3; charLocation->Y = 4; charLocation2->X = 37; charLocation2->Y = 4; break;
		case 11: charLocation->X = 2; charLocation->Y = 3; charLocation2->X = 67; charLocation2->Y = 3; break;
		case 12: charLocation->X = 4; charLocation->Y = 12; charLocation2->X = 67; charLocation2->Y = 21; break;
		case 13: charLocation->X = 63; charLocation->Y = 19; charLocation2->X = 19; charLocation2->Y = 19; break;
		case 14: charLocation->X = 31; charLocation->Y = 17; charLocation2->X = 39; charLocation2->Y = 17; break;
		case 15: charLocation->X = 34; charLocation->Y = 21; charLocation2->X = 36; charLocation2->Y = 21; break;
		case 16: charLocation->X = 3;charLocation->Y = 23;charLocation2->X = 67;charLocation2->Y = 23; break;
		case 100: charLocation->X = 2;charLocation->Y = 2;charLocation2->X = 68;charLocation2->Y = 2;break;
	}
}
void mapseq(double *elapsedTime)
{
	COORD charLoc1, charLoc2;
	//level sequence, and the reference "next" values
	switch(next)
	{
		case 0:menu();sidemenu();break;
		case 1:level1();break;
		case 2:level2();break;
		case 3:level3();break;
		case 4:level4();break;
		case 5:level5();break;
		case 6:level6();break;
		case 7:level7();break;
		case 8:level8();break;
		case 9:level9();break;
		case 10:level10();break;
		case 11:level11();break;
		case 12:level12();break;
		case 13:level13();break;
		case 14:level14();break;
		case 15:level15();break;
		case 16:win();break;
		case 99:help();break;
		case 100:lose();elapsedTime=0;break;
		case 101:levelskip(&charLoc1,&charLoc2);break;
	}
}