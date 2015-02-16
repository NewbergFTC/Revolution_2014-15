#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S3,     IR_Sensor,      sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          spinnerLeft,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          spinnerRight,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     backLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     linearRight,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     linearLeft,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     frontLeft,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C2_1,    pullerLeft,           tServoStandard)
#pragma config(Servo,  srvo_S2_C2_2,    pullerRight,          tServoStandard)
#pragma config(Servo,  srvo_S2_C2_3,    doorFront,            tServoContinuousRotation)
#pragma config(Servo,  srvo_S2_C2_4,    doorBack,             tServoContinuousRotation)
#pragma config(Servo,  srvo_S2_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an TETRIX robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "Util.h"
#include "Motor.h"
#include "Auto.h"
#include "IR.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
	disableDiagnosticsDisplay();

  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.
	servoChangeRate[pullerLeft] = 2;
	servoChangeRate[pullerRight] = 3;

	nMotorEncoder[backRight] = 0;

	startTask(Start_IR);

	eraseDisplay();
  autoRoutine = selectAutoRoutine();

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

uint IRCheckCount = 0;

bool rampstartPosOne = false;
bool rampstartPosTwo = false;
bool rampStartPosThree = false;
bool rampEndPosOne = false;
bool rampEndPosTwo = false;
bool rampEndPosThree = false;
bool rampEndTurnPosOne = false;
bool rampEndTurnPosTwo = false;
bool rampEndTurnPosThree = false;
bool rampBackPosOne = false;
bool rampLastPosOne = false;

void handleIR()
{
  if (IRCheckCount == 0)
  {
    if (FuzzyEquals(IR, 7, 1)) // Position One
    {
      rampstartPosOne = true;
      rampstartPosTwo = true;
      rampstartPosThree = true;
    }
  }
  else if (IRCheckCount == 1)
  {
    if (FuzzyEquals(IR, 5, 1))
    {
      rampEndPosOne = true;
    }

    if (FuzzyEquals(IR, 6, 1))
    {
    	rampEndPosTwo = true;
  	}

  	if (FuzzyEquals(IR, 0, 1))
  	{
  		rampEndPosThree = true;
  	}
  }
  else if (IRCheckCount == 2)
  {
    if (FuzzyEquals(IR, 3, 1))
    {
      rampEndTurnPosOne = true;
      rampEndPosTwo = true;
    }

    if (FuzzyEquals(IR, 0, 1))
    {
    	rampEndTurnPosThree	= true;
  	}
  }
  else if (IRCheckCount == 3)
  {
    if (FuzzyEquals(IR, 5, 1))
    {
      rampBackPosOne = true;
      rampBackPosOne = true;
    }
  }

  IRCheckCount++;
}

// Red - Ramp
// Start backwords
void  routineOne()
{
  eraseDisplay();
  nxtDisplayBigTextLine(0, "One");

  // Our goal here is to grab a goal, then try and knock over a pole
  RetractGrabbers();		// Make sure the grabbers are up
  servo[doorFront] = 255;
  servo[doorBack] = 255;
  Drive(67, 90); 		// Drive off the ramp
  wait1Msec(250);		// ----May need more stuff here to grab the goal----
  StopDriveMotors();
  wait1Msec(2000);
  //Turn(-WHEEL_45_DEGREES, 90);  // Ideally turn 45* away from the wall
  //wait1Msec(250);
  //Drive(12, 90);		// ----TODO: Knock down the pole----
  //wait1Msec(250);
};

// Red - Ground
void routineTwo()
{
  eraseDisplay();
  nxtDisplayBigTextLine(0, "Two");

  // Our goal here is to knock down the pole, then try and grab a bucket
  RetractGrabbers();
  Drive(12, 90);			// TODO: Have a real distance here
};

// Blue - Ramp
void routineThree()
{
  eraseDisplay();
  nxtDisplayBigTextLine(0, "Three");

  RetractGrabbers();
  handleIR();

  if (rampstartPosOne || rampstartPosTwo)
  {
    Drive(68, 90);  // Drive off the ramp
    wait1Msec(250);
    handleIR();

    if (rampEndPosOne || rampEndPosTwo)
    {
      Turn(-WHEEL_45_DEGREES * 1.4, 90);  // Turn away from the ramp
      wait1Msec(250);
      handleIR();

      if (rampEndTurnPosOne || rampEndTurnPosTwo)
      {
        Drive(-30, 90);  // Drive away from the ramp
        wait1Msec(250);
        handleIR();

        if (rampBackPosOne)
        {
          Turn(-WHEEL_45_DEGREES * 0.7, 90);  // Turn towards the pole
          wait1Msec(250);
          Drive(-32, 90);  // Knock down the pole
          wait1Msec(250);
          Turn(-WHEEL_45_DEGREES * 0.4, 90);  // Make sure it's down
          wait1Msec(250);
          Drive(20, 90);  // Drive away
          wait1Msec(250);
        }
      }
    }

    if (rampEndPosThree)
    {
   		Turn(-WHEEL_90_DEGREES, 90);
   	  wait1Msec(250);
   	  handleIR();

   	  if (rampEndTurnPosThree)
   	  {
   	  	Drive(-44, 90);
   	  	wait1Msec(250);
   	  	Turn(-WHEEL_45_DEGREES, 90);
   	  	wait1Msec(250);
   	  	Drive(12, 90);
   		}
    }
  }
};

// Blue - Ground
void routineFour()
{
	while (1)
	{
		eraseDisplay();
		nxtDisplayBigTextLine(0, "Four");

	//	Drive(25, 90);
	}
};

task main()
{
  initializeRobot();

  eraseDisplay();
  nxtDisplayBigTextLine(0, "Routine:");
  nxtDisplayBigTextLine(2, "%u", autoRoutine);

  waitForStart(); // Wait for the beginning of autonomous phase.

  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
  ////                                                   ////
  ////    Add your robot specific autonomous code here.  ////
  ////                                                   ////
  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////

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
		default:
			break;
	}
}
