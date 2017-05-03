#pragma once
#include "BaseObject.h"
class MovableObject : public BaseObject
{
public:
	bool ground;
	FRectangle spaceMove;
	virtual void update();
	virtual void onCollision(FBox* other, int nx, int ny);
	void setWidth(int width);
	void setHeight(int height);
	MovableObject();
	~MovableObject();
};

