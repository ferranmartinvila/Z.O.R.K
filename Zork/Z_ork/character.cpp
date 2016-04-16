#include"character.h"
#include"map.h"
#include"item.h"
//move instruction
void character::apply_go_instruction(const map& game_map, const vector<string>& instruction){
	if (game_map.exit.buffer[exit_used]->door_state&&inroom != next_room){
		pos_x = direction[0];
		pos_y = direction[1];
		inroom = next_room;
		printf("%s\n%s", game_map.room.buffer[inroom]->name.STR, game_map.room.buffer[inroom]->description.STR);
	}
	else if (game_map.exit.buffer[exit_used]->door_state == false){
		printf("\nThe %s %s door is closed.", instruction.buffer[1].STR, game_map.room.buffer[inroom]->name);
	}
	else printf("There's anything there.");
}

//look instruction
void character::apply_look_instruction(const vector<item*>& object, const map& game_map, const vector<string>& instruction){
	if (instruction.buffer[1] == "here")printf("%s\n%s\n", game_map.room.buffer[inroom]->name.STR, game_map.room.buffer[inroom]->description.STR);
	else if (instruction.buffer[1] == "me")printf("%s\n%s", name.STR, description.STR);
	else if (instruction.buffer[1] == "inventory"){
		for (int n = 0; n < 4; n++){
			if (n<bag.get_size())printf("Cell %i: %s\n", n, bag.buffer[n]->name.STR);
		}
		if(bag.get_size()==0) printf("The inventory is empty.");
	}
	else if (instruction.buffer[1] == "room"&&instruction.buffer[2] == "objects"){
		int j = 8;
		for (int n = 0; n < 8; n++){
				if (object.buffer[n]->location == inroom){
					printf("  -%s\n", object.buffer[n]->name.STR);
			}
				else j--;
		}
		if (j == 0)printf("There's no objects here");
	}
	else if (instruction.buffer[1] == "west" || instruction.buffer[1] == "south" || instruction.buffer[1] == "north" || instruction.buffer[1] == "east"){
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

//pick/drop instruction
void character::apply_pickdrop_instruction(vector<item*>& object, map& game_map, const vector<string>& instruction){
	if (object_focused != -1){

		//pick operator

		if (instruction.buffer[0] == "pick"){
			if (inroom != object.buffer[object_focused]->location&&object.buffer[object_focused]->state == UNKNOWN)printf("This object is in another room!");
			else if (object.buffer[object_focused]->state == EQUIPED || object.buffer[object_focused]->state == UNEQUIPED)printf("You already have this object!");
			else if (object.buffer[object_focused]->location == inroom&&object.buffer[object_focused]->state == UNKNOWN){
				object.buffer[object_focused]->state = UNEQUIPED;
				if (bag.get_size() < bag.get_capacity()){
					bag.push_back(object.buffer[object_focused]);
					printf("Now the %s is in your inventory!", bag.buffer[bag.get_size() - 1]->name.STR);
				}
			}
		}
		else if (bag.get_size() == bag.get_capacity()) printf("Your inventory is full!");


		//drop opetator
		if (instruction.buffer[0] == "drop"){
			if (object.buffer[object_focused]->state == EQUIPED)printf("You have to unequip this object before drop it!");
			else if (object.buffer[object_focused]->state == UNKNOWN)printf("This object is not inside your bag!");
			else{
				object.buffer[object_focused]->location = inroom;
				for (int n = 0; n < 6; n++){
					if (bag.buffer[n]->name == object.buffer[object_focused]->name.STR&&bag.buffer[n]->state == UNEQUIPED){
						if (n == bag.get_size() - 1){
							bag.pop_back();
							n = 6;
						}
						else{
							for (int moves = bag.get_size() - (n + 1); moves > 0; moves--){
								bag.buffer[n] = bag.buffer[n + 1];
								n++;
							}
							bag.pop_back();
							n = 6;
						}
					}
				}
				object.buffer[object_focused]->state = UNKNOWN;
				printf("You drop the %s!", object.buffer[object_focused]->name.STR);
			}
		}
	}
	else printf("Invalid Object");
}

//equip/unequip instruction
void character::apply_equipment_instruction(vector<item*>& object, const vector<string>& instruction){
	if (object_focused != -1){
		if (object.buffer[object_focused]->state != UNKNOWN){
			if (instruction.buffer[0] == "equip"){
				if (object.buffer[object_focused]->state == EQUIPED)printf("This object was equiped before");
				if (object.buffer[object_focused]->state == UNEQUIPED){
					object.buffer[object_focused]->state = EQUIPED;
					equipation = object.buffer[object_focused];
					printf("Now %s is equiped!", equipation->name.STR);
				}
			}
			else
				if (object.buffer[object_focused]->state == EQUIPED){
					if (bag.get_size() < bag.get_capacity()){
						object.buffer[object_focused]->state = UNEQUIPED;
						bag.push_back(equipation);
						printf("%s is now in your inventory!", bag.buffer[bag.get_size() - 1]->name.STR);
					}
					else printf("You need a free cell to put the unequiped item in the inventory");
				}
				else printf("This object is in your bag but not equiped");
		}
		else printf("You don't have this object");
	}
	else printf("Invalid Object");
}