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
				printf("\n%s\n%s\n", game_map->room[me->inroom].name, game_map->room[me->inroom].description);
			}
		}
		getchar();
	}
	
	//look order
	if (order == "look"){
		int u = 0;
		if (direction == "here"){
			printf("\n%s\n", game_map->room[me->inroom].description);
		}
		else{
			for (int k = 0; k < 18; k++){
				if (game_map->exit[k].in_room == me->inroom&&game_map->exit[k].way == direct_number){
					printf("\n%s", game_map->exit[k].description);
					u++;
				}
			}
			if (u == 0){
			printf("\nThere's anything there");
			}
		}
		getchar();
	}
	//help order
	if (order == "help"){
		printf("\n\nLook here -> Look this room\nLook + direction -> Look exits\nGo + direction ->Move\nOpen + direction -> Open door\nClose + direction -> Close door\n\n");
		getchar();
	}
	
	//open order
	if (order == "open"){
		for (int k = 0; k < 18; k++){
			if (game_map->exit[k].in_room == me->inroom&&game_map->exit[k].way == direct_number){
				if (game_map->exit[k].door_state == true){
					printf("\nThat door was already open\n");
				}
				if (game_map->exit[k].door_state == false && game_map->exit[k].door){
					for (int t = 0; t < 18; t++){
						if (game_map->exit[k].in_room == game_map->exit[t].to_room&&game_map->exit[t].in_room == game_map->exit[k].to_room){
							game_map->exit[k].door_state = game_map->exit[t].door_state = true;
							}
					}
					printf("\nNow the door is opened!\n");
				}
				else if (game_map->exit[k].door == false){
					printf("\nThere's no door\n");
				}
			}
		}
		getchar();
	}

	//close order
	if (order == "close"){
		for (int k = 0; k < 18; k++){
			if (game_map->exit[k].in_room == me->inroom&&game_map->exit[k].way == direct_number){
				if (game_map->exit[k].door_state == false){
					printf("\nThat door was already close\n");
				}
				if (game_map->exit[k].door_state&& game_map->exit[k].door){
					for (int t = 0; t < 18; t++){
						if (game_map->exit[k].in_room == game_map->exit[t].to_room&&game_map->exit[t].in_room == game_map->exit[k].to_room){
							game_map->exit[k].door_state = game_map->exit[t].door_state = false;
						}
					}
					printf("\nNow the door is closed!\n");
				}
				else if (game_map->exit[k].door == false){
					printf("\nThere's no door\n");
				}
			}
		}
		getchar();
	}	

	//quit order
	if (order == "quit"){
		return 'q';
	}
}