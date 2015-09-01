// This is the main file for the game logic and function
// Team members: Teck Ling, Junxiang, Tristan, Qingping.
// SP1 Framework.
#include "game.h"
#include "map.h"
#include "Framework\console.h"
#include "sound.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

// Console object
Console console(79, 25, "Mirror Image");
 
// extern from map.cpp
extern unsigned char level[26][71];
extern char side[25][10];
extern short next;
extern char checker;

//doubles for time recording purposes.
double elapsedTime;
double deltaTime;

short data;
short bubble[12];//array for scoring
short data1[10];
short defaulttime = 800;//specifies time given for the game.
//shorts for RNG monster
short arandom, brandom;
short spawnX, spawnY;
bool dooropen=0;
bool contact = 0;
bool contact2 = 0;
bool warpprint = 0;
bool swapprint =0;
bool nextlevel = 0;
bool ismute=false;

short levelcount = 0;// for the level 0, 5, 10 and 15 to be identified

int step = 0; // count the number of steps
short unsigned unsignedtime;


bool keyPressed[K_COUNT];

move character1, character2;
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
    console.setConsoleFont(10, 18, L"Terminal");
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
	if(next!=0 && next!= 16 && next!=99 && next != 101)
	{
		elapsedTime += dt;//if levels 1 to 15 are running, the timer moves.
	}
	if(ismute==false)
	{
		ambience();//if the game is not muted, play sound. DUH.
	}
	else
	{
		stopsound();//if the game IS muted, don't play sound!
	}
	mapseq(&elapsedTime);//follows the order of mapping.
    deltaTime = dt;//counts time for recording FPS
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter(&character1,&character2,&nextlevel,&levelcount);
		// moves the character, collision detection, physics, etc
    // sound can be played here too.
	
}
 
/*
    This is the render loop
    At this point, you should know exactly what to draw onto the screen.
    Just draw it!
    To get an idea of the values for colours, look at console.h and the URL listed there
*/



void processUserInput()
{
    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
    {
	    g_quitGame = true;
    }//quit when esc
	else if ((keyPressed[K_RETURN]) && (next == 0) && (charLocation2.X == 24) && (charLocation2.Y == 10))
	{
		Beep(1440, 30);
		next=101;
		charLocation.X = 2; charLocation.Y = 2; charLocation2.X = 68; charLocation2.Y = 2;
	}//startgame
	else if ((keyPressed[K_RETURN]) && (next == 0) && (charLocation2.X == 24) && (charLocation2.Y == 11))
	{
		Beep(1440, 30);
		next = 99;
		charLocation.X = 2; charLocation.Y = 23; charLocation2.X = 68; charLocation2.Y = 23;
	}//instructions
	else if ((keyPressed[K_RETURN]) && (next == 0) && (charLocation2.X == 24) && (charLocation2.Y == 12))
	{
		if(ismute==false)
		{
			ismute=true;
		}
		else
		{
			ismute=false;
		}
	}//mute
	else if ((keyPressed[K_RETURN]) && (next == 0) && (charLocation2.X == 24) && (charLocation2.Y == 13))
	{
		g_quitGame = true;
	}//quit
	else if ((keyPressed[K_SPACE]) && ((next == 100) || (next == 16)))
	{
		Beep(1440, 30);
		next = 0;
		step = 0;
		levelcount = 0;
		elapsedTime = 0;
		stopsound();
		charLocation.X = 24; charLocation.Y = 10; charLocation2.X = 24; charLocation2.Y = 10;
	}//return to main menu
	else if ((keyPressed[K_SPACE]) && (next == 99))
	{
		Beep(1440, 30);
		next = 0;
		step=0;
		charLocation.X = 24; charLocation.Y = 10; charLocation2.X = 24; charLocation2.Y = 10;
	}//return to main menu AFTER losing

	if ((keyPressed[K_SPACE]) && (next == 101))
	{
		switch(levelcount)
		{
			case 5:next=6;charLocation.X = 7; charLocation.Y = 3; charLocation2.X = 67; charLocation2.Y = 22;break;
			case 10:next=11;charLocation.X = 2; charLocation.Y =  3; charLocation2.X = 67; charLocation2.Y = 3;break;
		}
	}//resume gameplay at checkpoint

	activewarp(&character1,&contact,&charLocation);
	activeswap(&charLocation2 ,&charLocation ,&contact2);
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
	unsigned char a;
	if ((unsignedtime % 100 == 0 || nextlevel == true) && (next>0 &&next<15)) //spwan traps and AI when next level is started
	{
		warpspawn(&elapsedTime,&charLocation,&contact);
		swapspawn(&elapsedTime,&charLocation2 ,&contact2);
		nextlevel = false;
	}
	for (unsigned int i = 0; i<24; ++i)//for the y axis
	{
		for (unsigned int c = 0; c<71; ++c)//for the x axis
		{
			if(next>0 && next<16 && next!=101)
			{
				if (i == brandom && c == arandom && contact == true)
				{
					level[i][c] = 142;
				}
				if (i == spawnY && c==spawnX && contact2 == true)
				{
					level[i][c]=154;
				}
			}//spawns monsters
			if (level[i][c] == '#')
			{
				a = 219;
				if (next>0 && next<99 && next != 16)
				{
					console.writeToBuffer(c, i + 1, a, colors[next - 1]);
				}
				else
				{
					console.writeToBuffer(c, i + 1, a, 0x00);
				}
			}//paint the walls in a certain colour, anything else black
			else
			{
				console.writeToBuffer(c, i + 1, level[i][c]);
			}
			if (level[i][c] == '$')
			{
				if (dooropen == 0)
				{
					level[i][c] = 176;
				}
				else
				{
					level[i][c] = 0;
				}
				console.writeToBuffer(c, i + 1, level[i][c]);
			}//print doors
			if (level[i][c] == '%')
			{
				if (dooropen == 0)
				{
					level[i][c] = 233;
				}
				else
				{
					level[i][c] = 0;
				}
				console.writeToBuffer(c, i + 1, level[i][c]);
			}//print the key onto the map
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
			//run the side-menu for all the playable stages
        }
	if(next == 101)// prints the stats for steps made and time taken
	{
		std::ostringstream ss;
		std::ostringstream walked;
		walked<< step<<" steps";
		ss<< elapsedTime<<" Seconds";
		console.writeToBuffer(40,6,walked.str());
		console.writeToBuffer(40,7,ss.str());
	}

	if(next == 16)
	{
		std::ostringstream walked;
		walked<<"steps taken :"<< step<<" steps";
		console.writeToBuffer(41,2,walked.str());
		printpoints();
	}//steps
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
    c.X = console.getConsoleSize().X - 9;
    c.Y = 0;
    console.writeToBuffer(c, ss.str());
	unsignedtime = static_cast<unsigned short>(elapsedTime * 10);

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
		if (defaulttime-elapsedTime>0)
		{
		ss << defaulttime - elapsedTime << "s";
		}
		else
		{
			ss << "0s";
			elapsedTime=defaulttime;
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
	fs <<defaulttime-a<<std::endl;
	fs.close();
	std::ifstream inData;
	inData.open ("scoreboard.txt");//open file

	short var1 = 0;
	while (!inData.eof())
	{
		inData >>bubble[var1];//read line by line
		var1++;
	}
	short temp;
	for(short a = var1-1,b = var1;a>=0;a--,b--)
	{
			if(bubble[a]<bubble[b])
			{
				temp=bubble[a];
				bubble[a]=bubble[b];
				bubble[b]=temp; //replaces top score with better score.
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