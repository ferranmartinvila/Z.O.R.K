#include "entity.h"
#ifndef _character_
#define _character_
class character :public entity{
public:
	int pos_x, pos_y, inroom;
	void Initialize(){
		pos_x = pos_y = inroom = 0;
	}
};
#endif