#pragma once

#include "Poziomy.h"
#include "ZmienneMenu.h"

// zmienne gry
static int countOfMove{}, countOfTargets{};
static enum class Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
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
static std::vector<std::vector<char>> levelInGame = level8.numberLevel;
static int boyX = level8.boyX;
static int boyY = level8.boyY;
static int m = level8.m;
static int n = level8.n;
static int numberOfTargetsOnThisLevel = level8.numberOfTargetsOnThisLevel;

// zmienne do gry
static char character = '&';
static char box = 'S';
static char boxOnTheTarget = '$';

// sta³e do gry
const char forbiddenField = 'X';
const char emptyField = ' ';
const char targetField = '0';
