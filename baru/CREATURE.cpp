// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: CREATURE.cpp
// Tanggal 		: 9 Maret 2011
// Deskripsi 	: Kelas CREATURE di Tugas Besar 1

#include "POINT.h"
#include "CREATURE.h"

// Default constructor
Creature::Creature() {
	setPosition(0,0);
	setDirection(1);
	cout << "Sebuah creature yang terletak di titik (0,0) dan menghadap ke atas berhasil dibuat" << endl;
}

// User-defined constructor	
Creature::Creature(int newX, int newY, int newD) {
	setPosition(newX, newY);
	setDirection(newD);
	cout << "Sebuah creature yang terletak di titik (" << newX << "," << newY << ") dengan ID arah hadap " << newD << " berhasil dibuat" << endl;
}

// Copy constructor
// Creature::Creature(const Creature& C) {
// 	setPosition(C.Position.getX(), C.Position.getY());
//	setDirection(C.Direction);
// }

// Destructor
Creature::~Creature() {
	cout << "Creature berhasil dimusnahkan" << endl;
	
}

// Fungsi get dan set
int Creature::getPosition() {
	return Position.getX();
}

int Creature::getDirection() {
	return Direction;
}

void Creature::setPosition(int newX, int newY) {
	Position.setX(newX);
	Position.setY(newY);
}

void Creature::setDirection(int newD) {
	Direction = newD;
 }
// int main(){
	// int newX;
	// int newY;
	// int newD;
	
	// cout << "***** Constructor, copy constructor, destructor *****" << endl;
	// cout << "*** Default constructor ***" << endl;
	// Creature C;
	// Creature C1;
	
	// cout << "*** User-defined constructor ***" << endl;
	// Creature C2(2, 3, 4);
	
	// cout << "***** Fungsi get dan set *****" << endl;
	// cout << "*** Fungsi get atribut C2 ***" << endl;
	// cout << "Atribut position dari C2 = " << C2.getPosition() << endl;
	// cout << "Atribut direction dari C2 = " << C2.getDirection() << endl;
	
	// cout << "*** Fungsi set atribut C1 ***" << endl;
	// cout << "Masukkan nilai absis dari C1 = " << endl;
	// cin >> newX;
	// cout << "Masukkan nilai ordinat dari C1 = " << endl;
	// cin >> newY;
	// C1.setPosition(newX, newY);
	// do {
		// cout << "Masukkan ID direction dari C1 = " << endl;
		// cin >> newD;
	// } while ((newD < 1) || (newD > 4));
	// C1.setDirection(newD);
	
	// //\cout << "Atribut position dari C1 sekarang = " << C1.getPosition() << endl;
	// cout << "Atribut direction dari C1 sekarang = " << C1.getDirection() << endl;
	// return 0;
// }
