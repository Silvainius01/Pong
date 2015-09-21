/* Defines and "spawns" entities */

#include "Global.h"

Player PLAYER1{ 1, 230, 5, 40 }; //Note: You'll have to manually change numbers for hit box resizes!
Player PLAYER2{ 494, 230, 5, 40 };
Player AI{ 494, 230, 5, 40 };

void drawPlayer(Player p)
{
	drawLine(p.xPOS, p.yPOS, p.xPOS + p.WIDTH, p.yPOS); //Top line
	drawLine(p.xPOS, p.yPOS, p.xPOS, p.yPOS + p.HEIGHT); //Left line
	drawLine(p.xPOS + p.WIDTH, p.yPOS, p.xPOS + p.WIDTH, p.yPOS + p.HEIGHT); //Right line
	drawLine(p.xPOS, p.yPOS + p.HEIGHT, p.xPOS + p.WIDTH + 1, p.yPOS + p.HEIGHT);//Bottom line
}

void drawWalls(bool tennis)
{
	drawLine(0, 1, 500, 1);
	drawLine(0, 499, 500, 499);

	if (tennis)
	{
		drawLine(499, 0, 499, 500);
	}
}