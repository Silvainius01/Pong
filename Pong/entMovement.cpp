/* Determines entity movement */

#include "Global.h"

int runCount = 0;

float cSPEED_Y;

bool dirCX; //True: left (-=), false: right (+=)
bool dirCY; //True: up (-=), false: down (+=)

void movePlayers()
{
	if (getKey('w'))
	{
		PLAYER1.yPOS -= pSPEED * getDeltaTime();
		if (PLAYER1.yPOS < 1) { PLAYER1.yPOS = 1; }
	}
	else if (getKey('s'))
	{
		PLAYER1.yPOS += pSPEED * getDeltaTime();
		if (PLAYER1.yPOS > 459){ PLAYER1.yPOS = 459; }
	}

	if (getKey('p'))
	{
		PLAYER2.yPOS -= pSPEED * getDeltaTime();
		if (PLAYER2.yPOS < 1){ PLAYER2.yPOS = 1; }
	}
	else if (getKey(';'))
	{
		PLAYER2.yPOS += pSPEED * getDeltaTime();
		if (PLAYER2.yPOS > 459){PLAYER2.yPOS = 459; }
	}
}

void moveBall(bool force, bool tennis)
{
	bool changeDir = false;

	//This determines the direction the ball travels
	if (!force)
	{
		if (checkPlayerCollision(PLAYER1))
		{
			dirCX = false;

			//Section causes first deflect to be at angle
			if (curCY == 250)
			{
				srand(time(NULL));
				int r = std::rand() % 2;
				cSPEED_Y = (setCSpeedY[0] * 100) + (setCSpeedY[1] * 10) + setCSpeedY[2];

				if (r)
				{
					dirCY = true;
				}
				else
				{
					dirCY = false;
				}
			}
		}
		else if (checkPlayerCollision(PLAYER2) || checkPlayerCollision(AI))
		{
			dirCX = true;
		}

		if (checkWallCollision() == 0)
		{
			dirCY = true;
		}
		else if (checkWallCollision() == 1)
		{
			dirCY = false;
		}
		else if (checkWallCollision() == 2 && tennis == true)
		{
			dirCX = true;
			sMod += 5;
		}
	}
	else
	{
		dirCX = true;
	}

	lstCY = curCY;
	lstCX = curCX;

	if (dirCX) { curCX -= (cSPEED_X + sMod) * getDeltaTime(); } //Left
	else       { curCX += (cSPEED_X + sMod) * getDeltaTime(); }//Right
	if (dirCY) { curCY -= cSPEED_Y * getDeltaTime(); } //Up
	else       { curCY += cSPEED_Y * getDeltaTime(); } //Down

	cout << "The Y's: " << lstCY << "; " << curCY << endl;
	cout << "The X's: " << lstCX << "; " << curCX << endl;
}