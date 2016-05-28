#include "World.h"
#include "string.h"
#include "vector.h"
#include "leaks.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define SIZE 35

world *game = nullptr;
int main(){
	ReportMemoryLeaks();
	//Game data
	game = new world;
	game->Initialize();
	bool option = true;
	//kbhit test
	//Time data
	unsigned int last_time = 0;
	unsigned int update_rate = 2500;
	unsigned int current_time;
	//Instruction data
	char instruction[SIZE];
	unsigned int string_position = 0;
	vector<string> order;
	
	//Game loop
	while (option){
		//Update time data
		current_time = GetTickCount();
		//Program waiting
		if (current_time > last_time + update_rate){
			//Udates the game entities
			printf("\n game updated...\n");
			for (int k = 0; k < MAX_ENTITY; k++){
				game->game_data.buffer[k]->Update();
			}
			last_time = current_time;
		}
		//Reading input
		if (_kbhit()){
			if (string_position < SIZE){
				//Get all instruction chars
				instruction[string_position] = _getch();
				string_position++;
				//Instruction finished
				if (instruction[string_position - 1] == '\r'){
					instruction[string_position - 1] = '\0';
					printf("Your instruction: %s\n", instruction);
					//Tokenize the instruction
					order = tokenize(instruction);
					//Apply user input
					game->get_instruction(order);
					option = game->apply_order(order);
					//Imput data clean
					string_position = 0;
					order.clean();
				}
			}
			//Lenght error
			else { printf("Imput Reset.\n"); string_position = 0; }
		}
	}
	return 0;
}