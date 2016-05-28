#include "character.h"
#include "World.h"
//move instruction
void character::apply_go_instruction(const vector<string>& instruction){
	if (exit_focused && location!= next_room_ad){
		if ((exit_focused->door_state == true || exit_focused->door == false)){
			location = next_room_ad;
			printf("%s\n%s", location->name.get_string(), location->description.get_string());

		}
		else if (exit_focused->door_state == false && exit_focused->door == true){
			printf("\n%s door is closed.", exit_focused->name);

		}
	}
	else printf("There's anything there.");
}

//look instruction
void character::apply_look_instruction(vector<string>& instruction){
	
	//look room operator
	if (instruction.buffer[1] == "room" && instruction.get_size() == 2)printf("%s\n%s", location->name.get_string(), location->description.get_string());
	
	//look me operator
	else if (instruction.buffer[1] == "me")printf("%s\n%s\nSTATS:\nlive[%i]\nattack[%i]", name.get_string(), description.get_string(), live_points, attack);
	
	//look inventory operator
	else if (instruction.buffer[1] == "inventory"){
		if (data.first_element == nullptr)printf("The inventory is empty.");
		else{
			int y = 0;
			list<entity*>::node* temp = data.first_element;
			for (int k = 0; k < data.get_size(); k++){
				if (temp->data->type == ITEM && ((item*)temp->data)->state == UNEQUIPED){
					printf("Cell %i: %s\n", k, temp->data->name.get_string());
					temp = temp->next;
					y++;
				}
			}
			if (y == 0)printf("The inventory is empty.");
		}
	}
	
	//look room objects
	else if (instruction.buffer[1] == "room" && instruction.buffer[2] == "objects"){
		unsigned int prints = 0;
		list<entity*>::node* temp = location->data.first_element;
		while (temp){
			if (((entity*)temp->data)->type == ITEM){
				printf("\n- %s", ((item*)temp->data)->name.get_string());
				prints++;
			}
			else if (((entity*)temp->data)->type == CHEST){
				printf("\n- Chest");
				prints++;
			}
			temp = temp->next;
		}
		if (prints == 0)printf("There's no objects or chest in this room.");
	
	}
	
	//look exit 
	else if (exit_focused != nullptr){
		exit_focused->look_it();
	}
	
	//look object 
	else if (object_focused_ad != nullptr){
		if (object_focused_ad->place == location || object_focused_ad->state == UNEQUIPED || object_focused_ad->state ==  EQUIPED){
			object_focused_ad->look_it();
		}
		else printf("This object is out of sight");
	}
	
	//look equipation operator(when equiped)
	else if (instruction.buffer[1] == "equipation"){
		if (equipation == nullptr){
			printf("You don't have equiped any item");
		}
		else { 
			printf("You have equiped %s:\n", equipation->name.get_string()); 
			if (equipation->attack_buff > 0)printf("+%i attack!\n", equipation->attack_buff);
			if (equipation->live_buff > 0)printf("+%i live!\n", equipation->live_buff);
		}
	}

	//look npc
	else if (npc_focused != nullptr && instruction.buffer[1] == npc_focused->name.get_string()){
		if (npc_focused->location != location)printf("%s is not here", npc_focused->name.get_string());
		else if (npc_focused->alive == false)printf("%s is simply dead. There's anything interesting to know about him now.",npc_focused->name.get_string());
		else{
			printf("%s:\n%s", npc_focused->name.get_string(), npc_focused->description.get_string());
			//Add storage show
		}
	}

	//look chest
	else if (chest_focused_ad != nullptr && instruction.buffer[1] == "chest"){
		chest_focused_ad->look_it();
	}
	else if (chest_focused_ad == nullptr)printf("There's no chest here");

	else printf("Invalid Comand");
}

//open door instruction(list version)
bool character::apply_open_door_instruction(){
	//if there's no door where apply the action
	if (exit_focused->door == false){
		printf("There's no door.");
		return false;
	}
	//already opened door
	else if (exit_focused->door_state == true){
		printf("The door was already open.");
		return false;
	}
	//open door
	else{
		list<entity*>::node* next_exit = exit_focused->connected_room->data.first_element;
		while (next_exit){
			if (((exit*)next_exit->data)->connected_room == location){
				break;
			}
			else{
				next_exit = next_exit->next;
			}
		}
		((exit*)next_exit->data)->door_state = true;
		exit_focused->door_state = true;
		printf("Now the %s door is open!", exit_focused->name.get_string());
		return true;
	}
}

//close door instruction
bool character::apply_close_door_instruction(){
	//if there's no door where apply the action
	if (exit_focused->door == false){
		printf("There's no door.");
		return false;
	}
	//close door
	else if (exit_focused->door_state == false){
		printf("The door was already closed.");
		return false;
	}
	//already closed door
	else{
		list<entity*>::node* next_exit = exit_focused->connected_room->data.first_element;
		while (next_exit){
			if (((exit*)next_exit->data)->connected_room == location){
				break;
			}
			else{
				next_exit = next_exit->next;
			}
		}
		((exit*)next_exit->data)->door_state = false;
		exit_focused->door_state = false;
		printf("Now the %s door is closed!", exit_focused->name.get_string());
		return true;
	}
}


//pick instruction
bool character::apply_pick_instruction(){
	if (in_bag == 4){ printf("Your inventory is full!"); return false; }
	else if (location != object_focused_ad->place && object_focused_ad->state == UNKNOWN){ printf("This object is in another room!"); return false; }
	else if (object_focused_ad->state == EQUIPED || object_focused_ad->state == UNEQUIPED){ printf("You already have this object!"); return false; }
	else if (location == object_focused_ad->place && object_focused_ad->state == INCHEST){ printf("This object is inside the chest use other comand to get it"); return false; }
	else if (object_focused_ad->place == location && object_focused_ad->state == UNKNOWN){
		//add the item into the bag
		in_bag++;
		data.push_back(object_focused_ad);
		object_focused_ad->state = UNEQUIPED;
		unsigned int k = location->data.find_position(object_focused_ad);
		location->data.erase(k);
		printf("Now the %s is in your inventory!", object_focused_ad->name.get_string());
		return true;
	}
	return false;
}

//drop instruction
bool character::apply_drop_instruction(){
	if (object_focused_ad->state == EQUIPED){ printf("You have to unequip this object before drop it!"); return false; }
	else if (object_focused_ad->state == UNKNOWN){ printf("This object isn't inside your bag!"); return false; }
	else{
		in_bag--;
		object_focused_ad->place = location;
		object_focused_ad->state = UNKNOWN;
		location->data.push_back(object_focused_ad);
		data.erase(data.find_position((object_focused_ad)));
		printf("You drop the %s!", object_focused_ad->name.get_string());
		return true;
	}
}

// equip instruction
bool character::apply_equip_instruction(){
	if (object_focused_ad->state == UNKNOWN || object_focused_ad->state == INCHEST){ printf("You don't have this object!"); return false; }
	if (equipation != nullptr){ printf("You have to unequip the %s before equip other",equipation->name.get_string()); return false; };
	if (object_focused_ad->state == EQUIPED){ printf("This object was equiped before"); return false; }
	else{
		in_bag--;
		object_focused_ad->state = EQUIPED;
		equipation = object_focused_ad;
		live_points += object_focused_ad->live_buff;
		attack += object_focused_ad->attack_buff;
		printf("Now %s is equiped!", equipation->name.get_string());
		if (equipation->attack_buff > 0)printf("+%i attack!", equipation->attack_buff);
		if (equipation->live_buff > 0)printf("+%i live!", equipation->live_buff);
	}
}
//unequip instruction
bool character::apply_unequip_instruction(){
	if (object_focused_ad->state != EQUIPED){ printf("This object is not in your equipation."); return false; }
	if (in_bag == 4){ printf("You need a free cell to put the unequiped item in the inventory"); return false; }
	else{
		//unequip the object
		object_focused_ad->state = UNEQUIPED;
		live_points -= equipation->live_buff;
		attack -= equipation->attack_buff;
		equipation = nullptr;
		printf("%s is now in your inventory!", object_focused_ad->name.get_string());
		if (object_focused_ad->attack_buff > 0)printf("-%i attack!", object_focused_ad->attack_buff);
		if (object_focused_ad->live_buff > 0)printf("-%i live!", object_focused_ad->live_buff);
		return true;
	}
}

//put instruction
bool character::apply_put_instruction(){
	if (chest_focused_ad == nullptr){ printf("There's no chest here"); return false; }
	if (object_focused_ad->state == EQUIPED){ printf("You have to unequip this object before save it in a chest"); return false; }
	if (object_focused_ad->state != UNEQUIPED){ printf("You don't have this object."); return false; }
	if (chest_focused_ad->data.get_size() == chest_focused_ad->capacity){ printf("This chest is full!"); return false; }
	else{
		//put the object in the selected chest
		object_focused_ad->state = INCHEST;
		chest_focused_ad->data.push_back(object_focused_ad);
		data.erase(data.find_position((object_focused_ad)));
		printf("You save the %s in the %s", object_focused_ad->name.get_string(), chest_focused_ad->name.get_string());
		return true;
	}
}

//get instruction
bool character::apply_get_instruction(){
	if (in_bag == 4){ printf("Your inventory is full!"); return false; }
	if (object_focused_ad->state == INCHEST && chest_focused_ad->place != location){ printf("This object is in another chest"); return false; }
	if (object_focused_ad->state == UNKNOWN && object_focused_ad->place == location){ printf("This object is outside the %s use pick to get it.", chest_focused_ad->name); return false; }
	if (object_focused_ad->state == EQUIPED || object_focused_ad->state == UNEQUIPED){ printf("You already have this objects."); return false; }
	if (object_focused_ad->state == UNKNOWN){ printf("This object is in another room"); return false; }
	else{
		//get the object from the selected chest
		object_focused_ad->state = UNEQUIPED;
		data.push_back(object_focused_ad);
		chest_focused_ad->data.erase(chest_focused_ad->data.find_position((object_focused_ad)));
		printf("You get the %s from %s", object_focused_ad->name.get_string(), chest_focused_ad->name.get_string());
	}
}

//talk instruction
bool character::apply_talk_instruction(const vector<string>& instruction){
	if (npc_focused->location == location){
		if (npc_focused->type == TRADER){
			((trader*)npc_focused)->Talk(instruction);
		}
		else npc_focused->Talk(instruction);
	}
	else{ printf("This npc now is not inside this room."); }
	return true;
}

//attack instruction
bool character::apply_attack_instruction(const vector<string>& instruction){
	if (npc_focused->location == location){
		game->me->action = ATTACK;
		if (npc_focused->type == SOILDER){
			((soldier*)npc_focused)->Attack();
		}
		else npc_focused->Attack();
	}
	else{ printf("This npc now is not inside this room."); }
	return true;
}