#ifndef REVOLUTION_UTIL_H
#define REVOLUTION_UTIL_H

#include <math>	// Can I do this in RobotC ?

/*
 * Vector2f
 */
typedef struct
{
	float x;
	float y;
}Vector2f;

Vector2f Vector2fMake(float x, float y)
{
	return(Vector2f){x, y};
};

Vector2f Vector2fAdd(Vector2f a, Vector2f b)
{
	Vector2f result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;

	return result;
};

Vector2f Vector2fSubtract(Vector2f a, Vector2f b)
{
	Vector2f result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;

	return result;
};

const Vector2f ZeroVector2f = Vector2fMake(0, 0);

/*
 * General Helpers
 */
const float Epsilon = 0.000001f; // A very tiny number (10e-6)

bool FuzzyEquals(float value1, float value2, float epsilon=Epsilon) // Again, can I do that in RobotC ? c++ only ? I forget
{
	float a = value1 - value2;

	if (fabs(a) < epsilon)
	{
		return true;
	}

	return false;
}

bool FuzzyEquals(Vector2f vec1, Vector2f vec2, float epsilon=Epsilon)
{
	if ((FuzzyEquals(vec1.x, vec2.x, epsilon)) && (FuzzyEquals(vec1.y, vec2.y, epsilon)))
	{
		return true;
	}

	return false;
}

#endif /* REVOLUTION_UTIL_H */
