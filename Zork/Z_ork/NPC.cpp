#include "NPC.h"
#include "World.h"
void npc::Drop(){
	//Push all the npc items at his room
	list<entity*>::node* temp = data.first_element;
	while (temp){
		location->data.push_back(temp->data);
		temp = temp->next;
	}
	//Clean the npc data
	data.clean();
}

void npc::Talk(const vector<string>& instruction){
	printf("\n%s: Sorry I don't want to talk.",name.get_string()); 

}