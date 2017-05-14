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
	RM_ACTION_COUNT
};

enum BLINK_ACTIVITY
{
	BLINK_OPEN,
	BLINK_CLOSE
};

class Rockman :
	public MovableObject
{
	//phan tren rockman co va cham voi cau thang nao hay k
	bool isIntersectStair;
	BLINK_ACTIVITY blinkActivity;
	int health;
public:
	void setHealth(int health);
	ROCKMAN_TYPE rm_type;
	ROCKMAN_ACTION rm_action;
	static Rockman* instance;
	static Rockman* getInstance();

	/* Constructor & Destructor */
	Rockman();
	~Rockman();

	void update();
	void render();

	MGMGameTime delay;
	void onCollision(FBox* other, int nx, int ny);

	void updateBlink();
	DelayTime blinkDelay;
	DelayTime shootDelay;

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

	DelayTime rmBulletDelay;
	void updateAttack();
	void onLastFrameAnimation();
	bool onAttack;
	bool isAttack();

};

