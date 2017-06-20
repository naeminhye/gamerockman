#pragma once
#include "BaseObject.h"
class MovableObject : public BaseObject
{
public:
	bool ground;
	FRectangle spaceMove;

	virtual void update();
	virtual void onCollision(FBox* other, int nx, int ny);
	virtual void setWidth(int width);
	virtual void setHeight(int height);
	
	/* CONSTRUCTOR & DESTRUCTOR */
	MovableObject();
	~MovableObject();

};

