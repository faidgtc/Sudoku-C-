#include "Player.h"

Player::Player() {

}
string Player::getUsername() {
	return name;
}
void Player::setUsername(string nama) {
	name = nama;
}
void Player::save(string name, char board[9][9]) {
	
	ofstream fout(name + ".txt");

	if (fout.is_open()) {
		for (int i = 0; i < 9; i++)
		{
			for (int i = 0; i < 9; i++)
			{
				fout << board[9][9];
			}
			cout << endl;
		}
	}
}