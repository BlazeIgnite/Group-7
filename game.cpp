// This is the main file for the game logic and function
//
//
#include "game.h"
#include "map.h"
#include "Framework\console.h"
#include "sound.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

// Console object
Console console(79, 25, "SP1 Framework");
 
// extern from map.cpp
extern unsigned char level[26][71];
extern char side[25][10];
extern short next;
extern char checker;

double elapsedTime;
double deltaTime;

short data;
short bubble[1000];
short data1[10];

void storepoints();
void printpoints();
void spawnpoints();
void mapseq();
void win();

bool keyPressed[K_COUNT];
bool dooropen=0;
// Game specific variables here
COORD charLocation;
COORD charLocation2;
 
// Initialize variables, allocate memory, load data from file, etc.
// This is called once before entering into your main loop
void init()
{
    // Set precision for floating point output
    elapsedTime = 0.0;
 
    charLocation.X = 24;
    charLocation.Y = 10;
    charLocation2.X = 24;
    charLocation2.Y = 10;
    // sets the width, height and the font name to use in the console
    console.setConsoleFont(10, 20, L"8514oem");
}
 
// Do your clean up of memory here
// This is called once just before the game exits
void shutdown()
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    console.clearBuffer();
}
/*
        This function checks if any key had been pressed since the last time we checked
        If a key is pressed, the value for that particular key will be true
       
        Add more keys to the enum in game.h if you need to detect more keys
        To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition"
        For Alphanumeric keys, the values are their ascii values (uppercase).
*/
void getInput()
{    
    keyPressed[K_UP] = isKeyPressed(VK_UP);
    keyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
    keyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
    keyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
    keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	keyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
    keyPressed[K_RETURN] = isKeyPressed(VK_RETURN);
} 
/*
        This is the update function
        double dt - This is the amount of time in seconds since the previous call was made
        Game logic should be done here.
        Such as collision checks, determining the position of your game characters, status updates, etc
        If there are any calls to write to the console here, then you are doing it wrong.
    If your game has multiple states, you should determine the current state, and call the relevant function here.
*/
void update(double dt)
{
    // get the delta time
	if(next!=0 && next!= 16 && next!=99)
	{
		elapsedTime += dt;
		ambience();
	}
	mapseq();
    deltaTime = dt;
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
    // sound can be played here too.
	
}
 
/*
    This is the render loop
    At this point, you should know exactly what to draw onto the screen.
    Just draw it!
    To get an idea of the values for colours, look at console.h and the URL listed there
*/


void moveCharacter()
{
	struct move			//stuct for the movement of character
	{
		short X;
		short Y;
	}character1,character2;
	//initilize value to xy for each character
	character1.X = charLocation.X;
    character1.Y = charLocation.Y-1;
    character2.X = charLocation2.X;
    character2.Y = charLocation2.Y-1;
    // Updating the location of the character based on the key press
    if (keyPressed[K_UP] && charLocation.Y > 0)
    {
		if(level[character1.Y-1][character1.X]=='#');
		else if((level[character1.Y-1][character1.X]=='$') &&(dooropen == 0));
		else
		{
            charLocation.Y--;
		}
    }
    else if (keyPressed[K_LEFT] && charLocation.X > 0)
    {
        if(level[character1.Y][character1.X-1]=='#');
		else if((level[character1.Y][character1.X-1]=='$') &&(dooropen == 0));
		else
		{
            charLocation.X--;
		}
    }
    else if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1)
    {
        if(level[character1.Y+1][character1.X]=='#');
		else if((level[character1.Y+1][character1.X]=='$') &&(dooropen == 0));
		else
		{
			charLocation.Y++;
		}

    }
    else if (keyPressed[K_RIGHT] && charLocation.X < console.getConsoleSize().X - 1)
    {
        if(level[character1.Y][character1.X+1]=='#');
		else if((level[character1.Y][character1.X+1]=='$') &&(dooropen == 0));
		else
		{
            charLocation.X++;
		}
    }
        //2nd character
    if (keyPressed[K_UP] && charLocation2.Y > 0)
	{
		if(level[character2.Y-1][character2.X]=='#');
		else if((level[character2.Y-1][character2.X]=='$') &&(dooropen == 0));
		else
		{
            charLocation2.Y--;
		}
	}
	else if (keyPressed[K_LEFT] && charLocation2.X < console.getConsoleSize().X - 1)
	{
        if(level[character2.Y][character2.X+1]=='#');
		else if((level[character2.Y][character2.X+1]=='$') &&(dooropen == 0));
		else
		{
            charLocation2.X++;
		}
	}
	else if (keyPressed[K_DOWN] && charLocation2.Y < console.getConsoleSize().Y - 1)
	{
        if(level[character2.Y+1][character2.X]=='#');
		else if((level[character2.Y+1][character2.X]=='$') &&(dooropen == 0));
		else
		{
            charLocation2.Y++;
		}
	}
	else if (keyPressed[K_RIGHT] && charLocation2.X > 0)
	{
        if(level[character2.Y][character2.X-1]=='#');
		else if((level[character2.Y][character2.X-1]=='$') &&(dooropen == 0));
		else
		{
            charLocation2.X--;
		}
	}
	if(level[character2.Y][character2.X]=='%' || level[character1.Y][character1.X]=='%' )
	{
		dooropen = true;
	}
    if (level[character2.Y][character2.X]=='@' && level[character1.Y][character1.X]=='@' || (keyPressed[K_LEFT] && keyPressed[K_RETURN]))
    {
		dooropen = false;
		if(next==5)
		{
			next=101;
			charLocation.X = 7; charLocation.Y = 3; charLocation2.X = 67; charLocation2.Y = 22;
		}
		else if (next==10)
		{
			next=102;
			charLocation.X = 2; charLocation.Y =  3; charLocation2.X = 67; charLocation2.Y = 3;
		}
		else if (next==15)
		{
			next=103;
		}
		else if (next<16)
		{
			Beep(1440,30);
			next++;
		}
		spawnpoints();
    }
    else if ((keyPressed[K_RETURN]) && (next == 0) && (charLocation2.X == 24) && (charLocation2.Y == 10))
    {
        Beep(1440, 30);
        next++;
        charLocation.X = 2;charLocation.Y = 2;charLocation2.X = 68;charLocation2.Y = 2;
    }
	else if ((keyPressed[K_RETURN]) && (next == 0) && (charLocation2.X == 24) && (charLocation2.Y == 11))
    {
		Beep(1440,30);
        next=99;		
        charLocation.X = 2;charLocation.Y = 23;charLocation2.X = 68;charLocation2.Y = 23;		
    }
	else if ((keyPressed[K_RETURN]) && (next == 0) && (charLocation2.X == 24) && (charLocation2.Y == 12))
    {
		g_quitGame = true;
    }
	else if ((keyPressed[K_SPACE]) && ((next == 100) || (next==16)))
	{
		Beep(1440,30);
		next = 0;
		elapsedTime=0;
		stopsound();
		charLocation.X = 24;charLocation.Y = 10;charLocation2.X = 24;charLocation2.Y = 10;
	}
	else if ((keyPressed[K_SPACE]) && (next == 99))		
	{
		Beep(1440,30);
		next = 0;		
	    charLocation.X = 24;charLocation.Y = 10;charLocation2.X = 24;charLocation2.Y = 10;		
	}
}
void processUserInput()
{
    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
    {
	    g_quitGame = true;
    }
}
 
void clearScreen()
{
    // Clears the buffer with this colour attribute
    console.clearBuffer(0x0F);
}

void render()
{
    clearScreen();      // clears the current screen and draw from scratch
    renderMap();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
    renderFramerate();  // renders debug information, frame rate, elapsed time, etc
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
} 
void renderMap()
{
    // Set up sample colours, and output shadings
    const WORD colors[] = {
        0x07, 0x0F, 0x08, 0x02, 0x03, 0x04,
        0x05, 0x07, 0x0F, 0x08, 0x02, 0x03,
		0x03, 0x04, 0x05,
		};
        for (unsigned int i=0;i<24;++i)
        {
			for (unsigned int c=0;c<71;++c)
			{
				if(level[i][c] == '#')
				{
					unsigned char a = 219;
					if(next>0 && next<99 && next!=16)
					{
					console.writeToBuffer(c,i+1,a,colors[next-1]);
					}
					else
					{
						console.writeToBuffer(c,i+1,a,0x00);
					}
				}
				else
				{                           
					console.writeToBuffer(c,i+1,level[i][c]);
				}
				if(level[i][c] == '$')
				{
					if(dooropen==0)
					{
						level[i][c]= 209;
					}
					else
					{
						level[i][c] = 0;
					}
					console.writeToBuffer(c,i+1,level[i][c]);
				}
				if(level[i][c]=='%')
				{
					if(dooropen==0)
					{
						level[i][c]='%';
					}
					else
					{
						level[i][c]=0;
					}
					console.writeToBuffer(c,i+1,level[i][c]);
				}
			}
		}
        if(next>0 && next<16)
        {
            for (unsigned int i=0;i<23;++i)
            {
                for(unsigned int c=0;c<10;++c)
                {
                    if(side[i][c] == '#')
					{
						unsigned char a = 219;
                        console.writeToBuffer(c+70,i+1,a,0x00);//side menu
                    }
                    else
                    {
                        console.writeToBuffer(c+70,i+1,side[i][c]);
                    }
                }
            }
        }

	if(next == 16)
	{
		printpoints();
	}
}
void renderCharacter()
{
    // Draw the location of the character
	console.writeToBuffer(charLocation2, (char)153, 0x0A);
    console.writeToBuffer(charLocation, (char)153, 0x0C);
}
void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << 1.0 / deltaTime << "FPS";
    c.X = console.getConsoleSize().X - 8;
    c.Y = 0;
    console.writeToBuffer(c, ss.str());

	//displays the current level
	if (next>0 && next<16)
	{
		ss.str("");
		ss<<next;
		c.X=71;
		c.Y=12;
		console.writeToBuffer(c,ss.str());
		// displays the elapsed time

		ss.str("");
		if (1000-elapsedTime>0)
		{
		ss << 1000 - elapsedTime << "s";
		}
		else
		{
			ss << "0s";
			elapsedTime=1000;
			next=100;
		}
		c.X = 71;
		c.Y = 10;
		console.writeToBuffer(c, ss.str(), 0x0B);
	}
}
void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    console.flushBufferToConsole();
}

void storepoints()
{
	int c=0;
	playwin();
	int a =static_cast<int>(elapsedTime);
	std::fstream fs;
	fs.open ("scoreboard.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fs <<1000-a<<std::endl;
	fs.close();
	std::ifstream inData;
	inData.open ("scoreboard.txt");

	short var1 = 0;
	while (!inData.eof())
	{
		inData >>bubble[var1];
		var1++;
	}
	short temp;
	for(short a = var1-1,b = var1;a>=0;a--,b--)
	{
			if(bubble[a]<bubble[b])
			{
				temp=bubble[a];
				bubble[a]=bubble[b];
				bubble[b]=temp; 
			}
	}
	fs.open("scoreboard.txt", std::ofstream::out | std::ofstream::trunc);
	fs.close();
	fs.open ("scoreboard.txt",std::fstream::in | std::fstream::out);
	for(short a = 0;a<10;a++)
	{
		data1[a]=bubble[a];
		fs <<data1[a]<<std::endl;
	}
	fs.close();
}	
void printpoints()
{
	std::ostringstream ss;
	for(int a =0 ;a<10;a++)
	{
		if(data1[a] == 0)
		{
			console.writeToBuffer(4,4+a,"----");
		}
		// convert number (data[a]) into string
		else
		{
			ss.str("");
			ss << data1[a];
			// use void Console::writeToBuffer(SHORT x, SHORT y, std::string& s, WORD attribute)
			console.writeToBuffer(4,4+a,ss.str());
		}
	}
	ss.str("");
	ss<<1000-(int)elapsedTime;
	console.writeToBuffer(37,2,ss.str());
}

void win()
{
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
        ,       {" ##              **  **          ***       ***      ****            ##"}
        ,       {" ##              **  **          ***       ***      ****            ##"}
		,       {" #####################################################################"}};
 
        for(int i=0;i<24;++i)
        {
            for(int c=0;c<71;++c)
            {
                level[i][c] = win[i][c];
            }
        }
}
void spawnpoints()
{
	switch(next)
	{
		case 2: charLocation.X = 2; charLocation.Y = 23; charLocation2.X = 68; charLocation2.Y = 23;break;
		case 3: charLocation.X = 31; charLocation.Y = 4; charLocation2.X = 40; charLocation2.Y = 3;break;
		case 4: charLocation.X = 2; charLocation.Y = 3; charLocation2.X = 66; charLocation2.Y = 2;break;
		case 5: charLocation.X = 4; charLocation.Y = 5; charLocation2.X = 63; charLocation2.Y = 22;break;
		case 6: charLocation.X = 7; charLocation.Y = 3; charLocation2.X = 67; charLocation2.Y = 22;break;
		case 7: charLocation.X = 17; charLocation.Y = 12; charLocation2.X = 53; charLocation2.Y = 13;break;
		case 8: charLocation.X = 3; charLocation.Y = 21; charLocation2.X = 67; charLocation2.Y = 4; break;
		case 9: charLocation.X = 2; charLocation.Y = 14; charLocation2.X = 68; charLocation2.Y = 13; break;
		case 10: charLocation.X = 3; charLocation.Y = 4; charLocation2.X = 37; charLocation2.Y = 4; break;
		case 11: charLocation.X = 2; charLocation.Y =  3; charLocation2.X = 67; charLocation2.Y = 3; break;
		case 12: charLocation.X = 4; charLocation.Y = 12; charLocation2.X = 67; charLocation2.Y = 21; break;
		case 13: charLocation.X = 63; charLocation.Y = 19; charLocation2.X = 19; charLocation2.Y = 19; break;
		case 14: charLocation.X = 31; charLocation.Y = 17; charLocation2.X = 39; charLocation2.Y = 17; break;
		case 15: charLocation.X = 34; charLocation.Y = 21; charLocation2.X = 36; charLocation2.Y = 21; break;
		case 16: charLocation.X = 2;charLocation.Y = 2;charLocation2.X = 68;charLocation2.Y = 2; break;
		case 100: charLocation.X = 2;charLocation.Y = 2;charLocation2.X = 68;charLocation2.Y = 2;break;
	}
}
void mapseq()
{
	switch(next)
	{
		case 0:menu();sidemenu();break;
		case 1:level1();break;
		case 2:level2();break;
		case 3:level3();break;
		case 4:level4();break;
		case 5:level5();break;
		case 101:levelskip();break;
		case 6:level6();break;
		case 7:level7();break;
		case 8:level8();break;
		case 9:level9();break;
		case 10:level10();break;
		case 102:levelskip();break;
		case 11:level11();break;
		case 12:level12();break;
		case 13:level13();break;
		case 14:level14();break;
		case 15:level15();break;
		case 103:levelskip();break;
		case 16:win();break;
		case 99:help();break;
		case 100:lose();elapsedTime=0;break;
	}
}
