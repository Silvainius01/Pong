/* Runs game */

#include "Global.h"

/*************************************************************************************\
 * Even though this is afully functional game, I feel like I'm incompetent  at this  *
 * due to the shear number of if steaments and ternary operators I ended up using.   *
 * While yes, I do suppose I made quite few functions to do stuff, I've also been    *
 * using since pracically the day I started programming, and thus feel just as easy  *
 * and cheap as if statements. I don't use any <i>NECCESARY</i> complex systems,     *
 * as even the math functions I use are fairly simple concpets learned by everyone   *
 * freshman year of high-school at the latest. While I do use a fancy struct, and    *
 * have a reasonably placed switch statement, it all just feels and reads like any   *
 * scrub can come along and do this exact same thing with little or no issues.       *
\*************************************************************************************/


void main()
{
	int choiceMM = 0, choicePM = 0, choiceOM = 0, choiceBM = 0, choicePPM = 0, choiceLoss = 0;
	float tempSpeed;
	bool first = true;
	bool mm = true;
	bool dPress = false, aPress = false, wPress = false, sPress = false, spacePress = false;
	bool playTennis = false, playSingle = false, playMulti = false;
	bool ballOffScreen = false;
	bool ballOp = false, playOp = false;

	curCX = 250;
	curCY = 250;

	/*cout << "Please choose game mode:\n\n" 
		 << "Tennis: 1\n" 
		 << "Single Player: 2\n" 
		 << "Multiplayer: 3\n";
	cin >> choice;*/

	initContext(SCREEN_X, SCREEN_Y, "Pong");

	while (stepContext())
	{
		// The main Menu
		if(mm)
		{
			cout << "Main; ";

			//This if chunk makes one key = one press on MM
			if (getKey('D') && !dPress)
			{
				choiceMM++;
				dPress = true;
			}
			else if (getKey('A') && !aPress)
			{
				choiceMM--;
				aPress = true;
			}

			if (choiceMM <= -1) { choiceMM = 2; }
			else if (choiceMM >= 3) { choiceMM = 0; }

			if (getKey(' ') && !spacePress) 
			{ 
				mm = false;
				spacePress = true;
			}

			cout << choiceMM << "(1); ";

			menuMain(choiceMM);
		}
		//All other menus
		else if (!mm && !playTennis && !playSingle && !playMulti)
		{
			cout << "Other menu; ";
			//Play menu
			if (choiceMM == 0)
			{
				cout << "Play Menu; ";
				cout << choicePM << "(1); ";

				if (getKey('D') && !dPress)
				{
					switch (choicePM)
					{
					case 0:
						choicePM = 1;
						break;
					case 1:
						choicePM = 0;
						break;
					case 2:
						choicePM = 3;
						break;
					case 3:
						choicePM = 2;
						break;
					}

					dPress = true;
				}
				else if (getKey('A') && !aPress)
				{
					switch (choicePM)
					{
					case 0:
						choicePM = 1;
						break;
					case 1:
						choicePM = 0;
						break;
					case 2:
						choicePM = 3;
						break;
					case 3:
						choicePM = 2;
						break;
					}

					aPress = true;
				}
				else if (getKey('W') && !wPress)
				{  
					switch (choicePM)
					{
					case 0:
						choicePM = 2;
						break;
					case 1:
						choicePM = 3;
						break;
					case 2:
						choicePM = 0;
						break;
					case 3:
						choicePM = 1;
						break;
					}

					wPress = true;
				}
				else if (getKey('S') && !sPress)
				{
					switch (choicePM)
					{
					case 0:
						choicePM = 2;
						break;
					case 1:
						choicePM = 3;
						break;
					case 2:
						choicePM = 0;
						break;
					case 3:
						choicePM = 1;
						break;
					}

					sPress = true;
				}

				if (choicePM == -1) { choicePM = 3; }
				else if (choicePM == 4) { choicePM = 0; }

				if (getKey(' ') && !spacePress)
				{
					if (choicePM == 0)
					{
						playSingle = true;
					}
					else if (choicePM == 1)
					{
						playMulti = true;
					}
					else if (choicePM == 2)
					{
						choicePM = 0;
						choiceMM = 0;
						mm = true;
					}
					else
					{
						playTennis = true;
					}

					spacePress = true;
				}

				menuPlay(choicePM);
			}
			//Options menu
			else if (choiceMM == 1)
			{
				cout << "Op Menu; ";
				
				if (getKey('W') && !wPress)
				{
					choiceOM--;
					wPress = true;
				}
				else if (getKey('S') && !sPress)
				{
					choiceOM++;
					sPress = true;
				}

				if (choiceOM == -1) { choiceOM = 2; }
				else if (choiceOM == 3) { choiceOM = 0; }

				if (ballOp)
				{
					cout << "Ball menu; ";

					if (getKey('A')) { choiceBM--; }
					else if (getKey('D')) { choiceBM++; }
					if (choiceBM < 0) { choiceBM = 0; }
					else if(choiceBM > 1) {choiceBM = 1; }

					menuBallOp(choiceBM);

					if (getKey(' ') && !spacePress)
					{
						if (!choiceBM)
						{
							ballOp = false;
							menuBallOp(3);
						}
						else
						{
							menuBallOp(3);
						}

						spacePress = true;
					}

					cout << choiceBM << "(4); ";
				}
				else if (playOp)
				{
					cout << "Play  mmenu; ";

					if (getKey('A')) { choicePPM--; }
					else if (getKey('D')) { choicePPM++; }
					if (choicePPM < 0) { choicePPM = 0; }
					else if (choicePPM > 1) { choicePPM = 1; }

					menuBallOp(choicePPM);

					if (getKey(' ') && !spacePress)
					{
						if (!choicePPM)
						{
							playOp = false;
							menuPlayOp(3);
						}
						else
						{
							menuPlayOp(3);
						}

						spacePress = true;
					}

					cout << choicePPM << "(4); ";
				}
				else if(getKey(' ') && !spacePress)
				{
					switch (choiceOM)
					{
					case 0:
						ballOp = true;
						break;
					case 1:
						playOp = true;
						break;
					case 2:
						choiceOM = 0;
						choiceMM = 0;
						mm = true;
						break;
					}

					spacePress = true;
				}
				else
				{
					menuOpt(choiceOM);
				}

				cout << choiceOM << "(1); ";
			}
			else if (choiceMM == 2) { termContext(); }
		}
		else if (playTennis)
		{
			if (first)
			{
				moveBall(true, true);
				first = false;
			}

			if (!ballOffScreen)
			{
				movePlayers();
				moveBall(false, true);
			}
			else
			{
				if (getKey('W') && !wPress) { choiceLoss--, wPress = true; }
				else if (getKey('S') && !sPress) { choiceLoss++, sPress = true;  }
				if (choiceLoss < 0) { choiceLoss = 2; }
				else if (choiceLoss > 2) { choiceLoss = 0; }

				menuLoss(choiceLoss);

				if (getKey(' ') && !spacePress)
				{
					switch (choiceLoss)
					{
					case 0:
						curCX = xSpace(1, 2);
						curCY = ySpace(1, 2);
						first = true;
						cSPEED_Y = 0;
						ballOffScreen = false;
						break;
					case 1:
						choicePM = 0;
						choiceMM = 0;
						choiceLoss = 0;
						mm = true;
						playTennis = false;
						curCX = xSpace(1, 2);
						curCY = ySpace(1, 2);
						first = true;
						cSPEED_Y = 0;
						ballOffScreen = false;
						break;
					case 2:
						termContext();
						break;
					}
				}

				spacePress = true;
			}

			cout << choiceLoss << "(4); ";

			drawPlayer(PLAYER1);
			drawCircle(curCX, curCY, R);
			drawWalls(true);

			if (curCX > SCREEN_X || curCX < 0)
			{
				ballOffScreen = true;
			}
		}
		else if (playSingle)
		{
			if (first)
			{
				moveBall(true, false);
				first = false;
			}

			if (!ballOffScreen)
			{
				movePlayers();
				moveBall(false, true);
				moveAI();
			}
			else
			{
				if (getKey('W') && !wPress) { choiceLoss--, wPress = true; }
				else if (getKey('S') && !sPress) { choiceLoss++, sPress = true; }
				if (choiceLoss < 0) { choiceLoss = 2; }
				else if (choiceLoss > 2) { choiceLoss = 0; }

				menuLoss(choiceLoss);

				if (getKey(' ') && !spacePress)
				{
					switch (choiceLoss)
					{
					case 0:
						curCX = xSpace(1, 2);
						curCY = ySpace(1, 2);
						first = true;
						cSPEED_Y = 0;
						ballOffScreen = false;
						break;
					case 1:
						choicePM = 0;
						choiceMM = 0;
						choiceLoss = 0;
						mm = true;
						playSingle = false;
						curCX = xSpace(1, 2);
						curCY = ySpace(1, 2);
						first = true;
						cSPEED_Y = 0;
						ballOffScreen = false;
						break;
					case 2:
						termContext();
						break;
					}
				}

				spacePress = true;
			}

			cout << choiceLoss << "(4); ";

			drawPlayer(PLAYER1);
			drawPlayer(AI);
			drawCircle(curCX, curCY, R);
			drawWalls(false);

			if (curCX > SCREEN_X || curCX < 0)
			{
				ballOffScreen = true;
			}
		}
		else if (playMulti)
		{
			if (first)
			{
				moveBall(true, false);
				first = false;
			}

			if (!ballOffScreen)
			{
				movePlayers();
				moveBall(false, true);
			}
			else
			{
				if (getKey('W') && !wPress) { choiceLoss--, wPress = true; }
				else if (getKey('S') && !sPress) { choiceLoss++, sPress = true; }
				if (choiceLoss < 0) { choiceLoss = 2; }
				else if (choiceLoss > 2) { choiceLoss = 0; }

				menuLoss(choiceLoss);

				if (getKey(' ') && !spacePress)
				{
					switch (choiceLoss)
					{
					case 0:
						curCX = xSpace(1, 2);
						curCY = ySpace(1, 2);
						first = true;
						cSPEED_Y = 0;
						ballOffScreen = false;
						break;
					case 1:
						choicePM = 0;
						choiceMM = 0;
						choiceLoss = 0;
						mm = true;
						playMulti = false;
						curCX = xSpace(1, 2);
						curCY = ySpace(1, 2);
						first = true;
						cSPEED_Y = 0;
						ballOffScreen = false;
						break;
					case 2:
						termContext();
						break;
					}
				}

				cout << choiceLoss << "(4); ";
				spacePress = true;
			}

			drawPlayer(PLAYER1);
			drawPlayer(PLAYER2);
			drawCircle(curCX, curCY, R);
			drawWalls(false);

			if (curCX > SCREEN_X || curCX < 0)
			{
				ballOffScreen = true;
			}
		}

		if (!getKey('W') && wPress) { wPress = false; }
		if (!getKey('A') && aPress) { aPress = false; }
		if (!getKey('S') && sPress) { sPress = false; }
		if (!getKey('D') && dPress) { dPress = false; }
		if (!getKey(' ') && spacePress) { spacePress = false; }

		cout << endl;
	}
}