#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "World.h"

void world::generate_world(){

	//Principal Square Data
	strcpy(game_map->room[0].name, "\nBloody Sword Principal Square");
	strcpy(game_map->room[0].description, "Central Square of Bloody Sword. This square is impollute and there's one of the best kingdom knights sorrounding it. Maybe someone important for the king lives arround here.\n");
	//Room coordenades
	game_map->room[0].x_cor = game_map->room[0].y_cor = 0;
	//Principal Square to Lobby
	strcpy(game_map->exit[0].description, "\nA palace!? This is a poor district! This is probably the most big and shiniy build of Bloody Sword.\n");
	game_map->exit[0].way = 0;
	game_map->exit[0].to_room = 3;
	game_map->exit[0].in_room = 0;
	game_map->exit[0].door = true;
	game_map->exit[0].door_state = true;
	//Principal Square to Dead end Street
	strcpy(game_map->exit[1].description, "\nThere's a abandoned street. It don't seems to lead anywhere but the polluted air makes impossible see the end.\n");
	game_map->exit[1].way = 1;
	game_map->exit[1].to_room = 1;
	game_map->exit[1].in_room = 0;
	game_map->exit[1].door = false;
	game_map->exit[1].door_state = NULL;
	//Principal Square to Ruined House
	strcpy(game_map->exit[2].description, "\nUnder the herbs there's a ruined house with only one room. I don't know how there's people living there.");
	game_map->exit[2].way = 2;
	game_map->exit[2].to_room = 2;
	game_map->exit[2].in_room = 0;
	game_map->exit[2].door = true;
	game_map->exit[2].door_state = true;
	//Principal Square to Shop
	strcpy(game_map->exit[3].description, "\nThere's little but well maintained forge. In the door there's a poster where you can read 'Jack's Forge'.\n");
	//In the showcase there are some swords and helmets it seems that this Jack knows about the art of steelmaking.
	game_map->exit[3].way = 3;
	game_map->exit[3].to_room = 7;
	game_map->exit[3].in_room = 0;
	game_map->exit[3].door = true;
	game_map->exit[3].door_state = false;



	//Dead end street Data
	strcpy(game_map->room[1].name, "\nDead end Street");
	strcpy(game_map->room[1].description, "Abandoned street full of rubbish that ends in the wall of the city. Is difficult to stay here to much time, so people only comes here to throw his shit.\n");
	// room coordenades
	game_map->room[1].x_cor = 1;
	game_map->room[1].y_cor = 0;
	//Dead end Street to Principal Square
	strcpy(game_map->exit[4].description, "There's the principal Square where you come from better if you go there and get out of this mount of rubbish.\n");
	game_map->exit[4].way = 3;
	game_map->exit[4].to_room = 0;
	game_map->exit[4].in_room = 1;
	game_map->exit[4].door = false;
	game_map->exit[4].door_state = NULL;
	


	//Ruined House Data
	strcpy(game_map->room[2].name, "\nRuined House");
	strcpy(game_map->room[2].description, "This house will fall down at any moment it practically don't have roof and you can smell the odor of the street next to this house. Surprisingly here there's a poor family living or more precisely surviving\n");
	//Room coordenades
	game_map->room[2].x_cor = 0;
	game_map->room[2].y_cor = -1;
	//Ruined House ro Principal Square
	strcpy(game_map->exit[5].description, "There's the principal Square where you come from probably is more safe than this ruined house. Better if you go there.\n");
	game_map->exit[5].way = 0;
	game_map->exit[5].to_room = 0;
	game_map->exit[5].in_room = 2;
	game_map->exit[5].door = true;
	game_map->exit[5].door_state = true;
	


	//Jack's House Lobby Data
	strcpy(game_map->room[3].name, "\nJack's House Lobby");
	strcpy(game_map->room[3].description, "Little and luxury room for recieve guests. Full of family portraits.\n");
	//Room coordenades
	game_map->room[3].x_cor = 0;
	game_map->room[3].y_cor = 1;
	//Lobby to Main Room
	strcpy(game_map->exit[6].description, "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.\n");
	game_map->exit[6].way = 0;
	game_map->exit[6].to_room = 3;
	game_map->exit[6].in_room = 3;
	game_map->exit[6].door = false;
	game_map->exit[6].door_state = NULL;
	//Lobby to Principal Square
	strcpy(game_map->exit[7].description, "There's a big wood door that takes you outside.\n");
	game_map->exit[7].way = 2;
	game_map->exit[7].to_room = 0;
	game_map->exit[7].in_room = 3;
	game_map->exit[7].door = true;
	game_map->exit[7].door_state = true;



	//Jack's House Main Room Data
	strcpy(game_map->room[4].name, "\nJack's House Main Room");
	strcpy(game_map->room[4].description, "Biggest room of the house filled with belic objects with an incalculable valor. Like bright golden swords.\n");
	//Room coordenades
	game_map->room[4].x_cor = 0;
	game_map->room[4].y_cor = 2;
	//Main Room to Bathroom
	strcpy(game_map->exit[8].description, "Theres a door full of crystal decorations. Throwght it is possible to see a mirror but no more.\n");
	game_map->exit[8].way = 0;
	game_map->exit[8].to_room = 6;
	game_map->exit[8].in_room = 4;
	game_map->exit[8].door = true;
	game_map->exit[8].door_state = false;
	//Main Room to Kitchen
	strcpy(game_map->exit[9].description, "Is impossible to don't realize about the noise that comes from that room. It sounds like a group of people where fighting.\n");
	game_map->exit[9].way = 1;
	game_map->exit[9].to_room = 5;
	game_map->exit[9].in_room = 4;
	game_map->exit[9].door = true;
	game_map->exit[9].door_state = true;
	//Main Room to Lobby
	strcpy(game_map->exit[10].description, "There's the lobby.\n");
	game_map->exit[10].way = 2;
	game_map->exit[10].to_room = 3;
	game_map->exit[10].in_room = 4;
	game_map->exit[10].door = false;
	game_map->exit[10].door_state = NULL;



	//Jack's House Kitchen Data
	strcpy(game_map->room[5].name, "\nJack's House Kitchen");
	strcpy(game_map->room[5].description, "Big kichen fully of slaves working hard for the owners. Isn't so clean for be a kitchen probably the owners don't enter. They must be very busy.\n");
	//Room coordenades
	game_map->room[5].x_cor = 1;
	game_map->room[5].y_cor = 2;
	//Kitchen to Main Room
	//Main Room to Lobby
	strcpy(game_map->exit[11].description, "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.\n");
	game_map->exit[11].way = 3;
	game_map->exit[11].to_room = 3;
	game_map->exit[11].in_room = 5;
	game_map->exit[11].door = true;
	game_map->exit[11].door_state = true;



	//Jack's House Bathroom Data
	strcpy(game_map->room[6].name, "\nJack's House Bathroom");
	strcpy(game_map->room[6].description, "The most clean room of the house probably because there's only a hole , a mirror and a pair of vases.\n");
	//Room coordenades
	game_map->room[6].x_cor = 0;
	game_map->room[6].y_cor = 3;
	//Bathroom to Main Room
	strcpy(game_map->exit[12].description, "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.\n");
	game_map->exit[12].way = 2;
	game_map->exit[12].to_room = 4;
	game_map->exit[12].in_room = 6;
	game_map->exit[12].door = true;
	game_map->exit[12].door_state = false;



	//Jack's Forge Shop Data
	strcpy(game_map->room[7].name, "\nJack's Forge Shop");
	strcpy(game_map->room[7].description, "Little room full of iron tools and with a showcase of weapons behind the counter.\n");
	//Room coordenades
	game_map->room[7].x_cor = -1;
	game_map->room[7].y_cor = 0;
	//Shop to Principal Square
	strcpy(game_map->exit[13].description, "There's the door to go outside at the Principal Square.\n");
	game_map->exit[13].way = 1;
	game_map->exit[13].to_room = 0;
	game_map->exit[13].in_room = 7;
	game_map->exit[13].door = true;
	game_map->exit[13].door_state = true;
	//Shop to Warehouse
	strcpy(game_map->exit[14].description, "Between the tools there's a small door that probalby takes you to the warehouse.");
	game_map->exit[14].way = 3;
	game_map->exit[14].to_room = 8;
	game_map->exit[14].in_room = 7;
	game_map->exit[14].door = true;
	game_map->exit[14].door_state = true;



	//Jack's Forge Warehouse Data
	strcpy(game_map->room[8].name, "\nJack's Forge Warehouse");
	strcpy(game_map->room[8].description, "Amazingly big and dirty room full of metal pieces.Probably this is the biggest underground warehouse that I have ever seen.\n");
	//Room coordenades
	game_map->room[8].x_cor = -2;
	game_map->room[8].y_cor = 0;
	//Warehouse to Shop
	strcpy(game_map->exit[15].description, "That's the little door for go back to the Jack's Shop.\n");
	game_map->exit[15].way = 1;
	game_map->exit[15].to_room = 7;
	game_map->exit[15].in_room = 8;
	game_map->exit[15].door = true;
	game_map->exit[15].door_state = true;
	//Warehouse to Large Furnace
	strcpy(game_map->exit[16].description, "There's a big door practically invisible for the dirt.\n");
	game_map->exit[16].way = 2;
	game_map->exit[16].to_room = 9;
	game_map->exit[16].in_room = 8;
	game_map->exit[16].door = true;
	game_map->exit[16].door_state = true;



	//Jack's Forge Large Furnace Data
	strcpy(game_map->room[9].name, "\nJack's Forge Large Furnace");
	strcpy(game_map->room[9].description, "Excessively large furnace that can melt the most resistant metals. It not seems to have been used for melt metals..\n");
	// room coordenades
	game_map->room[9].x_cor = -2;
	game_map->room[9].y_cor = -1;
	//Large Furnace to Warehouse
	strcpy(game_map->exit[17].description, "There's the warehouse where you come from.\n");
	game_map->exit[17].way = 0;
	game_map->exit[17].to_room = 8;
	game_map->exit[17].in_room = 9;
	game_map->exit[17].door = true;
	game_map->exit[17].door_state = true;

	//Character Initalization
	me->Initialize();
}