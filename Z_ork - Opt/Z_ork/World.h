#include "character.h"
#include "map.h"

struct world{
	map*game_map = nullptr;
	character*me = nullptr;
	world(){
		game_map = new map;
		me = new character;
	}
	~world(){
		delete game_map;
		delete me;
	}
	void generate_world();
	char enter_action();
};