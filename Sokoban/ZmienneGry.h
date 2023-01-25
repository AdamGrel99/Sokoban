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
static int goToNextLevel{};
static std::vector<Level> vectorOfLevels = { level1, level2, level3, level4, level5, level6, level7, level8 };
static std::vector<std::vector<char>> levelInGame = vectorOfLevels[goToNextLevel].numberLevel;
static int boyX = vectorOfLevels[goToNextLevel].boyX;
static int boyY = vectorOfLevels[goToNextLevel].boyY;
static int m = vectorOfLevels[goToNextLevel].m;
static int n = vectorOfLevels[goToNextLevel].n;
static int numberOfTargetsOnThisLevel = vectorOfLevels[goToNextLevel].numberOfTargetsOnThisLevel;
// sta³e do gry
const char forbiddenField = 'X';
const char emptyField = ' ';
const char targetField = '0';
// zmienne do gry
static char character = '&';
static char box = 'S';
static char boxOnTheTarget = '$';