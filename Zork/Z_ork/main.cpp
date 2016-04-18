#include"World.h"
#include"string.h"
#include"dinamic_array.h"
#include"rooms.h"
#include<stdio.h>
#include"leaks.h"
int main(){
	ReportMemoryLeaks();
	//all the data structure
	world data;
	//initialize game data
	data.Initialize();
	//vector of strings for the user input
	vector<string> instruction;
	
	//game bucle
	char option = 0;
	while (option != 'q'){
		//gets user input and tokenize it
		printf("\n");
		data.get_instruction(instruction);
		//apply the user instruction
		option = data.apply_order(instruction);
		//clean the instruction data for the next order
		instruction.clean();
	}
	
	return 0;
}