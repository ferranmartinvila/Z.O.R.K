#include"character.h"
#include"map.h"

//move instruction
void character::apply_go_instruction(const map& game_map, const vector<string>& instruction){
	if (game_map.exit.buffer[exit_used]->door_state&&inroom != next_room){
		pos_x = direction[0];
		pos_y = direction[1];
		inroom = next_room;
		printf("%s\n%s", game_map.room.buffer[inroom]->name, game_map.room.buffer[inroom]->description);
	}
	else if (game_map.exit.buffer[exit_used]->door_state == false){
		printf("\nThe %s %s door is closed.", instruction.buffer[1].STR, game_map.room.buffer[inroom]->name);
	}
	else printf("There's anything there.");
}

//look instruction
void character::apply_look_instruction(const vector<item*>& object, const map& game_map, const vector<string>& instruction){
	if (instruction.buffer[1] == "here")printf("%s\n%s\n", game_map.room.buffer[inroom]->name, game_map.room.buffer[inroom]->description);
	else if (instruction.buffer[1] == "me")printf("%s\n%s", name, description);
	else if (instruction.buffer[1] == "inventory"){
		for (int n = 0; n < 4; n++){
			if (bag.buffer[n].name.STR != nullptr)printf("Cell %i: %s\n", n, bag.buffer[n].name.STR);
		}
	}
	else if (instruction.buffer[1] == "room"&&instruction.buffer[2] == "objects"){
		printf("Objects:\n");
		for (int n = 0; n < 9; n++){
			if (object.buffer[n]->location == inroom){
				printf("%s\n", object.buffer[n]->name.STR);
			}
		}
	}
	else{
		if ((inroom == game_map.exit.buffer[exit_used]->room_2) && (next_room == game_map.exit.buffer[exit_used]->room_1))printf("%s", game_map.exit.buffer[exit_used]->description_2.STR);
		else if ((inroom == game_map.exit.buffer[exit_used]->room_1) && (next_room == game_map.exit.buffer[exit_used]->room_2))printf("%s", game_map.exit.buffer[exit_used]->description_1.STR);
		else printf("There's nothing there.");
	}
}

//open/close instruction
void character::apply_door_instruction(map& game_map, const vector<string>& instruction){
	if (game_map.exit.buffer[exit_used]->door == false){
		printf("There's no door.");
	}
	else if (game_map.exit.buffer[exit_used]->door_state == true){
		//open
		if (instruction.buffer[0] == "open"){
			printf("The door was already open.");
		}
		//close
		if (instruction.buffer[0] == "close"){
			game_map.exit.buffer[exit_used]->door_state = false;
			printf("Now the %s door from %s is closed!", instruction.buffer[1].STR, game_map.room.buffer[inroom]->name.STR);
		}
	}
	else{
		//open
		if (instruction.buffer[0] == "open"){
			game_map.exit.buffer[exit_used]->door_state = true;
			printf("Now the %s door from %s is open!", instruction.buffer[1].STR, game_map.room.buffer[inroom]->name.STR);
		}
		//close
		if (instruction.buffer[0] == "close"){
			printf("The door was already closed.");
		}
	}
}

//pick/drop instruction in progress
void character::apply_pickdrop_instruction(vector<item*>& object, map& game_map, const vector<string>& instruction){
	//object where player focus the action 
	int object_focused;
	//the first free cell int the inventory
	int free_cell;
	//gets object_focused and free_cell
	for (int n = 0; n < 4; n++){
		if (instruction.buffer[1] == object.buffer[n]->name.STR)object_focused = n;
		if (bag.buffer[n].name.STR == nullptr)free_cell = n;
		else free_cell = -1;
	}

	//pick operator
	if (instruction.buffer[0] == "pick"){
		object.buffer[object_focused]->location = bag.buffer[free_cell].location;
		//bag.buffer[free_cell] = object.buffer[object_focused];
		printf("Now the %s is in your inventory!", bag.buffer[free_cell].name.STR);
	}
	else printf("Your inventory is full!");
	//drop opetator
	if (instruction.buffer[0] == "drop"){
		object.buffer[object_focused]->location = inroom;
		for (int n = 0; n <4; n++){
			if (bag.buffer[n].name == object.buffer[object_focused]->name.STR){
				bag.buffer[n].name = nullptr;
				bag.buffer[n].description = nullptr;
			}
		}
		printf("You drop the %s!", object.buffer[object_focused]->name.STR);
	}
}