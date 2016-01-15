// NIM : 13509044
// Nama : Bagus Rahman Aryabima
// Nama File : POINT.cpp
// Tanggal : 5 Maret 2011
// Deskripsi : Kelas POINT di Tugas Besar 1

#include "POINT.h"

// Default constructor
Point::Point() {
	setX(0);
	setY(0);
}

// User-defined constructor
Point::Point(int A, int B) {
	setX(A);
	setY(B);
}

// Copy constructor
Point::Point(const Point& P) {
	setX(P.X);
	setY(P.Y);
}

// Destructor
/*Point::~Point() {
	cout << "Point berhasil dimusnahkan" << endl;
}*/

// Fungsi get dan set
int Point::getX() {
	return X;		// Mengirimkan nilai absis
}

int Point::getY() {
	return Y;		// Mengirimkan nilai ordinat
}

void Point::setX(int newX) {
	X = newX;		// Set nilai absis baru
}

void Point::setY(int newY) {
	Y = newY;		// Set nilai ordinat baru
}

// Operator overloading
int Point::incX() {
	return X++;			// Tambah nilai absis
}

int Point::decX() {
	return X--;			// Kurangi nilai absis
}

int Point::incY() {
	return Y++;			// Tambah nilai ordinat
}

int Point::decY() {
	return Y--;			// Kurangi nilai ordinat
}
