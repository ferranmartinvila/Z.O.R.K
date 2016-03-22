#include"Rooms.h"
#include"exits.h"

#ifndef _map_
#define _map_
class map{
public:
	rooms*room = nullptr;
	exits*exit = nullptr;
	map(){
		room = new rooms[10];
		exit = new exits[9];
	}
	~map(){
		delete[]exit;
		delete[]room;
	}
	void Initialize(){
		//Principal Square Data
		room[0].name = "Principal Square";
		room[0].description = "Central Square of Bloody Sword. This square is impollute and there's one of the best kingdom knights sorrounding it. Maybe someone important for the king lives arround here.";
		//Coordenades
		room[0].x_cor = room[0].y_cor = 0;
		//Dead end street Data
		room[1].name = "Dead end Street";
		room[1].description = "Abandoned street full of rubbish that ends in the wall of the city. Is difficult to stay here to much time, so people only comes here to throw his shit.";
		//Coordenades
		room[1].x_cor = 1;
		room[1].y_cor = 0;
		//Ruined House Data
		room[2].name = "Ruined House";
		room[2].description = "This house will fall down at any moment it practically don't have roof and you can smell the odor of the street next to this house. Surprisingly here there's a poor family living or more precisely surviving.";
		//Coordenades
		room[2].x_cor = 0;
		room[2].y_cor = -1;
		//Jack's House Lobby Data
		room[3].name = "Jack's House Lobby";
		room[3].description = "Little and luxury room for recieve guests. Full of family portraits.";
		//Coordenades
		room[3].x_cor = 0;
		room[3].y_cor = 1;
		//Jack's House Main Room Data
		room[4].name = "Jack's House Main Room";
		room[4].description = "Biggest room of the house filled with belic objects with an incalculable valor. Like bright golden swords.";
		//Coordenades
		room[4].x_cor = 0;
		room[4].y_cor = 2;
		//Jack's House Kitchen Data
		room[5].name = "Jack's House Kitchen";
		room[5].description = "Big kichen fully of slaves working hard for the owners. Isn't so clean for be a kitchen probably the owners don't enter. They must be very busy.";
		//Room coordenades
		room[5].x_cor = 1;
		room[5].y_cor = 2;
		//Jack's House Bathroom Data
		room[6].name = "Jack's House Bathroom";
		room[6].description = "The most clean room of the house probably because there's only a hole , a mirror and a pair of vases.";
		//Room coordenades
		room[6].x_cor = 0;
		room[6].y_cor = 3;
		//Jack's Forge Shop Data
		room[7].name = "Jack's Forge Shop";
		room[7].description = "Little room full of iron tools and with a showcase of weapons behind the counter.";
		//Room coordenades
		room[7].x_cor = -1;
		room[7].y_cor = 0;
		//Jack's Forge Warehouse Data
		room[8].name = "Jack's Forge Warehouse";
		room[8].description = "Amazingly big and dirty room full of metal pieces.Probably this is the biggest underground warehouse that I have ever seen.";
		//Room coordenades
		room[8].x_cor = -2;
		room[8].y_cor = 0;
		//Jack's Forge Large Furnace Data
		room[9].name = "Jack's Forge Large Furnace";
		room[9].description = "Excessively large furnace that can melt the most resistant metals.It not seems to have been used for melt metals.";
		// room coordenades
		room[9].x_cor = -2;
		room[9].y_cor = -1;





		//Principal Square & Dead end Street
		exit[0].room_1 = 0;
		exit[0].room_2 = 1;
		exit[0].description_1 = "There's an abandoned street. It don't seems to lead anywhere but the polluted air makes impossible see the end.";
		exit[0].description_2 = "There's the principal Square where you come from better if you go there and get out of this mount of rubbish.";
		exit[0].door = false;
		exit[0].door_state = true;
		//Principal Square & Ruined House
		exit[1].room_1 = 0;
		exit[1].room_2 = 2;
		exit[1].description_1 = "Under the herbs there's a ruined house with only one room. I don't know how there's people living there.";
		exit[1].description_2 = "There's the principal Square where you come from probably is more safe than this ruined house. Better if you go there.";
		exit[1].door = true;
		exit[1].door_state = true;
		//Principal Square & Jack's House Lobby
		exit[2].room_1 = 0;
		exit[2].room_2 = 3;
		exit[2].description_1 = "A palace!? This is a poor district! This is probably the most big and shiniy build of Bloody Sword.";
		exit[2].description_2 = "There's a big wood door that takes you outside.";
		exit[2].door = true;
		exit[2].door_state = true;
		//Principal Square & Jack's Forge Shop
		exit[3].room_1 = 0;
		exit[3].room_2 = 7;
		exit[3].description_1 = "There's little but well maintained forge. In the door there's a poster where you can read 'Jack's Forge'.";
		exit[3].description_2 = "There's the door to go outside at the Principal Square.";
		exit[3].door = true;
		exit[3].door_state = true;
		//Shop & Warehouse
		exit[4].room_1 = 7;
		exit[4].room_2 = 8;
		exit[4].description_1 = "Between the tools there's a small door that probalby takes you to the warehouse.";
		exit[4].description_2 = "That's the little door for go back to the Jack's Shop.";
		exit[4].door = true;
		exit[4].door_state = true;
		//Warehouse & Large Furnace
		exit[5].room_1 = 8;
		exit[5].room_2 = 9;
		exit[5].description_1 = "There's a big door practically invisible for the dirt.";
		exit[5].description_2 = "There's the warehouse where you come from.";
		exit[5].door = true;
		exit[5].door_state = true;
		// Lobby & Main Room
		exit[6].room_1 = 3;
		exit[6].room_2 = 4;
		exit[6].description_1 = "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.";
		exit[6].description_2 = "There's the lobby.";
		exit[6].door = false;
		exit[6].door_state = true;
		// Main Room & Kitchen
		exit[7].room_1 = 4;
		exit[7].room_2 = 5;
		exit[7].description_1 = "Is impossible to don't realize about the noise that comes from that room. It sounds like a group of people where fighting.";
		exit[7].description_2 = "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.";
		exit[7].door = true;
		exit[7].door_state = true;
		//Main Room & Bathroom
		exit[8].room_1 = 4;
		exit[8].room_2 = 6;
		exit[8].description_1 = "Theres a door full of crystal decorations. Throwght it is possible to see a mirror but no more.";
		exit[8].description_2 = "It seems to be some shiniy objects right there or maybe is the sun reflected in that metal piece.";
		exit[8].door = true;
		exit[8].door_state = true;
	}
};
#endif