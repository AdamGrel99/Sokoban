#pragma once

#include "Poziomy.h"
#include "ZmienneGry.h"

// zmienne menu
static int menu{};
static enum class Game { MAIN, START, OPTION, INSTRUCTION };
static Game mode = Game::MAIN;
// zmienne opcje
static int option{};
static std::vector<std::string> tabLevel = { "LEVEL 1", "LEVEL 2", "LEVEL 3", "LEVEL 4", "LEVEL 5", "LEVEL 6", "LEVEL 7", "LEVEL 8" };
static char tabCharacter[3] = { '&', '#', 'E' };
static char tabBox[3] = { 'S', 'a', '<' };
static char tabBoxOnTheTarget[3] = { '$', '@', '=' };
static int typeLevel{};
static int typeCharacter{};
static int typeBox{};