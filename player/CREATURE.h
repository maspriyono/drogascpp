// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: CREATURE.h
// Tanggal 		: 4 Maret 2011
// Deskripsi 	: Kelas CREATURE di Tugas Besar 1

#ifndef CREATURE_H
#define	CREATURE_H
#include "POINT.h"
#include "../allmap/Area.h"
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
	//Creature(const Creature&);		// Copy constructor
	//~Creature();					// Destructor
	
	// Fungsi get dan set
	int getPositionX();				// Mengirimkan nilai absis dari creature
	int getPositionY();				// Mengirimkan nilai ordinat dari creature
	int getDirection();   			// Mengembalikan arah CREATURE menghadap; 1 : atas, 2 : kiri, 3 : kanan, 4 : bawah
	void setPosition(int,int);		// Mengeset titik baru dimana CREATURE berada
	void setDirection(int);			// Mengeset arah baru yang CREATURE hadapi
	int FaceX();					// Melihat posisi absis field yang dihadapi CREATURE
	int FaceY();					// Melihat posisi ordinat field yang dihadapi CREATURE
	
	// Fungsi aktivitas
	virtual void Water(AllMap*);			// Menyiram tanaman
	virtual void Harvest(AllMap*) {};// Memanen tanaman
	virtual void Slash(AllMap*);			// Menyabit tanaman
};

#endif	/* CREATURE_H */
