#include <stdio.h>
#include <cstdlib>
#include "world.h"


int main(){
	world data;
	data.generate_world();
	char option;
	do{
		system("cls");
		printf("Your actual possition is: %s\n\n", data.game_map->room[data.me->inroom].name);
		option = data.enter_action();
		getchar();
	} while (option != 'q');
	return 0;
}