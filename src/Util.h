#ifndef REVOLUTION_UTIL_H
#define REVOLUTION_UTIL_H

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

#endif /* REVOLUTION_UTIL_H */
