#include <iostream>
#include "funkcje.h"

int main() {
	HideCursor();
	while (true) {
		if (mode == Game::MAIN) {
			mainMenu(mode);
		}
		else if (mode == Game::OPTION) {
			gameOption(mode);
		}
		else if (mode == Game::INSTRUCTION) {
			gameInstruction(mode);
		}
		else {
			normalSetup();
			while (mode == Game::START) {
				gameDraw();
				gameInput(mode);
				gameLogic();
			}
		}
	}
}