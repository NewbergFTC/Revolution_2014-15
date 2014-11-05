#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          spinnerServoLeft, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          spinnerServoRight, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     backRight,     tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Motor.h"
#include "Auto.h"
#include "Controller.h"


void initRobot()
{
	selectAutoRoutine();
}

void driverControlledPeriod()
{
	while(1)
	{
		updateController();

		startTask(runMotors);
  }
}

void autoRoutinePeriod()
{

}

task main()
{
	//initRobot();

	// TODO: Find out what that does
	//waitForStart();

	//autoRoutinePeriod();

	// TODO: Some stuff?

	//driverControlledPeriod();
}
