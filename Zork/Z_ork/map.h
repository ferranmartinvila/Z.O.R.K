#ifndef _map_
#define _map_
#include "rooms.h"
#include "exits.h"
#include "dinamic_array.h"
class map{
public:
	vector<rooms*>room;
	vector<exits*>exit;
};
#endif