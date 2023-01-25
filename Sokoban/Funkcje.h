#pragma once

#include "Poziomy.h"
#include "ZmienneGry.h"
#include "ZmienneMenu.h"

// funkcje dla gry
void normalSetup();
void gameDraw();
void gameInput(Game& mode);
void gameLogic();

// funkcje dla menu
void HideCursor();
void gameInstruction(Game& mode);
void gameOption(Game& mode);
void mainMenu(Game& mode);
