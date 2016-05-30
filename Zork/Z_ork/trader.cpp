#include "trader.h"
#include "World.h"

void trader::Update(){
	if (action == ATTACK){
		Attack();
	}
}

void trader::Talk(const vector<string> instruction){
	game->me->action = TALK;
	char *option = new char[strlen(instruction.buffer[0].get_string())];
	strcpy_s(option, strlen(instruction.buffer[0].get_string()) + 1, instruction.buffer[0].get_string());
	//Options
	if (option[0] != 'a'&& option[0] != 'b'&& option[0] != 'c'&& option[0] != 'd'){
		printf(
			"\n[a]->Do you see my Sword?"
			"\n[b]->Can you help me?"
			"\n[c]->Trade Wine"
			"\n[d]->Stop talking.");
	}
	switch (option[0]){
	case 'a':
		//Do you see my Sword?
		printf("Oh no, do you lose it?");
		break;
	case 'b':
		//Can you help me?
		printf("Yes but you have to give me some Wine!");
		break;
	case 'c':
		//Trade Wine
		this->Trade();
		game->me->action = TALK;
		break;
	case 'd':
		//Stop Talking
		printf("Bye!");
		game->me->action = NOTHING;
		game->me->npc_focused = nullptr;
		break;
	}
}


void trader::Trade(){
	game->me->action = TRADE;
	item* player_object = nullptr;
	item* npc_object = nullptr;
	//Search Wine in the player bag
	for (int k = 0; k < MAX_ENTITY; k++){
		if (((item*)game->game_data.buffer[k])->name == "Marcus Notes"){
			npc_object = (item*)game->game_data.buffer[k];
		}
		if (((item*)game->game_data.buffer[k])->name == "Wine"){
			player_object = (item*)game->game_data.buffer[k];
		}
	}
	//Trade the objects
	
	if (player_object->state == EQUIPED)printf("\nYou have to unequip the Wine to can trade it.");
	else if (player_object->state != UNEQUIPED)printf("\nYou don't have Wine.");
	else{
		printf("\nYou trade %s for %s", player_object->name.get_string(), npc_object->name.get_string());
		npc_object->state = UNEQUIPED;
		player_object->state = IN_NPC;
		player_object->state;
		data.push_back(player_object);
		game->me->data.push_back(npc_object);
		data.erase(data.find_position(npc_object));
		game->me->data.erase(game->me->data.find_position(player_object));
		
	}
}