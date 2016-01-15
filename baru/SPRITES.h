// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: SPRITES.h
// Tanggal 		: 4 Maret 2011
// Deskripsi 	: Kelas SPRITES di Tugas Besar 1

#ifndef SPRITES_H
#define	SPRITES_H
#include <iostream>
using namespace std;

class Sprites {
private :
    // Data member
	int Status;
public :
    // Fungsi get dan set position
	int getPosition();				// Mengembalikan titik dimana SPRITES berada
	Sprites setPosition(int,int);	// Mengeset titik baru dimana SPRITES berada
	// Fungsi get dan set direction
	int getDirection();   			// Mengembalikan arah SPRITES menghadap; 1 : atas, 2 : kiri, 3 : kanan, 4 : bawah
	Sprites setDirection(int);		// Mengeset arah baru yang SPRITES hadapi
	    
    // Fungsi-fungsi tambahan
	void MoveTo(Position);			// Membaca masukan dari keyboard (arah) atau perintah langsung
	Position FindPath(Position);	// Mencari jalan menuju tampat yang perlu diurus oleh kurcaci
    Position CurrField();			// Melihat posisi field yang dihadapi CREATURE
};

#endif	/* SPRITES_H */