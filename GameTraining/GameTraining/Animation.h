#pragma once
#include <Windows.h>
#include "GameTime.h"

class Animation
{
public:
	RECT* frames; // mang luu dia chi khung hinh (moi frame la mot hinh chu nhat)
	int frameCount; // so luong khung hinh (frame) trong mot chuyen dong (animation)

	/* CONSTRUCTOR & DESTRUCTOR */
	Animation();
	~Animation();

	void next(int &index); // chuyen den frame tiep theo
};

