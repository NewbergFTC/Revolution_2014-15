#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_1,     linearLeft,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     linearRight,   tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C2_1,    bucketDoor,           tServoStandard)
#pragma config(Servo,  srvo_S3_C2_2,    bucketLeft,           tServoStandard)
#pragma config(Servo,  srvo_S3_C2_3,    bucketRight,          tServoStandard)
#pragma config(Servo,  srvo_S3_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C2_6,    servo6,               tServoNone)
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

	motor[frontLeft] = 100;
  wait1Msec(3000);
  motor[frontLeft] = 0;
}
