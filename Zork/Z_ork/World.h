#include"string.h"
#include "character.h"
#include "map.h"
#include "item.h"
#include"dinamic_array.h"
#ifndef _world_
#define _world_
class world{
public:
	map*game_map = nullptr;
	character*me = nullptr;
	vector<item*>object;
	world(){
		game_map = new map;
		me = new character;
	}
	~world(){
		delete me;
		delete game_map;
	}
	void Initialize();
	char apply_order(vector<string>& );
	void get_instruction(vector<string>&);
};
#endif
