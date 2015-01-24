#ifndef REVOLUTION_MOTOR_H
#define REVOLUTION_MOTOR_H

#define MOTOR_SPEED_MAX  100
#define MOTOR_SPEED_MIN  -100
#define MOTOR_SPEED_ZERO 0
#define MOTOR_COUNT      8
#define SERVO_COUNT      6	// ish
#define SERVO_POS_MAX    255
#define SERVO_POS_MIN    0
#define ENCODER_TICKS_PER_REVOLUTION 1140
#define WHEEL_DIAMETER 3.85
#define WHEEL_CIRCUMFRENCE (WHEEL_DIAMETER * PI)
#define WHEEL_90_DEGREES (1700)
#define WHEEL_45_DEGREES (WHEEL_90_DEGREES / 2)

enum LinearPosition
{
	LINEAR_30,
	LINEAR_60,
	LINEAR_90
};

bool spinning;
int frontLeftSpeed;
int frontRightSpeed;
int backLeftSpeed;
int backRightSpeed;
int linearLeftSpeed;
int linearRightSpeed;

int FixSpeed(int rawSpeed)
{
	return 0.0000141626 * (rawSpeed) * (rawSpeed) * (rawSpeed) - 0.00025542 * (rawSpeed) * (rawSpeed) + 0.581583 * (rawSpeed) + 0.092436;
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
	motor[linearLeft] = -linearLeftSpeed;
	motor[linearRight] = linearRightSpeed;
}

void setDriveMotors(int speed, bool invertLeft, bool invertRight)
{
	if (invertLeft)
	{
		//motor[frontLeft] = -speed;
		frontLeftSpeed = -speed;
		backLeftSpeed = -speed;
	}
	else
	{
		//motor[frontLeft] = speed;
		frontLeftSpeed = speed;
		backLeftSpeed = speed;
	}

	if (invertRight)
	{
		//motor[frontRight] = -speed;
		frontRightSpeed = -speed;
		backRightSpeed = -speed;
	}
	else
	{
		//motor[frontRight] = speed;
		frontRightSpeed = speed;
		backRightSpeed = speed;
	}
}

void Stop()
{
	frontRightSpeed = 0;
	frontLeftSpeed = 0;
	backRightSpeed = 0;
	backLeftSpeed = 0;
}

void HandleDriveTrain(int yAxis, int xAxis)
{
	int fixedX = FixSpeed(xAxis);
	int fixedY = FixSpeed(yAxis);
	bool noX = FuzzyEquals(xAxis, 0, 20);

	if (noX)
	{
		frontLeftSpeed = fixedY;
		frontRightSpeed = fixedY;
		backLeftSpeed = fixedY;
		backRightSpeed = fixedY;
	}
	else if (!noX && fixedX > 0)
	{
		// Right
		frontLeftSpeed = fixedX;
		frontRightSpeed = -fixedX;
		backLeftSpeed = fixedX;
		backRightSpeed = -fixedX;
	}
	else if (!noX && fixedX < 0)
	{
		// Left
		frontLeftSpeed = fixedX;
		frontRightSpeed = -fixedX;
		backLeftSpeed = fixedX;
		backRightSpeed = -fixedX;
	}
	else
	{
		frontLeftSpeed = 0;
		frontRightSpeed = 0;
		backLeftSpeed = 0;
		backRightSpeed = 0;
	}
}

// Left positive, right negitive
void Turn(float degree, float speed)
{
		float goal = nMotorEncoder[backRight] + degree;
		nxtDisplayBigTextLine(4, "G: %i", goal);
		bool complete = false;

		if (nMotorEncoder[backRight] < goal && !complete)
		{
			while (nMotorEncoder[backRight] < goal)
			{
				motor[frontRight] = speed;
				motor[backRight] = speed;
				motor[frontLeft] = -speed;
				motor[backLeft] = -speed;
			}
			complete = true;
		}
}

void Drive(float inches, float speed)
{
	float ticks = (ENCODER_TICKS_PER_REVOLUTION / WHEEL_CIRCUMFRENCE) * inches;
	float goal = nMotorEncoder[backRight] + ticks;
	nxtDisplayBigTextLine(4, "G: %i", goal);
	bool complete = false;

	if(nMotorEncoder[backRight] < goal && !complete)
	{
		while(nMotorEncoder[backRight] < goal)
		{
			motor[frontLeft] = speed;
			motor[frontRight] = speed;
			motor[backLeft] = speed;
			motor[backRight] = speed;
		}
		complete = true;
	}

	if(nMotorEncoder[backRight] > goal && !complete)
	{
		while(nMotorEncoder[backRight] > goal)
		{
			// Problem
			motor[frontLeft] = -speed;
			motor[frontRight] = -speed;
			motor[backLeft] = -speed;
			motor[backRight] = -speed;
		}
		complete = true;
	}

	Stop();
}

void HandleLinear(float y)
{
	if (FuzzyEquals(y, 0, 15))
	{
		linearLeftSpeed = 0;
		linearRightSpeed = 0;
	}

	float fixed = FixSpeed(y);

	linearLeftSpeed = fixed;
	linearRightSpeed = -fixed;
}

// TODO: Get an encoder for one of the linear motors and one of the drive train motors
void SetLinearPosition(LinearPosition pos)
{
	switch (pos)
	{
		case LINEAR_30:
		// TODO:
			break;
		case LINEAR_60:
		// TODO:
			break;
		case LINEAR_90:
		// TODO:
			break;
	};
};

/*
void MoveStraight(int speed)
{
	// Might have to invert that
	setDriveMotors(speed, true, false);
}

void HandleDriveTrain(int yAxis, int xAxis)
{
	//nxtDisplayBigTextLine(0, "%i", xAxis);
	int fixedX = FixSpeed(xAxis) * 2;
	//nxtDisplayBigTextLine(0, "%f", fixedX);
	int fixedY = FixSpeed(yAxis);
	//nxtDisplayBigTextLine(0, "%f", fixedY);
	bool noX = FuzzyEquals(xAxis, 0, CONTROLLER_JOY_ZERO_RANGE_MAX);

	// Turning doesn't do what it's meant to, but it works.
	if (noX && !FuzzyEquals(yAxis, 0, CONTROLLER_JOY_ZERO_RANGE_MAX))
	{
		MoveStraight(fixedY);
	}
	else if (!noX && fixedX > 0)
	{
		// Right
	  nxtDisplayBigTextLine(0, "Right");
		frontLeftSpeed += fixedX;
		backLeftSpeed += fixedX;
		frontRightSpeed -= fixedX;
		backRightSpeed -= fixedX;
	}
	else if (!noX && fixedX < 0)
	{
		// Left
		nxtDisplayBigTextLine(0, "Left");
		frontLeftSpeed -= fixedX;
		backLeftSpeed -= fixedX;
		frontRightSpeed += fixedX;
		backRightSpeed += fixedX;
	}
	else
	{
		setDriveMotors(0, false, false);
	}

	UpdateMotors();
}
*/

#endif // REVOLUTION_MOTOR_H
