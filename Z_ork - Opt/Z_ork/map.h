#include"rooms.h"
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
};
#endif