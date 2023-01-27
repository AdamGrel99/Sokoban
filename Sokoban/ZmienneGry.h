#pragma once

#include "Poziomy.h"
#include "ZmienneMenu.h"

// zmienne gry
static int countOfMove{}, countOfTargets{};
static enum class Direction { STOP, LEFT, RIGHT, UP, DOWN };
static Direction dir;
// zmienne do algorytmu przemieszczania siê chopa
static char variableToMove1 = ' ';
static char variableToMove2 = ' ';
static bool ifCorrectMoveBoy = false;
// zmienne do algorytmu przemieszczania siê skrzyni
static char variableToMoveBox1 = ' ';
static char variableToMoveBox2 = ' ';
static bool ifCorrectMoveBox = false;
// zmienne do odpalenia gry
static std::vector<Level> vectorOfLevels = { level1, level2, level3, level4, level5, level6, level7, level8 };
static std::vector<std::vector<char>> levelInGame = vectorOfLevels[0].numberLevel;
static int boyX = vectorOfLevels[0].boyX;
static int boyY = vectorOfLevels[0].boyY;
static int m = vectorOfLevels[0].m;
static int n = vectorOfLevels[0].n;
static int numberOfTargetsOnThisLevel = vectorOfLevels[0].numberOfTargetsOnThisLevel;
// sta³e do gry
const char forbiddenField = 'X';
const char emptyField = ' ';
const char targetField = '0';
// zmienne do gry
static char character = '&';
static char box = 'S';
static char boxOnTheTarget = '$';