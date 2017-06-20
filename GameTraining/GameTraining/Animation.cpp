#include "Animation.h"

void Animation::next(int &index)
{
	index++;
	if (index >= frameCount)
		index = 0; // animation cua doi tuong chuyen dong lap lai
}

/* CONSTRUCTOR & DESTRUCTOR */
Animation::Animation()
{
}

Animation::~Animation()
{
}
