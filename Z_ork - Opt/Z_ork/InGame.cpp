#include <stdio.h>
#include <iostream>
#include "World.h"
char world::enter_action(){
	char first_word[5], second_word[5], third_word[5];
	int direct_number;
	printf("Enter your order: ");
	
	//read first word
	scanf_s("%s", &first_word);
	std::string order(first_word);
	
	//read/generate second word if its necessary
	if ((order != "help"&&order!="quit")){
		scanf_s("%s", &second_word);
	}
	std::string direction(second_word);
	
	//transfrom string to number
	if (direction == "north"){
		direct_number = 0;
	}
	else if (direction == "east"){
		direct_number = 1;
	}
	else if (direction == "south"){
		direct_number = 2;
	}
	else if(direction == "west"){
		direct_number = 3;
	}
	
	//read/generate third word if its necessary
	if (order == "open" || order == "close"){
		scanf_s("%s", &third_word);
	}
	std::string obstacle(third_word);
	
	//go order
	if (order == "go"){
		for (int k = 0; k < 18; k++){
			if (me->inroom == game_map->exit[k].in_room){
				if (game_map->exit[k].door&&game_map->exit[k].door_state || game_map->exit[k].door == false){
					if (direct_number == 0 && game_map->exit[k].way == 0){ me->y++; }
					if (direct_number == 2 && game_map->exit[k].way == 2){ me->y--; }
					if (direct_number == 1 && game_map->exit[k].way == 1){ me->x++; }
					if (direct_number == 3 && game_map->exit[k].way == 3){ me->x--; }
				}
			}
		}
		for (int k = 0; k < 10; k++){
			if (game_map->room[k].x_cor == me->x&&game_map->room[k].y_cor == me->y){
				me->inroom = k;
			}
		}
	}
	
	//look order
	if (order == "look"){
		for (int k = 0; k < 18; k++){
			if (game_map->exit[k].in_room==me->inroom&&game_map->exit[k].way==direct_number){
				printf("%s", game_map->exit[k].description);
			}
		}
		if (direction == "here"){
		printf("%s\n", game_map->room[me->inroom].description);
	}
	
	//help order
	if (order == "help"){
		printf("Look -> Look this room\nLook + direction -> Look exits\nGo + direction ->Move\nOpen + direction -> Open door\nClose + direction -> Close door\n\n");
		getchar();
	}
	
	//open order
	if (order == "open"){
		for (int k = 0; k < 18; k++){
			if (game_map->exit[k].door_state == NULL&&game_map->exit[k].in_room == me->inroom&&game_map->exit[k].way == direct_number){
				printf("\nThere's no door\n");
			}
			else if (game_map->exit[k].door_state&&game_map->exit[k].in_room == me->inroom&&game_map->exit[k].way == direct_number&&game_map->exit[k].door_state==true){
				printf("\nThat door was already open\n");
			}
			else if (me->inroom == game_map->exit[k].in_room && direct_number == game_map->exit[k].way){
				game_map->exit[k].door_state = game_map->exit[k].door_state = true;
				printf("\nThe  door is open now!\n");
				}
			}
		}
	}
	
		/*if (me->inroom == game_map->gone[2].in_room&&direct_number == game_map->gone[2].way&&game_map->gone[2].door){
			game_map->gone[2].door_state = true;
			printf("The door is closed.");
		}
		else{
			printf("There's no door");
		}
		if (direction == "north"&&game_map->room[me->inroom].exit[0].acces&&game_map->room[me->inroom].exit[0].door == false){
			game_map->room[me->inroom].exit[0].door = true;
			printf("Now the north door from the %s is open!", game_map->room[me->inroom].name);
		}
		else if (direction == "south"&&game_map->room[me->inroom].exit[2].acces&&game_map->room[me->inroom].exit[2].door == false){
			game_map->room[me->inroom].exit[2].door = true;
			printf("Now the south door from the %s is open!", game_map->room[me->inroom].name);
		}
		else if (direction == "east"&&game_map->room[me->inroom].exit[1].acces&&game_map->room[me->inroom].exit[1].door == false){
			game_map->room[me->inroom].exit[1].door = true;
			printf("Now the east door from the %s is open!", game_map->room[me->inroom].name);
		}
		else if (direction == "west"&&game_map->room[me->inroom].exit[3].acces&&game_map->room[me->inroom].exit[3].door == false){
			game_map->room[me->inroom].exit[3].door = true;
			printf("Now the west door from the %s is open!", game_map->room[me->inroom].name);
		}*/
	/*
	//close order
	if (order == "close"){
		if (direction == "north"&&game_map->room[me->inroom].exit[0].acces&&game_map->room[me->inroom].exit[0].door){
			game_map->room[me->inroom].exit[0].door = false;
			printf("Now the north door from the %s is close!", game_map->room[me->inroom].name);
		}
		else if (direction == "south"&&game_map->room[me->inroom].exit[2].acces&&game_map->room[me->inroom].exit[2].door){
			game_map->room[me->inroom].exit[2].door = false;
			printf("Now the south door from the %s is close!", game_map->room[me->inroom].name);
		}
		else if (direction == "east"&&game_map->room[me->inroom].exit[1].acces&&game_map->room[me->inroom].exit[1].door){
			game_map->room[me->inroom].exit[1].door = false;
			printf("Now the east door from the %s is close!", game_map->room[me->inroom].name);
		}
		else if (direction == "west"&&game_map->room[me->inroom].exit[3].acces&&game_map->room[me->inroom].exit[3].door){
			game_map->room[me->inroom].exit[3].door = false;
			printf("Now the west door from the %s is close!", game_map->room[me->inroom].name);
		}
		else {
			printf("There's just a wall");
		}
		getchar();
	}
	*/
	//quit order
	if (order == "quit"){
		return 'q';
	}
}