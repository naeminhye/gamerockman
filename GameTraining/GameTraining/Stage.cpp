#include "Stage.h"

Stage* Stage::curStage = 0;

void Stage::setLocation(int camX, int camY, int rmX, int rmY)
{
	cameraBeginX = camX;
	cameraBeginY = camY;
	rmBeginX = rmX;
	rmBeginY = rmY;
}

Stage::Stage(ifstream &fs)
{
	fs >> index >> x >> y >> width >> height >> cameraBeginX >> cameraBeginY >> rmBeginX >> rmBeginY;
	
}

Stage::~Stage()
{
}
