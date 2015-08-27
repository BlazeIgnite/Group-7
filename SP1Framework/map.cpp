#include "map.h"

unsigned char level[26][71];
char side[25][10];
short next=0;//current level of map change to access other levels
char checker = 0;
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
	inData.open("MAPS/Level1.txt");
	char level1[24][71];
	std::string line;
	unsigned int y = 0;
	while ( getline (inData,line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level1[y][x] = line[x];
		}
		y++;
	}
	for(int i=0;i<24;++i)
	{
		for(int c=0;c<71;++c)
		{
				level[i][c] = level1[i][c];
		}
	}
}
void level2()
{
	std::ifstream inData;
	inData.open("MAPS/Level2.txt");
	char level2[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level2[y][x] = line[x];
		}
		y++;
	}
 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level2[i][c];
                }
        }
}
void level3()
{
	std::ifstream inData;
	inData.open("MAPS/Level3.txt");
	char level3[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level3[y][x] = line[x];
		}
		y++;
	}

 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level3[i][c];
                }
        }
}
void level4()
{
	std::ifstream inData;
	inData.open("MAPS/Level4.txt");
	char level4[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level4[y][x] = line[x];
		}
		y++;
	}


		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level4[i][c];
			}
		}
}


void level5()
{
	std::ifstream inData;
	inData.open("MAPS/Level5.txt");
	char level5[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level5[y][x] = line[x];
		}
		y++;
	}
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level5[i][c];
                }
        }
}//not yet
void level6()
{
	std::ifstream inData;
	inData.open("MAPS/Level6.txt");
	char level6[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level6[y][x] = line[x];
		}
		y++;
	}

 
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level6[i][c];
                }
        }
}//not yet
void level7()
{
	std::ifstream inData;
	inData.open("MAPS/Level7.txt");
	char level7[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level7[y][x] = line[x];
		}
		y++;
	}
        
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level7[i][c];
                }
        }
}//not yet
void level8()
{
	std::ifstream inData;
	inData.open("MAPS/Level8.txt");
	char level8[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level8[y][x] = line[x];
		}
		y++;
	}
       
        for(int i=0;i<24;++i)
        {
                for(int c=0;c<71;++c)
                {
                        level[i][c] = level8[i][c];
                }
        }
}//not yet

void level9()
{
	std::ifstream inData;
	inData.open("MAPS/Level9.txt");
	char level9[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level9[y][x] = line[x];
		}
		y++;
	}
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level9[i][c];
			}
		}
}
void level10()
{
	std::ifstream inData;
	inData.open("MAPS/Level10.txt");
	char level10[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level10[y][x] = line[x];
		}
		y++;
	}
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level10[i][c];
			}
		}
}
void level11()
{
	std::ifstream inData;
	inData.open("MAPS/Level11.txt");
	char level11[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level11[y][x] = line[x];
		}
		y++;
	}
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level11[i][c];
			}
		}
}

void level12()
{
	std::ifstream inData;
	inData.open("MAPS/Level12.txt");
	char level12[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level12[y][x] = line[x];
		}
		y++;
	}
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level12[i][c];
			}
		}
}

void level13()
{
	std::ifstream inData;
	inData.open("MAPS/Level13.txt");
	char level13[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level13[y][x] = line[x];
		}
		y++;
	}
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level13[i][c];
			}
		}
}

void level14()
{
	std::ifstream inData;
	inData.open("MAPS/Level14.txt");
	char level14[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level14[y][x] = line[x];
		}
		y++;
	}
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
			{
				level[i][c] = level14[i][c];
			}
		}
}

void level15()
{
	std::ifstream inData;
	inData.open("MAPS/Level15.txt");
	char level15[24][71];
	std::string line;
	unsigned int y = 0;
	while (getline(inData, line))
	{
		unsigned int x = 0;
		for (x; x < 71; x++)
		{
			level15[y][x] = line[x];
		}
		y++;
	}
		for (int i = 0; i<24; ++i)
		{
			for (int c = 0; c<71; ++c)
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
	,	{" #           should. You hear there is a way to revert               #"}		
	,	{" #           back to normal, but it involves going                   #"}		
	,	{" #           through a ordeal of fifteen magical doors               #"}		
	,	{" #           that only appear for a thousand seconds.                #"}		
	,	{" #           Should you fail, you will never return to               #"}		
	,	{" #           normal every again. Good Luck!                          #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                                                                   #"}		
	,	{" #                            How to play                            #"}		
	,	{" #                                                                   #"}		
	,	{" #           Use the arrow keys to move and reach the                #"}		
	,	{" #           goal, marked by @ to advance to the next                #"}		
	,	{" #           stage. Your shadow has its left and                     #"}		
	,	{" #           right controls reversed!                                #"}		
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
void levelskip()
{
	if(next==98)
	{
		next=1;
	}
	else if(next==101)
	{
		next=6;
	}
	else if(next==102)
	{
		next=11;
	}
	else if(next==103)
	{
		next=16;
	}
}