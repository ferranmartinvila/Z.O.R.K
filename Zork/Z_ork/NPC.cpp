#include "NPC.h"
#include "World.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void npc::Drop(){
	//Push all the npc items at his room
	int k = 0;
	list<entity*>::node* temp = data.first_element;
	while (temp){
		((item*)temp->data)->state = UNKNOWN;
		((item*)temp->data)->place = location;
		location->data.push_back(temp->data);
		temp = temp->next;
		k++;
		printf("\n%s drop %s", name.get_string(), ((item*)location->data.last_element()->data)->name.get_string());
	}
	if (k == 0)printf("\n%s don't drop anything.", name.get_string());
	//Clean the npc data
	data.clean();
}

void npc::Talk(const vector<string>& instruction){
	printf("\n%s: Sorry I don't want to talk.",name.get_string()); 

}

void npc::Attack(){
	if (game->me->live_points >= 1 && game->me->location == location && action == ATTACK && alive){
		action = ATTACK;
		srand(time(NULL));
		int random = rand() % attack;
		game->me->live_points -= random;
		printf("\n%s hit you with %i damage!", name.get_string(), random);
	}
	if (game->me->live_points <= 0){
		printf("\n%s kills you!enter['reset'] to reset de game.", name.get_string());
		game->me->action = DEAD;
		game->me->alive = false;
	}
	if (live_points <= 0){
		action = NOTHING;
		game->me->action = NOTHING;
		Drop();
		Die();
		printf("You get +100 money");
		game->me->money += 50;
	}
	else action = NOTHING;
}

void npc::Die(){
	this->location->data.erase(this->location->data.find_position(this));
	alive = false;
}

void npc::Sell(item*object){
	object->state = IN_NPC;
	game->me->money += object->price;
	game->me->data.erase(game->me->data.find_position(object));
	data.push_back(object);
}

void npc::Buy(item*object){
	object->state = UNEQUIPED;
	game->me->money -= object->price;
	data.erase(data.find_position(object));
	game->me->data.push_back(object);
}