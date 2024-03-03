#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"

using namespace std;

class gameManager
{
private: 
		 Board brd;
		 Player ply;
public: void Turn();
		char checkSimilar();
		char checkWin();
		void play();
		bool save();
		gameManager();

};

