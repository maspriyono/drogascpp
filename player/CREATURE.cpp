// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: CREATURE.cpp
// Tanggal 		: 9 Maret 2011
// Deskripsi 	: Kelas CREATURE di Tugas Besar 1

#include "CREATURE.h"

// Default constructor
Creature::Creature() {
	setPosition(0,0);
	setDirection(1);
}

// User-defined constructor	
Creature::Creature(int newX, int newY, int newD) {
	setPosition(newX, newY);
	setDirection(newD);
}

// Copy constructor
// Creature::Creature(const Creature& C) {
// 	setPosition(C.Position.getX(), C.Position.getY());
//	setDirection(C.Direction);
// }

// Destructor
/*Creature::~Creature() {
	cout << "Creature berhasil dimusnahkan" << endl;
}*/

// Fungsi get dan set
int Creature::getPositionX() {
	return Position.getX();
}

int Creature::getPositionY() {
	return Position.getY();
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

int Creature::FaceX() {
	int Temp;
	Temp = 0;
	if (getDirection() == 2) {
		Temp = -1;
	}
	else if (getDirection() == 3) {
		Temp = 1;
	}
	return (getPositionX()+Temp);
}

int Creature::FaceY() {
	int Temp;
	Temp = 0;
	if (getDirection() == 4) {
		Temp = -1;
	}
	else if (getDirection() == 1) {
		Temp = 1;
	}
	return (getPositionY()+Temp);
}

void Creature::Water(AllMap* am) {
	am->GetLFieldXY(FaceX(),FaceY())->Kerja('w');
}

void Creature::Slash(AllMap* am) {
	am->GetLFieldXY(FaceX(),FaceY())->Kerja('s');
}
