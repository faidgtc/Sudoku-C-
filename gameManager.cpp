#include "gameManager.h"


gameManager::gameManager() {

}
void gameManager::play() {
	int counter = 1000;
	string name;
	cout << "Masukan Nama Pemain" << endl;
	cin >> name;
	ply.setUsername(name);
	while (counter--)
	{
		int x, y;
		char value;
		brd.displayBoard();
		cout << "Masukan Nomor Kolom Yang Ingin Di Isi (0-8) : " << endl;
		cin >> x;
		cout << "Masukan Nomor Baris Yang Ingin Di Isi (0-8) : " << endl;
		cin >> y;
		cout << "Masukan Value Yang Ingin Di Isi (1-9) : " << endl;
		cin >> value;

		brd.setValueAtIndex(x, y, value);

		system("CLS");
		if (checkWin() == true)
		{
			break;
		}

	}
	cout <<ply.getUsername()<<" Selamat Anda Menang" << endl;
}
char gameManager::checkWin() {
	if (brd.isFull() == true && brd.isValidConfig() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
