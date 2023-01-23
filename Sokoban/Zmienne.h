#pragma once

#include "Poziomy.h"
#include <string>

// zmienne menu
enum class Game { MAIN, START, OPTION, INSTRUCTION };
Game mode = Game::START;
int menu = 0;
// zmienne opcje
int option = 0;
std::string tabLevel[10] = { "LEVEL 1", "LEVEL 2", "LEVEL 3", "LEVEL 4", "LEVEL 5", "LEVEL 6", "LEVEL 7", "LEVEL 8" };
char tabCharacter[3] = { '&', '#', 'E' };
char tabBox[3] = { 'S', 'a', '<' };
char tabBoxOnTheTarget[3] = { '$', '@', '=' };
int typeLevel = 0;
int typeCharacter = 0;
int typeBox = 0;
char character = '&';
char box = 'S';
char boxOnTheTarget = '$';
const char forbiddenField = 'X';
const char emptyField = ' ';
const char targetField = '0';
// zmienne gry
int countOfMove{}, countOfTargets{};
enum class Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
// zmienne do algorytmu przemieszczania siê chopa
char variableToMove1 = ' ';
char variableToMove2 = ' ';
bool ifCorrectMoveBoy = false;
// zmienne do algorytmu przemieszczania siê skrzyni
char variableToMoveBox1 = ' ';
char variableToMoveBox2 = ' ';
bool ifCorrectMoveBox = false;
// zmienne do odpalenia gry
std::vector<std::vector<char>> level1 = leveltest.numberLevel;
int boyX = 2;
int boyY = 2;
int m = 9;
int n = 8;
int numberOfTargetsOnThisLevel = 7;
