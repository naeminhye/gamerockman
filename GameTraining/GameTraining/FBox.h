#pragma once
#include "FRectangle.h"
#include"Config.h"

enum COLLISION_TYPE
{
	CT_STAIR,
	CT_GROUND,
	CT_ENEMY,
	CT_ITEM, 
	CT_BULLET,
	CT_ROCKMAN,
	CT_OUTERSPACE, 
	CT_NONE,
	CT_DOOR
};

class FBox : public FRectangle
{
public:
	bool alive;
	COLLISION_TYPE collisionType;
	float dx, dy;

	float vx, vy, ax, ay;

	virtual void updateLocation();

	bool isChangeDelta; // ktra xem xet va cham cua M voi nhiu S, M co thay doi dx dy hay ko
	bool isCollision; // ktra xem trong vong lap M co va cham voi bat cu thu gi ko

	virtual void update();

	void updateMove();

	//xu ly va cham
	virtual void onCollision(FBox* other, int nx, int ny);

	virtual void onIntersect(FBox* other);
	
	void slideHandle();

	FBox();
	~FBox();
};

