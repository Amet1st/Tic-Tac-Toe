#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

const int TICTAC_CELLS = 9;
const int COMPUTER_FIRST_TURNS = 4;  

void showStartMenu();
void showInterface(int array[], int TICTAC_CELLS);
void showField(int array[], int TICTAC_CELLS);
void showTicTac();
void rechargeField();
bool isEnd(int array[], int TICTAC_CELLS);
bool isFull(int array[], int TICTAC_CELLS);
void makeTicTacCenter();
void makeTicTacEdge();
void makeTicTacEven();
void makeHumanFirst();
void makeComputerFirst();
void makeHumanTurn();
void makeComputerTurn();
void makeWin(bool win);
void doNotLose(bool lose);
void makeGoodTurn(); 
bool isComputerWin();
bool isComputerLose();
bool isTrap();
bool isWasAlready(int turn);

int side = 0; 
int choice = 0;
int computerTurn = 0;
int interfaceArray[TICTAC_CELLS] = {1,2,3,4,5,6,7,8,9};
int field[TICTAC_CELLS] = {0};
int computerFirstTurns[COMPUTER_FIRST_TURNS] = {0}; 
int x = 0;
int i = 0;
int humanTurnCounter = 0;
int gameCounter = 0;
string key = "";

int main()
{	
	while (true) {
		rechargeField();
		system("cls");
		showStartMenu();
		cin >> side;
		while (side != 1 and side != 0) {
			showStartMenu();
			cin >> side;
		}
		if (side == 1) {
			makeHumanFirst();
		} 
		else 
		{
			makeComputerFirst();
		}
		gameCounter++;
		cout << endl << "Enter any key to continue ";
		cin >> key;
	}	
	
	return 0;
}

void showStartMenu()
{
	cout << "Welcome to the Tic-Tac GAME!!!" << endl << endl;
	cout << "Choose your side!" << endl;
	cout << "1 - Crosses" << endl;
	cout <<	"0 - Zeros" << endl;
	cout << "Choose: ";
}

void showInterface(int array[], int TICTAC_CELLS)
{
	for (int i = 0; i < TICTAC_CELLS; i++) {
		cout.width(3);
		cout << array[i];
		if ((i + 1) % 3 == 0) {
			cout << endl;
		}
	}
}

void showField(int array[], int TICTAC_CELLS)
{
	for (int i = 0; i < TICTAC_CELLS; i++) {
		cout.width(3);
		if (array[i] == 0) {
			cout << "-";	
		}
		if (array[i] == 1) {
			cout << "0";
		}
		if (array[i] == 2) {
			cout << "x";
		}
		if ((i + 1) % 3 == 0) {
			cout << endl;
		}
	}
}

void rechargeField()
{
	for (int i = 0; i < TICTAC_CELLS; i++) {
		field[i] = 0;
	}
}

bool isEnd(int array[], int TICTAC_CELLS) 
{	
	if (side == 1) {
		if (array[0] == array[1] and array[1] == array[2] and array[0] == 2 and array[1] == 2 and array[2] == 2) {
			showTicTac();
			cout << "Human win";
			return true;
		} 
		else if (array[3] == array[4] and array[4] == array[5] and array[3] == 2 and array[4] == 2 and array[5] == 2) {
			showTicTac();
			cout << "Human win";
			return true;
		}
		else if (array[6] == array[7] and array[7] == array[8] and array[6] == 2 and array[7] == 2 and array[8] == 2) {
			showTicTac();
			cout << "Human win";
			return true;
		} 
		if (array[0] == array[3] and array[3] == array[6] and array[0] == 2 and array[3] == 2 and array[6] == 2) {
			showTicTac();
			cout << "Human win";
			return true;
		} 
		else if (array[1] == array[4] and array[4] == array[7] and array[1] == 2 and array[4] == 2 and array[7] == 2) {
			showTicTac();
			cout << "Human win";
			return true;
		}
		else if (array[2] == array[5] and array[5] == array[8] and array[2] == 2 and array[5] == 2 and array[8] == 2) {
			showTicTac();
			cout << "Human win";
			return true;
		} 
		else if (array[0] == array[4] and array[4] == array[8] and array[0] == 2 and array[4] == 2 and array[8] == 2) {
			showTicTac();
			cout << "Human win";
			return true;
		}
		else if (array[6] == array[4] and array[4] == array[2] and array[6] == 2 and array[4] == 2 and array[2] == 2) {
			showTicTac();
			cout << "Human win";
			return true;
		} 
		if (array[0] == array[1] and array[1] == array[2] and array[0] == 1 and array[1] == 1 and array[2] == 1) {
			showTicTac();
			cout << "Computer win";
			return true;
		} 
		else if (array[3] == array[4] and array[4] == array[5] and array[3] == 1 and array[4] == 1 and array[5] == 1) {
			showTicTac();
			cout << "Computer win";
			return true;
		}
		else if (array[6] == array[7] and array[7] == array[8] and array[6] == 1 and array[7] == 1 and array[8] == 1) {
			showTicTac();
			cout << "Computer win";
			return true;
		} 
		if (array[0] == array[3] and array[3] == array[6] and array[0] == 1 and array[3] == 1 and array[6] == 1) {
			showTicTac();
			cout << "Computer win";
			return true;
		} 
		else if (array[1] == array[4] and array[4] == array[7] and array[1] == 1 and array[4] == 1 and array[7] == 1) {
			showTicTac();
			cout << "Computer win";
			return true;
		}
		else if (array[2] == array[5] and array[5] == array[8] and array[2] == 1 and array[5] == 1 and array[8] == 1) {
			showTicTac();
			cout << "Computer win";
			return true;
		} 
		else if (array[0] == array[4] and array[4] == array[8] and array[0] == 1 and array[4] == 1 and array[8] == 1) {
			showTicTac();
			cout << "Computer win";
			return true;
		}
		else if (array[6] == array[4] and array[4] == array[2] and array[6] == 1 and array[4] == 1 and array[2] == 1) {
			showTicTac();
			cout << "Computer win";
			return true;
		}
		else if (isFull(array, TICTAC_CELLS)) {
			showTicTac();
			cout <<"Draw";
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (array[0] == array[1] and array[1] == array[2] and array[0] == 2 and array[1] == 2 and array[2] == 2) {
			showTicTac();
			cout << "Computer win";
			return true;
		} 
		else if (array[3] == array[4] and array[4] == array[5] and array[3] == 2 and array[4] == 2 and array[5] == 2) {
			showTicTac();
			cout << "Computer win";
			return true;
		}
		else if (array[6] == array[7] and array[7] == array[8] and array[6] == 2 and array[7] == 2 and array[8] == 2) {
			showTicTac();
			cout << "Computer win";
			return true;
		} 
		if (array[0] == array[3] and array[3] == array[6] and array[0] == 2 and array[3] == 2 and array[6] == 2) {
			showTicTac();
			cout << "Computer win";
			return true;
		} 
		else if (array[1] == array[4] and array[4] == array[7] and array[1] == 2 and array[4] == 2 and array[7] == 2) {
			showTicTac();
			cout << "Computer win";
			return true;
		}
		else if (array[2] == array[5] and array[5] == array[8] and array[2] == 2 and array[5] == 2 and array[8] == 2) {
			showTicTac();
			cout << "Computer win";
			return true;
		} 
		else if (array[0] == array[4] and array[4] == array[8] and array[0] == 2 and array[4] == 2 and array[8] == 2) {
			showTicTac();
			cout << "Computer win";
			return true;
		}
		else if (array[6] == array[4] and array[4] == array[2] and array[6] == 2 and array[4] == 2 and array[2] == 2) {
			showTicTac();
			cout << "Computer win";
			return true;
		} 
		else if (array[3] == array[4] and array[4] == array[5] and array[3] == 1 and array[4] == 1 and array[5] == 1) {
			showTicTac();
			cout << "Human win";
			return true;
		}
		else if (array[6] == array[7] and array[7] == array[8] and array[6] == 1 and array[7] == 1 and array[8] == 1) {
			showTicTac();
			cout << "Human win";
			return true;
		} 
		if (array[0] == array[3] and array[3] == array[6] and array[0] == 1 and array[3] == 1 and array[6] == 1) {
			showTicTac();
			cout << "Human win";
			return true;
		} 
		else if (array[1] == array[4] and array[4] == array[7] and array[1] == 1 and array[4] == 1 and array[7] == 1) {
			showTicTac();
			cout << "Human win";
			return true;
		}
		else if (array[2] == array[5] and array[5] == array[8] and array[2] == 1 and array[5] == 1 and array[8] == 1) {
			showTicTac();
			cout << "Human win";
			return true;
		} 
		else if (array[0] == array[4] and array[4] == array[8] and array[0] == 1 and array[4] == 1 and array[8] == 1) {
			showTicTac();
			cout << "Human win";
			return true;
		}
		else if (array[6] == array[4] and array[4] == array[2] and array[6] == 1 and array[4] == 1 and array[2] == 1) {
			showTicTac();
			cout << "Human win";
			return true;
		}
		else if (isFull(array, TICTAC_CELLS)) {
			showTicTac();
			cout <<"Draw";
			return true;
		}
		else {
			return false;
		}
	}
}

bool isFull(int array[], int TICTAC_CELLS)
{
	for (int i = 0; i < TICTAC_CELLS; i++) {
		if (array[i] == 0) {
			return false;
		}
	}
	return true;
}

void showTicTac()
{
	system("cls");
	cout << "Numbers corresponding to each cell: " << endl << endl;
	showInterface(interfaceArray, TICTAC_CELLS);
	cout << "Playing field: " << endl << endl;
	showField(field, TICTAC_CELLS);
}

void makeHumanFirst()
{	
	while (!isEnd(field, TICTAC_CELLS)) {
		showTicTac();
		makeHumanTurn();
		if (!isEnd(field, TICTAC_CELLS))
			makeComputerTurn();
	}
}

void makeComputerFirst()
{	
	showTicTac();
	cout << "Computer turn...";
	Sleep(1500);
	do {
		srand(time(NULL));
		x = rand() % TICTAC_CELLS;
		if (isWasAlready(x)) {
			continue;
		}
		else {
			field[x] = 2;
			computerFirstTurns[gameCounter % 4] = x;
			break;
		}
	} while (true);
	while (!isEnd(field, TICTAC_CELLS)) {
		showTicTac();
		if (!isEnd(field, TICTAC_CELLS))
			makeHumanTurn();
		makeComputerTurn();
	}
}

void makeComputerTurn()
{		
	if (side == 1) {
		if(isComputerWin()){
			cout << "Computer turn...";
			Sleep(1500);
			field[computerTurn] = 1;
		} 
		else if (isComputerLose()) {
			cout << "Computer turn...";
			Sleep(1500);
			field[computerTurn] = 1;
		}
		else {
			makeGoodTurn();	
		}
	}
	else {
		if(isComputerWin()){
			cout << "Computer turn...";
			Sleep(1500);
			field[computerTurn] = 2;
		} 
		else if (isComputerLose()) {
			cout << "Computer turn...";
			Sleep(1500);
			field[computerTurn] = 2;
		}
		else {
			makeGoodTurn();	
		}
	}
	
}

void makeHumanTurn()
{
	if (side == 1) {
		cout << "Please, make turn: ";
		cin >> choice;
		if (field[choice - 1] == 0 and choice <= 9 and choice > 0)
			field[choice - 1] = 2;
		else 
			makeHumanTurn();
	}
	else {
		if (!isEnd(field, TICTAC_CELLS)) {
			cout << "Please, make turn: ";
			cin >> choice;
			if (field[choice - 1] == 0 and choice <= 9 and choice > 0)
				field[choice - 1] = 1;
			else 
				makeHumanTurn();	
		}
	}
}

void makeGoodTurn()
{
	if (isTrap()) {
		if (side == 1) {
			cout << "Computer turn...";
			Sleep(1500);
			field[computerTurn] = 1;	
		}
	} 
	else {
		if (side == 1) {
			cout << "Computer turn...";
			Sleep(1500);
			do {
				srand(time(NULL));
				x = rand() % TICTAC_CELLS;
				if (field[x] != 0) {
					continue;
				}
				else {
					field[x] = 1;
					break;
				}
			} while (field[x] != 0);
		}
		else {
			cout << "Computer turn...";
			Sleep(1500);
			do {
				srand(time(NULL));
				x = rand() % TICTAC_CELLS;
				if (field[x] != 0) {
					continue;
				}
				else {
					field[x] = 2;
					break;
				}
			} while (field[x] != 0);
		}
	}
}

bool isComputerWin()
{
	if (side == 1) {
		if (field[0] == 1 and field[1] == 1 and field[2] == 0) {
			computerTurn = 2; 
			return true;
		}
		else if (field[3] == 1 and field[4] == 1 and field[5] == 0) {
			computerTurn = 5; 
			return true;
		}
		else if (field[6] == 1 and field[7] == 1 and field[8] == 0) {
			computerTurn = 8; 
			return true;
		}
		else if (field[0] == 1 and field[3] == 1 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[1] == 1 and field[4] == 1 and field[7] == 0) {
			computerTurn = 7;
			return true;
		}
		else if (field[2] == 1 and field[5] == 1 and field[8] == 0) {
			computerTurn = 8;
			return true;
		}
		else if (field[0] == 1 and field[4] == 1 and field[8] == 0) {
			computerTurn = 8;
			return true;
		}
		else if (field[6] == 1 and field[4] == 1 and field[2] == 0) {
			computerTurn = 2;
			return true; 
		}
		else if (field[2] == 1 and field[1] == 1 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else if (field[3] == 1 and field[5] == 1 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[8] == 1 and field[7] == 1 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[6] == 1 and field[3] == 1 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else if (field[7] == 1 and field[4] == 1 and field[1] == 0) {
			computerTurn = 1;
			return true;
		}
		else if (field[8] == 1 and field[5] == 1 and field[2] == 0) {
			computerTurn = 2;
			return true;
		}
		else if (field[2] == 1 and field[0] == 1 and field[1] == 0) {
			computerTurn = 1;
			return true;
		}
		else if (field[0] == 1 and field[6] == 1 and field[3] == 0) {
			computerTurn = 3;
			return true;
		}
		else if (field[8] == 1 and field[2] == 1 and field[5] == 0) {
			computerTurn = 5;
			return true;
		}
		else if (field[6] == 1 and field[8] == 1 and field[7] == 0) {
			computerTurn = 7;
			return true;
		}
		else if (field[0] == 1 and field[8] == 1 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[2] == 1 and field[6] == 1 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[4] == 1 and field[2] == 1 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[4] == 1 and field[8] == 1 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (field[0] == 2 and field[1] == 2 and field[2] == 0) {
			computerTurn = 2; 
			return true;
		}
		else if (field[3] == 2 and field[4] == 2 and field[5] == 0) {
			computerTurn = 5; 
			return true;
		}
		else if (field[6] == 2 and field[7] == 2 and field[8] == 0) {
			computerTurn = 8; 
			return true;
		}
		else if (field[0] == 2 and field[3] == 2 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[1] == 2 and field[4] == 2 and field[7] == 0) {
			computerTurn = 7;
			return true;
		}
		else if (field[2] == 2 and field[5] == 2 and field[8] == 0) {
			computerTurn = 8;
			return true;
		}
		else if (field[0] == 2 and field[4] == 2 and field[8] == 0) {
			computerTurn = 8;
			return true;
		}
		else if (field[6] == 2 and field[4] == 2 and field[2] == 0) {
			computerTurn = 2;
			return true; 
		}
		else if (field[2] == 2 and field[1] == 2 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else if (field[3] == 2 and field[5] == 2 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[8] == 2 and field[7] == 2 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[6] == 2 and field[3] == 2 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else if (field[7] == 2 and field[4] == 2 and field[1] == 0) {
			computerTurn = 1;
			return true;
		}
		else if (field[8] == 2 and field[5] == 2 and field[2] == 0) {
			computerTurn = 2;
			return true;
		}
		else if (field[2] == 2 and field[0] == 2 and field[1] == 0) {
			computerTurn = 1;
			return true;
		}
		else if (field[0] == 2 and field[6] == 2 and field[3] == 0) {
			computerTurn = 3;
			return true;
		}
		else if (field[8] == 2 and field[2] == 2 and field[5] == 0) {
			computerTurn = 5;
			return true;
		}
		else if (field[6] == 2 and field[8] == 2 and field[7] == 0) {
			computerTurn = 7;
			return true;
		}
		else if (field[0] == 2 and field[8] == 2 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[2] == 2 and field[6] == 2 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[4] == 2 and field[2] == 2 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[4] == 2 and field[8] == 2 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else {
			return false;
		}
	}
}

bool isComputerLose()
{
	if (side == 1) {
		if (field[0] == 2 and field[1] == 2 and field[2] == 0) {
			computerTurn = 2; 
			return true;
		}
		else if (field[3] == 2 and field[4] == 2 and field[5] == 0) {
			computerTurn = 5; 
			return true;
		}
		else if (field[6] == 2 and field[7] == 2 and field[8] == 0) {
			computerTurn = 8; 
			return true;
		}
		else if (field[0] == 2 and field[3] == 2 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[1] == 2 and field[4] == 2 and field[7] == 0) {
			computerTurn = 7;
			return true;
		}
		else if (field[2] == 2 and field[5] == 2 and field[8] == 0) {
			computerTurn = 8;
			return true;
		}
		else if (field[0] == 2 and field[4] == 2 and field[8] == 0) {
			computerTurn = 8;
			return true;
		}
		else if (field[6] == 2 and field[4] == 2 and field[2] == 0) {
			computerTurn = 2;
			return true; 
		}
		else if (field[2] == 2 and field[1] == 2 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else if (field[3] == 2 and field[5] == 2 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[8] == 2 and field[7] == 2 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[6] == 2 and field[3] == 2 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else if (field[7] == 2 and field[4] == 2 and field[1] == 0) {
			computerTurn = 1;
			return true;
		}
		else if (field[8] == 2 and field[5] == 2 and field[2] == 0) {
			computerTurn = 2;
			return true;
		}
		else if (field[2] == 2 and field[0] == 2 and field[1] == 0) {
			computerTurn = 1;
			return true;
		}
		else if (field[0] == 2 and field[6] == 2 and field[3] == 0) {
			computerTurn = 3;
			return true;
		}
		else if (field[8] == 2 and field[2] == 2 and field[5] == 0) {
			computerTurn = 5;
			return true;
		}
		else if (field[6] == 2 and field[8] == 2 and field[7] == 0) {
			computerTurn = 7;
			return true;
		}
		else if (field[0] == 2 and field[8] == 2 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[2] == 2 and field[6] == 2 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[4] == 2 and field[2] == 2 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[4] == 2 and field[8] == 2 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (field[0] == 1 and field[1] == 1 and field[2] == 0) {
			computerTurn = 2; 
			return true;
		}
		else if (field[3] == 1 and field[4] == 1 and field[5] == 0) {
			computerTurn = 5; 
			return true;
		}
		else if (field[6] == 1 and field[7] == 1 and field[8] == 0) {
			computerTurn = 8; 
			return true;
		}
		else if (field[0] == 1 and field[3] == 1 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[1] == 1 and field[4] == 1 and field[7] == 0) {
			computerTurn = 7;
			return true;
		}
		else if (field[2] == 1 and field[5] == 1 and field[8] == 0) {
			computerTurn = 8;
			return true;
		}
		else if (field[0] == 1 and field[4] == 1 and field[8] == 0) {
			computerTurn = 8;
			return true;
		}
		else if (field[6] == 1 and field[4] == 1 and field[2] == 0) {
			computerTurn = 2;
			return true; 
		}
		else if (field[2] == 1 and field[1] == 1 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else if (field[3] == 1 and field[5] == 1 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[8] == 1 and field[7] == 1 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[6] == 1 and field[3] == 1 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else if (field[7] == 1 and field[4] == 1 and field[1] == 0) {
			computerTurn = 1;
			return true;
		}
		else if (field[8] == 1 and field[5] == 1 and field[2] == 0) {
			computerTurn = 2;
			return true;
		}
		else if (field[2] == 1 and field[0] == 1 and field[1] == 0) {
			computerTurn = 1;
			return true;
		}
		else if (field[0] == 1 and field[6] == 1 and field[3] == 0) {
			computerTurn = 3;
			return true;
		}
		else if (field[8] == 1 and field[2] == 1 and field[5] == 0) {
			computerTurn = 5;
			return true;
		}
		else if (field[6] == 1 and field[8] == 1 and field[7] == 0) {
			computerTurn = 7;
			return true;
		}
		else if (field[0] == 1 and field[8] == 1 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[2] == 1 and field[6] == 1 and field[4] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[4] == 1 and field[2] == 1 and field[6] == 0) {
			computerTurn = 6;
			return true;
		}
		else if (field[4] == 1 and field[8] == 1 and field[0] == 0) {
			computerTurn = 0;
			return true;
		}
		else {
			return false;
		}
	}
}

bool isTrap()
{
	if (side == 1) {
		if (field[0] == 2 and field[8] == 2 and field[3] == 0) {
			computerTurn = 3;
			return true;
		}
		else if (field[0] == 2 and field[8] == 2 and field[5] == 2) {
			computerTurn = 5;
			return true;
		}
		else if (field[6] == 2 and field[2] == 2 and field[3] == 0) {
			computerTurn = 3;
			return true;
		}
		else if (field[6] == 2 and field[2] == 2 and field[5] == 0) {
			computerTurn = 5;
			return true;
		}
		else if (field[0] == 2 and field[1] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[2] == 2 and field[1] == 2) {
			computerTurn = 4;
			return true;
		}
		else if (field[6] == 2 and field[7] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[8] == 2 and field[7] == 0) {
			computerTurn = 4;
			return true;
		}
		else if (field[4] == 2 and field[0] == 0 and field[2] == 0 and field[6] == 0 and field[8] == 0) {
			computerTurn = 0;
			return true;
		}
		else {
			return false;
		}
	}
}

bool isWasAlready(int turn)
{
	for (int i = 0; i < 4; i++) {
		if (computerFirstTurns[i] == turn)
			return true;
	}
	return false;
}
