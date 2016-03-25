#include "entity.h"
#ifndef _character_
#define _character_
class character :public entity{
public:
	int pos_x, pos_y, inroom;
};
#endif