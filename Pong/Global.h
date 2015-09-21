#pragma once
#include <iostream>
#include <ctime>
#include "sfwdraw.h"
using namespace sfw;
using namespace std;

struct Player
{
	float xPOS;
	float yPOS;
	const float WIDTH;
	const float HEIGHT;
};

extern Player PLAYER1; //Note: You'll have to manually change numbers for hit box resizes!
extern Player PLAYER2;
extern Player AI;

extern int checkWallCollision();

extern float curCX;
extern float curCY;
extern float lstCX;
extern float lstCY;
extern float sMod;
extern float cSPEED_Y;
extern float setCSpeedY[3];
extern float setPSpeed[3];
extern float xSpace(float num, float den);
extern float ySpace(float num, float den);
const float pSPEED = 500;
const float cSPEED_X = 175;
const float R = 5;
const float SCREEN_X = 500;
const float SCREEN_Y = 500;

extern bool checkPlayerCollision(Player p);

extern void movePlayers();
extern void moveAI();
extern void moveBall(bool force, bool tennis);
extern void drawPlayer(Player p);
extern void drawWalls(bool tennis);
extern void menuMain(int choice);
extern void menuPlay(int choice);
extern void menuOpt(int choice);
extern void menuLoss(int choice);
extern void menuBallOp(int choice);
extern void menuPlayOp(int choice);
