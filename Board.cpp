#include "Board.h"


Board::Board() {

	char board[9][9] = { { '-', '3', '-', '-', '7', '-', '-', '-', '-' },
						 { '6', '-', '-', '1', '9', '5', '-', '-', '-' },
						 { '-', '9', '8', '-', '-', '-', '-', '6', '-' },
						 { '8', '-', '-', '-', '6', '-', '-', '-', '3' },
						 { '4', '-', '-', '8', '-', '3', '-', '-', '1' },
						 { '7', '-', '-', '-', '2', '-', '-', '-', '6' },
						 { '-', '6', '-', '-', '-', '-', '2', '8', '-' },
						 { '-', '-', '-', '4', '1', '9', '-', '-', '5' },
						 { '-', '-', '-', '-', '8', '-', '-', '7', '9' } };

	//char boardX[9][9] = { { '-', '2', '3', '6', '7', '8', '9', '4', '5' }, //1
	//					 { '5', '8', '4', '2', '3', '9', '7', '6', '1' },
	//					 { '9', '6', '7', '1', '4', '5', '3', '2', '8' },
	//					 { '3', '7', '2', '4', '6', '1', '5', '8', '9' },
	//					 { '6', '9', '1', '5', '8', '3', '2', '7', '4' },
	//					 { '4', '5', '8', '7', '9', '2', '6', '1', '3' },
	//					 { '8', '3', '6', '9', '2', '4', '1', '5', '7' },
	//					 { '2', '1', '9', '8', '5', '7', '4', '3', '6' },
	//					 { '7', '4', '5', '3', '1', '6', '8', '9', '-' } }; //2

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
		{
			aBoard[i][j] = board[i][j];
			//aBoard[i][j] = '-';
		}
	}
}


bool Board::notInRow(char arr[][9], int row) {
	set<char> st;

	for (int x = 0; x < 9; x++) {
		if (st.find(arr[row][x]) != st.end())
			return false;
		if (arr[row][x] != '-')
		{
			st.insert(arr[row][x]);
		}
	}
	return true;
}

bool Board::notInColumn(char arr[][9], int column) {
	set<char> st;

	for (int x = 0; x < 9; x++)
	{
		if (st.find(arr[x][column]) != st.end())
			return false;

			if (arr[x][column] != '-')
				st.insert(arr[x][column]);
	}
	return true;
}

bool Board::notInBox(char arr[][9], int startRow, int startColumn) {
	set<char> st;

	for (int row = 0; row<3; row++)
	{
		for (int column = 0; column < 3; column++) {
			char current = arr[row + startRow][column + startColumn];

			if (st.find(current) != st.end()) {
				return false;
			}
			if (current!='-')
			{
				st.insert(current);
			}
		}

	}
	return true;
}

bool Board::isValid(char arr[][9], int row, int column) {
	return notInRow(arr, row) && notInColumn(arr, column) && notInBox(arr, row - row % 3, column - column % 3);

}

bool Board::isValidConfig() {

	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (!isValid(aBoard, x, y)) {
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	
}



bool Board::isAvailbleAtIndex(int x, int y) {
	if (aBoard[x][y] == '-') {
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::isEmpty() {
	bool output = true;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (isAvailbleAtIndex(i, j) == false) {
				output = false;
				break;
			}

		}
	}
	return output;
}

bool Board::isFull() {
	bool output = true;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (isAvailbleAtIndex(i, j) == true) {
				output = false;
				break;
			}
			
		}
	}
	return output;
	
}

void Board::setValueAtIndex(int x, int y, char value) {
	aBoard[x][y] = value;
}

char Board::getValueAtIndex(int x, int y) {
	return aBoard[x][y];
}
void Board::boardLoader(string fileName) {
	int i, j;
	string line;
	string array[9][9];
	
	ifstream myFile;
	myFile.open(fileName + ".txt");

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (getline(myFile, line, ';'))
			{
				array[i][j] = line;
				//setValueAtIndex(i,j, array[i][j]);
				//display initialRoute 1: 0  8  9  5  4  11  10  2  12  7  3  6  1  0
			}
		}

		myFile.close();
	}
}
void Board::displayBoard(){
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout<< getValueAtIndex(i, j)<<" ";
		}
		cout << endl;
	}
}
void Board::save(string name) {
	ply.save(name, aBoard);
}
