#ifndef _chest_
#define _chest_
#include"entity.h"
#include"dinamic_array.h"
#include"item.h"
class chest :public entity{
public:
	vector<item*>storage;
	unsigned int capacity;
	int location;
	chest(item* object, int cpy_location){
		storage.push_back(object);
		capacity = 2;
		location = cpy_location;
		name = "chest";
		description = "A blue metallic box with a limited storage of two";
	}
	void look_it(){
		if (storage.get_size() > 0){
			printf("Chest Storage:\n");
			for (int k = storage.get_size()-1; k >= 0;k--){
				printf("  -%s", storage.buffer[k]->name);
			}
		}
		else printf("There's nothing in the chest!");
	}
};

#endif