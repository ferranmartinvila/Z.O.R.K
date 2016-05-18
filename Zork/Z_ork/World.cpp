#define _CRT_SECURE_NO_WARNINGS
#include "World.h"
#include "string.h"
#include <string.h>
#include <stdio.h>
#include "vector.h"
#include "character.h"

void world::Initialize(){
	//OBJECTS
	//Oil Light
	item*Oil_Light = new item("Oil Light", "An old but usefull oil light.", 11,UNKNOWN,0,1);
	object.push_back(Oil_Light);
	game_data.push_back(Oil_Light);

	//Golden Dagger
	item*Golden_Dagger = new item("Golden Dagger", "A little gold Dagger that get the attention of any person that knows about metals.", 14,UNKNOWN,0,6);
	object.push_back(Golden_Dagger);
	game_data.push_back(Golden_Dagger);

	//Furnace Key
	item*Furnace_Key = new item("Furnace Key", "A big and strange key which seems to have been used.", 19,INCHEST,0,3);
	object.push_back(Furnace_Key);
	game_data.push_back(Furnace_Key);

	//Marcus Notes
	item*Marcus_Notes = new item("Marcus Notes", "Old and poorly maintained notes. Stained by humidity and illegible in certain parts.", 12,UNKNOWN,0,0);
	object.push_back(Marcus_Notes);
	game_data.push_back(Marcus_Notes);

	//Raw food
	item*Raw_food = new item("Raw food", "Food with a quite advanced state of rot. You will be healthier if you don't eat it.", 11,UNKNOWN,0,0);
	object.push_back(Raw_food);
	game_data.push_back(Raw_food);

	//Wine
	item*Wine = new item("Wine", "An alcoholic drink made from fermented grape juice. This drink is able to persuade anyone.", 15,UNKNOWN,0,2);
	object.push_back(Wine);
	game_data.push_back(Wine);

	//Knight's Sword
	item*Knight_Sword = new item("Knight Sword", "A huge iron sword full of drawings and with a dragon on the handle.", 10,INCHEST,0,8);
	object.push_back(Knight_Sword);
	game_data.push_back(Knight_Sword);

	//Bloody Sword
	item*Bloody_Sword = new item("Bloody Sword", "A magic red sword. It emits a strange energy that provides a supernatural force at the knight that uses it.", 19,INCHEST,100,12);
	object.push_back(Bloody_Sword);
	game_data.push_back(Bloody_Sword);

	//CHESTS
	//Principal Square Chest
	chest*PrincipalSquare_Chest = new chest(Knight_Sword,10);
	game_map->chests.push_back(PrincipalSquare_Chest);
	game_data.push_back(PrincipalSquare_Chest);

	//Furnace Chest
	chest*Furnace_Chest = new chest(Bloody_Sword,19);
	game_map->chests.push_back(Furnace_Chest);
	game_data.push_back(Furnace_Chest);
	
	//MAP
	
	//ROOMS
	//Principal Square Data
	room*Principal_Square = new room("Principal Square", "Central Square of Bloody Sword. This square is impollute and there's one of the best kingdom knights sorrounding it. Maybe someone important for the king lives arround here.", 0, 0);
	game_map->rooms.push_back(Principal_Square);
	game_data.push_back(Principal_Square);
	
	//Dead end Street Data
	room*Dead_end_Street=new room("Dead end Street", "Abandoned street full of rubbish that ends in the wall of the city. Is difficult to stay here to much time, so people only comes here to throw his shit.", 1, 0);
	game_map->rooms.push_back(Dead_end_Street);
	game_data.push_back(Dead_end_Street);
	
	//Ruined House Data
	room*Ruined_House=new room("Ruined House", "This house will fall down at any moment it practically don't have roof and you can smell the odor of the street next to this house. Surprisingly here there's a poor family living or more precisely surviving.", 0, -1);
	game_map->rooms.push_back(Ruined_House);
	game_data.push_back(Ruined_House);
	
	//Jack's House Lobby Data
	room*Jack_House_Lobby=new room("Jack's House Lobby", "Little and luxury room for recieve guests. Full of family portraits.", 0, 1);
	game_map->rooms.push_back(Jack_House_Lobby);
	game_data.push_back(Jack_House_Lobby);
	
	//Jack's House Main Room Data
	room*Jack_House_MainRoom = new room("Jack's House Main Room", "Biggest room of the house filled with belic objects with an incalculable valor. Like bright golden swords.", 0, 2);
	game_map->rooms.push_back(Jack_House_MainRoom);
	game_data.push_back(Jack_House_MainRoom);
	
	//Jack's House Kitchen Data
	room*Jack_House_Kitchen = new room("Jack's House Kitchen", "Big kichen fully of slaves working hard for the owners. Isn't so clean for be a kitchen probably the owners don't enter. They must be very busy.", 1, 2);
	game_map->rooms.push_back(Jack_House_Kitchen);
	game_data.push_back(Jack_House_Kitchen);
	
	//Jack's House Bathroom Data
	room*Jack_House_Bathroom = new room("Jack's House Bathroom", "The most clean room of the house probably because there's only a hole , a mirror and a pair of vases.", 0, 3);
	game_map->rooms.push_back(Jack_House_Bathroom);
	game_data.push_back(Jack_House_Bathroom);
	
	//Jack's Forge Shop Data
	room*Jack_Forge_Shop = new room("Jack's Forge Shop", "Little room full of iron tools and with a showcase of weapons behind the counter.", -1, 0);
	game_map->rooms.push_back(Jack_Forge_Shop);
	game_data.push_back(Jack_Forge_Shop);
	
	//Jack's Forge Warehouse Data
	room*Jack_Forge_Warehouse = new room("Jack's Forge Warehouse", "Amazingly big and dirty room full of metal pieces.Probably this is the biggest underground warehouse that I have ever seen.", -2, 0);
	game_map->rooms.push_back(Jack_Forge_Warehouse);
	game_data.push_back(Jack_Forge_Warehouse);
	
	//Jack's Forge Large Furnace Data
	room*Jack_Forge_Furnace = new room("Jack's Forge Large Furnace", "Excessively large furnace that can melt the most resistant metals.It not seems to have been used for melt metals.", -2, -1);
	game_map->rooms.push_back(Jack_Forge_Furnace);
	game_data.push_back(Jack_Forge_Furnace);

	//EXITS
	//Principal Square & Dead end Street
	exit*PrincipalSquare_to_DeadendStreet = new exit(10, 11, "There's an abandoned street. It don't seems to lead anywhere but the polluted air makes impossible see the end.", "There's the principal Square where you come from better if you go there and get out of this mount of rubbish.", false, true);
	game_map->exits.push_back(PrincipalSquare_to_DeadendStreet);
	game_data.push_back(PrincipalSquare_to_DeadendStreet);
	
	//Principal Square & Ruined House
	exit*PrincipalSquare_to_RuinedHouse = new exit(10, 12, "Under the herbs there's a ruined house with only one room. I don't know how there's people living there.", "There's the principal Square where you come from probably is more safe than this ruined house. Better if you go there.", true, true);
	game_map->exits.push_back(PrincipalSquare_to_RuinedHouse);
	game_data.push_back(PrincipalSquare_to_RuinedHouse);
	
	//Principal Square & Jack's House Lobby
	exit*PrincipalSquare_to_HouseLobby = new exit(10, 13, "A palace!? This is a poor district! This is probably the most big and shiniy build of Bloody Sword.", "There's a big wood door that takes you outside.", true, false);
	game_map->exits.push_back(PrincipalSquare_to_HouseLobby);
	game_data.push_back(PrincipalSquare_to_HouseLobby);
	
	//Principal Square & Jack's Forge Shop
	exit*PrincipalSquare_to_ForgeShop = new exit(10, 17, "There's little but well maintained forge. In the door there's a poster where you can read 'Jack's Forge'.", "There's the door to go outside at the Principal Square.", true, true);
	game_map->exits.push_back(PrincipalSquare_to_ForgeShop);
	game_data.push_back(PrincipalSquare_to_ForgeShop);
	
	//Shop & Warehouse
	exit*Shop_to_Warehouse = new exit(17, 18, "Between the tools there's a small door that probalby takes you to the warehouse.", "That's the little door for go back to the Jack's Shop.", true, true);
	game_map->exits.push_back(Shop_to_Warehouse);
	game_data.push_back(Shop_to_Warehouse);
	
	//Warehouse & Large Furnace
	exit*Warehouse_to_Furnace = new exit(18, 19, "There's a big door practically invisible for the dirt.", "There's the warehouse where you come from.", true, true);
	game_map->exits.push_back(Warehouse_to_Furnace);
	game_data.push_back(Warehouse_to_Furnace);
	
	// Lobby & Main Room
	exit*Lobby_to_MainRoom = new exit(13, 14, "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.", "There's the lobby.", false, true);
	game_map->exits.push_back(Lobby_to_MainRoom);
	game_data.push_back(Lobby_to_MainRoom);
	
	// Main Room & Kitchen
	exit*MainRoom_to_Kitchen = new exit(14, 15, "Is impossible to don't realize about the noise that comes from that room. It sounds like a group of people where fighting.", "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.", true, true);
	game_map->exits.push_back(MainRoom_to_Kitchen);
	game_data.push_back(MainRoom_to_Kitchen);
	
	//Main Room & Bathroom
	exit*MainRoom_to_Bathroom = new exit(14, 16, "Theres a door full of crystal decorations. Throwght it is possible to see a mirror but no more.", "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.", true, true);
	game_map->exits.push_back(MainRoom_to_Bathroom);
	game_data.push_back(MainRoom_to_Bathroom);
	
}

void world::get_instruction(vector<string>& instruction){
	/*//player pointer
	entity* p = game_data.buffer[0];
	character*player =nullptr;
	for (int k = 0; k < MAX_ENTITY; k++){
		if (p->type == type::CHARACTER){
			player=((character*)p)->;
			break;
		}
		p++;
	}*/
	//array that contain all de phrase characters
	char phrase[40];
	printf("Enter the next action:");
	gets_s(phrase);
	string cpy = phrase;
	if (cpy.lenght() > 0){
		instruction = tokenize(phrase);
	}
	if (instruction.buffer[0] == "go" || instruction.buffer[0] == "close" || instruction.buffer[0] == "open" || instruction.buffer[0] == "look"){
		//resets future direction from the actual position to calculate the next room you focus
		me->direction[0] = me->pos_x;
		me->direction[1] = me->pos_y;
		me->next_room = me->inroom;
		//generates a variable with the number of the room that the player is focused and coords of this room
		if (instruction.buffer[1] == "north")me->direction[1]++;
		else if (instruction.buffer[1] == "east")me->direction[0]++;
		else if (instruction.buffer[1] == "south")me->direction[1]--;
		else if (instruction.buffer[1] == "west")me->direction[0]--;
		else me->next_room = -1;
		if (me->next_room != -1){
			//calculates the room where you focus the action and the exit between your room and it
			/*for (int k = 0; k < 10; k++){
				if (game_map->rooms.buffer[k]->x_cor == me->direction[0] && game_map->rooms.buffer[k]->y_cor == me->direction[1]){
					me->next_room = k;
					k = 9;
				}
				else me->next_room = me->inroom;
			}
			for (int i = 0; i < 9; i++){
				if ((game_map->exits.buffer[i]->room_1 == me->inroom || game_map->exits.buffer[i]->room_2 == me->inroom) && (game_map->exits.buffer[i]->room_1 == me->next_room || game_map->exits.buffer[i]->room_2 == me->next_room)){
					me->exit_used = i;
					i = 9;
				}
			}*/
			//SECTOR
			for (int k = 0; k < MAX_ENTITY; k++){
				if (((room*)game_data.buffer[k])->x_cor == me->direction[0] && ((room*)game_data.buffer[k])->y_cor == me->direction[1] && ((room*)game_data.buffer[k])->type == ROOM){
					me->next_room = k;
					k = MAX_ENTITY;
				}
				else me->next_room = me->inroom;
			}
			for (int i = 0; i < MAX_ENTITY; i++){
				if ((((exit*)game_data.buffer[i])->room_1 == me->inroom || ((exit*)game_data.buffer[i])->room_2 == me->inroom) && (((exit*)game_data.buffer[i])->room_1 == me->next_room || ((exit*)game_data.buffer[i])->room_2 == me->next_room) && ((exit*)game_data.buffer[i])->type == EXIT){
					me->exit_used = i;
					i = MAX_ENTITY;
				}
			}
		}
	}
	//calculates the object you focus
	me->object_focused = -1;
	if ((instruction.buffer[0] == "pick" || instruction.buffer[0] == "drop" || instruction.buffer[0] == "equip" || instruction.buffer[0] == "unequip" || instruction.buffer[0] == "put" || instruction.buffer[0] == "get" || instruction.buffer[0] == "look")){
		if (instruction.buffer[2] != "objects"){
			//if item is a composed name the two strings that compose it are fusioned 
			if (instruction.get_size() == 3 || (instruction.get_size() == 5 && instruction.buffer[4] == "chest")){
				instruction.buffer[1] = instruction.buffer[1] + instruction.buffer[2];
			}
			//calculates the object you focus
			for (int n = object.get_size() - 1; n >= 0; n--){
				if (instruction.buffer[1] == object.buffer[n]->name.get_string()){
					me->object_focused = n;
					n = -1;
				}
			}
			//SECTOR
			for (int n = MAX_ENTITY - 1; n >= 0; n--){
				if (instruction.buffer[1] == ((item*)game_data.buffer[n])->name.get_string() && ((item*)game->game_data.buffer[n])->type == ITEM){
					me->object_focused = n;
					n = -1;
				}
			}
		}
		//calculates the chest you focus
		me->chest_focused = -1;
		/*if (((instruction.buffer[0] == "put" || instruction.buffer[0] == "get") && (instruction.buffer[4] == "chest" || instruction.buffer[3] == "chest")) || instruction.buffer[0] == "look"){
			for (int k = 0; k < 2; k++){
				if (me->inroom == game_map->chests.buffer[k]->location){
					me->chest_focused = k;
					k = 2;
				}
			}
		}*/
		//SECTOR
		if (((instruction.buffer[0] == "put" || instruction.buffer[0] == "get") && (instruction.buffer[4] == "chest" || instruction.buffer[3] == "chest")) || instruction.buffer[0] == "look"){
			for (int k = 0; k < MAX_ENTITY; k++){
				if (me->inroom == ((chest*)game_data.buffer[k])->location && ((chest*)game->game_data.buffer[k])->type == CHEST){
					me->chest_focused = k;
					k = MAX_ENTITY;
				}
			}
		}
	}
}

bool world::apply_order(vector<string>& instruction){
	int reader = false;
	//quit instruction
	if (instruction.buffer[0] == "quit")return false;
	//help instruction
	else if (instruction.buffer[0] == "help"){ printf("\nlook + room -> look this room\nlook + direction -> look + exits\nlook + me -> look the avatar\nlook + inventory -> Show all inventory objects\n"
		"look + room + objects -> Show all the objects in this room\n\look + inventory -> Show all your bag objects\nlook + chest -> Show all the items in the selected chest\nlook + item -> Show all item data"
		"go + direction ->Move in the direction\nopen + direction + door -> Open door\nclose + direction + door-> Close door\npick + object ->Save object in the inventory\n"
		"drop + object -> Throw object from the inventory\nequip + object -> Equip object from the inventory\nunequip + object -> Unequip equiped object and put it in the inventory\n"
		"get + object + from + chest ->Gets the object from the selected chest\nput + object + into + chest -> Put the selected item into the chest"); reader++; }
	//go instruction
	if (instruction.buffer[0] == "go")me->apply_go_instruction(*game_map, instruction),reader++;
	//look instruction
	else if (instruction.buffer[0] == "look")me->apply_look_instruction(object, *game_map, instruction), reader++;
	
	if (me->object_focused != -1){
		//pick instruction
		if ((instruction.buffer[0] == "pick" && instruction.get_size() <= 4))me->apply_pick_instruction(object, *game_map), reader++;
		//drop instruction
		else if ((instruction.buffer[0] == "drop" && instruction.get_size() <= 4))me->apply_drop_instruction(object, *game_map), reader++;
		//equip instruction
		else if (instruction.buffer[0] == "equip"){ me->apply_equip_instruction(object); reader++; }
		//unequip instruction
		else if (instruction.buffer[0] == "unequip"){ me->apply_unequip_instruction(object); reader++; }
		//put instruction
		else if (instruction.buffer[0] == "put" && (instruction.buffer[2] == "into" || instruction.buffer[3] == "into") && (instruction.buffer[3] == "chest" || instruction.buffer[4] == "chest")){ me->apply_put_instruction(game_map->chests, object); reader++; }
		//get instruction
		else if (instruction.buffer[0] == "get" && (instruction.buffer[2] == "from" || instruction.buffer[3] == "from") && (instruction.buffer[3] == "chest" || instruction.buffer[4] == "chest")){ me->apply_get_instruction(game_map->chests, object); reader++; }
	}
	else if (me->next_room != -1){
		//open instruction
		if ((instruction.buffer[0] == "open" && instruction.get_size() == 3 && instruction.buffer[2] == "door")){ me->apply_open_door_instruction(*game_map, instruction); reader++; }
		//close instruction
		else if ((instruction.buffer[0] == "close" && instruction.get_size() == 3 && instruction.buffer[2] == "door")){ me->apply_close_door_instruction(*game_map, instruction); reader++; }
	}
	//if the size of the instruction is not the respective for the action Invalid Comand alert is printed
	if (reader == false)printf("Invalid Comand");
	else return true;
}
	

