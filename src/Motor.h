#ifndef REVOLUTION_MOTOR_H
#define REVOLUTION_MOTOR_H

#define MOTOR_SPEED_MAX  100
#define MOTOR_SPEED_MIN  -100
#define MOTOR_SPEED_ZERO 0
#define MOTOR_COUNT      8
#define SERVO_COUNT      6	// ish
#define SERVO_POS_MAX    255
#define SERVO_POS_MIN    0

unsigned short motorsToRun[MOTOR_COUNT];
unsigned short motorsToRunCount;
unsigned short motorsRunTime;
unsigned short motorsReturnSpeed;
unsigned short motorsRunSpeed;
bool killMotors;

unsigned short servosToRun[SERVO_COUNT];
unsigned short servosToRunCount;
unsigned short servosAngle;	// I don't need grammer...
unsigned short servosChangeRate;

/* Set:
 * motorsToRun[] with the motors to run, starting at element 0
 * motorsToRunCount with the number of motors to run
 * motorsRunTime to the ammount of time the motors will run
 * motorsRunSpeed to the speed for the motors to run at
 * motorsReturnSpeed to the speed for the motos to return to after running
 */
task runMotors()
{
	killMotors = false;

    unsigned short i;
	for (i = 0; i <= motorsToRunCount - 1; ++i)
	{
		motor[motorsToRun[i]] = motorsRunSpeed;
	}

	for (i = motorsRunTime; i > 0; --i)
	{
		wait1Msec(1);

		if (killMotors)
		{
			stopTask(runMotors);
		}
	}

	for (i = 0; i <= motorsToRunCount - 1; ++i)
	{
		motor[motorsToRun[i]] = motorsReturnSpeed;
	}
};

/* Set:
 * servosToRun[] with the servos to run, starting at element 0
 * servosToRunCount with the number of servos to run
 * servosAngle to the angle for the servos
 * servosChangeRate to the change rate for the servos
 */
task runServos()
{
	unsigned short i;

	for (i = 0; i <= servosToRunCount - 1; ++i)
	{
		servoChangeRate[servosToRun[i]] = servosChangeRate;
	}

	for (i = 0; i <= servosToRunCount - 1; ++i)
	{
		servo[servosToRun[i]] = servosAngle;
	}
}

#endif // REVOLUTION_MOTOR_H
