#include "merchant.h"
#include "World.h"

void merchant::Update(){
	if (action == ATTACK){
		Attack();
	}
}

void merchant::Talk(const vector<string> instruction){
	game->me->action = TALK;
	//Show shoper storage
	list<entity*>::node*shoper_temp = data.first_element;
	printf("Jack Storage:\n");
	while (shoper_temp){
		printf("\n- %s[%i]", shoper_temp->data->name.get_string(),((item*)shoper_temp->data)->price);
			shoper_temp = shoper_temp->next;
	}
	//Show your storage
	list<entity*>::node*your_temp = game->me->data.first_element;
	printf("\nYour Storage:\n");
	while (your_temp){
		if (your_temp->data->type == ITEM && ((item*)your_temp->data)->state == UNEQUIPED){
			printf("\n- %s[%i]", your_temp->data->name.get_string(),((item*)your_temp->data)->price);
		}
		your_temp = your_temp->next;
	}
	if (instruction.buffer[0] == "buy" && game->me->object_focused_ad!=nullptr){
		if (game->me->in_bag == 4)printf("You dont have free bag cells.");
		else if (game->me->object_focused_ad->price <= game->me->money){
			printf("\nYou buy %s!", game->me->object_focused_ad->name.get_string());
			Buy(game->me->object_focused_ad);
		}
		else if (game->me->object_focused_ad->price >= game->me->money){
			printf("\nYou don't have enough money.");
		}
		else printf("This object isn't in Jack store");
	}
	else if (instruction.buffer[0] == "sell")printf("\nInvalid Command");
	if (instruction.buffer[0] == "sell" && game->me->object_focused_ad != nullptr){
		if (game->me->object_focused_ad->state == UNEQUIPED){
			printf("You sell %s and get + %i", game->me->object_focused_ad->name.get_string(), game->me->object_focused_ad->price);
			Sell(game->me->object_focused_ad);
		}
		else printf("This object isn't in your available store");
	}
	else if (instruction.buffer[0] == "sell")printf("\nInvalid Command");
	if (instruction.buffer[0] == "quit"){
		//Stop Trading
		printf("\nBye!");
		game->me->action = NOTHING;
		game->me->npc_focused = nullptr;
	}
}