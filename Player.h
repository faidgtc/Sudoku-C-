#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Player
{
private: string name;
		 int win;
public: Player();
		Player(string name, int win);
		string getUsername();
		void setUsername(string name);
		int getWinCount();
		void setWinCount(int win);
		void save(string name, char board[9][9]);

};

