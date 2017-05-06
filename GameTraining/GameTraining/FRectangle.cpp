#include "FRectangle.h"



FRectangle::FRectangle()
{
}


FRectangle::~FRectangle()
{
}

float FRectangle::left()
{
	return x;
}

float FRectangle::right()
{
	return x + width - 1;
}

float FRectangle::top()
{
	return y;
}

float FRectangle::bottom()
{
	return y - height + 1;
}

float FRectangle::getXCenter()
{
	return x + width/2;
}

float FRectangle::getYCenter()
{
	return y - height / 2;
}
