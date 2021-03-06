#pragma once
#include "MovableObject.h"
#include"Keyboard.h"
#include "DelayTime.h"
#include"RockmanBullet.h"

enum ROCKMAN_TYPE
{
	RMT_NORMAL,
	RMT_CUTMAN,
	RMT_GUSTMAN
};

enum ROCKMAN_ACTION
{
	RM_STAND,
	RM_BLINK,
	RM_PREPARE_RUN,
	RM_RUN,
	RM_JUMP,
	RM_STAIR,
	RM_END_STAIR,
	RM_STAND_SHOOT,
	RM_RUN_SHOOT,
	RM_STAIR_SHOOT,
	RM_JUMP_SHOOT,
	RM_INJURE,
	RM_DEATH,
	RM_ACTION_COUNT,
	RM_TELEPORT = 39,
	RM_EXPLOSE 
};

enum BLINK_ACTIVITY
{
	BLINK_OPEN,
	BLINK_CLOSE
};

enum ROCKMAN_DEATH_ACTIVITY {
	ON_DEATH,
	DEATH_FINISH
};

class Rockman :
	public MovableObject
{
	//phan tren rockman co va cham voi cau thang nao hay k
	bool isIntersectStair;
	BLINK_ACTIVITY blinkActivity;

public:
#pragma region LIFE 
	int health;
	int maxHealth;
	void setHealth(int health);
	bool onDeath;
	DelayTime deathDelay;
	void updateDeath();
	ROCKMAN_DEATH_ACTIVITY rm_death_activity;
	int life;
	void setLife(int life);

#pragma endregion

	int scores;
	void setScores(int scores);
	int bonusPoint;
	int clearPoint;
	
	ROCKMAN_TYPE rm_type;
	ROCKMAN_ACTION rm_action;
	static Rockman* instance;
	static Rockman* getInstance();
	
	void update();
	void render();
	void setWidth(int width);

	GameTime delay;
	void onCollision(FBox* other, int nx, int ny);

	void updateBlink();
	DelayTime blinkDelay;

#pragma region STAIR

	//dia chi cau thang dang va cham voi rockman
	BaseObject* stairIntersect;
	void setIsIntersectStair(bool isIntersectStair);
	bool onStair;
	void setOnStair(bool onStair);
	void updateStair();

#pragma endregion

	void setAction(int actionValue);

#pragma region STAGES

	bool checkChangeNextStage(List<Stage*>* stages);
	bool checkChangePrevStage(List<Stage*>* stages);

#pragma endregion

#pragma region ATTACK
	DelayTime rmBulletDelay;
	DelayTime shootDelay;
	void updateAttack();
	void onLastFrameAnimation();
	bool onAttack;
	bool isAttack();
#pragma endregion


#pragma region TELEPORT

	bool onTeleport;
	void updateTeleport();

#pragma endregion

	void updateRockmanType();

#pragma region INJURY
	GameTime disappearTime;
	bool isDisappear;
	void updateFlicker(); // khi trung dan

	bool isRecoil;
	bool onInjury;
	void updateInjury();
	DelayTime injuryDelay, flickeringDelay;
#pragma endregion

	bool onLand;
	void updateLocation();

	void initRockman();

	/* CONSTRUCTOR & DESTRUCTOR */
	Rockman();
	~Rockman();

};

