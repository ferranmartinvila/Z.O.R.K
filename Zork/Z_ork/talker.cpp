#include "talker.h"
#include "World.h"

void talker::Update(){
	if (action == ATTACK){
		Attack();
	}
}

void talker::Talk(const vector<string> instruction){
	game->me->action = TALK;
	char *option = new char[strlen(instruction.buffer[0].get_string())];
	strcpy_s(option, strlen(instruction.buffer[0].get_string()) + 1, instruction.buffer[0].get_string());
	//Options
	if (option[0] != 'a'&& option[0] != 'b'&& option[0] != 'c'&& option[0] != 'd'&& option[0] != 'e'){
		printf(
			"\n[a]->Who are you?"
			"\n[b]->Can you help me to find my sword?"
			"\n[c]->You have child?"
			"\n[d]->Who's your husband?"
			"\n[e]->Stop talking.");
	}
	switch (option[0]){
	case 'a':
		//Who are you
		printf("Im Mrs Daisy.Lady of this house.");
		break;
	case 'b':
		//Can you help me to find my sword
		printf("Mmmm no sorry I don't know about it.");
		break;
	case 'c':
		//You have child
		printf("Yes. My son Carl is the best of my life.He should be around here.");
		break;
	case 'd':
		//Who's your husband
		printf("My husband is Jack, owner of the Forge and frined of the king!");
		break;
	case 'e':
		//Stop Talking
		printf("Bye!");
		game->me->action = NOTHING;
		game->me->npc_focused = nullptr;
		break;
	}
}