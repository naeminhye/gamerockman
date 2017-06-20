#pragma once
#include "BaseObject.h"

/* ENUMERATIONS */
enum BRIDGE_TYPE {
	// co 4 loai, dau cau ben trai (BRIDGE_LEFT), dau cau ben phai (BRIDGE_RIGHT), 
	// doan cau thang (BRIDGE_STRAIGHT), doan cua gach dut (BRIDGE_DASH)
	BRIDGE_LEFT = -7,
	BRIDGE_RIGHT = -307,
	BRIDGE_STRAIGHT = -107,
	BRIDGE_DASH = -207
};

class Bridge :
	public BaseObject
{
public:

	/* CONSTRUCTOR & DESTRUCTOR */
	Bridge();
	~Bridge();

};

