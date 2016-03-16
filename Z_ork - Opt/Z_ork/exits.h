#ifndef _Exits_
#define _Exits_
struct exits{
	int in_room,to_room, way;
	bool door;
	bool door_state;
	char  description[300];
};
// 0 north 1 east 2 south 3 west
#endif