#include "soldier.h"
#include "World.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void soldier::Update(){
	if (action == ATTACK){
		Attack();
	}
}

