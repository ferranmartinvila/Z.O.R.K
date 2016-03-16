#include "Rooms.h"
#include "exits.h"
#ifndef _Map_
#define _Map_
struct map{
	rooms*room = nullptr;
	exits*exit = nullptr;
	map(){
		room = new rooms[10];
		exit = new exits[18];
	}
	~map(){
		delete[]room;
		delete[]exit;
	}
};
#endif