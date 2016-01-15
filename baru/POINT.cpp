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
	cout << "Point (0,0) berhasil dibuat" << endl;
}

// User-defined constructor
Point::Point(int A, int B) {
	setX(A);
	setY(B);
	cout << "Point (" << A << "," << B << ") berhasil dibuat" << endl;
}

// Copy constructor
Point::Point(const Point& P) {
	setX(P.X);
	setY(P.Y);
	cout << "Point berhasil disalin" << endl;
}

// Destructor
Point::~Point() {
	cout << "Point berhasil dimusnahkan" << endl;
}

// Fungsi get dan set
int Point::getX() {
	return X;		// Mengirimkan nilai absis
}

int Point::getY() {
	return Y;		// Mengirimkan nilai ordinat
}

Point Point::setX(int newX) {
	X = newX;		// Set nilai absis baru
}

Point Point::setY(int newY) {
	Y = newY;		// Set nilai ordinat baru
}

// Operator overloading
void Point::operator++() {
	Y++;			// Tambah nilai ordinat
}

void Point::operator--() {
	Y--;			// Kurangi nilai ordinat
}
// Point MakePoint(int a, int b){
	// x = a;
	// y = b;
// }
// void Point::operator>>() {
// 	X++;			// Tambah nilai absis
// }

// void Point::operator<<() {
// 	X--;			// Kurangi nilai absis
// }
