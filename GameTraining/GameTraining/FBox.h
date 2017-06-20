#pragma once
#include "FRectangle.h"
#include"Config.h"

#pragma region ENUMERATIONS
enum COLLISION_TYPE
{
	// Cac loai va cham
	CT_STAIR,
	CT_GROUND,
	CT_ENEMY,
	CT_ITEM,
	CT_BULLET,
	CT_ROCKMAN,
	CT_OUTERSPACE,
	CT_NONE,
	CT_DOOR,
	CT_TRUNDLE,
	CT_BRIDGE
};
#pragma endregion


class FBox : public FRectangle
{
public:
	bool alive;
	float dx, dy;
	float vx, vy, ax, ay;
	COLLISION_TYPE collisionType;

	virtual void updateLocation();

	bool isChangeDelta; // ktra xem xet va cham cua M voi nhiu S, M co thay doi dx dy hay ko
	bool isCollision; // ktra xem trong vong lap M co va cham voi bat cu thu gi ko

	virtual void update();
	void updateMove();

	virtual void onCollision(FBox* other, int nx, int ny); //xu ly va cham

	virtual void onIntersect(FBox* other);
	
	void slideHandle();

	/* CONSTRUCTOR & DESTRUCTOR */
	FBox();
	~FBox();

};

