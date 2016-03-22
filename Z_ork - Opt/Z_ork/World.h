#include <iostream>
#include "character.h"
#include "map.h"

#ifndef _world_
#define _world_
class world{
public:
	map*game_map = nullptr;
	character*me = nullptr;
	world(){
		game_map = new map;
		me = new character;
	}
	~world(){
		delete me;
		delete game_map;
	}
};
#endif
