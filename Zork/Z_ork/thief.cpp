#include "thief.h"
#include "World.h"
#include <time.h>
#include <conio.h>
void thief::Attack(){
	if (game->me->live_points >= 1 && game->me->location == location && action == ATTACK && alive){
		action = ATTACK;
		game->me->live_points -= attack;
		printf("\n%s hit you with %i damage!", name.get_string(), attack);
	}
	if (game->me->live_points <= 0){
		printf("\n%s kills you!enter['reset'] to reset de game at before the fight.", name.get_string());
		game->me->action = DEAD;
		game->me->alive = false;
	}
	if (live_points <= 0){
		action = NOTHING;
		game->me->action = NOTHING;
		Drop();
		Die();
		printf("You get +250 money");
		game->me->money += 250;
	}
	else action = NOTHING;
}


void thief::Update(){
	if (action == ATTACK){
		Attack();
	}
	else if(alive){
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
				printf("\n%s is inside the %s\n", name.get_string(), location->name.get_string());
			}
		
	}
}

