#pragma once

char level1[9][8]{
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

// zmienne planszy na określonym levelu
int boyX = 2;
int boyY = 2;
int m = 9;
int n = 8;
int numberOfTargetsOnThisLevel = 7;

/*
char level2[10][14]{
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
int boyX = 7;
int boyY = 4;
int m = 10;
int n = 14;
int numberOfTargetsOnThisLevel = 10;
*/

/*
char level3[10][17]{
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
int boyX = 14;
int boyY = 1;
int m = 10;
int n = 17;
int numberOfTargetsOnThisLevel = 11;
*/