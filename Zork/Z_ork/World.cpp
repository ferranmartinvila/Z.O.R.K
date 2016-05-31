#define _CRT_SECURE_NO_WARNINGS
#include "World.h"

void world::Initialize(){
	
	
	//MAP
	//ROOMS
	//Principal Square Data
	room*Principal_Square = new room("Principal Square", "Central Square of Bloody Sword. This square is impollute and there's one of the best kingdom knights sorrounding it. Maybe someone important for the king lives arround here.");
	game_data.push_back(Principal_Square);

	//Dead end Street Data
	room*Dead_end_Street = new room("Dead end Street", "Abandoned street full of rubbish that ends in the wall of the city. Is difficult to stay here to much time, so people only comes here to throw his shit.");
	game_data.push_back(Dead_end_Street);

	//Ruined House Data
	room*Ruined_House = new room("Ruined House", "This house will fall down at any moment it practically don't have roof and you can smell the odor of the street next to this house. Surprisingly here there's a poor family living or more precisely surviving.");
	game_data.push_back(Ruined_House);

	//Jack's House Lobby Data
	room*Jack_House_Lobby = new room("Jack's House Lobby", "Little and luxury room for recieve guests. Full of family portraits.");
	game_data.push_back(Jack_House_Lobby);

	//Jack's House Main Room Data
	room*Jack_House_MainRoom = new room("Jack's House Main Room", "Biggest room of the house filled with belic objects with an incalculable valor. Like bright golden swords.");
	game_data.push_back(Jack_House_MainRoom);

	//Jack's House Kitchen Data
	room*Jack_House_Kitchen = new room("Jack's House Kitchen", "Big kichen fully of slaves working hard for the owners. Isn't so clean for be a kitchen probably the owners don't enter. They must be very busy.");
	game_data.push_back(Jack_House_Kitchen);

	//Jack's House Bathroom Data
	room*Jack_House_Bathroom = new room("Jack's House Bathroom", "The most clean room of the house probably because there's only a hole , a mirror and a pair of vases.");
	game_data.push_back(Jack_House_Bathroom);

	//Jack's Forge Shop Data
	room*Jack_Forge_Shop = new room("Jack's Forge Shop", "Little room full of iron tools and a showcase of weapons behind the counter.");
	game_data.push_back(Jack_Forge_Shop);

	//Jack's Forge Warehouse Data
	room*Jack_Forge_Warehouse = new room("Jack's Forge Warehouse", "Amazingly big and dirty room full of metal pieces.Probably this is the biggest underground warehouse that I have ever seen.");
	game_data.push_back(Jack_Forge_Warehouse);

	//Jack's Forge Large Furnace Data
	room*Jack_Forge_Furnace = new room("Jack's Forge Large Furnace", "Excessively large furnace that can melt the most resistant metals.It not seems to have been used for melt metals.");
	game_data.push_back(Jack_Forge_Furnace);

	
	//EXITS
	//Principla Square
	exit*PrincipalSquare_RuinedHouse = new exit("Principal Square north exit", "Under the herbs there's a ruined house with only one room. I don't know how there's people living there.", SOUTH, Ruined_House, true, true);
	game_data.push_back(PrincipalSquare_RuinedHouse);
	exit*PrincipalSquare_DeadendStreet = new exit("Principal Square east exit", "There's an abandoned street. It don't seems to lead anywhere but the polluted air makes impossible see the end.",EAST, Dead_end_Street);
	game_data.push_back(PrincipalSquare_DeadendStreet);
	exit*PrincipalSquare_Lobby = new exit("Principal Square north exit", "A palace!? This is a poor district! This is probably the most big and shiniy build of Bloody Sword.",NORTH, Jack_House_Lobby, true);
	game_data.push_back(PrincipalSquare_Lobby);
	exit*PrincipalSquare_Shop = new exit("Principal Square west exit", "There's little but well maintained forge. In the door there's a poster where you can read 'Jack's Forge'.", WEST,Jack_Forge_Shop, true);
	game_data.push_back(PrincipalSquare_Shop);
	
	//Dead end Street
	exit*DeadendStreet_PrincipalSquare = new exit("Dead end Street west exit", "There's the principal Square where you come from better if you go there and get out of this mount of rubbish.",WEST,Principal_Square);
	game_data.push_back(DeadendStreet_PrincipalSquare);
	
	//Ruined house
	exit*RuinedHouse_PrincipalSquare = new exit("Ruined house north exit", "There's the principal Square where you come from probably is more safe than this ruined house. Better if you go there.",NORTH, Principal_Square, true, true);
	game_data.push_back(RuinedHouse_PrincipalSquare);
	
	//Lobby
	exit*Lobby_PrincipalSquare = new exit("Jack Lobby south exit", "There's a big wood door that takes you outside.",SOUTH, Principal_Square, true);
	game_data.push_back(Lobby_PrincipalSquare);
	exit*Lobby_MainRoom = new exit("Jack Lobby north exit", "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.", NORTH,Jack_House_MainRoom, true, true);
	game_data.push_back(Lobby_MainRoom);
	
	//MainRoom
	exit*MainRoom_Lobby = new exit("MainRoom south exit", "There's the lobby.", SOUTH, Jack_House_Lobby,true, true);
	game_data.push_back(MainRoom_Lobby);
	exit*MainRoom_Kitchen = new exit("MainRoom east exit", "Is impossible to don't realize about the noise that comes from that room. It sounds like a group of people where fighting.", EAST,Jack_House_Kitchen);
	game_data.push_back(MainRoom_Kitchen);
	exit*MainRoom_Bathroom = new exit("MainRoom north exit", "Theres a door full of crystal decorations. Throwght it is possible to see a mirror but no more.", NORTH, Jack_House_Bathroom, true);
	game_data.push_back(MainRoom_Bathroom);

	//Kitchen
	exit*Kitchen_MainRoom = new exit("Kitchen west exit", "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.", WEST, Jack_House_MainRoom);
	game_data.push_back(Kitchen_MainRoom);

	//Bathroom
	exit*Bathroom_MainRoom = new exit("Bathroom south exit", "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.", SOUTH, Jack_House_MainRoom, true);
	game_data.push_back(Bathroom_MainRoom);

	//Shop
	exit*Shop_PrincipalSquare = new exit("Jack Shop east exit", "There's the door to go outside at the Principal Square.", EAST, Principal_Square, true);
	game_data.push_back(Shop_PrincipalSquare);
	exit*Shop_Warehouse = new exit("Jack shop west exit", "Between the tools there's a small door that probalby takes you to the warehouse.", WEST, Jack_Forge_Warehouse, true);
	game_data.push_back(Shop_Warehouse);

	//Warehouse
	exit*Warehouse_Shop = new exit("Jack Warehouse east exit", "There's the little door for go back to the Jack's Shop.", EAST, Jack_Forge_Shop, true);
	game_data.push_back(Warehouse_Shop);
	exit*Warehouse_Furnace = new exit("Jack Warehouse south exit", "There's a big door practically invisible for the dirt.", SOUTH, Jack_Forge_Furnace, true);
	game_data.push_back(Warehouse_Furnace);

	//Furnace
	exit*Furnace_Warehouse = new exit("Jack Furnace south exit", "There's the warehouse where you come from.", NORTH, Jack_Forge_Warehouse, true);
	game_data.push_back(Furnace_Warehouse);
	

	//OBJECTS
	//Oil Light
	item*Oil_Light = new item("Oil Light", "An old but usefull oil light.",INCHEST,0,5,Principal_Square,50);
	game_data.push_back(Oil_Light);

	//Golden Dagger
	item*Golden_Dagger = new item("Golden Dagger", "A little gold Dagger that get the attention of any person that knows about metals.", IN_NPC, 0, 8, Jack_Forge_Shop, 100);
	game_data.push_back(Golden_Dagger);

	//Furnace Key
	item*Furnace_Key = new item("Furnace Key", "A big and strange key which seems to have been used.",IN_NPC,0,5,Jack_Forge_Shop,60);
	game_data.push_back(Furnace_Key);

	//Marcus Notes
	item*Marcus_Notes = new item("Marcus Notes", "Old and poorly maintained notes. Stained by humidity and illegible in certain parts.\n\nText: If you have lose something Carl have it, he is the best thieve.", IN_NPC, 0, 0, Dead_end_Street, 30);
	game_data.push_back(Marcus_Notes);

	//Raw food
	item*Raw_food = new item("Raw food", "Food with a quite advanced state of rot. You will be healthier if you don't eat it.", IN_NPC, -10, +2, Jack_Forge_Shop, 15);
	game_data.push_back(Raw_food);

	//Wine
	item*Wine = new item("Wine", "An alcoholic drink made from fermented grape juice. This drink is able to persuade anyone.",UNKNOWN,+5,2,Ruined_House,35);
	game_data.push_back(Wine);

	//Knight's Sword
	item*Knight_Sword = new item("Knight sword", "A huge iron sword full of drawings and with a dragon on the handle.",INCHEST,0,15,Jack_House_MainRoom,170);
	game_data.push_back(Knight_Sword);

	//Bloody Sword
	item*Bloody_Sword = new item("Bloody Sword", "A magic red sword. It emits a strange energy that provides a supernatural force at the knight that uses it.", INCHEST, 100, 20, Jack_Forge_Furnace,780);
	game_data.push_back(Bloody_Sword);

	
	//CHESTS
	//Principal Square Chest
	chest*PrincipalSquare_Chest = new chest(Principal_Square,"Principal Square chest","A big and blue metallic box.");
	PrincipalSquare_Chest->data.push_back(Oil_Light);
	game_data.push_back(PrincipalSquare_Chest);

	//Furnace Chest
	chest*Furnace_Chest = new chest(Jack_Forge_Furnace,"Furnace chest","A big and dark chest.");
	Furnace_Chest->data.push_back(Bloody_Sword);
	game_data.push_back(Furnace_Chest);
	
	//NPCs
	//Dead end Street trader
	trader* Marcus = new trader("Marcus", "Old man that lives in the street trying to survive with the rubbish of the people. He knows everthing about Bloody Sword.", 50,5, Dead_end_Street, Marcus_Notes);
	game_data.push_back(Marcus);
	
	//PrincipalSquare Soldier
	soldier* John = new soldier("John", "A soldier of Bloody Sword. He works for the King.", 50, 15, Principal_Square);
	game_data.push_back(John);
	
	//Ruined House Soldier
	soldier* Izac = new soldier("Izac", "A soldier of Bloody Sword. He works for the King.", 50, 15, Ruined_House);
	game_data.push_back(Izac);
	
	//Warehouse Soldier
	soldier* Tom = new soldier("Tom", "A soldier of Bloody Sword. He works for the King.", 50, 15, Jack_Forge_Warehouse);
	game_data.push_back(Tom);
	
	//Lobby Soldier
	soldier* Zad = new soldier("Zad", "A soldier of Bloody Sword. He works for the King.", 50, 15, Jack_House_Lobby);
	game_data.push_back(Zad);

	//Jack House thieve
	thief*Carl = new thief("Carl", "Son of Jack that works stealing value objects for his father.", 50, 15, Jack_House_MainRoom);
	game_data.push_back(Carl);
	Carl->data.push_back(Knight_Sword);

	//Jack forge merchant
	merchant* Jack = new merchant("Jack", "Owner of the best forge in the region. Recognized for their works and for being a friend of the king.", 50, 10, Jack_Forge_Shop, Raw_food, Golden_Dagger, Furnace_Key);
	game_data.push_back(Jack);

	//Jack Mainroom talker
	talker* Daisy = new talker("Daisy", "Wife of Jack. He spends all the day playing with the slaves inside the house waiting for his husband.", 50, Jack_House_MainRoom);
	game_data.push_back(Daisy);

	//Map Build
	//Principal Square
	Principal_Square->data.push_back(PrincipalSquare_Chest);
	Principal_Square->data.push_back(PrincipalSquare_Shop);
	Principal_Square->data.push_back(PrincipalSquare_Lobby);
	Principal_Square->data.push_back(PrincipalSquare_RuinedHouse);
	Principal_Square->data.push_back(PrincipalSquare_DeadendStreet);
	Principal_Square->data.push_back(John);
	//Dead end street
	Dead_end_Street->data.push_back(DeadendStreet_PrincipalSquare);
	Dead_end_Street->data.push_back(Marcus);
	//Ruined House
	Ruined_House->data.push_back(RuinedHouse_PrincipalSquare);
	Ruined_House->data.push_back(Wine);
	Ruined_House->data.push_back(Izac);
	//Jack Lobby
	Jack_House_Lobby->data.push_back(Lobby_PrincipalSquare);
	Jack_House_Lobby->data.push_back(Lobby_MainRoom);
	Jack_House_Lobby->data.push_back(Zad);
	//Jack Main room
	Jack_House_MainRoom->data.push_back(MainRoom_Bathroom);
	Jack_House_MainRoom->data.push_back(MainRoom_Kitchen);
	Jack_House_MainRoom->data.push_back(MainRoom_Lobby);
	Jack_House_MainRoom->data.push_back(Carl);
	Jack_House_MainRoom->data.push_back(Daisy);
	
	//Jack Kitchen
	Jack_House_Kitchen->data.push_back(Kitchen_MainRoom);
	//Jack Bathroom
	Jack_House_Bathroom->data.push_back(Bathroom_MainRoom);
	//Jack Shop
	Jack_Forge_Shop->data.push_back(Shop_PrincipalSquare);
	Jack_Forge_Shop->data.push_back(Shop_Warehouse);
	Jack_Forge_Shop->data.push_back(Jack);
	//Jack Warehouse
	Jack_Forge_Warehouse->data.push_back(Warehouse_Furnace);
	Jack_Forge_Warehouse->data.push_back(Warehouse_Shop);
	Jack_Forge_Warehouse->data.push_back(Tom);
	//Jack LargeFurnace
	Jack_Forge_Furnace->data.push_back(Furnace_Chest);
	Jack_Forge_Furnace->data.push_back(Furnace_Warehouse);
	
	//Character	
	me->location = Principal_Square;
	me->next_room_ad = Principal_Square;
	me->action = NOTHING;
	me->money = 0;
	me->live_points = 20;
	me->attack = 15;
	me->alive = true;
	while (me->data.empty() == false){
		me->data.pop_back();
	}
	game_data.push_back(me);
}

void world::get_instruction(vector<string>& instruction){

	//Player focused leemnts reset;
	me->exit_focused = nullptr;
	me->next_room_ad = me->location;
	me->object_focused_ad = nullptr;
	me->chest_focused_ad = nullptr;
	//Get exit & room focused
	if ((instruction.buffer[0] == "go" || instruction.buffer[0] == "close" || instruction.buffer[0] == "open" || instruction.buffer[0] == "look") && instruction.get_size()>1){
		unsigned int temp_direction = NONE;
		if (instruction.buffer[1] == "north")temp_direction = NORTH;
		else if (instruction.buffer[1] == "east")temp_direction = EAST;
		else if (instruction.buffer[1] == "south")temp_direction = SOUTH;
		else if (instruction.buffer[1] == "west")temp_direction = WEST;
		
		list<entity*>::node* temp = me->location->data.first_element;
		while (temp){
			if (((exit*)temp->data)->direction == temp_direction && ((exit*)temp->data)->type == EXIT){
				me->exit_focused = ((exit*)temp->data);
				break;
			}
			else{
				temp = temp->next;
			}
		}
		if (me->exit_focused != nullptr){
			me->next_room_ad = me->exit_focused->connected_room;
		}
		else me->next_room_ad = me->location;
	}
	
	//Calculates the object focused
	if (((instruction.buffer[0] == "pick" || instruction.buffer[0] == "drop" || instruction.buffer[0] == "equip" || instruction.buffer[0] == "unequip" || instruction.buffer[0] == "put" || instruction.buffer[0] == "get" || instruction.buffer[0] == "look" || instruction.buffer[0] == "buy" || instruction.buffer[0] == "sell")&& instruction.get_size()>1)){
		//If item is a composed name the two strings that compose it are fusioned 
		if ((instruction.get_size() == 3 && instruction.buffer[1] != "room") || (instruction.get_size() == 5 && instruction.buffer[4] == "chest")){
			instruction.buffer[1]+=instruction.buffer[2];
		}
		//Object focused
		for (int k = 0; k < MAX_ENTITY; k++){
			if (instruction.buffer[1] == ((item*)game_data.buffer[k])->name && ((item*)game_data.buffer[k])->type == ITEM){
				me->object_focused_ad = (item*)game_data.buffer[k];
				break;
			}
		}
	}
	//Chest focused
	if ((instruction.buffer[0] == "put" || instruction.buffer[0] == "get" || instruction.buffer[0] == "look") && instruction.get_size()>1){
		//Chest focused
		list<entity*>::node* temp = me->location->data.first_element;
		while(temp){
			if (((chest*)temp->data)->type == CHEST){
				me->chest_focused_ad = (chest*)temp->data;
				break;
			}
			else{
				temp = temp->next;
			}
		}
	}
	//NPC focused
	if ((instruction.buffer[0] == "talk" || instruction.buffer[0] == "look" || instruction.buffer[0] == "attack") && instruction.get_size()>1){
		for (int k = 0; k < MAX_ENTITY; k++){
			if ((instruction.get_size() == 3 && ((npc*)game_data.buffer[k])->name == instruction.buffer[2]) || (instruction.get_size() == 2 && ((npc*)game_data.buffer[k])->name == instruction.buffer[1])){
				me->npc_focused = (npc*)game_data.buffer[k];
				break;
			}
		}
	}
}

bool world::apply_order(vector<string>& instruction){
	int reader = false;
	if (me->action == NOTHING){
	//quit instruction
	if (instruction.buffer[0] == "quit")return false;
	//help instruction
	else if (instruction.buffer[0] == "help")
	{ printf(
	//Look
	"\nlook + room -> look this room"
	"\nlook + me -> look the avatar"
	"\nlook + direction -> Show exit focused content"
	"\nlook + inventory -> Show all inventory objects"
	"\nlook + room + objects -> Show all the objects in this room"
	"\nlook + equipation -> Show your equiped object stats"
	"\nlook + chest -> Show all the items in the selected chest"
	"\nlook + item -> Show all the selected item data"
	"\nlook + npc_name -> Show the selected npc current data"
	//Movement
	"\ngo + direction ->Move in the direction"
	//Door actions
	"\nopen + direction + door -> Open door"
	"\nclose + direction + door-> Close door"
	//Item actions
	"\npick + object ->Save object in the inventory"
	"\ndrop + object -> Throw object from the inventory"
	//Equipation actions
	"\nequip + object -> Equip object from the inventory"
	"\nunequip + object -> Unequip equiped object and put it in the inventory"
	//Chest actions
	"\nget + object + from + chest ->Gets the object from the selected chest"
	"\nput + object + into + chest -> Put the selected item into the chest"
	//NPC actions
	"\ntalk to + npc_name -> Talk to the selected npc"
	"\nlook + npc_name -> Show all the information of the npc"
	"\nattack + npc_name -> Start a fight"
	"\n(inside shop) sell + object / buy + object"
	"\n(when inside shop) quit -> Stop trading"
	"\n(when you are in a interaction with a npc non npc related commands are blocked)"
	"\n(you have to respect upper cases in the names)"
	//Quit
	"\nquit ->Exit the game"
	"\n"
	); 
	reader++; }

	
	//go instruction
	if (instruction.buffer[0] == "go" && instruction.get_size()>1)me->apply_go_instruction(instruction), reader++;
	//look instruction
	else if (instruction.buffer[0] == "look" && instruction.get_size()>1)me->apply_look_instruction(instruction), reader++;
		
	if (me->object_focused_ad != nullptr){
		//pick instruction
		if ((instruction.buffer[0] == "pick" && instruction.get_size() <= 4))me->apply_pick_instruction(), reader++;
		//drop instruction
		else if ((instruction.buffer[0] == "drop" && instruction.get_size() <= 4))me->apply_drop_instruction(), reader++;
		//equip instruction
		else if (instruction.buffer[0] == "equip"){ me->apply_equip_instruction(); reader++; }
		//unequip instruction
		else if (instruction.buffer[0] == "unequip"){ me->apply_unequip_instruction(); reader++; }
		//put instruction
		else if (instruction.buffer[0] == "put" && instruction.get_size()>3 &&(instruction.buffer[2] == "into" || instruction.buffer[3] == "into") && (instruction.buffer[3] == "chest" || instruction.buffer[4] == "chest")){ me->apply_put_instruction(); reader++; }
		//get instruction
		else if (instruction.buffer[0] == "get" && instruction.get_size()>3 && (instruction.buffer[2] == "from" || instruction.buffer[3] == "from") && (instruction.buffer[3] == "chest" || instruction.buffer[4] == "chest")){ me->apply_get_instruction(); reader++; }
	}
	else if (me->next_room_ad != nullptr && me->exit_focused != nullptr){
		//open instruction
		if ((instruction.buffer[0] == "open" && instruction.get_size() == 3 && instruction.buffer[2] == "door")){ me->apply_open_door_instruction(); reader++; }
		//close instruction
		else if ((instruction.buffer[0] == "close" && instruction.get_size() == 3 && instruction.buffer[2] == "door")){ me->apply_close_door_instruction(); reader++; }
	}
	}
	if (me->npc_focused != nullptr){
		if (me->npc_focused->alive == true){
			//talk instruction
			if (instruction.buffer[0] == "talk" && instruction.buffer[1] == "to" || me->action == TALK){ me->apply_talk_instruction(instruction); reader++; }
			//attack instruction
			if (instruction.buffer[0] == "attack" || me->action == ATTACK){ me->apply_attack_instruction(); reader++; }
			//special attack instruction
			if (instruction.buffer[0] == "special" && instruction.buffer[1] == "attack" && me->action == ATTACK){ me->apply_special_attack_instruction(); reader++; }
		}
	}
	if (me->action == DEAD && instruction.buffer[0] == "reset")reader = reset_game();
	//if the instruction is not the correct for the action Invalid Comand alert is printed
	if (reader == false){ printf("Invalid Comand"); return true; }
	else return true;
}

//reset game
bool world::reset_game(){
	//Character	
	me->action = NOTHING;
	me->live_points = 20;
	me->alive = true;
	me->npc_focused->action = NOTHING;
	me->npc_focused->heal();
	printf("\n\nTHE GAME HAS BEEN RESET!\n\n");
	printf("Now you are at the same situation before start the fight that kill you.\n");
	return true;
}



