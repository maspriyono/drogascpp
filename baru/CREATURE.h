// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: CREATURE.h
// Tanggal 		: 4 Maret 2011
// Deskripsi 	: Kelas CREATURE di Tugas Besar 1

#ifndef CREATURE_H
#define	CREATURE_H
#include "POINT.h"
#include <iostream>
using namespace std;

class Creature {
protected :
    // Data member
	Point Position;
    int Direction;
public :
    Creature();						// Default constructor
	Creature(int, int, int);		// User-defined constructor
	Creature(const Creature&);		// Copy constructor
	~Creature();					// Destructor
	
	// Fungsi get dan set
	int getPosition();				// Mengembalikan titik dimana CREATURE berada
	int getDirection();   			// Mengembalikan arah CREATURE menghadap; 1 : atas, 2 : kiri, 3 : kanan, 4 : bawah
	void setPosition(int,int);		// Mengeset titik baru dimana CREATURE berada
	void setDirection(int);			// Mengeset arah baru yang CREATURE hadapi
};

#endif	/* CREATURE_H */
