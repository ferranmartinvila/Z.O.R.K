#ifndef _world_
#define _world_
#include "string.h"
#include "string.h"
#include <string.h>
#include <stdio.h>
#include "rooms.h"
#include "chest.h"
#include "exits.h"
#include "item.h"
#include "vector.h"
#include "character.h"
#include "trader.h"
#include "soldier.h"
#include "thief.h"
#include "merchant.h"
#include "talker.h"

#define MAX_ENTITY 47

enum Direction{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NONE
};

class world{
public:
	// me pointer
	character*me = nullptr;
	// all game data (me included)
	vector<entity*>game_data;
	
	
	//world constructor
	world(){
		me = new character;
	}
	//world destructor
	~world(){
		while (game_data.empty()==false)
		{
			game_data.pop_back();
		}
		game_data.clean();
	}
	//initialize word function
	void Initialize();
	//apply the order the the user enter 
	bool apply_order(vector<string>& );
	//read the order that the user enter
	void get_instruction(vector<string>&);
	//reset game
	bool reset_game();
};
extern world*game;
#endif
