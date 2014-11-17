#ifndef REVOLUTION_AUTO_H
#define REVOLUTION_AUTO_H

//TODO: real names, add more?
#define AUTO_ROUTINE_ONE 	1
#define AUTO_ROUTINE_TWO 	2
#define AUTO_ROUTINE_THREE 	3
#define AUTO_ROUTINE_FOUR	4

unsigned short autoRoutine;

// TODO: Routines
void  routineOne()
{

};

void routineTwo()
{

};

void routineThree()
{

};

void routineFour()
{

};

void selectAutoRoutine()
{

};

void runAutoRoutine()
{
	if (autoRoutine <= 0 || autoRoutine >= 5)
	{
		return;
	}

	switch(autoRoutine)
	{
		case AUTO_ROUTINE_ONE:
			routineOne();
			break;
		case AUTO_ROUTINE_TWO:
			routineTwo();
			break;
		case AUTO_ROUTINE_THREE:
			routineThree();
			break;
		case AUTO_ROUTINE_FOUR:
			routineFour();
			break;
	}
};

#endif //REVOLUTION_AUTO_H
