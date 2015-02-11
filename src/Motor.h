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
#define SERVO_LEFT_DOWN (178)
#define SERVO_LEFT_UP (100)
#define SERVO_RIGHT_DOWN (90)
#define SERVO_RIGHT_UP (275)

int frontLeftSpeed;
int frontRightSpeed;
int backLeftSpeed;
int backRightSpeed;
int linearRightSpeed;

int FixSpeed(int rawSpeed)
{
	return 0.0000141626 * (rawSpeed) * (rawSpeed) * (rawSpeed) - 0.00025542 * (rawSpeed) * (rawSpeed) + 0.581583 * (rawSpeed) + 0.092436;
}

void SpinSpinners()
{
	motor[spinnerLeft] = 100;
	motor[spinnerRight] = 100;
}

void StopSpinners()
{
	motor[spinnerLeft] = 0;
	motor[spinnerRight] = 0;
}

void DeployGrabbers()
{
	servo[pullerLeft] = SERVO_LEFT_DOWN;
	servo[pullerRight] = SERVO_RIGHT_DOWN;
}


void RetractGrabbers()
{
	servo[pullerLeft] = SERVO_LEFT_UP;
	servo[pullerRight] = SERVO_RIGHT_UP;
}

void UpdateMotors()
{
	motor[frontLeft] = frontLeftSpeed;
	motor[frontRight] = frontRightSpeed;
	motor[backLeft] = backLeftSpeed;
	motor[backRight] = backRightSpeed;
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

void StopDriveMotors()
{
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backLeft] = 0;
	motor[backRight] = 0;
	frontRightSpeed = 0;
	frontLeftSpeed = 0;
	backRightSpeed = 0;
	backLeftSpeed = 0;
}

void HandleDriveTrain(int yAxis, int xAxis)
{
	int fixedX = FixSpeed(xAxis);
	int fixedY = FixSpeed(yAxis);
	bool noX = FuzzyEquals(xAxis, 0, 40);

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

		if (nMotorEncoder[backRight] > goal && !complete)
		{
			while (nMotorEncoder[backRight] > goal)
			{
				//nxtDisplayBigTextLine(6, "%i", nMotorEncoder[backRight]);
				motor[frontRight] = -speed;
				motor[backRight] = -speed;
				motor[frontLeft] = speed;
				motor[backLeft] = speed;
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
			nxtDisplayBigTextLine(2, "%i", nMotorEncoder[backRight]);
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
			nxtDisplayBigTextLine(2, "%i", nMotorEncoder[backRight]);
			motor[frontLeft] = -speed;
			motor[frontRight] = -speed;
			motor[backLeft] = -speed;
			motor[backRight] = -speed;
		}
		complete = true;
	}

	StopDriveMotors();
}

void HandleLinear(float y)
{
	if (FuzzyEquals(y, 0, 15))
	{
		linearRightSpeed = 0;
	}

	float fixed = FixSpeed(y);

	linearRightSpeed = -fixed;
}

#endif // REVOLUTION_MOTOR_H
