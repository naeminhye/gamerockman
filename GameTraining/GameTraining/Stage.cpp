#include "Stage.h"

Stage* Stage::curStage = 0;

Stage::Stage(ifstream &fs)
{
	fs >> index >> x >> y >> width >> height;
	
}

Stage::~Stage()
{
}
