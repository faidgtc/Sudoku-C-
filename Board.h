#pragma once
#include<iostream>
#include<string>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include "Player.h"

using namespace std;

class Board
{
private :
	char aBoard[9][9];
	Player ply;
public :
	Board();

	bool notInRow(char arr[][9], int row);
	bool notInColumn(char arr[][9], int column);
	bool notInBox(char arr[][9], int startRow, int startColumn);
	bool isValid(char arr[][9], int row, int column);
	bool isValidConfig();
	bool isAvailbleAtIndex(int x, int y);
	bool isEmpty();
	bool isFull();
	void setValueAtIndex(int x, int y, char value);
	char getValueAtIndex(int x, int y);
	void boardLoader(string fileName);
	void displayBoard();
	void save(string name);
	//bool validationIndex();

};

