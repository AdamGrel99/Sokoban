#include <iostream>
#include "funkcje.h"


using namespace std;

int main() {
	//game_Setup();
	while (true) {
		if (mode == Game::MAIN) {
			//main_Menu();
		}
		else if (mode == Game::OPTION) {
			//game_Option();
		}
		else if (mode == Game::INSTRUCTION) {
			//game_Instruction();
		}
		else {
			normalSetup();
			while (mode == Game::START) {
				gameDraw();
				gameInput();
				gameLogic();
			}
		}
	}
}