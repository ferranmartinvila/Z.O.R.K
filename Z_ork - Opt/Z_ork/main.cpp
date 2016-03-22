#include"World.h"
#include"functions.h"
int main(){
	//structs data
	world data;
	functions calculate;
	//initialize game data
	data.me->Initialize();
	data.game_map->Initialize();
	//game bucle
	char option = 0;
	while (option != 'q'){
		option = calculate.enter_and_apply_order(data);
	}
	//deletes the game data before close the progam
	return 0;
}