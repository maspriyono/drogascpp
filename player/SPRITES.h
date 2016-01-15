// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: SPRITES.h
// Tanggal 		: 4 Maret 2011
// Deskripsi 	: Kelas SPRITES di Tugas Besar 1

#ifndef SPRITES_H
#define	SPRITES_H
#include "POINT.h"
#include "CREATURE.h"
#include <iostream>
using namespace std;

class Sprites : public Creature {
private :
    // Data member
	int Status;
	Point Target;
	int mCounter[6][7];
public :
    Sprites();							// Default constructor
	Sprites(int, int, int, int);		// User-defined constructor
	Sprites(const Sprites&);			// Copy constructor
	~Sprites();							// Destructor
	
	//Fungsi get dan set
	int getStatus();					// Mengirimkan nilai identifier status
	void setStatus(int);				// Mengeset nilai identifier status yang baru
	
	// Fungsi-fungsi tambahan
	int FieldCheck(Point,Point);		// Menguji perbandingan antara posisi awal dan posisi tujuan
	void markCounter(int, int);			// Prosedur pada kurcaci untuk mengingat langkah yang sudah pernah dijalaninya
	void resetMarkCounter();
	int isMovable(int, int);			// Menguji apakah sebuah field di lahan bisa dilewati atau tidak
	int checkMark(int, int);			// Menguji berapa kali sebuah field dilewati
	void nextMove(Point,Point);			// Menentukan langkah kurcaci selanjutnya
};

#endif	/* SPRITES_H */
