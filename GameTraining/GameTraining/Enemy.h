#pragma once
#include "MovableObject.h"
#include"Rockman.h"
class Enemy :
	 public MovableObject
{
public:
	int healthPoint;
	int maxHealth; 
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

