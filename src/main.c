#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Hubs,  S4, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          spinnerServoLeft, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          spinnerServoRight, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_1,     testMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     testMotor2,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    servoOne,             tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    servoTwo,             tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Util.h"
#include "Motor.h"
#include "Auto.h"
#include "Controller.h"

void initRobot()
{
	//selectAutoRoutine();
}


void handleJoyStick()
{
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

    // More testing
	motor[testMotor] = getLeftJoy(CONTROLLER_ONE).y;
}

void driverControlledPeriod()
{
	while(1)
	{
		updateController();
		handleJoyStick();

		//startTask(runMotors);
  }
}

void autoRoutinePeriod()
{

}

task main()
{
	initRobot();

	// TODO: Find out what this does
	//waitForStart();

	//autoRoutinePeriod();

	driverControlledPeriod();

    /* Motor Testing
     *
	 * unsigned int i;
	 * for (i = 0; i <= 100; i += 1)
	 * {
	 *     motor[testMotor] = i;
	 *     wait1Msec(250);
	 * }
     *
	 * for (i = 100; i >= 0; i -= 1)
	 * {
	 *     motor[testMotor] = i;
     *     wait1Msec(250);
	 * }
	 */

    /* Servo Testing
     *
	 * servoTarget[servoOne] = 160;
	 * wait1Msec(1000);
	 * servoTarget[servoTwo] = 160;
	 * wait1Msec(1000);
	 * servoTarget[servoOne] = 90;
	 * wait1Msec(1000);
	 * servoTarget[servo2] = 90;
     */
}
