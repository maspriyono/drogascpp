// Penanggung jawab : Dimas Gilang Saputra / 13509038

// Kelas ini adalah kelas turunan dari tanaman
// Kelas ini mendeskripsikan salah satu jenis tanaman yaitu mushroom

#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "tanaman.h"

class Mushroom: public Tanaman {
	
	public:
	
	// Konstruktor, copy konstruktor, destruktor
	
	Mushroom();
	//Mushroom(int,int,int,int,int,int,Point,int,int,int,int);
	Mushroom(const Mushroom&);
	~Mushroom(){};
	
	// Method
	
	void showInformasi();	
	// Menampilkan informasi tanaman ini yaitu
	// ID, happy meter, titik dewasa, titik panen, umur, tipe panen, harga bibit,
	// harga hasil panen, efek over dosis, efek sakaw, dan what is this

};

#endif
