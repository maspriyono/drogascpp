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
    //~Point();                   // Destructor
	
	// Fungsi get dan set
    int getX();
    int getY();
    void setX(int);
    void setY(int);
	
	// Increment & decrement
	int incX();
	int decX();
	int incY();
	int decY();
	
};

#endif	/* POINT_H */
