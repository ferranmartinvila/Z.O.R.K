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
			printf("%s\n%s", game_map.rooms.buffer[inroom]->name.STR, game_map.rooms.buffer[inroom]->description.STR);
		}
		else if (game_map.exits.buffer[exit_used]->door_state == false){
			printf("\nThe %s %s door is closed.", instruction.buffer[1].STR, game_map.rooms.buffer[inroom]->name);
		}
		else printf("There's anything there.");
	}
	else printf("Invalid direction");
}

//look instruction
void character::apply_look_instruction(vector<item*>& object, const map& game_map,vector<string>& instruction){
	
	if (instruction.buffer[1] == "room"&&instruction.get_size() == 2)printf("%s\n%s\n", game_map.rooms.buffer[inroom]->name.STR, game_map.rooms.buffer[inroom]->description.STR);
	else if (instruction.buffer[1] == "me")printf("%s\n%s\nSTATS:\nlive[%i]\nattack[%i]\n", name.STR, description.STR,live,attack);
	else if (instruction.buffer[1] == "inventory"){
		for (int n = 0; n < 4; n++){
			if (n<bag.get_size())printf("Cell %i: %s\n", n, bag.buffer[n]->name.STR);
		}
		if(bag.get_size()==0) printf("The inventory is empty.");
	}
	else if (instruction.buffer[1] == "room"&&instruction.buffer[2] == "objects"){
		int j = 8;
		for (int n = 0; n < 8; n++){
				if (object.buffer[n]->location == inroom&&object.buffer[n]->state!=INCHEST){
					printf("  -%s\n", object.buffer[n]->name.STR);
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
	else if (instruction.buffer[1] == "west" || instruction.buffer[1] == "south" || instruction.buffer[1] == "north" || instruction.buffer[1] == "east"){
		if ((inroom == game_map.exits.buffer[exit_used]->room_2) && (next_room == game_map.exits.buffer[exit_used]->room_1))printf("%s", game_map.exits.buffer[exit_used]->description_2.STR);
		else if ((inroom == game_map.exits.buffer[exit_used]->room_1) && (next_room == game_map.exits.buffer[exit_used]->room_2))printf("%s", game_map.exits.buffer[exit_used]->description_1.STR);
		else printf("There's nothing there.");
	}
	else if (object_focused != -1){	
		if ((object.buffer[object_focused]->location == inroom||object.buffer[object_focused]->location>9)&&(object.buffer[object_focused]->state!=INCHEST)){
			object.buffer[object_focused]->look_it();
		}
		else printf("This object is out of sight");
	}
	else if (chest_focused != -1&&instruction.buffer[1]=="chest"){
		if (game_map.chests.buffer[chest_focused]->location == inroom){
			game_map.chests.buffer[chest_focused]->look_it();
		}
	}
	else if(chest_focused==-1)printf("There's no chest here");
	else if (instruction.buffer[1] == "equipation"){
		if (equipation == nullptr){
			printf("You don't have equiped any item");
		}
		else printf("You have equiped %s", equipation->name.STR);
	}
	else printf("Invalid Comand");
}

//open/close instruction
void character::apply_door_instruction(map& game_map, const vector<string>& instruction){
	if (next_room != -1){
		if (game_map.exits.buffer[exit_used]->door == false){
			printf("There's no door.");
		}
		else if (game_map.exits.buffer[exit_used]->door_state == true){
			//open
			if (instruction.buffer[0] == "open"){
				printf("The door was already open.");
			}
			//close
			if (instruction.buffer[0] == "close"){
				game_map.exits.buffer[exit_used]->door_state = false;
				printf("Now the %s door from %s is closed!", instruction.buffer[1].STR, game_map.rooms.buffer[inroom]->name.STR);
			}
		}
		else{
			//open
			if (instruction.buffer[0] == "open"){
				game_map.exits.buffer[exit_used]->door_state = true;
				printf("Now the %s door from %s is open!", instruction.buffer[1].STR, game_map.rooms.buffer[inroom]->name.STR);
			}
			//close
			if (instruction.buffer[0] == "close"){
				printf("The door was already closed.");
			}
		}
	}
	else printf("Invalid Direction");
}

//pick/drop instruction
void character::apply_pickdrop_instruction(vector<item*>& object, map& game_map, const vector<string>& instruction){
	if (object_focused != -1){

		//pick operator

		if (instruction.buffer[0] == "pick"){
			if (inroom != object.buffer[object_focused]->location&&object.buffer[object_focused]->state == UNKNOWN)printf("This object is in another room!");
			else if (object.buffer[object_focused]->state == EQUIPED || object.buffer[object_focused]->state == UNEQUIPED)printf("You already have this object!");
			else if (inroom == object.buffer[object_focused]->location&&object.buffer[object_focused]->state == INCHEST)printf("This object is inside the chest use other comand to get it");
			else if (object.buffer[object_focused]->location == inroom&&object.buffer[object_focused]->state == UNKNOWN){
				object.buffer[object_focused]->state = UNEQUIPED;
				object.buffer[object_focused]->location = bag.get_size()+10;
				if (bag.get_size() < bag.get_capacity()){
					bag.push_back(object.buffer[object_focused]);
					printf("Now the %s is in your inventory!", bag.buffer[bag.get_size() - 1]->name.STR);
				}
			}
		}
		else if (bag.get_size() == bag.get_capacity()) printf("Your inventory is full!");


		//drop opetator
		else if (instruction.buffer[0] == "drop"){
			if (object.buffer[object_focused]->state == EQUIPED)printf("You have to unequip this object before drop it!");
			else if (object.buffer[object_focused]->state == UNKNOWN)printf("This object is not inside your bag!");
			else{
				object.buffer[object_focused]->location = inroom;
				for (int n = bag.get_size()-1; n >=0; n--){
					if (bag.buffer[n]->name == object.buffer[object_focused]->name.STR&&bag.buffer[n]->state == UNEQUIPED){
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
				printf("You drop the %s!", object.buffer[object_focused]->name.STR);
			}
		}
	}
	else printf("Invalid Object");
}

//equip/unequip instruction
void character::apply_equipment_instruction(vector<item*>& object, const vector<string>& instruction){
	if (object_focused != -1){
		if (object.buffer[object_focused]->state != UNKNOWN && object.buffer[object_focused]->state != INCHEST){
			if (instruction.buffer[0] == "equip"){
				if (equipation_state)printf("You have to unequip the current object before equip other");
				else if (object.buffer[object_focused]->state == EQUIPED)printf("This object was equiped before");
				else if (object.buffer[object_focused]->state == UNEQUIPED){
					for (int n = 0; n < bag.get_capacity()-1; n++){
						if (bag.buffer[n]->name == object.buffer[object_focused]->name.STR){
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
					equipation_state = true;
					object.buffer[object_focused]->state = EQUIPED;
					object.buffer[object_focused]->location = 15;
					equipation = object.buffer[object_focused];
					live += equipation->live_buff;
					attack += equipation->attack_buff;
					printf("Now %s is equiped!", equipation->name.STR);
					if (equipation->attack_buff > 0)printf("+%i attack!",equipation->attack_buff);
					if (equipation->live_buff > 0)printf("+%i live!", equipation->live_buff);
				}
			}
			else
				if (object.buffer[object_focused]->state == EQUIPED){
					if (bag.get_size() < bag.get_capacity()){
						equipation_state = false;
						object.buffer[object_focused]->state = UNEQUIPED;
						object.buffer[object_focused]->location = bag.get_size()+10;
						live -= equipation->live_buff;
						attack -= equipation->attack_buff;
						bag.push_back(equipation);
						equipation = nullptr;
						printf("%s is now in your inventory!", bag.buffer[bag.get_size() - 1]->name.STR);
						if (object.buffer[object_focused]->attack_buff > 0)printf("-%i attack!", object.buffer[object_focused]->attack_buff);
						if (object.buffer[object_focused]->live_buff > 0)printf("-%i live!", object.buffer[object_focused]->live_buff);
					}
					else printf("You need a free cell to put the unequiped item in the inventory");
				}
				else printf("This object is in your bag but not equiped");
		}
		else printf("You don't have this object");
	}
	else printf("Invalid Object");
}

void character::apply_chest_instruction(vector<chest*>&chests,vector<item*>&objects,const vector<string>&instruction){
	if (chest_focused != -1){
		if (object_focused != -1){
				//put operator
				if (instruction.buffer[0] == "put"){
					if (objects.buffer[object_focused]->state != INCHEST){
						if (objects.buffer[object_focused]->state != UNKNOWN){
							if (objects.buffer[object_focused]->state != EQUIPED){
								if (chests.buffer[chest_focused]->storage.get_size() < chests.buffer[chest_focused]->capacity){
									objects.buffer[object_focused]->state = INCHEST;
									objects.buffer[object_focused]->location = chests.buffer[chest_focused]->location;
									chests.buffer[chest_focused]->storage.push_back(objects.buffer[object_focused]);
									for (int n = bag.get_size()-1; n >=0; n--){
										if (bag.buffer[n]->name == objects.buffer[object_focused]->name.STR){
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
									printf("You save the %s in the %s", objects.buffer[object_focused]->name.STR, chests.buffer[chest_focused]->name.STR);
								}
								else printf("This chest is full!");
							}
							else printf("You have to unequip this object before save it in a chest");
						}
						else printf("You don't have this object");
					}
					else printf("This objects is already in the chest");
				}
				//get operator
				else if (bag.get_size() < bag.get_capacity()){

					if (objects.buffer[object_focused]->state != UNKNOWN&&objects.buffer[object_focused]->location==inroom){
						if (objects.buffer[object_focused]->state != UNEQUIPED){
							if (chests.buffer[chest_focused]->storage.get_size() != 0){
								objects.buffer[object_focused]->state = UNEQUIPED;
								objects.buffer[object_focused]->location=bag.get_size()+10;
								bag.push_back(objects.buffer[object_focused]);
								for (int k = chests.buffer[chest_focused]->storage.get_size()-1; k >=0; k--){
									if (chests.buffer[chest_focused]->storage.buffer[k]->name == objects.buffer[object_focused]->name.STR){
										if (k == chests.buffer[chest_focused]->storage.get_size() - 1){
											chests.buffer[chest_focused]->storage.pop_back();
											k = -1;
											printf("You get %s from chest", objects.buffer[object_focused]->name.STR);
										}
										else{
											for (int moves = chests.buffer[chest_focused]->storage.get_size() - (k + 1); moves > 0; moves--){
												chests.buffer[chest_focused]->storage.buffer[k] = chests.buffer[chest_focused]->storage.buffer[k + 1];
												k++;
											}
											chests.buffer[chest_focused]->storage.pop_back();
											printf("You get %s from chest", objects.buffer[object_focused]->name.STR);
											k = -1;
										}
									}
								}
							}
							else printf("This chest is empty");
						}
						else printf("This object is in your inventory");
					}
					else printf("This object isn't in this chest");
				}
				else printf("Your inventory is full!");
		}
		else printf("Invalid Object");
	}
	else if(instruction.buffer[3]!="chest"&&instruction.buffer[4]!="chest")printf("Invalid Chest");
}