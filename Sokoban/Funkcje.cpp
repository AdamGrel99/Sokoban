#include <iostream>
#include <Windows.h>
#include "Funkcje.h"
#include "Poziomy.h"

// ************ funckje pomocnicze *****************

// funkcja odpowiedzialna za to, aby konsola nie miga³a(je¿eli u¿ywa³bym system("cls")), odpowiada za nadpisywanie isnietj¹cej zawartoœci w konsoli
void goToXY(int x, int y) {   
	HANDLE hCon;
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}
// funkcja sprawdza czy wychodzimy poza zakres wektora
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
	
	if (levelInGame[boyY + coordinateY][boyX + coordinateX] != field) {
		return true;
	}

	return false;
}

bool ifYouCanGo(int coordinateY1, int coordinateX1, char field1, int coordinateY2, int coordinateX2, char field2) {
	if (checkIfOutOfBoundaries(coordinateY1, coordinateX1)) {
		return false;
	}

	if ((levelInGame[boyY + coordinateY1][boyX + coordinateX1] != field1) && (levelInGame[boyY + coordinateY2][boyX + coordinateX2] == field2)) {
		return true;
	}

	return false;
}

void movementAlgorithm(int coordinateY, int coordinateX, char field, char& temp1, char& temp2) {
	switch (dir) {
	case Direction::UP:
		temp2 = levelInGame[coordinateY][coordinateX];
		levelInGame[coordinateY][coordinateX] = field;
		levelInGame[coordinateY + 1][coordinateX] = temp1;
		temp1 = temp2;
		break;
	case Direction::LEFT:
		temp2 = levelInGame[coordinateY][coordinateX];
		levelInGame[coordinateY][coordinateX] = field;
		levelInGame[coordinateY][coordinateX + 1] = temp1;
		temp1 = temp2;
		break;
	case Direction::RIGHT:
		temp2 = levelInGame[coordinateY][coordinateX];
		levelInGame[coordinateY][coordinateX] = field;
		levelInGame[coordinateY][coordinateX - 1] = temp1;
		temp1 = temp2;
		break;
	case Direction::DOWN:
		temp2 = levelInGame[coordinateY][coordinateX];
		levelInGame[coordinateY][coordinateX] = field;
		levelInGame[coordinateY - 1][coordinateX] = temp1;
		temp1 = temp2;
		break;
	}
}

void movementAlgorithm(int coordinateY, int coordinateX, char& temp1, char& temp2, char field, char field2) {
	switch (dir) {
	case Direction::UP:
		temp2 = levelInGame[coordinateY][coordinateX];
		levelInGame[coordinateY][coordinateX] = field;
		levelInGame[coordinateY + 1][coordinateX] = field2;
		temp1 = temp2;
		break;
	case Direction::LEFT:
		temp2 = levelInGame[coordinateY][coordinateX];
		levelInGame[coordinateY][coordinateX] = field;
		levelInGame[coordinateY][coordinateX + 1] = field2;
		temp1 = temp2;
		break;
	case Direction::RIGHT:
		temp2 = levelInGame[coordinateY][coordinateX];
		levelInGame[coordinateY][coordinateX] = field;
		levelInGame[coordinateY][coordinateX - 1] = field2;
		temp1 = temp2;
		break;
	case Direction::DOWN:
		temp2 = levelInGame[coordinateY][coordinateX];
		levelInGame[coordinateY][coordinateX] = field;
		levelInGame[coordinateY - 1][coordinateX] = field2;
		temp1 = temp2;
		break;
	}
}

// ************ funckje do menu *****************
// funkcja odpowiedzialna za chowanie kursora podczas odpalania programu (dziala tylko dla wartoœci domyslnych konsoli)
void HideCursor() {
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}
// funkcja nie pozwalaj¹ca wyjœc poza zakres w menu i opcjach
void moveInMenu(int& option, int max) {
	if (option < 0) {
		option = max;
	}
	else if (option > max) {
		option = 0;
	}
}

void gameOption(Game& mode) {
	std::system("cls");

	switch (option) {
	case 0:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << ">> Level : " << tabLevel[typeLevel] << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "Box : " << std::endl;
		std::cout << "Character : " << std::endl;
		break;
	case 1:
		std::cout << "Level : " << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << ">> Box : " << tabBox[typeBox] << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "Character : " << std::endl;
		break;
	case 2:
		std::cout << "Level : " << std::endl;
		std::cout << "Box : " << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << ">> Character : " << tabCharacter[typeCharacter] << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	}
	std::system("pause>0");

	if (GetAsyncKeyState(VK_ESCAPE)) {
		box = tabBox[typeBox];
		boxOnTheTarget = tabBoxOnTheTarget[typeBox];		
		character = tabCharacter[typeCharacter];

		levelInGame = vectorOfLevels[typeLevel].numberLevel;
		boyX = vectorOfLevels[typeLevel].boyX;
		boyY = vectorOfLevels[typeLevel].boyY;
		m = vectorOfLevels[typeLevel].m;
		n = vectorOfLevels[typeLevel].n;
		numberOfTargetsOnThisLevel = vectorOfLevels[typeLevel].numberOfTargetsOnThisLevel;

		mode = Game::MAIN;
		std::system("cls");
	}
	else if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
		if (option == 0) {
			typeLevel--;
		}
		else if (option == 1) {
			typeBox--;
		}
		else if (option == 2) {
			typeCharacter--;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		if (option == 0) {
			typeLevel++;
		}
		if (option == 1) {
			typeBox++;
		}
		else if (option == 2) {
			typeCharacter++;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
		option++;
		Sleep(80);
	}
	else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
		option--;
		Sleep(80);
	}

	moveInMenu(option, 2);
	moveInMenu(typeBox, 2);
	moveInMenu(typeCharacter, 2);
	moveInMenu(typeLevel, 7);
}

void gameInstruction(Game& mode) {
	std::system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	std::cout << "*** Instruction Sokoban Game ***" << std::endl << std::endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	std::cout << "These are the default controls for playing Sokoban :" << std::endl << std::endl;;
	std::cout << "- Arrow or 'WASD' keys for movement." << std::endl;
	std::cout << "- Q for reset." << std::endl;
	std::cout << "- ESC for return." << std::endl << std::endl;

	std::cout << "These are the specific rules to solve a Classic puzzle :" << std::endl << std::endl;;
	std::cout << "- Only one box can be pushed at a time." << std::endl;
	std::cout << "- A box cannot be pulled." << std::endl;
	std::cout << "- The player cannot walk through boxes or walls." << std::endl;
	std::cout << "- The puzzle is solved when all boxes are on the goals." << std::endl << std::endl;

	std::cout << "In Options you can change character and box, if you like." << std::endl;
	std::cout << "Good luck" << std::endl;

	std::system("pause>0");

	if (GetAsyncKeyState(VK_ESCAPE)) {
		mode = Game::MAIN;
	}
}

void mainMenu(Game& mode) {
	std::system("cls");

	switch (menu) {
	case 0:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // zielony
		std::cout << ">> Play the Game" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // domylny bia³y
		std::cout << "Option" << std::endl;
		std::cout << "Instruction" << std::endl;
		std::cout << "End Game" << std::endl;
		break;
	case 1:
		std::cout << "Play the Game" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << ">> Option" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "Instruction" << std::endl;
		std::cout << "End Game" << std::endl;
		break;
	case 2:
		std::cout << "Play the Game" << std::endl;
		std::cout << "Option" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << ">> Instruction" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "End Game" << std::endl;
		break;
	case 3:
		std::cout << "Play the Game" << std::endl;
		std::cout << "Option" << std::endl;
		std::cout << "Instruction" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << ">> End Game" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	}

	std::system("pause>0");
	
	if (GetAsyncKeyState(VK_RETURN)) {
		switch (menu) {
		case 0:
			mode = Game::START;
			std::system("cls");
			break;
		case 1:
			mode = Game::OPTION;
			std::system("cls");
			break;
		case 2:
			mode = Game::INSTRUCTION;
			std::system("cls");
			break;
		case 3:
			std::system("cls");
			exit(0);
			break;
		}
	}

	// naprawia b³¹d wynikaj¹cy z naciœniêcie 'wasd' przed nacisnieciem play the game (dir = stop)
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A') || GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		dir = Direction::STOP;
	}
	else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
		dir = Direction::STOP;
		menu++;
		Sleep(80);
	}
	else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
		dir = Direction::STOP;
		menu--;
		Sleep(80);
	}
	else if (GetAsyncKeyState(VK_ESCAPE)) {
		std::system("cls");
		exit(0);
	}

	moveInMenu(menu, 3);
}

// ************ funckje do gry *****************

void resetSetup() {
	normalSetup();
	levelInGame = vectorOfLevels[typeLevel].numberLevel;
	boyX = vectorOfLevels[typeLevel].boyX;
	boyY = vectorOfLevels[typeLevel].boyY;
	m = vectorOfLevels[typeLevel].m;
	n = vectorOfLevels[typeLevel].n;
	numberOfTargetsOnThisLevel = vectorOfLevels[typeLevel].numberOfTargetsOnThisLevel;
	std::system("cls");
}

void normalSetup() {
	dir = Direction::STOP;
	countOfMove = 0;
	countOfTargets = 0;
}

void gameDraw() {
	goToXY(0, 0);

	std::cout << "*** " << tabLevel[typeLevel] << " ***" << std::endl << std::endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (box != 'S' || character != '&') {
				if (levelInGame[i][j] == 'S') {
					levelInGame[i][j] = tabBox[typeBox];
				}
				if (levelInGame[i][j] == '$') {
					levelInGame[i][j] = tabBoxOnTheTarget[typeBox];
				}
				if (levelInGame[i][j] == '&') {
					levelInGame[i][j] = tabCharacter[typeCharacter];
				}
			}

			if (levelInGame[i][j] == boxOnTheTarget || levelInGame[i][j] == targetField) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); // zielony
			}
			else if (levelInGame[i][j] == box) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5); // fioletowy
			}
			else if (levelInGame[i][j] == character) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // ¿ó³ty
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // domyslny bia³y
			}

			std::cout << levelInGame[i][j];
			
			if (levelInGame[i][j] == boxOnTheTarget) {
				countOfTargets++;
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "Moves: " << countOfMove << std::endl;
	std::cout << "Targets: " << countOfTargets << "/" << numberOfTargetsOnThisLevel << std::endl;

	// Opcja zwiekszania targetów oraz warunek koñca levela
	if (countOfTargets == numberOfTargetsOnThisLevel) {
		if (typeLevel == 7) {
			typeLevel = 0;
		}
		else {
			typeLevel++;
		}
		resetSetup();
	}
	else {
		countOfTargets = 0;
		std::system("pause>0");
	}
}

void gameInput(Game& mode) {
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
		resetSetup();
	}
	else if (GetAsyncKeyState('Q')) {
		resetSetup();
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
			if (levelInGame[boyY - 1][boyX] == box) {
				movementAlgorithm(boyY - 2, boyX, box, variableToMoveBox1, variableToMoveBox2);
				// chroni przed zapisaniem targetField do pamieci i wypisaniem jej przy poruszeniu innej skrzynki
				if (variableToMoveBox1 == '0') {
					levelInGame[boyY - 2][boyX] = boxOnTheTarget;
					variableToMoveBox1 = emptyField;
				}
			}
			else if (levelInGame[boyY - 1][boyX] == boxOnTheTarget) {
				if (levelInGame[boyY - 2][boyX] == '0') {
					movementAlgorithm(boyY - 2, boyX, variableToMoveBox1, variableToMoveBox2, boxOnTheTarget, targetField);
					if (variableToMoveBox1 == '0') {
						levelInGame[boyY - 2][boyX] = boxOnTheTarget;
						variableToMoveBox1 = emptyField;
					}
				}
				else {
					movementAlgorithm(boyY - 2, boyX, variableToMoveBox1, variableToMoveBox2, box, targetField);
				}
			}
			break;
		case Direction::LEFT:
			if (levelInGame[boyY][boyX - 1] == box) {
				movementAlgorithm(boyY, boyX - 2, box, variableToMoveBox1, variableToMoveBox2);
				if (variableToMoveBox1 == '0') {
					levelInGame[boyY][boyX - 2] = boxOnTheTarget;
					variableToMoveBox1 = emptyField;
				}
			}
			else if (levelInGame[boyY][boyX - 1] == boxOnTheTarget) {
				if (levelInGame[boyY][boyX - 2] == '0') {
					movementAlgorithm(boyY, boyX - 2, variableToMoveBox1, variableToMoveBox2, boxOnTheTarget, targetField);
					if (variableToMoveBox1 == '0') {
						levelInGame[boyY][boyX - 2] = boxOnTheTarget;
						variableToMoveBox1 = emptyField;
					}
				}
				else {
					movementAlgorithm(boyY, boyX - 2, variableToMoveBox1, variableToMoveBox2, box, targetField);
				}
			}
			break;
		case Direction::RIGHT:
			if (levelInGame[boyY][boyX + 1] == box) {
				movementAlgorithm(boyY, boyX + 2, box, variableToMoveBox1, variableToMoveBox2);
				if (variableToMoveBox1 == '0') {
					levelInGame[boyY][boyX + 2] = boxOnTheTarget;
					variableToMoveBox1 = emptyField;
				}
			} 
			else if (levelInGame[boyY][boyX + 1] == boxOnTheTarget) {
				if (levelInGame[boyY][boyX + 2] == '0') {
					movementAlgorithm(boyY, boyX + 2, variableToMoveBox1, variableToMoveBox2, boxOnTheTarget, targetField);
					if (variableToMoveBox1 == '0') {
						levelInGame[boyY][boyX + 2] = boxOnTheTarget;
						variableToMoveBox1 = emptyField;
					}
				}
				else {
					movementAlgorithm(boyY, boyX + 2, variableToMoveBox1, variableToMoveBox2, box, targetField);
				}
			}
			break;
		case Direction::DOWN:
			if (levelInGame[boyY + 1][boyX] == box) {
				movementAlgorithm(boyY + 2, boyX, box, variableToMoveBox1, variableToMoveBox2);
				if (variableToMoveBox1 == '0') {
					levelInGame[boyY + 2][boyX] = boxOnTheTarget;
					variableToMoveBox1 = emptyField;
				}
			}else if (levelInGame[boyY + 1][boyX] == boxOnTheTarget) {
				if (levelInGame[boyY + 2][boyX] == '0') {
					movementAlgorithm(boyY + 2, boyX, variableToMoveBox1, variableToMoveBox2, boxOnTheTarget, targetField);
					if (variableToMoveBox1 == '0') {
						levelInGame[boyY + 2][boyX] = boxOnTheTarget;
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
