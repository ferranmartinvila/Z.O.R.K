#include "thief.h"
#include "World.h"
#include <time.h>
#include <conio.h>
void thief::Attack(){
	if (game->me->live_points >= 1 && game->me->location == location){
		action = ATTACK;
		game->me->live_points -= attack;
		printf("\n%s hit you with %i damage!", name.get_string(), attack);
		if (game->me->live_points <= 0){
			action = NOTHING;
			printf("\n%s kills you!enter['reload'] to reset de game.");
		}
		if (live_points <= 0){
			action = NOTHING;
			Drop();
			Die();
			printf("You get +250 money");
			game->me->money += 250;
		}
	}
	else action = NOTHING;
}
void thief::Update(){
	if (action == ATTACK){
		Attack();
	}
	else{
		list<entity*>::node*temp = last_room->data.first_element;
			int k = exit_choosed;
			while (k){
				temp = temp->next;
				k--;
			}
			if (exit_choosed < 2){
				exit_choosed++;
			}
			else exit_choosed = 0;
			((exit*)temp->data)->connected_room->data.push_back(this);
			location->data.erase(location->data.find_position(this));
			location = ((exit*)temp->data)->connected_room;
			if (location == game->me->location){
				printf("\n%s is inside the %s", name.get_string(), location->name.get_string());
			}
		
	}
}

