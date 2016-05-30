#include "soldier.h"
#include "World.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void soldier::Attack(){
	if (game->me->live_points >= 1 && game->me->location == location){
		action = ATTACK;
		srand(time(NULL));
		int random = rand() % attack;
		game->me->live_points -= random;
		printf("\n%s hit you with %i damage!", name.get_string(), random);
		if (game->me->live_points <= 0){
			action = NOTHING;
			printf("\n%s kills you!enter['reload'] to reset de game.");
		}
		if (live_points <= 0){
			action = NOTHING;
			Drop();
			Die();
			printf("You get +100 money");
			game->me->money += 100;
		}
	}
	else action = NOTHING;
}
void soldier::Update(){
	if (action == ATTACK){
		Attack();
	}
}

