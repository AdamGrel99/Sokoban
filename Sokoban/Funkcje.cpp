#include <iostream>
#include <Windows.h>
#include "Funkcje.h"

using namespace std;

// funckje pomocnicze

void idzdoxy(int x, int y) {
	HANDLE hCon;
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

bool checkIfOutOfBoundaries(int coordinateY, int coordinateX) {
	if (boyY + coordinateY >= m || boyY + coordinateY < 0 || boyX + coordinateX >= n || boyX + coordinateX < 0) {
		return true;
	}
	return false;
}
bool ifYouCanGo(int coordinateY, int coordinateX, char field) {
	if (checkIfOutOfBoundaries(coordinateY,coordinateX)) {
		return false;
	}
	
	if (level1[boyY + coordinateY][boyX + coordinateX] != field) {
		return true;
	}

	return false;
}

bool ifYouCanGo(int coordinateY1, int coordinateX1, char field1, int coordinateY2, int coordinateX2, char field2) {
	if (checkIfOutOfBoundaries(coordinateY1, coordinateX1)) {
		return false;
	}

	if ((level1[boyY + coordinateY1][boyX + coordinateX1] != field1) && (level1[boyY + coordinateY2][boyX + coordinateX2] == field2)) {
		return true;
	}

	return false;
}

void movementAlgorithm(int coordinateY, int coordinateX, char field, char& temp1, char& temp2) {
	switch (dir) {
	case Direction::UP:
		temp2 = level1[coordinateY][coordinateX];
		level1[coordinateY][coordinateX] = field;
		level1[coordinateY + 1][coordinateX] = temp1;
		temp1 = temp2;
		break;
	case Direction::LEFT:
		temp2 = level1[coordinateY][coordinateX];
		level1[coordinateY][coordinateX] = field;
		level1[coordinateY][coordinateX + 1] = temp1;
		temp1 = temp2;
		break;
	case Direction::RIGHT:
		temp2 = level1[coordinateY][coordinateX];
		level1[coordinateY][coordinateX] = field;
		level1[coordinateY][coordinateX - 1] = temp1;
		temp1 = temp2;
		break;
	case Direction::DOWN:
		temp2 = level1[coordinateY][coordinateX];
		level1[coordinateY][coordinateX] = field;
		level1[coordinateY - 1][coordinateX] = temp1;
		temp1 = temp2;
		break;
	}
}

void movementAlgorithm(int coordinateY, int coordinateX, char& temp1, char& temp2, char field, char field2) {
	switch (dir) {
	case Direction::UP:
		temp2 = level1[coordinateY][coordinateX];
		level1[coordinateY][coordinateX] = field;
		level1[coordinateY + 1][coordinateX] = field2;
		temp1 = temp2;
		break;
	case Direction::LEFT:
		temp2 = level1[coordinateY][coordinateX];
		level1[coordinateY][coordinateX] = field;
		level1[coordinateY][coordinateX + 1] = field2;
		temp1 = temp2;
		break;
	case Direction::RIGHT:
		temp2 = level1[coordinateY][coordinateX];
		level1[coordinateY][coordinateX] = field;
		level1[coordinateY][coordinateX - 1] = field2;
		temp1 = temp2;
		break;
	case Direction::DOWN:
		temp2 = level1[coordinateY][coordinateX];
		level1[coordinateY][coordinateX] = field;
		level1[coordinateY - 1][coordinateX] = field2;
		temp1 = temp2;
		break;
	}
}

// funkcje g³ówne

void normalSetup() {
	dir = Direction::STOP;
	countOfMove = 0;
	countOfTargets = 0;
}

void gameDraw() {
	idzdoxy(0, 0);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << level1[i][j];
			if (level1[i][j] == boxOnTheTarget) {
				countOfTargets++;
			}
		}
		cout << endl;
	}

	cout << endl << "Moves: " << countOfMove << endl;
	cout << "Targets: " << countOfTargets << "/" << numberOfTargetsOnThisLevel << endl;

	// Opcja zwiekszania targetów oraz warunek koñca levela
	if (countOfTargets == numberOfTargetsOnThisLevel) {
		exit(0);
	}
	else {
		countOfTargets = 0;
		system("pause>0");
	}
}

void gameInput() {
	if ((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))) {
		dir = Direction::LEFT;
	}
	else if ((GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))) {
		dir = Direction::RIGHT;
	}
	else if ((GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))) {
		dir = Direction::DOWN;
	}
	else if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))) {
		dir = Direction::UP;
	}
	else if (GetAsyncKeyState(VK_ESCAPE)) {
		mode = Game::MAIN;
	}
}

void gameLogic() {
	//	Poruszanie sie po polach dozwolonych dla chlopa
	switch (dir) {
	case Direction::UP:
		if (ifYouCanGo(-1, 0, forbiddenField) && ifYouCanGo(-1, 0, box) && ifYouCanGo(-1, 0, boxOnTheTarget)) {
			ifCorrectMoveBoy = true;
		}
		break;
	case Direction::LEFT:
		if (ifYouCanGo(0, -1, forbiddenField) && ifYouCanGo(0, -1, box) && ifYouCanGo(0, -1, boxOnTheTarget)) {
			ifCorrectMoveBoy = true;
		}
		break;
	case Direction::RIGHT:
		if (ifYouCanGo(0, 1, forbiddenField) && ifYouCanGo(0, 1, box) && ifYouCanGo(0, 1, boxOnTheTarget)) {
			ifCorrectMoveBoy = true;
		}
		break;
	case Direction::DOWN:
		if (ifYouCanGo(1, 0, forbiddenField) && ifYouCanGo(1, 0, box) && ifYouCanGo(1, 0, boxOnTheTarget)) {
			ifCorrectMoveBoy = true;
		}
		break;
	}
	
	//	Poruszanie sie po polach dozwolonych dla skrzyni
	switch (dir) {
	case Direction::UP:
		if (ifYouCanGo(-2, 0, forbiddenField) && (ifYouCanGo(-2, 0, box, -1, 0, box) || ifYouCanGo(-2, 0, boxOnTheTarget, -1, 0, boxOnTheTarget)) && (ifYouCanGo(-2, 0, box, -1, 0, boxOnTheTarget) || ifYouCanGo(-2, 0, boxOnTheTarget, -1, 0, box))) {
			ifCorrectMoveBox = true;
			ifCorrectMoveBoy = true;
		}
		break;
	case Direction::LEFT:
		if (ifYouCanGo(0, -2, forbiddenField) && (ifYouCanGo(0, -2, box, 0, -1, box) || ifYouCanGo(0, -2, boxOnTheTarget, 0, -1, boxOnTheTarget)) && (ifYouCanGo(0, -2, boxOnTheTarget, 0, -1, box) || ifYouCanGo(0, -2, box, 0, -1, boxOnTheTarget))) {
			ifCorrectMoveBox = true;
			ifCorrectMoveBoy = true;
		}
		break;
	case Direction::RIGHT:
		if (ifYouCanGo(0, 2, forbiddenField) && (ifYouCanGo(0, 2, box, 0, 1, box) || ifYouCanGo(0, 2, boxOnTheTarget, 0, 1, boxOnTheTarget)) && (ifYouCanGo(0, 2, box, 0, 1, boxOnTheTarget) || ifYouCanGo(0, 2, boxOnTheTarget, 0, 1, box))) {
			ifCorrectMoveBox = true;
			ifCorrectMoveBoy = true;
		}
		break;
	case Direction::DOWN:
		if (ifYouCanGo(2, 0, forbiddenField) && (ifYouCanGo(2, 0, box, 1, 0, box) || ifYouCanGo(2, 0, boxOnTheTarget, 1, 0, boxOnTheTarget)) && (ifYouCanGo(2, 0, box, 1, 0, boxOnTheTarget) || ifYouCanGo(2, 0, boxOnTheTarget, 1, 0, box))) {
			ifCorrectMoveBox = true;
			ifCorrectMoveBoy = true;
		}
		break;
	}

	// Ruch skrzyni
	if (ifCorrectMoveBox) {
		switch (dir) {
		case Direction::UP:
			if (level1[boyY - 1][boyX] == box) {
				movementAlgorithm(boyY - 2, boyX, box, variableToMoveBox1, variableToMoveBox2);
				// chroni przed zapisaniem targetField do pamieci i wypisaniem jej przy poruszeniu innej skrzynki
				if (variableToMoveBox1 == '0') {
					level1[boyY - 2][boyX] = boxOnTheTarget;
					variableToMoveBox1 = emptyField;
				}
			}
			else if (level1[boyY - 1][boyX] == boxOnTheTarget) {
				if (level1[boyY - 2][boyX] == '0') {
					movementAlgorithm(boyY - 2, boyX, variableToMoveBox1, variableToMoveBox2, boxOnTheTarget, targetField);
					if (variableToMoveBox1 == '0') {
						level1[boyY - 2][boyX] = boxOnTheTarget;
						variableToMoveBox1 = emptyField;
					}
				}
				else {
					movementAlgorithm(boyY - 2, boyX, variableToMoveBox1, variableToMoveBox2, box, targetField);
				}
			}
			break;
		case Direction::LEFT:
			if (level1[boyY][boyX - 1] == box) {
				movementAlgorithm(boyY, boyX - 2, box, variableToMoveBox1, variableToMoveBox2);
				if (variableToMoveBox1 == '0') {
					level1[boyY][boyX - 2] = boxOnTheTarget;
					variableToMoveBox1 = emptyField;
				}
			}
			else if (level1[boyY][boyX - 1] == boxOnTheTarget) {
				if (level1[boyY][boyX - 2] == '0') {
					movementAlgorithm(boyY, boyX - 2, variableToMoveBox1, variableToMoveBox2, boxOnTheTarget, targetField);
					if (variableToMoveBox1 == '0') {
						level1[boyY][boyX - 2] = boxOnTheTarget;
						variableToMoveBox1 = emptyField;
					}
				}
				else {
					movementAlgorithm(boyY, boyX - 2, variableToMoveBox1, variableToMoveBox2, box, targetField);
				}
			}
			break;
		case Direction::RIGHT:
			if (level1[boyY][boyX + 1] == box) {
				movementAlgorithm(boyY, boyX + 2, box, variableToMoveBox1, variableToMoveBox2);
				if (variableToMoveBox1 == '0') {
					level1[boyY][boyX + 2] = boxOnTheTarget;
					variableToMoveBox1 = emptyField;
				}
			} 
			else if (level1[boyY][boyX + 1] == boxOnTheTarget) {
				if (level1[boyY][boyX + 2] == '0') {
					movementAlgorithm(boyY, boyX + 2, variableToMoveBox1, variableToMoveBox2, boxOnTheTarget, targetField);
					if (variableToMoveBox1 == '0') {
						level1[boyY][boyX + 2] = boxOnTheTarget;
						variableToMoveBox1 = emptyField;
					}
				}
				else {
					movementAlgorithm(boyY, boyX + 2, variableToMoveBox1, variableToMoveBox2, box, targetField);
				}
			}
			break;
		case Direction::DOWN:
			if (level1[boyY + 1][boyX] == box) {
				movementAlgorithm(boyY + 2, boyX, box, variableToMoveBox1, variableToMoveBox2);
				if (variableToMoveBox1 == '0') {
					level1[boyY + 2][boyX] = boxOnTheTarget;
					variableToMoveBox1 = emptyField;
				}
			}else if (level1[boyY + 1][boyX] == boxOnTheTarget) {
				if (level1[boyY + 2][boyX] == '0') {
					movementAlgorithm(boyY + 2, boyX, variableToMoveBox1, variableToMoveBox2, boxOnTheTarget, targetField);
					if (variableToMoveBox1 == '0') {
						level1[boyY + 2][boyX] = boxOnTheTarget;
						variableToMoveBox1 = emptyField;
					}
				}
				else {
					movementAlgorithm(boyY + 2, boyX, variableToMoveBox1, variableToMoveBox2, box, targetField);
				}
			}
			break;
		}
		ifCorrectMoveBox = false;
	}

	// Ruch ch³opa
	if (ifCorrectMoveBoy) {
		switch (dir) {
		case Direction::UP:
			boyY--;
			movementAlgorithm(boyY, boyX, character, variableToMove1, variableToMove2);
			countOfMove++;
			break;
		case Direction::LEFT:
			boyX--;
			movementAlgorithm(boyY, boyX, character, variableToMove1, variableToMove2);
			countOfMove++;
			break;
		case Direction::RIGHT:
			boyX++;
			movementAlgorithm(boyY, boyX, character, variableToMove1, variableToMove2);
			countOfMove++;
			break;
		case Direction::DOWN:
			boyY++;
			movementAlgorithm(boyY, boyX, character, variableToMove1, variableToMove2);
			countOfMove++;
			break;
		}
		ifCorrectMoveBoy = false;
	}
	
	// zapobieganie problemowi dowolnemu naciskaniu przycisków podczas gry
	dir = Direction::STOP;
}

void startGame() {
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