#include <iostream>
#include "character.h"
#include "map.h"
#include "item.h"

#ifndef _world_
#define _world_
class world{
public:
	map*game_map = nullptr;
	character*me = nullptr;
	item*object = nullptr;
	world(){
		game_map = new map;
		me = new character;
		object = new item[8];
	}
	~world(){
		delete me;
		delete game_map;
	}
	void Initialize(){
		//OBJECTS

		//Oil Light
		object[0].name = "Oil Light";
		object[0].description = "An old but usefull oil light.";
		//Golden Dagger
		object[1].name = "Golden Dagger";
		object[1].description = "A little gold Dagger that get the attention of any person that knows about metals.";
		//Furnace Key
		object[2].name = "Furnace Key";
		object[2].description = "A big and strange key which seems to have been used.";
		//Marcus Notes
		object[3].name = "Marcus Notes";
		object[3].description = "Old and poorly maintained notes. Stained by humidity and illegible in certain parts.";
		//Raw food
		object[4].name = "Raw food";
		object[4].description = "Food with a quite advanced state of rot. You will be healthier if you don't eat it.";
		//Wine
		object[5].name = "Wine";
		object[5].description = "An alcoholic drink made from fermented grape juice. This drink is able to persuade anyone.";
		//Knight's Sword
		object[6].name = "Knight's Sword";
		object[6].description = "A huge iron sword full of drawings and with a dragon on the handle.";
		//Bloody Sword
		object[7].name = "Bloody Sword";
		object[7].description = "A magic red sword. It emits a strange energy that provides a supernatural force at the knight that uses it.";

		
		
		//CHARACTER
		me->pos_x = me->pos_y = me->inroom = 0;
		me->name = "Earl the knight";
		me->description = "You are a brave knight from a far village called Gandar there all the people respects you but here in Bloody Sword nobody knows you.";
		
		
		
		//MAP
		//Principal Square Data
		game_map->room[0].name = "Principal Square";
		game_map->room[0].description = "Central Square of Bloody Sword. This square is impollute and there's one of the best kingdom knights sorrounding it. Maybe someone important for the king lives arround here.";
		//Coordenades
		game_map->room[0].x_cor = game_map->room[0].y_cor = 0;
		//Dead end street Data
		game_map->room[1].name = "Dead end Street";
		game_map->room[1].description = "Abandoned street full of rubbish that ends in the wall of the city. Is difficult to stay here to much time, so people only comes here to throw his shit.";
		//Coordenades
		game_map->room[1].x_cor = 1;
		game_map->room[1].y_cor = 0;
		//Ruined House Data
		game_map->room[2].name = "Ruined House";
		game_map->room[2].description = "This house will fall down at any moment it practically don't have roof and you can smell the odor of the street next to this house. Surprisingly here there's a poor family living or more precisely surviving.";
		//Coordenades
		game_map->room[2].x_cor = 0;
		game_map->room[2].y_cor = -1;
		//Jack's House Lobby Data
		game_map->room[3].name = "Jack's House Lobby";
		game_map->room[3].description = "Little and luxury room for recieve guests. Full of family portraits.";
		//Coordenades
		game_map->room[3].x_cor = 0;
		game_map->room[3].y_cor = 1;
		//Jack's House Main Room Data
		game_map->room[4].name = "Jack's House Main Room";
		game_map->room[4].description = "Biggest room of the house filled with belic objects with an incalculable valor. Like bright golden swords.";
		//Coordenades
		game_map->room[4].x_cor = 0;
		game_map->room[4].y_cor = 2;
		//Jack's House Kitchen Data
		game_map->room[5].name = "Jack's House Kitchen";
		game_map->room[5].description = "Big kichen fully of slaves working hard for the owners. Isn't so clean for be a kitchen probably the owners don't enter. They must be very busy.";
		//Room coordenades
		game_map->room[5].x_cor = 1;
		game_map->room[5].y_cor = 2;
		//Jack's House Bathroom Data
		game_map->room[6].name = "Jack's House Bathroom";
		game_map->room[6].description = "The most clean room of the house probably because there's only a hole , a mirror and a pair of vases.";
		//Room coordenades
		game_map->room[6].x_cor = 0;
		game_map->room[6].y_cor = 3;
		//Jack's Forge Shop Data
		game_map->room[7].name = "Jack's Forge Shop";
		game_map->room[7].description = "Little room full of iron tools and with a showcase of weapons behind the counter.";
		//Room coordenades
		game_map->room[7].x_cor = -1;
		game_map->room[7].y_cor = 0;
		//Jack's Forge Warehouse Data
		game_map->room[8].name = "Jack's Forge Warehouse";
		game_map->room[8].description = "Amazingly big and dirty room full of metal pieces.Probably this is the biggest underground warehouse that I have ever seen.";
		//Room coordenades
		game_map->room[8].x_cor = -2;
		game_map->room[8].y_cor = 0;
		//Jack's Forge Large Furnace Data
		game_map->room[9].name = "Jack's Forge Large Furnace";
		game_map->room[9].description = "Excessively large furnace that can melt the most resistant metals.It not seems to have been used for melt metals.";
		// room coordenades
		game_map->room[9].x_cor = -2;
		game_map->room[9].y_cor = -1;





		//Principal Square & Dead end Street
		game_map->exit[0].room_1 = 0;
		game_map->exit[0].room_2 = 1;
		game_map->exit[0].description_1 = "There's an abandoned street. It don't seems to lead anywhere but the polluted air makes impossible see the end.";
		game_map->exit[0].description_2 = "There's the principal Square where you come from better if you go there and get out of this mount of rubbish.";
		game_map->exit[0].door = false;
		game_map->exit[0].door_state = true;
		//Principal Square & Ruined House
		game_map->exit[1].room_1 = 0;
		game_map->exit[1].room_2 = 2;
		game_map->exit[1].description_1 = "Under the herbs there's a ruined house with only one room. I don't know how there's people living there.";
		game_map->exit[1].description_2 = "There's the principal Square where you come from probably is more safe than this ruined house. Better if you go there.";
		game_map->exit[1].door = true;
		game_map->exit[1].door_state = true;
		//Principal Square & Jack's House Lobby
		game_map->exit[2].room_1 = 0;
		game_map->exit[2].room_2 = 3;
		game_map->exit[2].description_1 = "A palace!? This is a poor district! This is probably the most big and shiniy build of Bloody Sword.";
		game_map->exit[2].description_2 = "There's a big wood door that takes you outside.";
		game_map->exit[2].door = true;
		game_map->exit[2].door_state = true;
		//Principal Square & Jack's Forge Shop
		game_map->exit[3].room_1 = 0;
		game_map->exit[3].room_2 = 7;
		game_map->exit[3].description_1 = "There's little but well maintained forge. In the door there's a poster where you can read 'Jack's Forge'.";
		game_map->exit[3].description_2 = "There's the door to go outside at the Principal Square.";
		game_map->exit[3].door = true;
		game_map->exit[3].door_state = true;
		//Shop & Warehouse
		game_map->exit[4].room_1 = 7;
		game_map->exit[4].room_2 = 8;
		game_map->exit[4].description_1 = "Between the tools there's a small door that probalby takes you to the warehouse.";
		game_map->exit[4].description_2 = "That's the little door for go back to the Jack's Shop.";
		game_map->exit[4].door = true;
		game_map->exit[4].door_state = true;
		//Warehouse & Large Furnace
		game_map->exit[5].room_1 = 8;
		game_map->exit[5].room_2 = 9;
		game_map->exit[5].description_1 = "There's a big door practically invisible for the dirt.";
		game_map->exit[5].description_2 = "There's the warehouse where you come from.";
		game_map->exit[5].door = true;
		game_map->exit[5].door_state = true;
		// Lobby & Main Room
		game_map->exit[6].room_1 = 3;
		game_map->exit[6].room_2 = 4;
		game_map->exit[6].description_1 = "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.";
		game_map->exit[6].description_2 = "There's the lobby.";
		game_map->exit[6].door = false;
		game_map->exit[6].door_state = true;
		// Main Room & Kitchen
		game_map->exit[7].room_1 = 4;
		game_map->exit[7].room_2 = 5;
		game_map->exit[7].description_1 = "Is impossible to don't realize about the noise that comes from that room. It sounds like a group of people where fighting.";
		game_map->exit[7].description_2 = "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.";
		game_map->exit[7].door = true;
		game_map->exit[7].door_state = true;
		//Main Room & Bathroom
		game_map->exit[8].room_1 = 4;
		game_map->exit[8].room_2 = 6;
		game_map->exit[8].description_1 = "Theres a door full of crystal decorations. Throwght it is possible to see a mirror but no more.";
		game_map->exit[8].description_2 = "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.";
		game_map->exit[8].door = true;
		game_map->exit[8].door_state = true;

		}
};
#endif
