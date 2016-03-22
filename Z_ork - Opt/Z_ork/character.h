#ifndef _Character_
#define _Character_
struct character{
	int pos_x, pos_y, inroom;
	void Initialize(){
		pos_x = pos_y = inroom = 0;
	}
};
#endif