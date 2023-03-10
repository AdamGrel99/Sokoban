#pragma once

#include <vector>
#include <string>

struct Level {
	std::vector<std::vector<char>> numberLevel;
	// zmienne planszy na określonym levelu
	int boyX;
	int boyY;
	int m;
	int n;
	int numberOfTargetsOnThisLevel;
};

static std::vector<std::vector<char>> boardOfLevel1{
		{'X','X','X','X','X','X','X','X'},
		{'X','X','X',' ',' ',' ','X','X'},
		{'X','0','&','S',' ',' ','X','X'},
		{'X','X','X',' ','S','0','X','X'},
		{'X','0','X','X','S',' ','X','X'},
		{'X',' ','X',' ','0',' ','X','X'},
		{'X','S',' ','$','S','S','0','X'},
		{'X',' ',' ',' ','0',' ',' ','X'},
		{'X','X','X','X','X','X','X','X'}
};

static std::vector<std::vector<char>> boardOfLevel2{
		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		{'X','0','0',' ',' ','X',' ',' ',' ',' ',' ','X','X','X'},
		{'X','0','0',' ',' ','X',' ','S',' ',' ','S',' ',' ','X'},
		{'X','0','0',' ',' ','X','S','X','X','X','X',' ',' ','X'},
		{'X','0','0',' ',' ',' ',' ','&',' ','X','X',' ',' ','X'},
		{'X','0','0',' ',' ','X',' ','X',' ',' ','S',' ','X','X'},
		{'X','X','X','X','X','X',' ','X','X','S',' ','S',' ','X'},
		{'X','X','X',' ','S',' ',' ','S',' ','S',' ','S',' ','X'},
		{'X','X','X',' ',' ',' ',' ','X',' ',' ',' ',' ',' ','X'},
		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
};

static std::vector<std::vector<char>> boardOfLevel3{
		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ',' ',' ',' ',' ','&','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ','S','X','S',' ','X','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ','S',' ',' ','S','X','X','X'},
		{'X','X','X','X','X','X','X','X','X','X','S',' ','S',' ','X','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ','S',' ','X',' ','X','X','X'},
		{'X','0','0','0','0',' ',' ','X','X',' ','S',' ',' ','S',' ',' ','X'},
		{'X','X','0','0','0',' ',' ',' ',' ','S',' ',' ','S',' ',' ',' ','X'},
		{'X','0','0','0','0',' ',' ','X','X','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
};

static std::vector<std::vector<char>> boardOfLevel4{
		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ',' ',' ','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ','X','S','X','X',' ',' ','X'},
		{'X','X','X','X','X','X','X','X','X',' ',' ',' ',' ',' ','S',' ','X'},
		{'X','X','X','X','X','X','X','X','X',' ','X','X','X',' ',' ',' ','X'},
		{'X','0','0','0','0',' ',' ','X','X',' ','S',' ',' ','S','X','X','X'},
		{'X','0','0','0','0',' ',' ',' ',' ','S',' ','S','S',' ','X','X','X'},
		{'X','0','0','0','0',' ',' ','X','X','S',' ',' ','S',' ','&','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ',' ','S',' ',' ','X','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ','S',' ','S',' ',' ','X','X'},
		{'X','X','X','X','X','X','X','X','X','X','X',' ','X','X',' ','X','X'},
		{'X','X','X','X','X','X','X','X','X','X','X',' ',' ',' ',' ','X','X'},
		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
};

static std::vector<std::vector<char>> boardOfLevel5{
		{'X','X','X','X','X','X','X','X','X','X','X','X'},
		{'X','0','0',' ',' ','X','X','X','X','&','X','X'},
		{'X','0','0',' ',' ','X','X','X',' ',' ',' ','X'},
		{'X','0','0',' ',' ',' ',' ',' ','S','S',' ','X'},
		{'X','0','0',' ',' ','X',' ','X',' ','S',' ','X'},
		{'X','0','0','X','X','X',' ','X',' ','S',' ','X'},
		{'X','X','X','X',' ','S',' ','X','S',' ',' ','X'},
		{'X','X','X','X',' ',' ','S','X',' ','S',' ','X'},
		{'X','X','X','X',' ','S',' ',' ','S',' ',' ','X'},
		{'X','X','X','X',' ',' ','X','X',' ',' ',' ','X'},
		{'X','X','X','X','X','X','X','X','X','X','X','X'}
};

static std::vector<std::vector<char>> boardOfLevel6{
		{'X','X','X','X','X','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X',' ',' ',' ','X','X'},
		{'X','X',' ','X',' ','&','X','X',' ','S','S',' ','X'},
		{'X',' ',' ',' ',' ','S',' ',' ',' ',' ',' ',' ','X'},
		{'X',' ',' ','S',' ',' ','X','X','X',' ',' ',' ','X'},
		{'X','X','X',' ','X','X','X','X','X','S','X','X','X'},
		{'X',' ','S',' ',' ','X','X','X',' ','0','0','X','X'},
		{'X',' ','S',' ','S',' ','S',' ','0','0','0','X','X'},
		{'X',' ',' ',' ',' ','X','X','X','0','0','0','X','X'},
		{'X',' ','S','S',' ','X','X','X','0','0','0','X','X'},
		{'X',' ',' ','X','X','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X','X','X','X','X'}
};

static std::vector<std::vector<char>> boardOfLevel7{
		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X','X','X',' ',' ','0','0','0','X'},
		{'X','X','X','X','X','X','X','X','X','X','X',' ',' ','0','0','0','X'},
		{'X','X','X','X','X','X','X',' ',' ',' ',' ',' ',' ','0','0','0','X'},
		{'X','X','X','X','X','X','X',' ',' ','X','X',' ',' ','0','0','0','X'},
		{'X','X','X','X','X','X','X','X',' ','X','X',' ',' ','0','0','0','X'},
		{'X','X','X','X','X','X','X','X',' ','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X',' ','S','S','S',' ','X','X','X','X','X','X'},
		{'X','X','X','X','X','X',' ',' ','S',' ','S',' ','X','X','X','X','X'},
		{'X','X',' ',' ',' ','X','S',' ','S',' ',' ',' ','X',' ',' ',' ','X'},
		{'X','&',' ','S',' ',' ','S',' ',' ',' ',' ','S',' ',' ','S',' ','X'},
		{'X','X','X','X','X','X',' ','S','S',' ','S',' ','X','X','X','X','X'},
		{'X','X','X','X','X','X',' ','S',' ',' ',' ',' ','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ',' ','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ',' ','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X',' ',' ','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
};

static std::vector<std::vector<char>> boardOfLevel8{
		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X','X','X',' ',' ','X','X','X','X','X','X'},
		{'X','X','X','X','X','X',' ',' ','X','X','X','S',' ','X','X','X','X','X','X'},
		{'X','X','X','X',' ',' ',' ','&',' ',' ','S',' ',' ','X','X','X','X','X','X'},
		{'X','X','X',' ',' ','S',' ','S','S','X','X',' ','X','X','X','X','X','X','X'},
		{'X','X',' ',' ','X','S','X','X',' ',' ',' ',' ',' ','X','X','X','X','X','X'},
		{'X','X',' ','X',' ','S',' ','S','S',' ','X',' ','X','X','X','X','X','X','X'},
		{'X','X',' ',' ',' ','S',' ','X',' ',' ','X',' ','S',' ','X','X','X','X','X'},
		{'X','X','X','X',' ',' ',' ',' ','X',' ',' ','S','S',' ','X',' ',' ',' ','X'},
		{'X','X','X','X',' ','X','X',' ','S',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		{'X','0',' ',' ',' ',' ','X','X','X',' ',' ','X','X','X','X','X','X','X','X'},
		{'X','0','0',' ','0','0','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		{'X','0','0','0','X','0','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		{'X','0','0','0','0','0','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
};

static Level level1{ boardOfLevel1, 2, 2, 9, 8, 7 };
static Level level2{ boardOfLevel2, 7, 4, 10, 14, 10 };
static Level level3{ boardOfLevel3, 14, 1, 10, 17, 11 };
static Level level4{ boardOfLevel4, 14, 7, 13, 17, 12 };
static Level level5{ boardOfLevel5, 9, 1, 11, 12, 10 };
static Level level6{ boardOfLevel6, 5, 2, 12, 13, 11 };
static Level level7{ boardOfLevel7, 1, 10, 18, 17, 15 };
static Level level8{ boardOfLevel8, 7, 3, 15, 19, 14 };

