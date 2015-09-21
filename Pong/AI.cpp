/* Holds the AI for single player */

#include "Global.h"


float getAITarget()
{
	srand(time(NULL));
	int r = std::rand() % 3;

	float slope = ((curCY - lstCY) / (curCX - lstCX)); //Rise over run!
	float dist = AI.xPOS - curCX;
	float predY = ((dist * slope) + curCY);

	if (r == 0) { predY -= 10; }
	else if (r == 1) { predY -= 20; }
	else if (r == 2) { predY -= 30; }

	cout << "The AI: " << AI.xPOS << "; " << dist << "; " << slope << "; " << predY << endl << endl;
	return predY;
}

void moveAI()
{
	float targetY = getAITarget();

	if (AI.yPOS > targetY)      { AI.yPOS -= pSPEED * getDeltaTime(); }
	else if (AI.yPOS < targetY) { AI.yPOS += pSPEED * getDeltaTime(); }

	if (AI.yPOS > 459)    { AI.yPOS = 459; }
	else if (AI.yPOS < 0) { AI.yPOS = 0;  }
}
