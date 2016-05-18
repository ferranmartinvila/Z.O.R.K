#include"World.h"
#include"string.h"
#include "vector.h"
#include"rooms.h"
#include<stdio.h>
#include<stdlib.h>
#include"leaks.h"
world *game = nullptr;
int main(){
	ReportMemoryLeaks();
	//all the data structure
	game = new world;
	//initialize game data
	game->Initialize();
	//vector of strings for the user input
	vector<string> instruction;
	bool option=true;
	//game bucle
	while (option){
		//gets user input and tokenize it
		printf("\n\n");
		game->get_instruction(instruction);
		//apply the user instruction
		option = game->apply_order(instruction);
		//clean the instruction data for the next order
		instruction.clean();
	}
	
	return 0;
}