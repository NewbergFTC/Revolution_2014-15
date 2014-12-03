#ifndef REVOLUTION_MOTOR_H
#define REVOLUTION_MOTOR_H

#define MOTOR_SPEED_MAX  100
#define MOTOR_SPEED_MIN  -100
#define MOTOR_SPEED_ZERO 0
#define MOTOR_COUNT      8
#define SERVO_COUNT      6	// ish
#define SERVO_POS_MAX    255
#define SERVO_POS_MIN    0

bool stopTurn;

void setDriveMotors(int speed, bool invertLeft, bool invertRight)
{
	if (invertLeft)
		motor[frontLeft] = -speed;
	else
		motor[frontLeft] = speed;

	if (invertRight)
		motor[frontRight] = -speed;
	else
		motor[frontRight] = speed;

	if (invertLeft)
		motor[backLeft] = -speed;
	else
		motor[backLeft] = speed;

	if (invertRight)
		motor[backRight] = -speed;
	else
		motor[backRight] = speed;
}

void MoveStraight(int speed)
{
	if (speed > 100)
		speed = 100;
	else if (speed < -100)
		speed = -100;

	// Might have to invert that
	setDriveMotors(speed, true, false);
}

task TurnRightStart()
{
	stopTurn = false;
	while(!stopTurn)
	{
		setDriveMotors(100, false, true);
	}
	setDriveMotors(0, false, false);
	stopTurn = false;
}

task TurnLeft()
{
	stopTurn = false;
	while(!stopTurn)
	{
		setDriveMotors(100, true, false);
	}
	setDriveMotors(0, false, false);
	stopTurn = false;
}

// TODO: After bot is complete, do some math.
void Turn(int degree) {}

#endif // REVOLUTION_MOTOR_H
