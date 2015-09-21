/* Detects entity collison */

#include "Global.h"

float curCX;
float curCY;
float lstCX;
float lstCY;
float sMod = 0;

bool checkPlayerCollision(Player p)
{
	//Yea, yea.... ternary operaters. Sue me.
	if (p.xPOS == PLAYER1.xPOS)
	{
		if (curCX - R <= p.xPOS + p.WIDTH)
		{
			if (curCY >= p.yPOS && curCY <= p.yPOS + p.HEIGHT)
			{
				if (curCY <= p.yPOS + (p.HEIGHT / 3)) //Upper third
				{
					sMod += 5;
				}
				else if (curCY >= p.yPOS + ((p.HEIGHT / 3) * 2)) //Lower third
				{
					sMod += 5;
				}
				else
				{
					sMod -= 10;
				}

				return true;
			}
		}
	}

	if (p.xPOS == PLAYER2.xPOS)
	{
		if (curCX + R >= p.xPOS)
		{
			if (curCY >= p.yPOS && curCY <= p.yPOS + p.HEIGHT)
			{
				if (curCY <= p.yPOS + (p.HEIGHT / 3)) //Upper third
				{
					sMod += 5;
				}
				else if (curCY >= p.yPOS + ((p.HEIGHT / 3) * 2)) //Lower third
				{
					sMod += 5;
				}
				else
				{
					sMod -= 10;
				}

				return true;
			}
		}
	}

	return false;
}

int checkWallCollision()
{
	if (curCY + R >= 499)
	{
		return 0;
	}
	else if (curCY - R <= 0)
	{
		return 1;
	}
	else if (curCX + R >= 499)
	{
		return 2;
	}
	else
	{
		return 100;
	}
}