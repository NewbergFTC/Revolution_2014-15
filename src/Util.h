#ifndef REVOLUTION_UTIL_H
#define REVOLUTION_UTIL_H

typedef struct
{
	float x;
	float y;
}Vector2f;

Vector2f CreateVector2f(float x, float y)
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

#endif /* REVOLUTION_UTIL_H */
