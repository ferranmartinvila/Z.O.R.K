#ifndef _exits_
#define _exits_
#include"string.h"
class exits{
public:
	int room_1, room_2;
	string description_1, description_2;
	bool door, door_state;

	exits(const int cpy_room_1, const int cpy_room_2, const string& cpy_description_1, const string& cpy_description_2, const bool& cpy_door, const bool& cpy_door_state){
		room_1 = cpy_room_1;
		room_2 = cpy_room_2;
		description_1 = cpy_description_1;
		description_2 = cpy_description_2;
		door = cpy_door;
		door_state = cpy_door_state;
	}
};
#endif