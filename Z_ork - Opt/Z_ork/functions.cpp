#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"world.h"
#include"functions.h"

char functions::enter_and_apply_order(world& data){
	//Action data variables

	//array that contain all de phrase characters
	char phrase[40];
	//array with the different words
	char*word[4] = { nullptr, nullptr, nullptr, nullptr };
	//number of words entered by the user
	std::string str[4];

	//Action fractioner & focus
	printf("Enter the next action:");
	//gets all the words together
	gets_s(phrase);
	printf("\n");
	//break the phrase in different strings
	word[0] = strtok(phrase, " ");
	for (int k = 1; k < 4; k++){
		if (word[k - 1] != NULL){
			word[k] = strtok(NULL, " ");
			str[k - 1] = word[k - 1];
		}
	}
	//generates a variable with the number of the room that the player is focused and coords of this room
	int to_room, exit_used;
	int pos_x_copy = data.me->pos_x, pos_y_copy = data.me->pos_y;
	if (str[0] == "go" || str[0] == "look" || str[0] == "open" || str[0] == "close"){
		if (str[1] == "north")pos_y_copy++;
		else if (str[1] == "east")pos_x_copy++;
		else if (str[1] == "south")pos_y_copy--;
		else if (str[1] == "west")pos_x_copy--;
	}
	//calculates the room where you focus the action and the exit between your room and it
	for (int k = 0; k < 10; k++){
		if (data.game_map->room[k].x_cor == pos_x_copy&&data.game_map->room[k].y_cor == pos_y_copy){
			to_room = k;
			k = 9;
		}
		else to_room = data.me->inroom;
	}
	for (int i = 0; i < 9; i++){
		if ((data.game_map->exit[i].room_1 == data.me->inroom || data.game_map->exit[i].room_2 == data.me->inroom) && (data.game_map->exit[i].room_1 == to_room || data.game_map->exit[i].room_2 == to_room)){
			exit_used = i;
		}
	}



	//one word operators(quit, help)

	//quit operator
	if (str[0] == "quit"){
		return 'q';
	}
	//help operator
	else if (str[0] == "help"){
		printf("\nLook here -> Look this room\nLook + direction -> Look exits\nGo + direction ->Move\nOpen + direction + door -> Open door\nClose + direction + door-> Close door");
	}


	//two words operators (go + direction & look + direction)
	else if (str[0] == "go" || str[0] == "look"){

		//go operator
		if (str[0] == "go"){
			if (data.game_map->exit[exit_used].door_state&&data.me->inroom != to_room){
				data.me->pos_x = pos_x_copy;
				data.me->pos_y = pos_y_copy;
				data.me->inroom = to_room;
				printf("%s\n%s", data.game_map->room[data.me->inroom].name, data.game_map->room[data.me->inroom].description);
			}
			else if (data.game_map->exit[exit_used].door_state == false)printf("\nThe door %s is closed.", word[1]);
			else printf("There's anything there.");
		}
		//look operator
		if (str[0] == "look"){
			if (str[1] == "here"){ printf("%s\n%s", data.game_map->room[data.me->inroom].name, data.game_map->room[data.me->inroom].description); }
			else if (str[1] == "me"){ printf("%s\n%s", data.me->name, data.me->description);}
			else{
				if ((data.me->inroom == data.game_map->exit[exit_used].room_2) && (to_room == data.game_map->exit[exit_used].room_1))printf("%s", data.game_map->exit[exit_used].description_2);
				else if ((data.me->inroom == data.game_map->exit[exit_used].room_1) && (to_room == data.game_map->exit[exit_used].room_2))printf("%s", data.game_map->exit[exit_used].description_1);
				else printf("There's nothing there.");
			}
		}
	}

	//three words operators(open + direction + door & close + direction + door)
	else if (str[0] == "open" || str[0] == "close"){
		if (data.game_map->exit[exit_used].door == false){
			printf("There's no door.");
		}
		else if (data.game_map->exit[exit_used].door_state == true){
			//open
			if (str[0] == "open"){
				printf("The door was already open.");
			}
			//close
			if (str[0] == "close"){
				data.game_map->exit[exit_used].door_state = false;
				printf("Now the %s door from %s is closed!", word[1],data.game_map->room[data.me->inroom].name);
			}
		}
		else{
			//open
			if (str[0] == "open"){
				data.game_map->exit[exit_used].door_state = true;
				printf("Now the %s door from %s is open!", word[1], data.game_map->room[data.me->inroom].name);
			}
			//close
			if (str[0] == "close"){
				printf("The door was already closed.");
			}
		}
	}

	//four words operators(pick x from y, drop x, put x inside of y)....
	
	
	
	printf("\n\n");
	return 'g';
}