#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          spinnerLeft,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          spinnerRight,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     linearRight,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     linearLeft,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C2_1,    pullerLeft,           tServoStandard)
#pragma config(Servo,  srvo_S2_C2_2,    pullerRight,          tServoStandard)
#pragma config(Servo,  srvo_S2_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Util.h"
#include "Motor.h"
#include "Auto.h"
#include "Controller.h"

void initRobot()
{
	servoChangeRate[pullerLeft] = 2;
	servoChangeRate[pullerRight] = 3;

	//selectAutoRoutine();
}

void driverControlledPeriod()
{
	while(1)
	{
		getJoystickSettings(joystick);

	  HandleDriveTrain(getRightJoyY(CONTROLLER_ONE), getRightJoyX(CONTROLLER_ONE));

		//nxtDisplayBigTextLine(0, "L:%i", ServoValue[pullerLeft]);
		//nxtDisplayBigTextLine(2, "R: %i", ServoValue[pullerRight]);

		if (joy1Btn(CONTROLLER_BUTTON_X) == 1)
		{
			servo[pullerLeft] = 178;
			servo[pullerRight] = 100;
		}

		if (joy1Btn(CONTROLLER_BUTTON_A) == 1)
		{
			servo[pullerLeft] = 100;
			servo[pullerRight] = 225;
		}

		if (joy1Btn(CONTROLLER_BUTTON_Y) == 1)
		{
			if (spinning)
				StopSpinners();
			else
				SpinSpinners();
		}
	}
}

void autoRoutinePeriod()
{

}

task main()
{
	//TODO: Auto
	initRobot();

	driverControlledPeriod();
}
