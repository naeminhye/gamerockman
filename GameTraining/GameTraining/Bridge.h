#pragma once
#include "BaseObject.h"
enum BRIDGE_TYPE {
	BRIDGE_END = -7,
	BRIDGE_STRAIGHT = -107,
	BRIDGE_DASH = -207
};

class Bridge :
	public BaseObject
{
public:
	Bridge();
	~Bridge();
};

