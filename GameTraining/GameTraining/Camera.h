#pragma once
#include "Config.h"
#include "Texture.h"
#include"FBox.h"
#include"ObjectsFilter.h"
#include "Stage.h"
class Camera: public FBox
{
private:
	static Camera* instance;
public:
	static Camera* getInstance();
	void Transform(float x, float y, float& xRender, float& yRender);
	void update();
	ObjectsFilter objects;

	void onCollision(FBox * other, int nx, int ny);

	bool isIntersect(FRectangle* other);

	void updateLocation();

	/* CONSTRUCTOR & DESTRUCTOR */
	Camera();
	~Camera();

};

