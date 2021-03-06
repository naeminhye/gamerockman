#pragma once
class FRectangle
{
public:
	float x, y;
	float width, height;

	/* CONSTRUCTOR & DESTRUCTOR */
	FRectangle();
	~FRectangle();

	float left();
	float right();
	float top();
	float bottom();

	float getXCenter();
	float getYCenter();

};

