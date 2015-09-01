//DO NOT MODIFY

#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"

extern StopWatch g_timer;
extern bool g_quitGame;

enum Keys
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
	K_RETURN,
	K_SPACE,
    K_COUNT
};
struct move			//stuct for the movement of character
{
	short X;
	short Y;
};

void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory

void moveCharacter(int *step ,move *character1,move*character2,bool *nextlevel,short*next,short*levelcount);
// moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderMap();           // renders the map to the buffer first
void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game

void win();
void mapseq(double *elapsedTime);
void spawnpoints(COORD *charLocation , COORD *charLocation2);

//run functions
void storepoints();
void printpoints();


void warpspawn(double *elapsedTime , COORD *charLocation , bool *contact);
void activewarp(move * character1 , bool * contact, COORD *charLocation);
void swapspawn(double *elapsedTime , COORD *charLocation2 , bool *contact2);
void activeswap(COORD * charLocation2 ,COORD *charLocation, bool * contact2);
#endif // _GAME_H
