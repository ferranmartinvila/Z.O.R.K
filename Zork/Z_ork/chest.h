#ifndef _chest_
#define _chest_
#include "entity.h"
#include "item.h"
#include "rooms.h"
class chest :public entity{
public:

	//Storage capactity
	unsigned int capacity;

	room*place;
public:

	//Constructor
	chest(room*place, const string& name, const string& description) :entity(name, description), place(place){
		capacity = 2;
		type = CHEST;
	}
	//Functions
	void look_it(){
		list<entity*>::node* temp = data.first_element;
		printf("%s:\n%s\n\nStorage:\n", name.get_string(),description.get_string());
		if (temp != nullptr){
			while (temp){
				printf("- %s\n", ((entity*)temp->data)->name.get_string());
				temp = temp->next;
			}
		}
		else printf("There's nothing in the chest!");
	}
};

#endif