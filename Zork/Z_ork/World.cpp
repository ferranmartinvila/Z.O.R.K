#define _CRT_SECURE_NO_WARNINGS
#include"World.h"
#include"string.h"
#include<string.h>
#include<stdio.h>
#include"rooms.h"
#include"exits.h"
#include"item.h"
#include"dinamic_array.h"

void world::Initialize(){
	//OBJECTS
	//Oil Light
	item*Oil_Light = new item("Oil Light", "An old but usefull oil light.", 1);
	object.push_back(Oil_Light);

	//Golden Dagger
	item*Golden_Dagger = new item("Golden Dagger", "A little gold Dagger that get the attention of any person that knows about metals.", 4);
	object.push_back(Golden_Dagger);
	
	//Furnace Key
	item*Furnace_Key = new item("Furnace Key", "A big and strange key which seems to have been used.", 8);
	object.push_back(Furnace_Key);
	
	//Marcus Notes
	item*Marcus_Notes = new item("Marcus Notes", "Old and poorly maintained notes. Stained by humidity and illegible in certain parts.", 2);
	object.push_back(Marcus_Notes);

	//Raw food
	item*Raw_food = new item("Raw food", "Food with a quite advanced state of rot. You will be healthier if you don't eat it.", 1);
	object.push_back(Raw_food);

	//Wine
	item*Wine = new item("Wine", "An alcoholic drink made from fermented grape juice. This drink is able to persuade anyone.", 5);
	object.push_back(Wine);

	//Knight's Sword
	item*Knight_Sword = new item("Knight's Sword", "A huge iron sword full of drawings and with a dragon on the handle.", 8);
	object.push_back(Knight_Sword);

	//Bloody Sword
	item*Bloody_Sword = new item("Bloody Sword", "A magic red sword. It emits a strange energy that provides a supernatural force at the knight that uses it.", 9);
	object.push_back(Bloody_Sword);
	
	
	//CHARACTER
	me->pos_x = me->pos_y = me->inroom = me->exit_used = me->next_room = me->direction[0] = me->direction[1] = 0;
	me->name = "Earl the knight";
	me->description = "You are a brave knight from a far village called Gandar there all the people respects you but here in Bloody Sword nobody knows you.";
	//inventory
	int cell_location = 10;
	for (int k = 0; k < 4; k++){
	me->bag.buffer[k].name = nullptr;
	me->bag.buffer[k].description = nullptr;
	me->bag.buffer[k].location = cell_location;
	cell_location++;
	}
	me->equipation.name = nullptr;
	me->equipation.description = nullptr;
	me->equipation.location = 13;
	
	//MAP
	//ROOMS
	//Principal Square Data
	rooms*Principal_Square = new rooms("Principal Square", "Central Square of Bloody Sword. This square is impollute and there's one of the best kingdom knights sorrounding it. Maybe someone important for the king lives arround here.", 0, 0);
	game_map->room.push_back(Principal_Square);
	//Dead end Street Data
	rooms*Dead_end_Street=new rooms("Dead end Street", "Abandoned street full of rubbish that ends in the wall of the city. Is difficult to stay here to much time, so people only comes here to throw his shit.", 1, 0);
	game_map->room.push_back(Dead_end_Street);

	//Ruined House Data
	rooms*Ruined_House=new rooms("Ruined House", "This house will fall down at any moment it practically don't have roof and you can smell the odor of the street next to this house. Surprisingly here there's a poor family living or more precisely surviving.", 0, -1);
	game_map->room.push_back(Ruined_House);

	//Jack's House Lobby Data
	rooms*Jack_House_Lobby=new rooms("Jack's House Lobby", "Little and luxury room for recieve guests. Full of family portraits.", 0, 1);
	game_map->room.push_back(Jack_House_Lobby);

	//Jack's House Main Room Data
	rooms*Jack_House_MainRoom = new rooms("Jack's House Main Room", "Biggest room of the house filled with belic objects with an incalculable valor. Like bright golden swords.", 0, 2);
	game_map->room.push_back(Jack_House_MainRoom);

	//Jack's House Kitchen Data
	rooms*Jack_House_Kitchen = new rooms("Jack's House Kitchen", "Big kichen fully of slaves working hard for the owners. Isn't so clean for be a kitchen probably the owners don't enter. They must be very busy.", 1, 2);
	game_map->room.push_back(Jack_House_Kitchen);

	//Jack's House Bathroom Data
	rooms*Jack_House_Bathroom = new rooms("Jack's House Bathroom", "The most clean room of the house probably because there's only a hole , a mirror and a pair of vases.", 0, 3);
	game_map->room.push_back(Jack_House_Bathroom);

	//Jack's Forge Shop Data
	rooms*Jack_Forge_Shop = new rooms("Jack's Forge Shop", "Little room full of iron tools and with a showcase of weapons behind the counter.", -1, 0);
	game_map->room.push_back(Jack_Forge_Shop);

	//Jack's Forge Warehouse Data
	rooms*Jack_Forge_Warehouse = new rooms("Jack's Forge Warehouse", "Amazingly big and dirty room full of metal pieces.Probably this is the biggest underground warehouse that I have ever seen.", -2, 0);
	game_map->room.push_back(Jack_Forge_Warehouse);

	//Jack's Forge Large Furnace Data
	rooms*Jack_Forge_Furnace = new rooms("Jack's Forge Large Furnace", "Excessively large furnace that can melt the most resistant metals.It not seems to have been used for melt metals.", -2, -1);
	game_map->room.push_back(Jack_Forge_Furnace);

	//EXITS
	//Principal Square & Dead end Street
	exits*PrincipalSquare_to_DeadendStreet = new exits(0, 1, "There's an abandoned street. It don't seems to lead anywhere but the polluted air makes impossible see the end.", "There's the principal Square where you come from better if you go there and get out of this mount of rubbish.", false, true);
	game_map->exit.push_back(PrincipalSquare_to_DeadendStreet);

	//Principal Square & Ruined House
	exits*PrincipalSquare_to_RuinedHouse = new exits(0, 2, "Under the herbs there's a ruined house with only one room. I don't know how there's people living there.", "There's the principal Square where you come from probably is more safe than this ruined house. Better if you go there.", true, true);
	game_map->exit.push_back(PrincipalSquare_to_RuinedHouse);
	
	//Principal Square & Jack's House Lobby
	exits*PrincipalSquare_to_HouseLobby = new exits(0, 3, "A palace!? This is a poor district! This is probably the most big and shiniy build of Bloody Sword.", "There's a big wood door that takes you outside.", true, false);
	game_map->exit.push_back(PrincipalSquare_to_HouseLobby);
	
	//Principal Square & Jack's Forge Shop
	exits*PrincipalSquare_to_ForgeShop = new exits(0, 7, "There's little but well maintained forge. In the door there's a poster where you can read 'Jack's Forge'.", "There's the door to go outside at the Principal Square.", true, true);
	game_map->exit.push_back(PrincipalSquare_to_ForgeShop);
	
	//Shop & Warehouse
	exits*Shop_to_Warehouse = new exits(7, 8, "Between the tools there's a small door that probalby takes you to the warehouse.", "That's the little door for go back to the Jack's Shop.", true, true);
	game_map->exit.push_back(Shop_to_Warehouse);

	//Warehouse & Large Furnace
	exits*Warehouse_to_Furnace = new exits(8, 9, "There's a big door practically invisible for the dirt.", "There's the warehouse where you come from.", true, true);
	game_map->exit.push_back(Warehouse_to_Furnace);

	// Lobby & Main Room
	exits*Lobby_to_MainRoom = new exits(3, 4, "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.", "There's the lobby.", false, true);
	game_map->exit.push_back(Lobby_to_MainRoom);
	
	// Main Room & Kitchen
	exits*MainRoom_to_Kitchen = new exits(4, 5, "Is impossible to don't realize about the noise that comes from that room. It sounds like a group of people where fighting.", "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.", true, true);
	game_map->exit.push_back(MainRoom_to_Kitchen);
	//Main Room & Bathroom
	exits*MainRoom_to_Bathroom = new exits(4, 6, "Theres a door full of crystal decorations. Throwght it is possible to see a mirror but no more.", "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.", true, true);
	game_map->exit.push_back(MainRoom_to_Bathroom);
	
}

void world::get_instruction(vector<string>& instruction){

	//array that contain all de phrase characters
	char phrase[40];
	printf("Enter the next action:");
	gets_s(phrase);
	instruction=tokenize(phrase);

	//generates a variable with the number of the room that the player is focused and coords of this room
	if (instruction.buffer[0] == "go" || instruction.buffer[0] == "look" || instruction.buffer[0] == "open" || instruction.buffer[0] == "close"){
		if (instruction.buffer[1] == "north")me->direction[1]++;
		else if (instruction.buffer[1] == "east")me->direction[0]++;
		else if (instruction.buffer[1] == "south")me->direction[1]--;
		else if (instruction.buffer[1] == "west")me->direction[0]--;


		//calculates the room where you focus the action and the exit between your room and it
		for (int k = 0; k < 10; k++){
			if (game_map->room.buffer[k]->x_cor == me->direction[0] && game_map->room.buffer[k]->y_cor == me->direction[1]){
				me->next_room = k;
				k = 9;
			}
			else me->next_room = me->inroom;
		}
		for (int i = 0; i < 9; i++){
			if ((game_map->exit.buffer[i]->room_1 == me->inroom || game_map->exit.buffer[i]->room_2 == me->inroom) && (game_map->exit.buffer[i]->room_1 == me->next_room || game_map->exit.buffer[i]->room_2 == me->next_room)){
				me->exit_used = i;
				i = 9;
			}
		}
	}
}

char world::apply_order(vector<string>& instruction){
	if (instruction.buffer[0] == "quit")return 'q';
	if (instruction.buffer[0] == "help"){ printf("\nLook here -> Look this room\nLook + direction -> Look exits\nLook me -> Look the avatar\nLook inventory -> Show all inventory objects\nLook room objects -> Show all the objects in this room\nGo + direction ->Move\nOpen + direction + door -> Open door\nClose + direction + door-> Close door\n"); }
	else if (instruction.buffer[0] == "go")me->apply_go_instruction(*game_map, instruction);
	else if (instruction.buffer[0] == "look")me->apply_look_instruction(object, *game_map, instruction);
	else if ((instruction.buffer[0] == "open" || instruction.buffer[0] == "close") && instruction.buffer[2] == "door")me->apply_door_instruction(*game_map, instruction);
	else if (instruction.buffer[0] == "pick" || instruction.buffer[0] == "drop")me->apply_pickdrop_instruction(object, *game_map, instruction);
}
	

