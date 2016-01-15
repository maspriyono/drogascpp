// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: SPRITES.cpp
// Tanggal 		: 17 Maret 2011
// Deskripsi 	: Kelas SPRITES di Tugas Besar 1

#include "SPRITES.h"

// Default constructor
Sprites::Sprites() {
	setPosition(0,0);
	setDirection(1);
	setStatus(0);
	cout << "Kurcaci tertidur dibuat" << endl;
}

// User-defined constructor
Sprites::Sprites(int newX, int newY, int newD, int newS) {
	int x,y;
	setPosition(newX, newY);
	setDirection(newD);
	setStatus(newS);
	cout << "Kurcaci sesuai masukan dibuat" << endl;
}

// Copy constructor
// Sprites::Sprites(const Sprites& SS) {
//	setPositionX(SS.X);
//	setPositionY(SS.Y);
//	setDirection(SS.Direction);
//	setStatus(SS.Status);
// }

// Destructor
Sprites::~Sprites() {
	cout << "Kurcaci berhasil dimusnahkan" << endl;
}

// Fungsi get dan set
int Sprites::getStatus() {
	return Status;
}

void Sprites::setStatus(int newStatus) {
	Status = newStatus;
}

int Sprites::FieldCheck(Point P, Point T) {
	int i = 0;
	if ((P.getX() < T.getX()) && (P.getY() < T.getY())) {
		i = 1;
	}
	else if ((P.getX() < T.getX()) && (P.getY() == T.getY())) {
		i = 2;
	}
	else if ((P.getX() < T.getX()) && (P.getY() > T.getY())) {
		i = 3;
	}
	else if ((P.getX() == T.getX()) && (P.getY() < T.getY())) {
		i = 4;
	}
	else if ((P.getX() == T.getX()) && (P.getY() == T.getY())) {
		i = 5;
	}
	else if ((P.getX() == T.getX()) && (P.getY() > T.getY())) {
		i = 6;
	}
	else if ((P.getX() > T.getX()) && (P.getY() < T.getY())) {
		i = 7;
	}
	else if ((P.getX() > T.getX()) && (P.getY() == T.getY())) {
		i = 8;
	}
	else if ((P.getX() > T.getX()) && (P.getY() > T.getY())) {
		i = 9;
	}
	return i;
}	
void Sprites::resetMarkCounter() {
	int x, y;
	for (x == 1;x > 6;x++) {
		for (y == 1;y > 7;y++) {
			mCounter[x][y] = 0;
		}
	}
}
void Sprites::markCounter(int ex, int ye) {
	mCounter[ex][ye] = mCounter[ex][ye]+1;
}

int Sprites::checkMark(int X, int Y) {
	return (mCounter[X][Y]);
}

// void Creature::water() {
	
// }
/*
(x < xt) && (y < yt) : up-right
(x < xt) && (y = yt) : right
(x < xt) && (y > yt) : down-right
(x = xt) && (y < yt) : up
(x = xt) && (y = yt) : voila!
(x = xt) && (y > yt) : down
(x > xt) && (y < yt) : up-left
(x > xt) && (y = yt) : left
(x > xt) && (y < yt) : down-right
*/

// void Sprites::nextMove(Point P1, Point P2) {
	// if (FieldCheck(P1, P2) == 1) {
		// if (am->GetLFieldXY(P1.getX(),incY(P1.getY()))->IsMoveAble() == ) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() + 1);
		// }
		// else if (isMovable(P1.getX() + 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() + 1, P1.getY());
		// }
		// else if (isMovable(P1.getX(), P1.getY() - 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() - 1);
		// }
		// else if (isMovable(P1.getX() - 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() - 1, P1.getY());
		// }
	// }
	// if (FieldCheck(P1, P2) == 2) {
		// if (isMovable(P1.getX() + 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() + 1, P1.getY());
		// }
		// else if (isMovable(P1.getX(), P1.getY() - 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() - 1);
		// }
		// else if (isMovable(P1.getX() - 1, P1.getY())) {
			// markCounter(P1.getX() , P1.getY());
			// setPosition(P1.getX() - 1, P1.getY());
		// }
		// else if (isMovable(P1.getX(), P1.getY() + 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() + 1);
		// }	
	// }
	// if (FieldCheck(P1, P2) == 3) {
		// if (isMovable(P1.getX() + 1, P1.getY())) { //perhatikan
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() + 1, P1.getY());
		// }
		// else if (isMovable(P1.getX(), P1.getY() - 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() - 1);
		// }
		// else if (isMovable(P1.getX() - 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() - 1, P1.getY());
		// }
		// else if (isMovable(P1.getX(), P1.getY() + 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() + 1);
		// }	
	// }
	// if (FieldCheck(P1, P2) == 4) {
		// if (isMovable(P1.getX(), P1.getY() + 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() + 1);
		// }
		// else if (isMovable(P1.getX() + 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() + 1, P1.getY());
		// }
		// else if (isMovable(P1.getX() - 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() - 1, P1.getY());
		// }
		// else if (isMovable(P1.getX(), P1.getY() - 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() - 1);
		// }
	// }
	// if (FieldCheck(P1, P2) == 6) {
		// if (isMovable(P1.getX(), P1.getY() - 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() - 1);
		// }
		// else if (isMovable(P1.getX() + 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() + 1, P1.getY());
		// }
		// else if (isMovable(P1.getX() - 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() - 1, P1.getY());
		// }
		// else if (isMovable(P1.getX(), P1.getY() + 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() + 1);
		// }
	// }
	// if (FieldCheck(P1, P2) == 7) {
		// if (isMovable(P1.getX(), P1.getY() + 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() + 1);
		// }
		// else if (isMovable(P1.getX() - 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() - 1, P1.getY());
		// }
		// else if (isMovable(P1.getX(), P1.getY() - 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() - 1);
		// }
		// else if (isMovable(P1.getX() + 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() + 1, P1.getY());
		// }
	// }
	// if (FieldCheck(P1, P2) == 8) {
		// if (isMovable(P1.getX() - 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() - 1, P1.getY());
		// }
		// else if (isMovable(P1.getX(), P1.getY() - 1)) { //perhatikan
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() - 1);
		// }
		// else if (isMovable(P1.getX() + 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() + 1, P1.getY());
		// }
		// else if (isMovable(P1.getX(), P1.getY() + 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() + 1);
		// }
	// }
	// if (FieldCheck(P1, P2) == 9) {
		// if (isMovable(P1.getX(), P1.getY() - 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() - 1);
		// }
		// else if (isMovable(P1.getX() - 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() - 1, P1.getY());
		// }
		// else if (isMovable(P1.getX(), P1.getY() + 1)) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX(), P1.getY() + 1);
		// }
		// else if (isMovable(P1.getX() + 1, P1.getY())) {
			// markCounter(P1.getX(), P1.getY());
			// setPosition(P1.getX() + 1, P1.getY());
		// }
	// }
// }

// Fungsi aktivitas
// void Sprites::Execute(AllMap* am, Point P1, Point P2) {
	// if (FieldCheck(P1,P2) == 5) {
		// if (getType() == 1) {
			// am->GetLFieldXY((CurrField()).getX(),(CurrField()).getY())->Kerja('w');
		// }
		// else if (getType() == 2) {
			// am->GetLFieldXY((CurrField().getX()),(CurrField.getY()))->Kerja('h');
		// }
		// else if (getType() == 3) {
			// am->GetLFieldXY((CurrField()).getX(),(CurrField()).getY())->Kerja('s');
		// }
	// }
// }

