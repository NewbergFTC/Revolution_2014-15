#ifndef REVOLUTION_AUTO_H
#define REVOLUTION_AUTO_H

//TODO: real names, add more?
#define AUTO_ROUTINE_ONE 	1
#define AUTO_ROUTINE_TWO 	2
#define AUTO_ROUTINE_THREE 	3
#define AUTO_ROUTINE_FOUR	4
#define AUTO_ROUTINE_COUNT 4

ushort autoRoutine;
uint watchDogDelay;

// TODO: Routines

int selectAutoRoutine()
{
	int currMenuPos = -1;
	int finalMenuPos = -1;
	nNxtButtonTask = -2;

	nxtDisplayBigTextLine(1,"RouteMenu");
	nxtDisplayTextLine(3,"Use arrow keys");
	nxtDisplayTextLine(4,"to choose an");
	nxtDisplayTextLine(5,"automomous");
	nxtDisplayTextLine(6,"routine. Press");
	nxtDisplayTextLine(7,"orange button");
	nxtDisplayTextLine(8,"to select.");

	while (1)
	{
		TButtons nBtn;

		while (1)
		{
			nBtn = nNxtButtonPressed;
			if (nBtn != -1)
				break;
		}

		switch (nBtn)
		{
			case kLeftButton:
				currMenuPos -= 1;
				if (currMenuPos < 0)
				{
					currMenuPos = AUTO_ROUTINE_COUNT - 1;
				}
				break;
			case kRightButton:
				currMenuPos += 1;
				if (currMenuPos == AUTO_ROUTINE_COUNT)
				{
					currMenuPos = 0;
				}
				break;
			case kEnterButton:
				finalMenuPos = currMenuPos;
				break;
			default:
				break;
		}

	  while (1)
	  {
	  	nBtn = nNxtButtonPressed;
	  	if (nBtn == -1)
	  		break;
		}

		if (finalMenuPos > -1)
			return finalMenuPos + 1;

			eraseDisplay();
			nxtDisplayBigTextLine(1, "%i", currMenuPos + 1);
			nxtDisplayTextLine(5, "Choice %i of %i", currMenuPos + 1, AUTO_ROUTINE_COUNT);
	}
};

task WatchDog()
{
  wait1Msec(watchDogDelay);
  StopAllTasks();
}

#endif //REVOLUTION_AUTO_H
