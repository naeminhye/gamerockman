#include "Enemy.h"



void Enemy::initDirectionFollowRockman()
{
	if (Rockman::getInstance()->xCenter() > this->xCenter())
		direction = Right;
	else
		direction = Left;
}

Enemy::Enemy()
{
	collisionType = CT_ENEMY;
}


Enemy::~Enemy()
{
}
