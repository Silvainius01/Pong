/* Holds all non-entity UI elements */

#include "Global.h"

bool bFir = false;
bool bSec = false;
bool bThi = false;
bool press = true;

char cFir = '#';
char cSec = '#';
char cThi = '#';

float fInput;
float setCSpeedY[3] = { 0, 5, 0 };
float setPSpeed[3] = { 0, 5, 0 };

// 1/100 = 5px  1/200 = 2.5px @ 500px
float xSpace(float num, float den)
{
	float space = ((SCREEN_X / den) * num);
	return space;
}

float ySpace(float num, float den)
{
	float space = ((SCREEN_Y / den) * num);
	return space;
}

char getNumInput()
{
	char input;

	if (getKey('0')) { input = '0'; }
	else if (getKey('1')) { input = '1', fInput = 1; }
	else if (getKey('2')) { input = '2', fInput = 2; }
	else if (getKey('3')) { input = '3', fInput = 3; }
	else if (getKey('4')) { input = '4', fInput = 4; }
	else if (getKey('5')) { input = '5', fInput = 5; }
	else if (getKey('6')) { input = '6', fInput = 6; }
	else if (getKey('7')) { input = '7', fInput = 7; }
	else if (getKey('8')) { input = '8', fInput = 8; }
	else if (getKey('9')) { input = '9', fInput = 9; }
	else { input = 'n'; }

	return input;
}

/*******************************************************************
 * IMPORTTANT NOTE:                                                *
 *                                                                 *
 *  This function was desined to print at a 3:1 h/w ratio!         *
 *  While it CAN print other ratios, they might not look as good!  *
 *                                                                 *
 *******************************************************************/
void drawChar(char a, float x, float y, float h, float w)
{
	switch (a)
	{
	case 'A':
		drawLine(x, y + h, x + (w / 2), y); //Left Diag
		drawLine(x + w, y + h, x + (w / 2), y); //Right diag
		drawLine(x + (w / 4), y + (h / 2), x + ((w / 4) * 3), y + (h / 2)); //Center Line
		break;
	case 'B':
		drawLine(x, y, x, y + h); //spine
		drawLine(x, y, x + (w / 4), y); //Top-Top flat
		drawLine(x + (w / 4), y, x + w, y + (h / 6)); //Top-Top Diag
		drawLine(x + w, y + (h / 6), x + w, y + ((h / 6) * 2)); //Top-Left flat
		drawLine(x + w, y + ((h / 6) * 2), x + (w / 4), y + ((h / 6) * 3));//Top-Bot diag
		drawLine(x, y + (h / 2), x + (w / 4), y + (h / 2)); //Mid Flat
		drawLine(x + (w / 4), y + ((h / 6) * 3), x + w, y + ((h / 6) * 4)); //Bot-Top diag
		drawLine(x + w, y + ((h / 6) * 4), x + w, y + ((h / 6) * 5)); //Bot-Left flat
		drawLine(x + w, y + ((h / 6) * 5), x + (w / 4), y + ((h / 6) * 6)); //Bot-Bot diag
		drawLine(x, y + h, x + (w / 4), y + h); //Bot-Bot flat
		break;
	case 'C':
		drawLine(x + w, y, x + ((w / 3) * 2), y); // 2/3 -> 1/3 //Top flat
		drawLine(x, y + (h / 3), x + ((w / 3) * 2), y); //top-spine connector
		drawLine(x, y + (h / 3), x, y + ((h / 3) * 2)); //Spine
		drawLine(x, y + ((h / 3) * 2), x + ((w / 3) * 2), y + h); //spine-bot connector
		drawLine(x + ((w / 3) * 2), y + h, x + w, y + h); //Bot flat
		break;
	case 'D':
		drawLine(x, y, x, y + h); //spine
		drawLine(x, y, x + (w / 4), y); //Top flat
		drawLine(x + (w / 4), y, x + w, y + ((h / 7) * 2)); //Top-Sode connector
		drawLine(x + w, y + ((h / 7) * 2), x + w, y + ((h / 7) * 5)); //right side
		drawLine(x + w, y + ((h / 7) * 5), x + (w / 4), y + h); //bot- Side connector
		drawLine(x, y + h, x + (w / 4), y + h); //bot flat
		break;
	case 'E':
		drawLine(x, y, x + w, y); //Top flat
		drawLine(x, y, x, y + h - 1); //Spine
		drawLine(x, y + (h / 2), x + (w / 2), y + (h / 2)); //Mid flat
		drawLine(x, y + h - 1, x + w, y + h - 1); //bot flat
		break;
	case 'F':
		drawLine(x, y, x + w, y); //Top flat
		drawLine(x, y, x, y + h); //spine
		drawLine(x, y + (h / 2), x + ((w / 3) * 2), y + (h / 2)); //Mid Flat
		break;
	case 'G': //Note to self: ,ake it fancier
		drawLine(x, y, x + w, y); //top flat
		drawLine(x, y, x, y + h); //Spine
		drawLine(x, y + h - 1, x + w, y + h - 1); //bot flat
		drawLine(x + w, y + h - 1, x + w, y + (h / 2)); //right side
		drawLine(x + w, y + (h / 2), x + (w / 2), y + (h / 2)); //Center "G-line"
		break;
	case 'H':
		drawLine(x, y, x, y + h); //Left side
		drawLine(x + w, y, x + w, y + h); //Right side
		drawLine(x, y + (h / 2), x + w, y + (h / 2)); //Center flat
		break;
	case 'I':
		drawLine(x, y, x + w, y); //Top flat
		drawLine(x + (w / 2), y, x + (w / 2), y + h); //Spine
		drawLine(x, y + h, x + w, y + h); //bot flat
		break;
	case 'J':
		drawLine(x + w, y, x + w, y + ((h / 4) * 3)); //Spine
		drawLine(x + w, y + ((h / 4) * 3), x + ((w / 3) * 2), y + h); //spine-bot connecotr
		drawLine(x + ((w / 3) * 2), y + h, x + (w / 3), y + h); //Bot flat
		drawLine(x, y + ((h / 4) * 3), x + (w / 3), y + h); //Hook
		break;
	case 'K':
		drawLine(x, y, x, y + h); //Spine
		drawLine(x, y + (h / 2), x + w, y); //Top diag
		drawLine(x, y + (h / 2), x + w, y + h); //Bot diag
		break;
	case 'L':
		drawLine(x, y, x, y + h); //Spine
		drawLine(x, y + h - 1, x + w, y + h - 1); //bot Flat
		break;
	case 'M':
		drawLine(x, y, x, y + h); //Left side
		drawLine(x + w, y, x + w, y + h); //Left-Mid diag
		drawLine(x, y, x + (w / 2), y + (h / 2));//Right-Mid Diag
		drawLine(x + (w / 2), y + (h / 2), x + w, y); //Right side
		break;
	case 'N':
		drawLine(x, y, x, y + h); //Left side
		drawLine(x + w, y, x + w, y + h);//Left-Right diag
		drawLine(x, y, x + w, y + h);//Right diag
		break;
	case 'O':
		drawLine(x + (w / 3) + 1, y, x + ((w / 3) * 2), y); //Top flat
		drawLine(x, y + (h / 3), x, y + ((h / 3) * 2)); //Left flat
		drawLine(x + w, y + (h / 3), x + w, y + ((h / 3) * 2)); //right flat
		drawLine(x + (w / 3), y + h, x + ((w / 3) * 2), y + h); // bot flat
		drawLine(x + (w / 3), y + 1, x, y + (h / 3)); //T-L connector
		drawLine(x, y + ((h / 3) * 2), x + (w / 3), y + h); //L-B Connector
		drawLine(x + ((w / 3) * 2), y + 1, x + w, y + (h / 3)); //T-R Connector
		drawLine(x + w, y + ((h / 3) * 2), x + ((w / 3) * 2), y + h); //R-B Connector
		break;
	case 'P': //Note to self: make it fancier
		drawLine(x, y, x, y + h); //Spine
		drawLine(x, y, x + w, y); //top flat
		drawLine(x + w, y, x + w, y + (h / 3)); //right side
		drawLine(x + w, y + (h / 3), x, y + (h / 3)); //Mid flat
		break;
	case 'Q':
		drawChar('O', x, y, h, w);//lel
		drawLine(x + (w / 2), y + ((h / 3) * 2), x + w, y + h); //Slicer diag
		break;
	case 'R':
		drawChar('P', x, y, h, w); //lel
		drawLine(x + ((w / 3) * 2), y + (h / 3), x + w, y + h); //Mid-Bot diag
		break;
	case 'S':
		drawLine(x + (w / 3), y, x + w, y); //Top flat
		drawLine(x + (w / 3), y, x, y + (h / 4)); //T-L connector
		drawLine(x, y + (h / 4), x, y + (h / 3)); //Left side
		drawLine(x, y + (h / 3), x + (w / 3), y + (h / 2) + 1); //L-M Connector
		drawLine(x + (w / 3), y + (h / 2), x + ((w / 3) * 2), y + (h / 2)); //mid flat
		drawLine(x + ((w / 3) * 2), y + (h / 2), x + w, y + ((h / 4) * 3) - 1); //M-R Connector
		drawLine(x + w, y + ((h / 4) * 3), x + w, y + ((h / 3) * 2)); //Right side
		drawLine(x + w, y + ((h / 4) * 3), x + ((w / 3) * 2), y + h); //R-B Connector
		drawLine(x + ((w / 3) * 2), y + h, x, y + h); //Bot flat
		break;
	case 'T':
		drawLine(x, y, x + w, y); //Top flat
		drawLine(x + (w / 2), y, x + (w / 2), y + h); //Spine
		break;
	case 'U':
		drawLine(x, y, x, y + ((h / 3) * 2)); //left side
		drawLine(x, y + ((h / 3) * 2), x + (w / 3) - 1, y + h); //L-B Connector
		drawLine(x + (w / 3), y + h, x + ((w / 3) * 2) + 1, y + h); //Bot flat
		drawLine(x + w, y + ((h / 3) * 2), x + ((w / 3) * 2) + 1, y + h);//R-B connector
		drawLine(x + w, y, x + w, y + ((h / 3) * 2)); //Right side
		break;
	case 'V':
		drawLine(x, y, x + (w / 2), y + h);//Left diag
		drawLine(x + w, y, x + (w / 2), y + h); //Right Diag
		break;
	case 'W':
		drawLine(x, y, x, y + h);//Left side
		drawLine(x, y + h, x + (w / 2), y + (h / 2)); //left diag
		drawLine(x + w, y + h, x + (w / 2), y + (h / 2));//Right diag
		drawLine(x + w, y, x + w, y + h);//Right side
		break;
	case 'X':
		drawLine(x, y, x + w, y + h); //Left diag
		drawLine(x + w, y, x, y + h); //Right diag
		break;
	case 'Y':
		drawLine(x, y, x + (w / 2), y + (h / 2));//Left diag
		drawLine(x + w, y, x + (w / 2), y + (h / 2));//Right diag
		drawLine(x + (w / 2), y + (h / 2), x + (w / 2), y + h); //Spine
		break;
	case 'Z':
		drawLine(x, y, x + w, y);//Top flat
		drawLine(x + w, y, x, y + h);//Diag
		drawLine(x, y + h - 1, x + w, y + h - 1);//bot flat
		break;
	case '0':
		drawChar('O', x, y, h, w); //Lel
		drawLine(x + w, y + (h / 3), x, y + ((h / 3) * 2)); //Diag
		break;
	case '1':
		drawLine(x + (w / 2), y, x + (w / 2), y + h); //Spine
		drawLine(x + (w / 5), y + h, x + ((w / 5) * 4), y + h); //Bot flat
		drawLine(x + (w / 2), y, x + (w / 6), y + (w / 4)); //Diag tip
		break;
	case '2':
		drawLine(x, y + (h / 5), x + ((w / 5) * 2), y);//Left-Top diag
		drawLine(x + ((w / 5) * 2), y, x + ((w / 5) * 4), y); //Top flat
		drawLine(x + ((w / 5) * 4), y, x + w, y + (h / 5)); //Right flat
		drawLine(x + w, y + (h / 5), x, y + h); //Right-Bot diag
		drawLine(x, y + h, x + w, y + h);//Bot flat
		break;
	case '3':
		drawLine(x, y, x + ((w / 5) * 3), y);//Top Flat
		drawLine(x + ((w / 5) * 3), y, x + w, y + (h / 4)); //Top-down diag 1
		drawLine(x + w, y + (h / 4), x + ((w / 5) * 2), y + (h / 2)); //Top-Down diag 2
		drawLine(x + ((w / 5) * 2), y + (h / 2), x + w, y + ((h / 4) * 3)); //Top-Down diag 3
		drawLine(x + w, y + ((h / 4) * 3), x + ((w / 5) * 3), y + h); //Top-Down 3 diag
		drawLine(x, y + h, x + ((w / 5) * 3), y + h);
		break;
	case '4':
		drawLine(x, y + (h / 2), x + w, y + (h / 2));//Middle flat
		drawLine(x, y + (h / 2), x + ((w / 5) * 4), y); //Mid-Top diag
		drawLine(x + ((w / 5) * 4), y, x + ((w / 5) * 4), y + h);//Spine
		break;
	case '5':
		drawLine(x, y, x + w, y); //top flat
		drawLine(x, y, x, y + (h / 2));//Left side;
		drawLine(x, y + (h / 2), x + w, y + (h / 2));//Mid flat
		drawLine(x + w, y + (h / 2), x + w, y + ((h / 5) * 3));//Right side;
		drawLine(x + w, y + ((h / 5) * 4), x + ((w / 3) * 2), y + h);//Right-Bot diag
		drawLine(x + ((w / 3) * 2), y + h, x + (w / 3), y + h);//Bot flat
		drawLine(x + w, y + ((h / 5) * 3), x + w, y + ((h / 5) * 4));
		drawLine(x + (w / 3), y + h, x, y + ((h / 5) * 4));//Bot-Left diag
		break;
	case '6':
		drawChar('O', x, y + ((h / 3)), ((h / 3) * 2), w); //Lel
		drawLine(x + (w / 3) + 1, y + ((h / 3)), x + w, y);//Top diag
		break;
	case '7':
		drawLine(x, y, x + w, y);//Top flat
		drawLine(x + w, y, x + (w / 3), y + h);//Diag
		break;
	case '8':
		drawChar('O', x, y + ((h / 2)), (h / 2), w); //Lel
		drawChar('O', x, y, (h / 2), w); //Double Lel
		break;
	case '9':
		drawChar('O', x, y, ((h / 3) * 2), w); //Lel
		drawLine(x + ((w / 3) * 2), y + ((h / 3) * 2), x + (w / 4), y + h); //Diag
		break;
	case '(':
		drawLine(x + (w / 2), y, x, y + (h / 3)); //Mid-Left diag
		drawLine(x, y + (h / 3), x, y + ((h / 3) * 2)); //left side
		drawLine(x, y + ((h / 3) * 2), x + (w / 2), y + h); //Mid-Right diag
		break;
	case ')':
		drawLine(x + (w / 2), y, x + w, y + (h / 3)); //Mid-Left diag
		drawLine(x + w , y + (h / 3), x + w, y + ((h / 3) * 2)); //left side
		drawLine(x + w, y + ((h / 3) * 2), x + (w / 2), y + h); //Mid-Right diag
		break;
	case '-':
		drawLine(x + (w / 4), y + ((h / 7) * 3), x + ((w / 4) * 3), y + ((h / 7) * 3)); //Top
		drawLine(x + (w / 4), y + ((h / 7) * 3), x + (w / 4), y + ((h / 7) * 4)); //Left
		drawLine(x + ((w / 4) * 3), y + ((h / 7) * 3), x + ((w / 4) * 3), y + ((h / 7) * 4)); //Right
		drawLine(x + (w / 4), y + ((h / 7) * 4), x + ((w / 4) * 3), y + ((h / 7) * 4)); //Bot
		break;
	case '#':
		drawLine(x, y, x + w, y);
		drawLine(x, y, x, y + h);
		drawLine(x + w, y, x + w, y + h);
		drawLine(x, y + h, x + w, y + h);
		break;
	case '?':
		drawLine(x, y, x + (w / 2), y + (h / 3)); //Diag
		drawLine(x + (w / 2), y + (h / 3), x + (w / 2), y + (h / 2)); //Spine
		drawLine(x + (w / 2), y + (h / 2), x + (w / 4), y + ((h / 3) * 2)); //Diag 2
		drawLine(x + (w / 4), y + ((h / 3) * 2), x + (w / 4), y + ((h / 5) * 4));//straight
		drawLine(x + (w / 5), y + ((h / 10) * 9), x + (w / 5), y + h); //Left
		drawLine(x + ((w / 5) * 2.5), y + ((h / 10) * 9), x + ((w / 5) * 2.5), y + h); //Right
		drawLine(x + (w / 5), y + ((h / 10) * 9), x + ((w / 5) * 2.5), y + ((h / 10) * 9)); //Top
		drawLine(x + ((w / 5) * 2.5), y + h, x + (w / 5), y + h); //Bot
		break;
	}
}

void drawSelBoxMM(int choice)
{
	cout << "Drawing SelBox " << choice << "(3); ";

	if (choice == 0)
	{
		drawLine(xSpace(28, 100), ySpace(49, 100), xSpace(32, 100), ySpace(49, 100)); //Top
		drawLine(xSpace(28, 100), ySpace(49, 100), xSpace(28, 100), ySpace(84, 100)); //Left
		drawLine(xSpace(32, 100), ySpace(49, 100), xSpace(32, 100), ySpace(84, 100));//Right
		drawLine(xSpace(28, 100), ySpace(84, 100), xSpace(32, 100), ySpace(84, 100));//Bot
	}
	else if (choice == 1)
	{
		drawLine(xSpace(34, 100), ySpace(125, 200), xSpace(62, 100), ySpace(125, 200)); //Top
		drawLine(xSpace(34, 100), ySpace(125, 200), xSpace(34, 100), ySpace(141, 200)); //Left
		drawLine(xSpace(62, 100), ySpace(125, 200), xSpace(62, 100), ySpace(141, 200));//Right
		drawLine(xSpace(34, 100), ySpace(141, 200), xSpace(62, 100), ySpace(141, 200));//Bot
	}
	else if (choice == 2)
	{
		drawLine(xSpace(64, 100), ySpace(49, 100), xSpace(68, 100), ySpace(49, 100)); //Top
		drawLine(xSpace(64, 100), ySpace(49, 100), xSpace(64, 100), ySpace(84, 100)); //Left
		drawLine(xSpace(68, 100), ySpace(49, 100), xSpace(68, 100), ySpace(84, 100));//Right
		drawLine(xSpace(64, 100), ySpace(84, 100), xSpace(68, 100), ySpace(84, 100));//Bot
	}
}

void drawSelBoxPM(int choice)
{
	cout << "Drawing SelBox " << choice << "(3); ";

	int lolzArray[5] = { 0, 0, 0, 0, 0 };
	int forTheRubrick;
	lolzArray[choice + 1] = 1;

	for (int cuzUWantedJuan = 0; !lolzArray[cuzUWantedJuan]; ++cuzUWantedJuan)
	{
		forTheRubrick = cuzUWantedJuan;
		cout << forTheRubrick;
	}

	cout << "(4); ";

	if (forTheRubrick == 0) //Singleplayer
	{
		drawLine(xSpace(25, 100), ySpace(49, 100), xSpace(44, 100), ySpace(49, 100));//Top
		drawLine(xSpace(25, 100), ySpace(49, 100), xSpace(25, 100), ySpace(64, 100));//Left
		drawLine(xSpace(44, 100), ySpace(49, 100), xSpace(44, 100), ySpace(64, 100));//right
		drawLine(xSpace(25, 100), ySpace(64, 100), xSpace(44, 100), ySpace(64, 100));//Bot
	}
	else if (forTheRubrick == 1) //Multiplayer
	{
		drawLine(xSpace(52, 100), ySpace(49, 100), xSpace(71, 100), ySpace(49, 100));//Top
		drawLine(xSpace(52, 100), ySpace(49, 100), xSpace(52, 100), ySpace(64, 100));//Left
		drawLine(xSpace(71, 100), ySpace(49, 100), xSpace(71, 100), ySpace(64, 100));//right
		drawLine(xSpace(52, 100), ySpace(64, 100), xSpace(71, 100), ySpace(64, 100));//Bot
	}
	else if (forTheRubrick == 2) //Exit
	{
		drawLine(xSpace(31, 100), ySpace(70.4, 100), xSpace(44, 100), ySpace(70.4, 100));//Top
		drawLine(xSpace(31, 100), ySpace(70.4, 100), xSpace(31, 100), ySpace(78.4, 100));//Left
		drawLine(xSpace(44, 100), ySpace(70.4, 100), xSpace(44, 100), ySpace(78.4, 100));//right
		drawLine(xSpace(31, 100), ySpace(78.4, 100), xSpace(44, 100), ySpace(78.4, 100));//Bot
	}
	else if (forTheRubrick == 3) //Tennis
	{
		drawLine(xSpace(52, 100), ySpace(70.4, 100), xSpace(71, 100), ySpace(70.4, 100));//Top
		drawLine(xSpace(52, 100), ySpace(70.4, 100), xSpace(52, 100), ySpace(78.4, 100));//Left
		drawLine(xSpace(71, 100), ySpace(70.4, 100), xSpace(71, 100), ySpace(78.4, 100));//right
		drawLine(xSpace(52, 100), ySpace(78.4, 100), xSpace(71, 100), ySpace(78.4, 100));//Bot
	}
}

void drawSelBoxOM(int choice)
{
	switch (choice)
	{
	case 0: //Ball Speed
		drawLine(xSpace(28, 100), ySpace(44.83, 100), xSpace(74, 100), ySpace(44.83, 100));//Top
		drawLine(xSpace(28, 100), ySpace(44.83, 100), xSpace(28, 100), ySpace(52.83, 100));//Left
		drawLine(xSpace(74, 100), ySpace(44.83, 100), xSpace(74, 100), ySpace(52.83, 100));//Right
		drawLine(xSpace(28, 100), ySpace(52.83, 100), xSpace(74, 100), ySpace(52.83, 100));//Bottom
		break;
	case 1:
		drawLine(xSpace(23, 100), ySpace(53.16, 100), xSpace(79, 100), ySpace(53.16, 100));//Top
		drawLine(xSpace(23, 100), ySpace(53.16, 100), xSpace(23, 100), ySpace(61.16, 100));//Left
		drawLine(xSpace(79, 100), ySpace(53.16, 100), xSpace(79, 100), ySpace(61.16, 100));//Right
		drawLine(xSpace(23, 100), ySpace(61.16, 100), xSpace(79, 100), ySpace(61.16, 100));//Bottom
		break;
	case 2:
		drawLine(xSpace(42, 100), ySpace(61.5, 100), xSpace(61, 100), ySpace(61.5, 100));//Top
		drawLine(xSpace(42, 100), ySpace(61.5, 100), xSpace(42, 100), ySpace(69.5, 100));//Left
		drawLine(xSpace(61, 100), ySpace(61.5, 100), xSpace(61, 100), ySpace(69.5, 100));//Right
		drawLine(xSpace(42, 100), ySpace(69.5, 100), xSpace(61, 100), ySpace(69.5, 100));//Bottom
		break;
	}
}

void drawSelBoxBM(int choice)
{
	switch (choice)
	{
	case 0:
		drawLine(xSpace(24, 100), ySpace(65.33, 100), xSpace(37, 100), ySpace(65.33, 100)); //Top
		drawLine(xSpace(24, 100), ySpace(65.33, 100), xSpace(24, 100), ySpace(73.33, 100)); //Left
		drawLine(xSpace(37, 100), ySpace(65.33, 100), xSpace(37, 100), ySpace(73.33, 100)); //Right
		drawLine(xSpace(24, 100), ySpace(73.33, 100), xSpace(37, 100), ySpace(73.33, 100)); //Bot
		break;
	case 1:
		drawLine(xSpace(53, 100), ySpace(65.33, 100), xSpace(78, 100), ySpace(65.33, 100)); //Top
		drawLine(xSpace(53, 100), ySpace(65.33, 100), xSpace(53, 100), ySpace(73.33, 100)); //Left
		drawLine(xSpace(78, 100), ySpace(65.33, 100), xSpace(78, 100), ySpace(73.33, 100)); //Right
		drawLine(xSpace(53, 100), ySpace(73.33, 100), xSpace(78, 100), ySpace(73.33, 100)); //Bot
		break;
	}
}

void drawSelBoxLoss(int choice)
{
	switch (choice)
	{
	case 0:
		drawLine(xSpace(44.5, 100), ySpace(41, 100), xSpace(54.5, 100), ySpace(41, 100)); //Top
		drawLine(xSpace(44.5, 100), ySpace(41, 100), xSpace(44.5, 100), ySpace(49, 100));//Left
		drawLine(xSpace(54.5, 100), ySpace(41, 100), xSpace(54.5, 100), ySpace(49, 100));//Right
		drawLine(xSpace(44.5, 100), ySpace(49, 100), xSpace(54.5, 100), ySpace(49, 100));//Bot
		break;
	case 1:
		drawLine(xSpace(42, 100), ySpace(49, 100), xSpace(57, 100), ySpace(49, 100)); //Top
		drawLine(xSpace(42, 100), ySpace(49, 100), xSpace(42, 100), ySpace(57, 100));//Left
		drawLine(xSpace(57, 100), ySpace(49, 100), xSpace(57, 100), ySpace(57, 100));//Right
		drawLine(xSpace(42, 100), ySpace(57, 100), xSpace(57, 100), ySpace(57, 100));//Bot
		break;
	case 2:
		drawLine(xSpace(42, 100), ySpace(57, 100), xSpace(57, 100), ySpace(57, 100)); //Top
		drawLine(xSpace(42, 100), ySpace(57, 100), xSpace(42, 100), ySpace(65, 100));//Left
		drawLine(xSpace(57, 100), ySpace(57, 100), xSpace(57, 100), ySpace(65,100));//Right
		drawLine(xSpace(42, 100), ySpace(65, 100), xSpace(57, 100), ySpace(65, 100));//Bot
		break;
	}
}

void menuMain(int choice)
{
	cout << "Drawing Main; ";

	drawChar('P', xSpace(29, 100), ySpace(1, 3), 30, 10);
	drawChar('O', xSpace(41, 100), ySpace(1, 3), 30, 10);
	drawChar('N', xSpace(53, 100), ySpace(1, 3), 30, 10);
	drawChar('G', xSpace(65, 100), ySpace(1, 3), 30, 10);

	drawChar('P', xSpace(29, 100), ySpace(1, 2), 30, 10);
	drawChar('L', xSpace(29, 100), ySpace(59, 100), 30, 10);
	drawChar('A', xSpace(29, 100), ySpace(17, 25), 30, 10);
	drawChar('Y', xSpace(29, 100), ySpace(77, 100), 30, 10);

	drawChar('O', xSpace(35, 100), ySpace(127, 200), 30, 10);
	drawChar('P', xSpace(39, 100), ySpace(127, 200), 30, 10);
	drawChar('T', xSpace(43, 100), ySpace(127, 200), 30, 10);
	drawChar('I', xSpace(47, 100), ySpace(127, 200), 30, 10);
	drawChar('O', xSpace(51, 100), ySpace(127, 200), 30, 10);
	drawChar('N', xSpace(55, 100), ySpace(127, 200), 30, 10);
	drawChar('S', xSpace(59, 100), ySpace(127, 200), 30, 10);

	drawChar('E', xSpace(65, 100), ySpace(1, 2), 30, 10);
	drawChar('X', xSpace(65, 100), ySpace(59, 100), 30, 10);
	drawChar('I', xSpace(65, 100), ySpace(17, 25), 30, 10);
	drawChar('T', xSpace(65, 100), ySpace(77, 100), 30, 10);

	cout << choice << "(2); ";

	drawSelBoxMM(choice);
}

void menuPlay(int choice)
{
	cout << "Drawing Play; " << choice << "(2); ";

	drawChar('P', xSpace(29, 100), ySpace(1, 3), 30, 10);
	drawChar('L', xSpace(41, 100), ySpace(1, 3), 30, 10);
	drawChar('A', xSpace(53, 100), ySpace(1, 3), 30, 10);
	drawChar('Y', xSpace(65, 100), ySpace(1, 3), 30, 10);

	drawChar('S', xSpace(26, 100), ySpace(1, 2), 30, 10);
	drawChar('I', xSpace(29, 100), ySpace(1, 2), 30, 10);
	drawChar('N', xSpace(32, 100), ySpace(1, 2), 30, 10);
	drawChar('G', xSpace(35, 100), ySpace(1, 2), 30, 10);
	drawChar('L', xSpace(38, 100), ySpace(1, 2), 30, 10);
	drawChar('E', xSpace(41, 100), ySpace(1, 2), 30, 10);
	drawChar('P', xSpace(26, 100), ySpace(4, 7), 30, 10);
	drawChar('L', xSpace(29, 100), ySpace(4, 7), 30, 10);
	drawChar('A', xSpace(32, 100), ySpace(4, 7), 30, 10);
	drawChar('Y', xSpace(35, 100), ySpace(4, 7), 30, 10);
	drawChar('E', xSpace(38, 100), ySpace(4, 7), 30, 10);
	drawChar('R', xSpace(41, 100), ySpace(4, 7), 30, 10);

	drawChar('M', xSpace(53, 100), ySpace(1, 2), 30, 10);
	drawChar('U', xSpace(56, 100), ySpace(1, 2), 30, 10);
	drawChar('L', xSpace(59, 100), ySpace(1, 2), 30, 10);
	drawChar('T', xSpace(62, 100), ySpace(1, 2), 30, 10);
	drawChar('I', xSpace(65, 100), ySpace(1, 2), 30, 10);
	drawChar('P', xSpace(53, 100), ySpace(4, 7), 30, 10);
	drawChar('L', xSpace(56, 100), ySpace(4, 7), 30, 10);
	drawChar('A', xSpace(59, 100), ySpace(4, 7), 30, 10);
	drawChar('Y', xSpace(62, 100), ySpace(4, 7), 30, 10);
	drawChar('E', xSpace(65, 100), ySpace(4, 7), 30, 10);
	drawChar('R', xSpace(68, 100), ySpace(4, 7), 30, 10);

	drawChar('B', xSpace(32, 100), ySpace(5, 7), 30, 10);
	drawChar('A', xSpace(35, 100), ySpace(5, 7), 30, 10);
	drawChar('C', xSpace(38, 100), ySpace(5, 7), 30, 10);
	drawChar('K', xSpace(41, 100), ySpace(5, 7), 30, 10);

	drawChar('T', xSpace(53, 100), ySpace(5, 7), 30, 10);
	drawChar('E', xSpace(56, 100), ySpace(5, 7), 30, 10);
	drawChar('N', xSpace(59, 100), ySpace(5, 7), 30, 10);
	drawChar('N', xSpace(62, 100), ySpace(5, 7), 30, 10);
	drawChar('I', xSpace(65, 100), ySpace(5, 7), 30, 10);
	drawChar('S', xSpace(68, 100), ySpace(5, 7), 30, 10);

	drawSelBoxPM(choice);
}

void menuOpt(int choice)
{
	drawChar('O', xSpace(35, 100), ySpace(1, 3), 30, 10);
	drawChar('P', xSpace(40, 100), ySpace(1, 3), 30, 10);
	drawChar('T', xSpace(45, 100), ySpace(1, 3), 30, 10);
	drawChar('I', xSpace(50, 100), ySpace(1, 3), 30, 10);
	drawChar('O', xSpace(55, 100), ySpace(1, 3), 30, 10);
	drawChar('N', xSpace(60, 100), ySpace(1, 3), 30, 10);
	drawChar('S', xSpace(65, 100), ySpace(1, 3), 30, 10);

	drawChar('B', xSpace(29, 100), ySpace(2.75, 6), 30, 10);
	drawChar('A', xSpace(34, 100), ySpace(2.75, 6), 30, 10);
	drawChar('L', xSpace(39, 100), ySpace(2.75, 6), 30, 10);
	drawChar('L', xSpace(44, 100), ySpace(2.75, 6), 30, 10);
	drawChar('S', xSpace(51, 100), ySpace(2.75, 6), 30, 10);
	drawChar('P', xSpace(56, 100), ySpace(2.75, 6), 30, 10);
	drawChar('E', xSpace(61, 100), ySpace(2.75, 6), 30, 10);
	drawChar('E', xSpace(66, 100), ySpace(2.75, 6), 30, 10);
	drawChar('D', xSpace(71, 100), ySpace(2.75, 6), 30, 10);

	drawChar('P', xSpace(24, 100), ySpace(3.25, 6), 30, 10);
	drawChar('L', xSpace(29, 100), ySpace(3.25, 6), 30, 10);
	drawChar('A', xSpace(34, 100), ySpace(3.25, 6), 30, 10);
	drawChar('Y', xSpace(39, 100), ySpace(3.25, 6), 30, 10);
	drawChar('E', xSpace(44, 100), ySpace(3.25, 6), 30, 10);
	drawChar('R', xSpace(49, 100), ySpace(3.25, 6), 30, 10);
	drawChar('S', xSpace(56, 100), ySpace(3.25, 6), 30, 10);
	drawChar('P', xSpace(61, 100), ySpace(3.25, 6), 30, 10);
	drawChar('E', xSpace(66, 100), ySpace(3.25, 6), 30, 10);
	drawChar('E', xSpace(71, 100), ySpace(3.25, 6), 30, 10);
	drawChar('D', xSpace(76, 100), ySpace(3.25, 6), 30, 10);

	drawChar('B', xSpace(43, 100), ySpace(3.75, 6), 30, 10);
	drawChar('A', xSpace(48, 100), ySpace(3.75, 6), 30, 10);
	drawChar('C', xSpace(53, 100), ySpace(3.75, 6), 30, 10);
	drawChar('K', xSpace(58, 100), ySpace(3.75, 6), 30, 10);

	drawSelBoxOM(choice);
}

void menuLoss(int choice)
{
	drawChar('P', xSpace(35, 100), ySpace(1, 3), 30, 10);
	drawChar('L', xSpace(38, 100), ySpace(1, 3), 30, 10);
	drawChar('A', xSpace(41, 100), ySpace(1, 3), 30, 10);
	drawChar('Y', xSpace(44, 100), ySpace(1, 3), 30, 10);

	drawChar('A', xSpace(50, 100), ySpace(1, 3), 30, 10);
	drawChar('G', xSpace(53, 100), ySpace(1, 3), 30, 10);
	drawChar('A', xSpace(56, 100), ySpace(1, 3), 30, 10);
	drawChar('I', xSpace(59, 100), ySpace(1, 3), 30, 10);
	drawChar('N', xSpace(62, 100), ySpace(1, 3), 30, 10);
	drawChar('?', xSpace(65, 100), ySpace(1, 3), 30, 10);

	drawChar('Y', xSpace(45.5, 100), ySpace(42, 100), 30, 10);
	drawChar('E', xSpace(48.5, 100), ySpace(42, 100), 30, 10);
	drawChar('S', xSpace(51.5, 100), ySpace(42, 100), 30, 10);

	drawChar('M', xSpace(44, 100), ySpace(1, 2), 30, 10);
	drawChar('E', xSpace(47, 100), ySpace(1, 2), 30, 10);
	drawChar('N', xSpace(50, 100), ySpace(1, 2), 30, 10);
	drawChar('U', xSpace(53, 100), ySpace(1, 2), 30, 10);

	drawChar('E', xSpace(44, 100), ySpace(58, 100), 30, 10);
	drawChar('X', xSpace(47, 100), ySpace(58, 100), 30, 10);
	drawChar('I', xSpace(50, 100), ySpace(58, 100), 30, 10);
	drawChar('T', xSpace(53, 100), ySpace(58, 100), 30, 10);

	drawSelBoxLoss(choice);
}

void menuBallOp(int choice)
{
	if (choice == 3)
	{
		bFir = false;
		bSec = false;
		bThi = false;

		cFir = '#';
		cSec = '#';
		cThi = '#';
	}
	else
	{
		//Reminder: each char takes up 2/100 on the x-axis, and takes up 6/100 on the y!
		drawChar('(', xSpace(21.5, 100), ySpace(1, 3), 30, 10);

		drawChar('E', xSpace(27.5, 100), ySpace(1, 3), 30, 10);
		drawChar('N', xSpace(30.5, 100), ySpace(1, 3), 30, 10);
		drawChar('T', xSpace(33.5, 100), ySpace(1, 3), 30, 10);
		drawChar('E', xSpace(36.5, 100), ySpace(1, 3), 30, 10);
		drawChar('R', xSpace(39.5, 100), ySpace(1, 3), 30, 10);

		drawChar('3', xSpace(45.5, 100), ySpace(1, 3), 30, 10);

		drawChar('N', xSpace(51.5, 100), ySpace(1, 3), 30, 10);
		drawChar('U', xSpace(54.5, 100), ySpace(1, 3), 30, 10);
		drawChar('M', xSpace(57.5, 100), ySpace(1, 3), 30, 10);
		drawChar('B', xSpace(60.5, 100), ySpace(1, 3), 30, 10);
		drawChar('E', xSpace(63.5, 100), ySpace(1, 3), 30, 10);
		drawChar('R', xSpace(66.5, 100), ySpace(1, 3), 30, 10);
		drawChar('S', xSpace(69.5, 100), ySpace(1, 3), 30, 10);

		drawChar(')', xSpace(75.5, 100), ySpace(1, 3), 30, 10);

		if (!press)
		{
			if (!bFir && getNumInput() != 'n')
			{
				cFir = getNumInput();
				setCSpeedY[0] = fInput;
				bFir = true;
				press = true;
			}
			else if (!bSec && getNumInput() != 'n')
			{
				cSec = getNumInput();
				setCSpeedY[1] = fInput;
				bSec = true;
				press = true;
			}
			else if (!bThi && getNumInput() != 'n')
			{
				cThi = getNumInput();
				setCSpeedY[2] = fInput;
				bThi = true;
				press = true;
			}
		}

		if (getNumInput() == 'n' && press)
		{
			press = false;
		}

		drawChar(cFir, xSpace(25, 100), ySpace(1.5, 3), 30, 10);
		drawChar(cSec, xSpace(50, 100), ySpace(1.5, 3), 30, 10);
		drawChar(cThi, xSpace(75, 100), ySpace(1.5, 3), 30, 10);

		drawChar('O', xSpace(25, 100), ySpace(2, 3), 30, 10);
		drawChar('K', xSpace(28, 100), ySpace(2, 3), 30, 10);
		drawChar('A', xSpace(31, 100), ySpace(2, 3), 30, 10);
		drawChar('Y', xSpace(34, 100), ySpace(2, 3), 30, 10);

		drawChar('R', xSpace(54, 100), ySpace(2, 3), 30, 10);
		drawChar('E', xSpace(57, 100), ySpace(2, 3), 30, 10);
		drawChar('-', xSpace(60, 100), ySpace(2, 3), 30, 10);
		drawChar('E', xSpace(63, 100), ySpace(2, 3), 30, 10);
		drawChar('N', xSpace(66, 100), ySpace(2, 3), 30, 10);
		drawChar('T', xSpace(69, 100), ySpace(2, 3), 30, 10);
		drawChar('E', xSpace(72, 100), ySpace(2, 3), 30, 10);
		drawChar('R', xSpace(75, 100), ySpace(2, 3), 30, 10);

		if (bFir && bSec && bThi)
		{
			drawSelBoxBM(choice);
		}

		cout << cFir << "(c1); " << cSec << "(c2); " << cThi << "(c3); ";
	}
}

void menuPlayOp(int choice)
{
	//Reminder: each char takes up 2/100 on the x-axis, and takes up 6/100 on the y!
	drawChar('(', xSpace(21.5, 100), ySpace(1, 3), 30, 10);

	drawChar('E', xSpace(27.5, 100), ySpace(1, 3), 30, 10);
	drawChar('N', xSpace(30.5, 100), ySpace(1, 3), 30, 10);
	drawChar('T', xSpace(33.5, 100), ySpace(1, 3), 30, 10);
	drawChar('E', xSpace(36.5, 100), ySpace(1, 3), 30, 10);
	drawChar('R', xSpace(39.5, 100), ySpace(1, 3), 30, 10);

	drawChar('3', xSpace(45.5, 100), ySpace(1, 3), 30, 10);

	drawChar('N', xSpace(51.5, 100), ySpace(1, 3), 30, 10);
	drawChar('U', xSpace(54.5, 100), ySpace(1, 3), 30, 10);
	drawChar('M', xSpace(57.5, 100), ySpace(1, 3), 30, 10);
	drawChar('B', xSpace(60.5, 100), ySpace(1, 3), 30, 10);
	drawChar('E', xSpace(63.5, 100), ySpace(1, 3), 30, 10);
	drawChar('R', xSpace(66.5, 100), ySpace(1, 3), 30, 10);
	drawChar('S', xSpace(69.5, 100), ySpace(1, 3), 30, 10);

	drawChar(')', xSpace(75.5, 100), ySpace(1, 3), 30, 10);

	if (!press)
	{
		if (!bFir && getNumInput() != 'n')
		{
			cFir = getNumInput();
			setPSpeed[0] = fInput;
			bFir = true;
			press = true;
		}
		else if (!bSec && getNumInput() != 'n')
		{
			cSec = getNumInput();
			setPSpeed[1] = fInput;
			bSec = true;
			press = true;
		}
		else if (!bThi && getNumInput() != 'n')
		{
			cThi = getNumInput();
			setPSpeed[2] = fInput;
			bThi = true;
			press = true;
		}
	}

	if (getNumInput() == 'n' && press)
	{
		press = false;
	}

	drawChar(cFir, xSpace(25, 100), ySpace(1.5, 3), 30, 10);
	drawChar(cSec, xSpace(50, 100), ySpace(1.5, 3), 30, 10);
	drawChar(cThi, xSpace(75, 100), ySpace(1.5, 3), 30, 10);

	drawChar('O', xSpace(25, 100), ySpace(2, 3), 30, 10);
	drawChar('K', xSpace(28, 100), ySpace(2, 3), 30, 10);
	drawChar('A', xSpace(31, 100), ySpace(2, 3), 30, 10);
	drawChar('Y', xSpace(34, 100), ySpace(2, 3), 30, 10);

	drawChar('R', xSpace(54, 100), ySpace(2, 3), 30, 10);
	drawChar('E', xSpace(57, 100), ySpace(2, 3), 30, 10);
	drawChar('-', xSpace(60, 100), ySpace(2, 3), 30, 10);
	drawChar('E', xSpace(63, 100), ySpace(2, 3), 30, 10);
	drawChar('N', xSpace(66, 100), ySpace(2, 3), 30, 10);
	drawChar('T', xSpace(69, 100), ySpace(2, 3), 30, 10);
	drawChar('E', xSpace(72, 100), ySpace(2, 3), 30, 10);
	drawChar('R', xSpace(75, 100), ySpace(2, 3), 30, 10);

	if (bFir && bSec && bThi)
	{
		drawSelBoxBM(choice);
	}

	cout << cFir << "(c1); " << cSec << "(c2); " << cThi << "(c3); ";
}