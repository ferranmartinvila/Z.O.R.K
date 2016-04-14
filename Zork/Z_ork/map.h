#include "rooms.h"
#include "exits.h"
#include "dinamic_array.h"
#ifndef _map_
#define _map_

class map{
public:
	vector<rooms*>room;
	vector<exits*>exit;
};
#endif