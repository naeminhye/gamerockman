#include "Collision.h"
#include<iostream>
#include<string>

using namespace std;


FBox * Collision::GetSweptBroadPhaseBox(FBox * box)
{
	FBox* bigBox = new FBox();
	bigBox->x = box->dx > 0 ? box->x : (box->x + box->dx);
	bigBox->y = box->dy > 0 ? (box->y + box->dy) : box->y;
	bigBox->width = box->dx > 0 ? (box->width + box->dx) : (box->width - box->dx);
	bigBox->height = box->dy > 0 ? (box->height + box->dy) : (box->height - box->dy);
	return bigBox;
}

bool Collision::AABBCheck(FRectangle * M, FRectangle * S)
{
	return ((M->left() < S->right() && M->right() > S->left()) &&
		(M->bottom() < S->top() && M->top() > S->bottom()));
}

float Collision::SweptAABB(FBox * M, FBox * S, int & normalX, int & normalY)
{
	normalX = 0;
	normalY = 0;
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	if (M->dx > 0.0f)
	{
		xInvEntry = S->x - (M->x + M->width);
		xInvExit = (S->x + S->width) - M->x;
	}
	else
	{
		xInvEntry = (S->x + S->width) - M->x;
		xInvExit = S->x - (M->x + M->width);
	}

	if (M->dy > 0.0f)
	{
		yInvEntry = S->y - (M->y + M->height);
		yInvExit = (S->y + S->height) - M->y;
	}
	else
	{
		yInvEntry = (S->y + S->height) - M->y;
		yInvExit = S->y - (M->y + M->height);
	}

	float xEntry, yEntry;
	float xExit, yExit;

	if (M->dx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / M->dx;
		xExit = xInvExit / M->dx;
	}

	if (M->dy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / M->dy;
		yExit = yInvExit / M->dy;
	}

	float entryTime = MAX(xEntry, yEntry);
	float exitTime = MIN(xExit, yExit);

	//if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	if (entryTime > exitTime || xEntry > 1.0f || yEntry > 1.0f)
	{ // ko xay ra va cham
		normalX = 0;
		normalY = 0;
		return 1.0f;
	}
	else
	{ // xay ra va cham
	  // lay huong va cham
		if (M->left() < S->right() && M->right() > S->left())
		{
			if (M->dy > 0)
				normalY = -1;
			else
				normalY = 1;
			normalX = 0;
			return entryTime;
		}

		if (M->top() < S->bottom() && M->bottom() > S->top())
		{
			if (M->dx > 0)
				normalX = -1;
			else
				normalX = 1;
			normalY = 0;
		}
		return entryTime;
	}
}

void Collision::CheckCollision(FBox * M, FBox * S)
{
	FBox* broadPhaseBox = GetSweptBroadPhaseBox(M);
	if (AABBCheck(broadPhaseBox, S))
	{
		delete broadPhaseBox; //*********************
		if (AABBCheck(M, S))
		{
			M->onIntersect(S);
			S->onIntersect(M);
			return;
		}
		int normalX = 0, normalY = 0;
		float sweptTime = SweptAABB(M, S, normalX, normalY);
		//if (sweptTime < 1)
		{
			normalX = 0;
			normalY = 0;
			if (M->left() < S->right() && M->right() > S->left())
			{
				if (M->dy > 0)
					normalY = -1;
				else
					normalY = 1;
			}
			else if(M->bottom() < S->top() && M->top() > S->bottom())
			{
				if (M->dx > 0)
					normalX = -1;
				else
					normalX = 1;
			}

			//chac chan co va cham
			M->isCollision = true;
			//xu ly va cham
			M->onCollision(S, normalX, normalY);
			S->onCollision(M, normalX, normalY);

		}

		return;
	}
	delete broadPhaseBox;
}
#include<Windows.h>

void Collision::PreventMoving(FBox * M, FBox * S)
{
	//OutputDebugString(((string)"ok" + "\n").c_str());
	
	//chac chan co va cham
	if (M->top() > S->bottom() && M->bottom() < S->top())
	{
		if (M->dx > 0)
		{
			M->isChangeDelta = true;
			M->dx = S->left() - M->right() - 1;
			return;
		}
		else
		{
			M->isChangeDelta = true;
			M->dx = S->right() - M->left() + 1;
			return;
		}
	}
	if (M->right() > S->left() && M->left() < S->right())
	{
		if (M->dy > 0)
		{
			M->isChangeDelta = true;
			M->dy = S->bottom() - M->top() - 1;
			return;
		}
		else
		{
			M->isChangeDelta = true;
			M->dy = S->top() - M->bottom() + 1;
			return;
		}
	}
}

Collision::Collision()
{
}


Collision::~Collision()
{
}