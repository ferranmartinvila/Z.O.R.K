#include "character.h"
#include "map.h"
#include "item.h"
#include "chest.h"

//move instruction
void character::apply_go_instruction(const map& game_map, const vector<string>& instruction){
	if (next_room != -1){
		if (game_map.exits.buffer[exit_used]->door_state&&inroom != next_room){
			pos_x = direction[0];
			pos_y = direction[1];
			inroom = next_room;
			printf("%s\n%s", game_map.rooms.buffer[inroom]->name.get_string(), game_map.rooms.buffer[inroom]->description.get_string());
		}
		else if (game_map.exits.buffer[exit_used]->door_state == false){
			printf("\nThe %s %s door is closed.", instruction.buffer[1].get_string(), game_map.rooms.buffer[inroom]->name);
		}
		//if no room concides with the direction is significates that there's no
		else printf("There's anything there.");
	}
	//if next_room is -1 it significates that the direction word has been entered wrongly
	else printf("Invalid direction");
}

//look instruction
void character::apply_look_instruction(vector<item*>& object, const map& game_map,vector<string>& instruction){
	
	//look room operator
	if (instruction.buffer[1] == "room"&&instruction.get_size() == 2)printf("%s\n%s", game_map.rooms.buffer[inroom]->name.get_string(), game_map.rooms.buffer[inroom]->description.get_string());
	
	//look me operator
	else if (instruction.buffer[1] == "me")printf("%s\n%s\nSTATS:\nlive[%i]\nattack[%i]", name.get_string(), description.get_string(), live, attack);
	
	//look inventory operator
	else if (instruction.buffer[1] == "inventory"){
		for (int n = 0; n < 4; n++){
			if (n<bag.get_size())printf("Cell %i: %s\n", n, bag.buffer[n]->name.get_string());
		}
		if(bag.get_size()==0) printf("The inventory is empty.");
	}
	
	//look room objects operator
	else if (instruction.buffer[1] == "room"&&instruction.buffer[2] == "objects"){
		int j = 8;
		for (int n = 0; n < 8; n++){
			if (object.buffer[n]->location == inroom&&object.buffer[n]->state!=INCHEST){
				printf("  -%s\n", object.buffer[n]->name.get_string());
			}
			else j--;
		}
		for (int k = 0; k < 2; k++){
			if (game_map.chests.buffer[k]->location == inroom){
				printf("  -Chest\n");
				j++;
			}
		}
		if (j == 0)printf("There's no objects here");
	}
	
	//look exit operator
	else if (instruction.buffer[1] == "west" || instruction.buffer[1] == "south" || instruction.buffer[1] == "north" || instruction.buffer[1] == "east"){
		if ((inroom == game_map.exits.buffer[exit_used]->room_2) && (next_room == game_map.exits.buffer[exit_used]->room_1))printf("%s", game_map.exits.buffer[exit_used]->description_2.get_string());
		else if ((inroom == game_map.exits.buffer[exit_used]->room_1) && (next_room == game_map.exits.buffer[exit_used]->room_2))printf("%s", game_map.exits.buffer[exit_used]->description_1.get_string());
		else printf("There's nothing there.");
	}
	
	//look object operator
	else if (object_focused != -1){	
		if ((object.buffer[object_focused]->location == inroom||object.buffer[object_focused]->location>9)&&(object.buffer[object_focused]->state!=INCHEST)){
			object.buffer[object_focused]->look_it();
		}
		else printf("This object is out of sight");
	}
	
	//look chest operator
	else if (chest_focused != -1&&instruction.buffer[1]=="chest"){
		if (game_map.chests.buffer[chest_focused]->location == inroom){
			game_map.chests.buffer[chest_focused]->look_it();
		}
	}
	else if(chest_focused==-1)printf("There's no chest here");
	
	//look equipation operator
	else if (instruction.buffer[1] == "equipation"){
		if (equipation == nullptr){
			printf("You don't have equiped any item");
		}
		else printf("You have equiped %s", equipation->name.get_string());
	}
	else printf("Invalid Comand");
}

//open door instruction
bool character::apply_open_door_instruction(map& game_map,const vector<string>& instruction){
	//if there's no door where apply the action
	if (game_map.exits.buffer[exit_used]->door == false){
		printf("There's no door.");
		return false;
	}
	//already opened door
	else if (game_map.exits.buffer[exit_used]->door_state == true){
		printf("The door was already open.");
		return false;
	}
	else{
		game_map.exits.buffer[exit_used]->door_state = true;
		printf("Now the %s door from %s is open!", instruction.buffer[1].get_string(), game_map.rooms.buffer[inroom]->name.get_string());
		return true;
	}
}

//close door instruction
bool character::apply_close_door_instruction(map& game_map, const vector<string>& instruction){
	//if there's no door where apply the action
	if (game_map.exits.buffer[exit_used]->door == false){
		printf("There's no door.");
		return false;
	}
	else if (game_map.exits.buffer[exit_used]->door_state == true){
		game_map.exits.buffer[exit_used]->door_state = false;
		printf("Now the %s door from %s is closed!", instruction.buffer[1].get_string(), game_map.rooms.buffer[inroom]->name.get_string());
		return true;
	}
	else{
		printf("The door was already closed.");
		return false;
	}
}

//pick instruction
bool character::apply_pick_instruction(vector<item*>& object, map& game_map){
	if (bag.get_size() == bag.get_capacity()){ printf("Your inventory is full!"); return false; }
	else if (inroom != object.buffer[object_focused]->location&&object.buffer[object_focused]->state == UNKNOWN){printf("This object is in another room!"); return false;}
	else if (object.buffer[object_focused]->state == EQUIPED || object.buffer[object_focused]->state == UNEQUIPED){printf("You already have this object!"); return false; }
	else if (inroom == object.buffer[object_focused]->location&&object.buffer[object_focused]->state == INCHEST){printf("This object is inside the chest use other comand to get it"); return false; }
	else if (object.buffer[object_focused]->location == inroom && object.buffer[object_focused]->state == UNKNOWN){
		//add the item into the bag
		object.buffer[object_focused]->state = UNEQUIPED;
		object.buffer[object_focused]->location = bag.get_size() + 10;
		bag.push_back(object.buffer[object_focused]);
		printf("Now the %s is in your inventory!", bag.buffer[bag.get_size() - 1]->name.get_string());
		return true;
	}
}

//drop instruction
bool character::apply_drop_instruction(vector<item*>& object, map& game_map){
	if (object.buffer[object_focused]->state == EQUIPED){printf("You have to unequip this object before drop it!"); return false;}
	else if (object.buffer[object_focused]->state == UNKNOWN){printf("This object is not inside your bag!"); return false;}
	else{
		object.buffer[object_focused]->location = inroom;
		//reorganice the bag cells
		for (int n = bag.get_size() - 1; n >= 0; n--){
			if (bag.buffer[n]->name == object.buffer[object_focused]->name.get_string() && bag.buffer[n]->state == UNEQUIPED){
				if (n == bag.get_size() - 1){
					bag.pop_back();
					n = -1;
				}
				else{
					for (int moves = bag.get_size() - (n + 1); moves > 0; moves--){
						bag.buffer[n] = bag.buffer[n + 1];
						n++;
					}
					bag.pop_back();
					n = -1;
				}
			}
		}
		object.buffer[object_focused]->state = UNKNOWN;
		printf("You drop the %s!", object.buffer[object_focused]->name.get_string());
		return true;
	}
}

//equip instruction
bool character::apply_equip_instruction(vector<item*>& object){
	if (object.buffer[object_focused]->state == UNKNOWN || object.buffer[object_focused]->state == INCHEST){ printf("You don't have this object!"); return false; }
	if (equipation_state){ printf("You have to unequip the current object before equip other"); return false; };
	if (object.buffer[object_focused]->state == EQUIPED){ printf("This object was equiped before"); return false; }
	else {
		//reorganize the bag cells
		for (int n = 0; n < bag.get_capacity() - 1; n++){
			if (bag.buffer[n]->name == object.buffer[object_focused]->name.get_string()){
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
		//equip the object 
		equipation_state = true;
		object.buffer[object_focused]->state = EQUIPED;
		object.buffer[object_focused]->location = 15;
		equipation = object.buffer[object_focused];
		live += equipation->live_buff;
		attack += equipation->attack_buff;
		printf("Now %s is equiped!", equipation->name.get_string());
		if (equipation->attack_buff > 0)printf("+%i attack!", equipation->attack_buff);
		if (equipation->live_buff > 0)printf("+%i live!", equipation->live_buff);
		return true;
	}
}

//unequip instruction
bool character::apply_unequip_instruction(vector<item*>& object){
	if (object.buffer[object_focused]->state != EQUIPED){ printf("This object is not equiped."); return false; }
	if (bag.get_size() == bag.get_capacity()){ printf("You need a free cell to put the unequiped item in the inventory"); return false; }
	else{
		//unequip the object
		equipation_state = false;
		object.buffer[object_focused]->state = UNEQUIPED;
		object.buffer[object_focused]->location = bag.get_size() + 10;
		live -= equipation->live_buff;
		attack -= equipation->attack_buff;
		bag.push_back(equipation);
		equipation = nullptr;
		printf("%s is now in your inventory!", bag.buffer[bag.get_size() - 1]->name.get_string());
		if (object.buffer[object_focused]->attack_buff > 0)printf("-%i attack!", object.buffer[object_focused]->attack_buff);
		if (object.buffer[object_focused]->live_buff > 0)printf("-%i live!", object.buffer[object_focused]->live_buff);
		return true;
	}
}

//put instruction
bool character::apply_put_instruction(vector<chest*>&chests, vector<item*>&objects){
	if (objects.buffer[object_focused]->state == EQUIPED){ printf("You have to unequip this object before save it in a chest"); return false; }
	if (objects.buffer[object_focused]->state != UNEQUIPED){ printf("You don't have this object."); return false; }
	if (chests.buffer[chest_focused]->storage.get_size() == chests.buffer[chest_focused]->capacity){ printf("This chest is full!"); return false; }
	else{
		//put the object in the selected chest
		objects.buffer[object_focused]->state = INCHEST;
		objects.buffer[object_focused]->location = chests.buffer[chest_focused]->location;
		chests.buffer[chest_focused]->storage.push_back(objects.buffer[object_focused]);
		//reorganize the bag cells
		for (int n = bag.get_size() - 1; n >= 0; n--){
			if (bag.buffer[n]->name == objects.buffer[object_focused]->name.get_string()){
				if (n == bag.get_size() - 1){
					bag.pop_back();
					n = -1;
				}
				else{
					for (int moves = bag.get_size() - (n + 1); moves > 0; moves--){
						bag.buffer[n] = bag.buffer[n + 1];
						n++;
					}
					bag.pop_back();
					n = -1;
				}
			}
		}
		printf("You save the %s in the %s", objects.buffer[object_focused]->name.get_string(), chests.buffer[chest_focused]->name.get_string());
		return true;
	}
}

//get instruction
bool character::apply_get_instruction(vector<chest*>&chests, vector<item*>&objects){
	if (bag.get_size() == bag.get_capacity()){ printf("Your inventory is full!"); return false; }
	if (objects.buffer[object_focused]->state == INCHEST && objects.buffer[object_focused]->location != inroom){ printf("This object isn't in this chest"); return false; }
	else{
		//get the object from the selected chest
		objects.buffer[object_focused]->state = UNEQUIPED;
		objects.buffer[object_focused]->location = bag.get_size() + 10;
		bag.push_back(objects.buffer[object_focused]);
		//reorganize the chest cells
		for (int k = chests.buffer[chest_focused]->storage.get_size() - 1; k >= 0; k--){
			if (chests.buffer[chest_focused]->storage.buffer[k]->name == objects.buffer[object_focused]->name.get_string()){
				if (k == chests.buffer[chest_focused]->storage.get_size() - 1){
					chests.buffer[chest_focused]->storage.pop_back();
					k = -1;
					printf("You get %s from chest", objects.buffer[object_focused]->name.get_string());
				}
				else{
					for (int moves = chests.buffer[chest_focused]->storage.get_size() - (k + 1); moves > 0; moves--){
						chests.buffer[chest_focused]->storage.buffer[k] = chests.buffer[chest_focused]->storage.buffer[k + 1];
						k++;
					}
					chests.buffer[chest_focused]->storage.pop_back();
					printf("You get %s from chest", objects.buffer[object_focused]->name.get_string());
					k = -1;
				}
				return true;
			}
		}
	}
}