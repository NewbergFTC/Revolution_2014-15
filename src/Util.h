#ifndef REVOLUTION_UTIL_H
#define REVOLUTION_UTIL_H

/*
 * Vector2f
 */
typedef struct
{
	float x;
	float y;
} Vector2f;

/*
Vector2f Vector2fMake(float x, float y)
{
	Vector2f result;
	result.x = x;
	result.y = y;

	return result;
};
*/

/*
 * General Helpers
 */
const float Epsilon = 0.000001; // A very tiny number (10e-6)

bool FuzzyEquals(float value1, float value2, float epsilon=Epsilon)
{
	float a = value1 - value2;

	if (abs(a) < epsilon)
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
