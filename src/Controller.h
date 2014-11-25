#ifndef REVOLUTION_CONTROLLER_H
#define REVOLUTION_CONTROLLER_H


#define CONTROLLER_ONE						1
#define CONTROLLER_TWO						2
#define CONTROLLER_BUTTON_Y 				4
#define CONTROLLER_BUTTON_B 				3
#define CONTROLLER_BUTTON_A 				2
#define CONTROLLER_BUTTON_X 				1
#define CONTROLLER_BUTTON_START 			10
#define CONTROLLER_BUTTON_BACK 				9
#define CONTROLLER_BUTTON_LEFT_TRIGGER   	7
#define CONTROLLER_BUTTON_LEFT_BUMPPER   	5
#define CONTROLLER_BUTTON_RIGHT_TRIGGER  	8
#define CONTROLLER_BUTTON_RIGHT_BUMPPER  	6
#define CONTROLLER_BUTTON_LEFT_JOY_DOWN  	11
#define CONTROLLER_BUTTON_RIGHT_JOY_DOWN 	12
#define CONTROLLER_TOPHAT_CENTER			-1	// When nothing is pressed
#define CONTROLLER_TOPHAT_NORTH				0
#define CONTROLLER_TOPHAT_NORTH_EAST		1
#define CONTROLLER_TOPHAT_EAST				2
#define CONTROLLER_TOPHAT_SOUTH_EAST		3
#define CONTROLLER_TOPHAT_SOUTH				4
#define CONTROLLER_TOPHAT_SOUTH_WEST		5
#define CONTROLLER_TOPHAT_WEST				6
#define CONTROLLER_TOPHAT_NORTH_WEST		7
#define CONTROLLER_JOY_LEFT_X_MIN 			-128
#define CONTROLLER_JOY_LEFT_X_MAX 			127
#define CONTROLLER_JOY_LEFT_Y_MIN 			-128
#define CONTROLLER_JOY_LEFT_Y_MAX 			127
#define CONTROLLER_JOY_RIGHT_X_MIN		    -128
#define CONTROLLER_JOY_RIGHT_X_MAX			127
#define CONTROLLER_JOY_RIGHT_Y_MIN			-128
#define CONTROLLER_JOY_RIGHT_Y_MAX			127
// The controller's joysticks don't normally default to zero, but around it
#define CONTROLLER_JOY_ZERO_RANGE_MIN		-7
#define CONTROLLER_JOY_ZERO_RANGE_MAX		7

#include "JoystickDriver.c"
#include "Util.h"
#include "Motor.h"

void updateController()
{
	getJoystickSettings(joystick);
};

bool getKeyDown(short key, unsigned short controller)
{
	if (controller == CONTROLLER_ONE)
	{
		return joy1Btn(key) == 1;
	}
	else if (controller == CONTROLLER_TWO)
	{
		return joy2Btn(key) == 1;
	}
	else
	{
		return false;
	}
};

bool getKeyUp(short key, unsigned short controller)
{
		if (controller == CONTROLLER_ONE)
	{
		return joy1Btn(key) != 1;
	}
	else if (controller == CONTROLLER_TWO)
	{
		return joy2Btn(key) != 1;
	}
	else
	{
		return false;
	}
};

int getLeftJoyX(unsigned short controller)
{
	if (controller == CONTROLLER_ONE)
	{
			return joystick.joy1_x1;
  }
  else if (controller == CONTROLLER_TWO)
  {
  	return joystick.joy2_x1;
	}
	else
	{
		return 0;
	}
};

int getLeftJoyY(unsigned short controller)
{
	if (controller == CONTROLLER_ONE)
	{
		return joystick.joy1_y1;
	}
	else if (controller == CONTROLLER_TWO)
	{
		return joystick.joy2_y1;
	}
	else
	{
		return 0;
	}
};

int getRightJoyX(unsigned short controller)
{
	if (controller == CONTROLLER_ONE)
	{
		return joystick.joy1_x2;
	}
	else if (controller == CONTROLLER_TWO)
	{
		return joystick.joy2_x2;
	}
	else
	{
		return 0;
	}
};

int getRightJoyY(unsigned short controller)
{
		if (controller == CONTROLLER_ONE)
	{
		return joystick.joy1_y2;
	}
	else if (controller == CONTROLLER_TWO)
	{
		return joystick.joy2_y2;
	}
	else
	{
		return 0;
	}
};

void handleJoyStick()
{
	// TODO: Find a better place for this
	Vector2f ZeroVector2f;
	ZeroVector2f.x = 0;
	ZeroVector2f.y = 0;


	// Controller One
	if (getKeyDown(CONTROLLER_BUTTON_A, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_B, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_X, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_Y, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_RIGHT_BUMPPER, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_RIGHT_TRIGGER, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_LEFT_BUMPPER, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_LEFT_TRIGGER, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_START, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_BACK, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_LEFT_JOY_DOWN, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_RIGHT_JOY_DOWN, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_CENTER, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_NORTH, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_NORTH_EAST, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_EAST, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_SOUTH_EAST, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_SOUTH, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_SOUTH_WEST, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_WEST, CONTROLLER_ONE))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_NORTH_WEST, CONTROLLER_ONE))
	{

	}

	// Controller Two
	if (getKeyDown(CONTROLLER_BUTTON_A, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_B, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_X, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_Y, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_RIGHT_BUMPPER, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_RIGHT_TRIGGER, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_LEFT_BUMPPER, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_LEFT_TRIGGER, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_START, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_BACK, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_LEFT_JOY_DOWN, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_BUTTON_RIGHT_JOY_DOWN, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_CENTER, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_NORTH, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_NORTH_EAST, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_EAST, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_SOUTH_EAST, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_SOUTH, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_SOUTH_WEST, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_WEST, CONTROLLER_TWO))
	{

	}

	if (getKeyDown(CONTROLLER_TOPHAT_NORTH_WEST, CONTROLLER_TWO))
	{

	}

	// Drive train motors


	// More testing
	//motor[testMotor] = getLeftJoy(CONTROLLER_ONE).y;
}

#endif //REVOLUTION_CONTROLLER_H
