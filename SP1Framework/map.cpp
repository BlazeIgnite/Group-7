#include "map.h"
#include "game.h"
#include <fstream>
#include <string>

unsigned char level[26][71];
char side[25][10];
short next=0;//current level of map change to access other levels
char checker = 0;

extern short levelcount;
void menu()
{
		checker = 0;
        char menu[24][71]={
                {" #####################################################################"}
        ,       {" #                                                                   #"}
		,       {" #      *       * ***** ****  ****   ***  ****                       #"}
		,       {" #      **     **   *   *   * *   * *   * *   *                      #"}
		,       {" #      * *   * *   *   ****  ****  *   * ****                       #"}
		,       {" #      *  * *  *   *   *  *  *  *  *   * *  *                       #"}
		,       {" #      *   *   * ***** *   * *   *  ***  *   *                      #"}
        ,       {" #                                                                   #"}
		,       {" #                     ###                                           #"}
        ,       {" #                     # # Start                                     #"}
        ,       {" #                     # # Instructions                              #"}
		,       {" #                     # # Mute                                      #"}
		,       {" #                     # # Quit                                      #"}
		,       {" #                     ###                                           #"}
		,       {" #      *****  *       *   ***    ****  *****                        #"}
		,       {" #        *    **     **  *   *  *      *                            #"}
		,       {" #        *    * *   * *  *****  *  **  ***                          #"}
		,       {" #        *    *  * *  *  *   *  *   *  *                            #"}
		,       {" #      *****  *   *   *  *   *   ****  *****                        #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #                                                                   #"}
        ,       {" #####################################################################"}};
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = menu[i][c];
                }
        }
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
	std::ifstream inData;
	inData.open("MAPS/Level1.txt"); //Obtain map from text
	char level1[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while ( getline (inData,line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level1[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
	for(int i=0;i<24;++i)
	{
		for(int c=0;c<70;++c)
		{
				level[i][c] = level1[i][c]; //send data to buffer
		}
	}
}
void level2()
{
	std::ifstream inData;
	inData.open("MAPS/Level2.txt"); //Obtain map from text
	char level2[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level2[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
    for(int i=0;i<24;++i)
    {
            for(int c=0;c<70;++c)
            {
                    level[i][c] = level2[i][c];
            }
    }
}
void level3()
{
	std::ifstream inData;
	inData.open("MAPS/Level3.txt"); //Obtain map from text
	char level3[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level3[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
    for(int i=0;i<24;++i)
    {
            for(int c=0;c<70;++c)
            {
                    level[i][c] = level3[i][c];
            }
    }
}
void level4()
{
	std::ifstream inData;
	inData.open("MAPS/Level4.txt"); //Obtain map from text
	char level4[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level4[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
	for (int i = 0; i<24; ++i)
	{
		for (int c = 0; c<70; ++c)
		{
			level[i][c] = level4[i][c];
		}
	}
}
void level5()
{
	std::ifstream inData;
	inData.open("MAPS/Level5.txt"); //Obtain map from text
	char level5[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level5[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
    for(int i=0;i<24;++i)
    {
            for(int c=0;c<70;++c)
            {
                    level[i][c] = level5[i][c];
            }
    }
}//not yet
void level6()
{
	std::ifstream inData;
	inData.open("MAPS/Level6.txt"); //Obtain map from text
	char level6[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level6[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
    for(int i=0;i<24;++i)
    {
            for(int c=0;c<70;++c)
            {
                    level[i][c] = level6[i][c];
            }
    }
}//not yet
void level7()
{
	std::ifstream inData;
	inData.open("MAPS/Level7.txt"); //Obtain map from text
	char level7[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level7[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}   
    for(int i=0;i<24;++i)
    {
            for(int c=0;c<70;++c)
            {
                    level[i][c] = level7[i][c];
            }
    }
}//not yet
void level8()
{
	std::ifstream inData;
	inData.open("MAPS/Level8.txt"); //Obtain map from text
	char level8[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level8[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
    for(int i=0;i<24;++i)
    {
            for(int c=0;c<70;++c)
            {
                    level[i][c] = level8[i][c];
            }
    }
}//not yet
void level9()
{
	std::ifstream inData;
	inData.open("MAPS/Level9.txt"); //Obtain map from text
	char level9[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level9[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
	for (int i = 0; i<24; ++i)
	{
		for (int c = 0; c<70; ++c)
		{
			level[i][c] = level9[i][c];
		}
	}
}
void level10()
{
	std::ifstream inData;
	inData.open("MAPS/Level10.txt"); //Obtain map from text
	char level10[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level10[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
	for (int i = 0; i<24; ++i)
	{
		for (int c = 0; c<70; ++c)
		{
			level[i][c] = level10[i][c];
		}
	}
}
void level11()
{
	std::ifstream inData;
	inData.open("MAPS/Level11.txt"); //Obtain map from text
	char level11[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level11[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
	for (int i = 0; i<24; ++i)
	{
		for (int c = 0; c<70; ++c)
		{
			level[i][c] = level11[i][c];
		}
	}
}
void level12()
{
	std::ifstream inData;
	inData.open("MAPS/Level12.txt"); //Obtain map from text
	char level12[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level12[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
	for (int i = 0; i<24; ++i)
	{
		for (int c = 0; c<70; ++c)
		{
			level[i][c] = level12[i][c];
		}
	}
}
void level13()
{
	std::ifstream inData;
	inData.open("MAPS/Level13.txt"); //Obtain map from text
	char level13[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level13[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
	for (int i = 0; i<24; ++i)
	{
		for (int c = 0; c<70; ++c)
		{
			level[i][c] = level13[i][c];
		}
	}
}
void level14()
{
	std::ifstream inData;
	inData.open("MAPS/Level14.txt"); //Obtain map from text
	char level14[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level14[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
	for (int i = 0; i<24; ++i)
	{
		for (int c = 0; c<70; ++c)
		{
			level[i][c] = level14[i][c];
		}
	}
}
void level15()
{
	std::ifstream inData;
	inData.open("MAPS/Level15.txt"); //Obtain map from text
	char level15[24][71];  //2d array to store map
	std::string line;
	unsigned int y = 0;
	unsigned int x = 0;
	while (getline(inData, line)) //get map line by line into the var line
	{
		x = 0;
		for (x; x < 70; x++)
		{
			level15[y][x] = line[x]; //storing string line into the char 2d array
		}
		y++;
	}
	for (int i = 0; i<24; ++i)
	{
		for (int c = 0; c<70; ++c)
		{
			level[i][c] = level15[i][c];
		}
	}
}
void lose()
{
        char lose[24][71]={
			    {" #####################################################################"}
        ,       {" # ################################################################# #"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
		,       {" ##                                                                 ##"}
		,       {" ##                                                                 ##"}
		,       {" ##            ***     ***     ********     **        **            ##"}
		,       {" ##            ***     ***     ********     **        **            ##"}
		,       {" ##            ***     ***  ***        **   **        **            ##"}
        ,       {" ##            ***     ***  ***        **   **        **            ##"}
        ,       {" ##              ***  **    ***        **   **        **            ##"}
        ,       {" ##              ***  **    ***        **   **        **            ##"}
		,       {" ##                ***      ***        **   **        **            ##"}
        ,       {" ##                ***      ***        **   **        **            ##"}
        ,       {" ##                ***         ********       ********              ##"}
		,       {" ##                ***         ********       ********              ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                     Lost.                       ##"}
        ,       {" ##             press space to continue....                         ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##                                                                 ##"}
        ,       {" #####################################################################"}

       
        };
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = lose[i][c];
                }
        }
}
void help() 		
{		
	char help[24][71]={		
		{" #####################################################################"}		
	,	{" #                                                                   #"}		
	,	{" #                               Story                               #"}		
	,	{" #                                                                   #"}		
	,	{" #           Your shadow seems to be trolling you, and               #"}		
	,	{" #           doesn't seem to follow you as it normally               #"}		
	,	{" #           should. You must escape the 15 levels of                #"}		
	,	{" #           the dungeon within 1000 seconds or fail!                #"}		
	,	{" #                                                                   #"}				
	,	{" #                            How to play                            #"}		
	,	{" #                                                                   #"}		
	,	{" #           Use the arrow keys to move and reach the                #"}		
	,	{" #           goal, marked by @ to advance to the next                #"}		
	,	{" #           stage. Your shadow has its left and                     #"}		
	,	{" #           right controls reversed!                                #"}
	,	{" #                                                                   #"}		
	,	{" #             is a door.   is a portal. If your shadow              #"}		
	,	{" #           touches  , you will swap places with yourself.          #"}		
	,	{" #           If you touch  , you will be randomly teleported.        #"}		
	,	{" #           When you touch  , you will open doors!                  #"}		
	,	{" #                                                                   #"}
	,	{" ##                                                                 ##"}		
	,	{" # #             PRESS SPACE TO RETURN TO THE MENU                 # #"}		
	,	{" #####################################################################"}};		
		
        for(int i=0;i<24;++i)		
        {		
                for(int c=0;c<71;++c)		
                {		
                        level[i][c] = help[i][c];		
                }		
        }		
		
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
	char help[24][71]={		
		{" #####################################################################"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                    Number of steps :                              #"}		
	,	{" #                         Time taken :                              #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}				
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}
	,	{" ##                                                                 ##"}		
	,	{" # #                   PRESS SPACE TO CONTINUE                     # #"}		
	,	{" #####################################################################"}};		
		
        for(int i=0;i<24;++i)		
        {		
                for(int c=0;c<71;++c)		
                {		
                        level[i][c] = help[i][c];		
                }		
        }

}

void win()
{
	//screen for winning, if the player has a highscore.
		if(checker == 0)
		{
			storepoints();
			checker++;
		}
        char win[24][71]={
			    {" #####################################################################"}
        ,       {" # #                  Your score is:                               # #"}
        ,       {" ##Top 10 scores:     Press space to continue...                    ##"}
		,       {" ##                                                                 ##"}
		,       {" ##            ***     ***     ********     **        **            ##"}
		,       {" ##            ***     ***    **********    **        **            ##"}
		,       {" ##            ***     ***   **        **   **        **            ##"}
        ,       {" ##            ***     ***   **        **   **        **            ##"}
        ,       {" ##              ***  **     **        **   **        **            ##"}
        ,       {" ##              ***  **     **        **   **        **            ##"}
		,       {" ##                ***       **        **   **        **            ##"}
        ,       {" ##                ***       **        **   **        **            ##"}
        ,       {" ##                ***        **********      ********              ##"}
		,       {" ##                ***         ********       ********              ##"}
        ,       {" ##                                                                 ##"}
        ,       {" ##            **  **  **        ***       *****      **            ##"}
        ,       {" ##            **  **  **        ***       *****      **            ##"}
        ,       {" ##            **  **  **        ***       ***  **    **            ##"}
        ,       {" ##            **  **  **        ***       ***  **    **            ##"}
        ,       {" ##            **  **  **        ***       ***    **  **            ##"}
        ,       {" ##            **  **  **        ***       ***    **  **            ##"}
		,       {" ###             **  **          ***       ***      ****           ###"}
		,       {" ## #            **  **          ***       ***      ****          # ##"}
		,       {" #####################################################################"}};
 
        for(int i=0;i<24;++i)
        {
            for(int c=0;c<71;++c)
            {
                level[i][c] = win[i][c];
            }
        }
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
		case 16: charLocation->X = 2;charLocation->Y = 23;charLocation2->X = 68;charLocation2->Y = 23; break;
		case 100: charLocation->X = 2;charLocation->Y = 2;charLocation2->X = 68;charLocation2->Y = 2;break;
	}
}
void mapseq(double *elapsedTime)
{
	COORD charLocation1, charLocation2;

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
		case 101:levelskip(&charLocation1,&charLocation2);break;
	}
}