#define MOTOR_SPEED_MAX  100
#define MOTOR_SPEED_MIN  -100
#define MOTOR_SPEED_ZERO 0
#define MOTOR_COUNT      6
#define SERVO_POS_MAX    255
#define SERVO_POS_MIN    0

typedef struct
{
	tMotor varMotor;
 short speed;
}RunnableMotor;

RunableMotor createRunnableMotor(tMotor m, short s)
{
	RunnableMotor result;
	result.varMotor = m;
	result.speed = s;

	return result;
};

RunnableMotor motorFrontLeft   = createRunnableMotor(frontLeft,   0);
RunnableMotor motorFrontRight  = createRunnableMotor(frontRight,  0);
RunnableMotor motorBackLeft    = createRunnableMotor(backLeft,    0);
RunnableMotor motorBackRight   = createRunnableMotor(backRight,   0);
RunnableMotor motorLinearLeft  = createRunnableMotor(linearLeft,  0);
RunnableMotor motorLinearRight = createRunnableMotor(linearRight, 0);

// Motor stuff
RunnableMotor motorsToRun[MOTOR_COUNT];
unsigned short motorsToRunCount;
unsigned short motorRunTime;

task runMotors()
{
	unsigned short i;

	for (i = 0; i < motorsToRunCount; ++i)
	{
		motor[motorsToRun[i].varMotor] = motorsToRun[i].speed;
	}

	stopTask(runMotors);
};

task runMotorsForTime()
{
	startTask(runMotors);
	wait1Msec(motorRunTime);
	stopTask(runMotorsForTime);
};
