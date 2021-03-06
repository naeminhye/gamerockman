#include "Camera.h"
#include"Rockman.h"
#include"OuterSpace.h"

Camera* Camera::instance = 0;
Camera* Camera::getInstance(){
	if (instance == 0){
		instance = new Camera();
	}
	return instance;
}
void Camera::onCollision(FBox * other, int nx, int ny)
{
	if (other->collisionType == CT_OUTERSPACE)
	{
		slideHandle();
	}
}

bool Camera::isIntersect(FRectangle * other)
{
	int delta = 50;
	float tempX = this->x - delta;
	float tempY = this->y - delta;
	float tempW = this->width + 2 * delta;
	float tempH = this->height + 2 * delta;

	return ((tempX < other->x + other->width && tempX + tempW > other->x) &&
		(tempY - tempH < other->y && tempY > other->y - other->height));
}

extern float roundToInt(float num);

void Camera::updateLocation()
{
	x = roundToInt(x + dx);
	y = roundToInt(y + dy);
}

Camera::Camera()
{
	this->x = 0;
	this->y = 217;
	this->width = BACKBUFFER_WIDTH;
	this->height = BACKBUFFER_HEIGHT;
	dy = 0;
}


Camera::~Camera()
{
}

void Camera::Transform(float x, float y, float& xRender, float& yRender)
{

	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	matrix._22 = -1;
	matrix._41 = -this->x;
	matrix._42 = this->y;

	D3DXVECTOR3 pos3(x, y, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrix);

	xRender = MatrixResult.x;
	yRender = MatrixResult.y;
}

void Camera::update()
{
	FBox::update();
	dy = 0;
	auto rockman = Rockman::getInstance();
	if (((rockman->getXCenter() + rockman->dx > this->getXCenter()) && rockman->dx > 0) ||
		((rockman->getXCenter() + rockman->dx < this->getXCenter()) && rockman->dx < 0))
		this->dx = rockman->dx;
	else
		dx = 0;

	if (x + dx < Stage::curStage->left() && dx < 0)
	{
		x = Stage::curStage->left();
		dx = 0;
	}

	if (right() + dx > Stage::curStage->right() + 1 && dx > 0)
	{
		x = Stage::curStage->right() - width + 1;
		dx = 0;
	}

	if (rockman->x + rockman->dx < Stage::curStage->left() && rockman->dx < 0)
	{
		rockman->x = Stage::curStage->left();
		rockman->dx = 0;
	}

	if (rockman->right() + rockman->dx > Stage::curStage->right() && rockman->dx > 0)
	{
		rockman->x = Stage::curStage->right() - rockman->width;
		rockman->dx = 0;
	}
}
