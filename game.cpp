// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Console object
Console console(80, 40, "SP1 Framework");

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
char level[26][71];
int next=1;
void level1();
void level2();


// Game specific variables here
COORD charLocation;
COORD charLocation2;
COORD mapCreate;


// Initialize variables, allocate memory, load data from file, etc. 
// This is called once before entering into your main loop
void init()
{
    // Set precision for floating point output
    elapsedTime = 0.0;

    charLocation.X = 2;
    charLocation.Y = 2;
	charLocation2.X = 68;
	charLocation2.Y = 2;
    // sets the width, height and the font name to use in the console
    console.setConsoleFont(0, 28, L"Consolas");
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
    elapsedTime += dt;
    deltaTime = dt;
	switch(next)
	{
	case 1:level1();break;
	case 2:level2();break;
	}
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
void render()
{
    clearScreen();      // clears the current screen and draw from scratch 
    renderMap();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
    renderFramerate();  // renders debug information, frame rate, elapsed time, etc
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void moveCharacter()
{
	int X = charLocation.X;
	int Y = charLocation.Y-1;
	int a = charLocation2.X;
	int b = charLocation2.Y-1;
    // Updating the location of the character based on the key press
    if (keyPressed[K_UP] && charLocation.Y > 0)
    {
		if(level[Y-1][X]!='#')
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
    }
    else if (keyPressed[K_LEFT] && charLocation.X > 0)
    {
		if(level[Y][X-1]!='#')
		{
			Beep(1440, 30);
			charLocation.X--;
		}
    }
    else if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1)
    {
		if(level[Y+1][X]!='#')
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
    }
    else if (keyPressed[K_RIGHT] && charLocation.X < console.getConsoleSize().X - 1)
    {
		if(level[Y][X+1]!='#')
		{
			Beep(1440, 30);
			charLocation.X++;
		}
    }
	//2nd character
	 if (keyPressed[K_UP] && charLocation2.Y > 0)
    {
		if(level[b-1][a]!='#')
		{
			Beep(1440, 30);
			charLocation2.Y--;
		}
    }
    else if (keyPressed[K_LEFT] && charLocation2.X < console.getConsoleSize().X - 1)
    {
		if(level[b][a+1]!='#')
		{
			Beep(1440, 30);
			charLocation2.X++;
		}
    }
    else if (keyPressed[K_DOWN] && charLocation2.Y < console.getConsoleSize().Y - 1)
    {
		if(level[b+1][a]!='#')
		{
			Beep(1440, 30);
			charLocation2.Y++;
		}
    }
    else if (keyPressed[K_RIGHT] && charLocation2.X > 0)
    {
		if(level[b][a-1]!='#')
		{
			Beep(1440, 30);
			charLocation2.X--;
		}
    }
	if (level[b][a]=='@' && level[Y][X]=='@')
	{
		next++;
		switch(next)
		{
			case 2: charLocation.X = 2; charLocation.Y = 23; charLocation2.X = 68; charLocation2.Y = 23;break;
		}
	}
}
void processUserInput()
{
    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
        g_quitGame = true;
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    console.clearBuffer(0x0F);
}
void renderMap()
{
    // Set up sample colours, and output shadings
    const WORD colors[] = {
        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
    };
	for (unsigned int i=0;i<24;++i)
	{
		for (unsigned int c=0;c<71;++c)
		{
			console.writeToBuffer(c,i+1,level[i][c]);
		}
	}
}

void renderCharacter()
{
    // Draw the location of the character
    console.writeToBuffer(charLocation, (char)153, 0x0C);
	console.writeToBuffer(charLocation2, (char)153, 0x0A);
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

    // displays the elapsed time
    ss.str("");
    ss << elapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
    console.writeToBuffer(c, ss.str(), 0x0B);
}
void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    console.flushBufferToConsole();
}

void level1()
{
	char level1[24][71]={
		{" #####################################################################"}
	,	{" #                        #        @        #                        #"}
	,	{" #                        #                 #                        #"}
	,	{" #                        #                 #                        #"}
	,	{" #                        #                 #                        #"}
	,	{" #                        #                 #                        #"}
	,	{" #                        #                 #                        #"}
	,	{" #                        #                 #                        #"}
	,	{" #                        #                 #                        #"}
	,	{" #                        #                 #                        #"}
	,	{" #           ##############                 ##############           #"}
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
	,	{" #####################################################################"}};

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
	char level2[24][71]={
		{" #####################################################################"}
	,	{" #                                                                   #"}
	,	{" #                                                                   #"}
	,	{" #                                                                   #"}
	,	{" #                                                                   #"}
	,	{" #                                                                   #"}
	,	{" #                                                                   #"}
	,	{" #                                                                   #"}
	,	{" #                                                                   #"}
	,	{" #                                                                   #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #         ###################           ##################          #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #####################       #           #         ###################"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #     @     #                           #"}
	,	{" #####################################################################"}};

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
	char level3[26][71]={
		{" #####################################################################"}
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
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #         ###################           ##################          #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #####################       #           #         ###################"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #           #                           #"}
	,	{" #                           #     @     #                           #"}
	,	{" #####################################################################"}};

	for(int i=0;i<26;++i)
	{
		for(int c=0;c<71;++c)
		{
			level[i][c] = level3[i][c];
		}
	}
}
