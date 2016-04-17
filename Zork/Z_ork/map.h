#ifndef _map_
#define _map_
#include "rooms.h"
#include "exits.h"
#include"chest.h"
#include "dinamic_array.h"
class map{
public:
	vector<chest*>chests;
	vector<room*>rooms;
	vector<exit*>exits;
};
#endif