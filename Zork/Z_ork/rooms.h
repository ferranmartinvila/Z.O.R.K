#include"entity.h"
#include"string.h"
#ifndef _rooms_
#define _rooms_
class rooms :public entity{
public:
	int x_cor, y_cor;

	//constructs the room with the recived data
	rooms (const string& cpy_name, const string& cpy_description, const int& cpy_x_cor, const int& cpy_y_cor){
		name = cpy_name;
		description = cpy_description;
		x_cor = cpy_x_cor;
		y_cor = cpy_y_cor;
	}
};

#endif