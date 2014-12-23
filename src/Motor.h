#ifndef REVOLUTION_MOTOR_H
#define REVOLUTION_MOTOR_H

#define MOTOR_SPEED_MAX  100
#define MOTOR_SPEED_MIN  -100
#define MOTOR_SPEED_ZERO 0
#define MOTOR_COUNT      8
#define SERVO_COUNT      6	// ish
#define SERVO_POS_MAX    255
#define SERVO_POS_MIN    0

#include "Controller.h"

bool spinning;
// Might be useful in the future
int frontLeftSpeed;
int frontRightSpeed;
int backLeftSpeed;
int backRightSpeed;

int FixSpeed(int rawSpeed)
{
	if (rawSpeed > 100)
		return 100;
	else if (rawSpeed < -100)
		return -100;
	else
		return rawSpeed;
}

void SpinSpinners()
{
	spinning = true;
	motor[spinnerLeft] = 100;
	motor[spinnerRight] = 100;
}

void StopSpinners()
{
	spinning = false;
	motor[spinnerLeft] = 0;
	motor[spinnerRight] = 0;
}

void UpdateMotors()
{
	motor[frontLeft] = frontLeftSpeed;
	motor[frontRight] = frontRightSpeed;
	motor[backLeft] = backLeftSpeed;
	motor[backRight] = backRightSpeed;
}

void setDriveMotors(int speed, bool invertLeft, bool invertRight)
{
	if (invertLeft)
	{
		//motor[frontLeft] = -speed;
		frontLeftSpeed = -speed;
	}
	else
	{
		//motor[frontLeft] = speed;
		frontLeftSpeed = speed;
	}

	if (invertRight)
	{
		//motor[frontRight] = -speed;
		frontRightSpeed = -speed;
	}
	else
	{
		//motor[frontRight] = speed;
		frontRightSpeed = speed;
	}

	if (invertLeft)
	{
		//motor[backLeft] = -speed;
		backLeftSpeed = -speed;
	}
	else
	{
		//motor[backLeft] = speed;
		backLeftSpeed = speed;
	}

	if (invertRight)
	{
		//motor[backRight] = -speed;
		backRightSpeed = -speed;
	}
	else
	{
		//motor[backRight] = speed;
		backRightSpeed = speed;
	}
}

void StopMotors()
{
	setDriveMotors(0, false, false);
}

void MoveStraight(int speed)
{
	int fixedSpeed = FixSpeed(speed);

	// Might have to invert that
	setDriveMotors(fixedSpeed, true, false);
}

void HandleDriveTrain(int yAxis, int xAxis)
{
	int fixedX = FixSpeed(xAxis);
	int fixedY = FixSpeed(yAxis);
	bool noX = FuzzyEquals(fixedX, 0, 7);

	// Turning doesn't do what it's meant to, but it works.
	if (noX && !FuzzyEquals(fixedY, 0, CONTROLLER_JOY_ZERO_RANGE_MAX))
	{
		MoveStraight(fixedY);
	}
	else if (!noX && fixedX > 0)
	{
		// Right
		frontLeftSpeed -= fixedX;
		backLeftSpeed -= fixedX;
		frontRightSpeed = frontLeftSpeed;
		backRightSpeed = backLeftSpeed;
	}
	else if (!noX && fixedX < 0)
	{
		// Left
		frontRightSpeed -= fixedX;
		backRightSpeed -= fixedX;
		frontLeftSpeed = frontRightSpeed;
		backLeftSpeed = backRightSpeed;
	}
	else
	{
		setDriveMotors(0, false, false);
	}

	UpdateMotors();
}

#endif // REVOLUTION_MOTOR_H
