#ifndef _world_
#define _world_
#include"string.h"
#include "character.h"
#include "map.h"
#include "item.h"
#include "vector.h"
class world{
public:
	map*game_map = nullptr;
	character*me = nullptr;
	vector<item*>object;
	//world constructor
	world(){
		game_map = new map;
		me = new character;
	}
	//world destructor
	~world(){
		object.clean();
	}
	//initialize word function
	void Initialize();
	//apply the order the the user enter 
	bool apply_order(vector<string>& );
	//read the order that the user enter
	void get_instruction(vector<string>&);
};
#endif
