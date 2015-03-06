#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     IR_Sensor,      sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          spinnerLeft,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          spinnerRight,  tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     backLeft,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     linearRight,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Util.h"
#include "Motor.h"
#include "Controller.h"
#include "IR.h"

void initRobot()
{
    disableDiagnosticsDisplay();
    servoChangeRate[pullerLeft] = 2;
    servoChangeRate[pullerRight] = 3;

    bFloatDuringInactiveMotorPWM = false;

    startTask(Start_IR);

    nMotorEncoder[backRight] = 0;
}

task main()
{
    initRobot();

    waitForStart();

    while(1)
    {
        getJoystickSettings(joystick);

        HandleDriveTrain(getRightJoyY(CONTROLLER_ONE), getRightJoyX(CONTROLLER_ONE));
        HandleLinear(getLeftJoyY(CONTROLLER_TWO);
        UpdateMotors();
        nxtDisplayBigTextLine(2, "%i", nMotorEncoder[backRight]);

        if (joy1Btn(CONTROLLER_BUTTON_A))
    	{
        	SpinSpinners();
        }

        if (joy1Btn(CONTROLLER_BUTTON_B))
    	{
            StopSpinners();
        }

        if (joy1Btn(CONTROLLER_BUTTON_X))
    	{
        	servo[pullerLeft] = SERVO_LEFT_DOWN;
            servo[pullerRight] = SERVO_RIGHT_DOWN;
        }

        if (joy1Btn(CONTROLLER_BUTTON_Y))
    	{
        	servo[pullerLeft] = SERVO_LEFT_UP;
            servo[pullerRight] = SERVO_RIGHT_UP;
        }

        if (joy2Btn(CONTROLLER_BUTTON_A))
    	{
        	servo[doorBack] = 125;
        }

        if (joy2Btn(CONTROLLER_BUTTON_B))
    	{
        	servo[doorBack] = 255;
        }

        if (joy2Btn(CONTROLLER_BUTTON_X))
    	{
        	servo[doorFront] = 60;
        }

        if (joy2Btn(CONTROLLER_BUTTON_Y))
    	{
        	servo[doorFront] = 255;
        }
    }
}
