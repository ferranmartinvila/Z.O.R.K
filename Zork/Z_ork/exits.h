#ifndef _exits_
#define _exits_
#include"string.h"
#include "entity.h"
struct room;
class exit:public entity{
public:
	//the rooms that the exit connects
	int room_1, room_2;
	//description for the different directions
	string description_1, description_2;
	//the door of the exit 
	bool door, door_state;
	room* connected_room;
	unsigned int direction;
	//exit constructor
	/*exit(const int room_1, const int room_2, const string& description_1, const string& description_2, const bool& door, const bool& door_state):room_1(room_1),room_2(room_2),description_1(description_1),description_2(description_2),door(door),door_state(door_state){
		type = EXIT;
	}*/
	exit(const string& name, const string& description, unsigned int direction, room* connected_room, bool door = false, bool door_state = false) : entity(name, description), connected_room(connected_room), door(door), door_state(door_state), direction(direction) { type = EXIT; };

};
#endif