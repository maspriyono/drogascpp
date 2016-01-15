// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: mCREATURE.cpp
// Tanggal 		: 9 Maret 2011
// Deskripsi 	: Kelas CREATURE di Tugas Besar 1
#include <iostream>
#include "CREATURE.h"
using namespace std;
int main() {
	int newX;
	int newY;
	int newD;
	
	cout << "***** Constructor, copy constructor, destructor *****" << endl;
	cout << "*** Default constructor ***" << endl;
	Creature C;
	Creature C1;
	
	cout << "*** User-defined constructor ***" << endl;
	Creature C2(2, 3, 4);
	
	cout << "***** Fungsi get dan set *****" << endl;
	cout << "*** Fungsi get atribut C2 ***" << endl;
	cout << "Atribut position dari C2 = " << C2.getPosition() << endl;
	cout << "Atribut direction dari C2 = " << C2.getDirection() << endl;
	
	cout << "*** Fungsi set atribut C1 ***" << endl;
	cout << "Masukkan nilai absis dari C1 = " << endl;
	cin >> newX;
	cout << "Masukkan nilai ordinat dari C1 = " << endl;
	cin >> newY;
	C1.setPosition(newX, newY);
	do {
		cout >> "Masukkan ID direction dari C1 = " << endl;
		cin >> newD;
	} while ((newD < 1) || (newD > 4));
	C1.setDirection(newD);
	
	cout << "Atribut position dari C1 sekarang = " << C1.getPosition() << endl;
	cout << "Atribut direction dari C1 sekarang = " << C1.getDirection() << endl;
	return 0;
}
