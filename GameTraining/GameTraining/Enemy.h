#pragma once
#include "MovableObject.h"
#include"Rockman.h"

enum ITEM_DECISION {
	SMALL_LIFE_ENERGY_D,
	BIG_LIFE_ENERGY_D,
	SMALL_WEAPON_D,
	BIG_WEAPON_D,
	ONE_UP_LIFE_D,
	BONUS_BALL_POINTS_D
};

class Enemy :
	 public MovableObject
{
public:
	int* itemDecisionTable;
	int itemCount;
	void selectItem();
	ITEM_DECISION itemDecision;

	int healthPoint;
	int maxHealth; 
	int points; // diem so Rockman duoc cong khi giet dc enemy
	int attackDamage;	// kha nang tan cong cua Enemy, 
						//luong mau cua Rockman se mat theo thong so nay
	
	virtual bool setHealthPoint(int healthPoint);
	virtual void setDeath();
	void initDirectionFollowRockman(); // TODO: doi ten
	void onIntersect(FBox* other);
	void init();
	void restoreLocation();

	/* CONSTRUCTOR & DESTRUCTOR */
	Enemy();
	~Enemy();

};

