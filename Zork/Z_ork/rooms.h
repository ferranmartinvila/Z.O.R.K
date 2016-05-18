#ifndef _rooms_
#define _rooms_
#include"entity.h"
#include"string.h"
class room :public entity{
public:
	int x_cor, y_cor;

	//copy room constructor
	room (const string& cpy_name, const string& cpy_description, const int& cpy_x_cor, const int& cpy_y_cor){
		name = cpy_name;
		description = cpy_description;
		x_cor = cpy_x_cor;
		y_cor = cpy_y_cor;
		type = ROOM;
	}
};

#endif