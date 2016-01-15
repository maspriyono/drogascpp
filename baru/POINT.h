// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: POINT.h
// Tanggal 		: 4 Maret 2011
// Deskripsi 	: Kelas POINT di Tugas Besar 1

#ifndef POINT_H
#define	POINT_H
#include <iostream>
using namespace std;

class Point {
private :
    // Data member
    int X;
    int Y;
	
public :
    Point();                    // Default constructor
    Point(int,int);             // User-defined constructor
    Point(const Point&);        // Copy constructor
    ~Point();                   // Destructor
	
	// Fungsi get dan set
    int getX();
    int getY();
	int MakePoint(int a, int b);
    Point setX(int);
    Point setY(int);
	
	// Operator overloading
	void operator+();
	void operator-();
	void operator++();
	void operator--();
	
};

// Point::Point() {
	// setX(0);
	// setY(0);
	// cout << "Point (0,0) berhasil dibuat" << endl;
// }

// // User-defined constructor
// Point::Point(int A, int B) {
	// setX(A);
	// setY(B);
	// cout << "Point (" << A << "," << B << ") berhasil dibuat" << endl;
// }

// // Copy constructor
// Point::Point(const Point& P) {
	// setX(P.X);
	// setY(P.Y);
	// cout << "Point berhasil disalin" << endl;
// }

// // Destructor
// Point::~Point() {
	// cout << "Point berhasil dimusnahkan" << endl;
// }

// // Fungsi get dan set
// int Point::getX() {
	// return X;		// Mengirimkan nilai absis
// }

// int Point::getY() {
	// return Y;		// Mengirimkan nilai ordinat
// }

// Point Point::setX(int newX) {
	// X = newX;		// Set nilai absis baru
// }

// Point Point::setY(int newY) {
	// Y = newY;		// Set nilai ordinat baru
// }

// // Operator overloading
// void Point::operator++() {
	// Y++;			// Tambah nilai ordinat
// }

// void Point::operator--() {
	// Y--;			// Kurangi nilai ordinat
// }
// Point MakePoint(int a, int b){
	// X = a;
	// Y = b;
// }
#endif	/* POINT_H */
