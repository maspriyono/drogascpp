// Penanggung jawab : Dimas Gilang Saputra / 13509038

// Kelas ini adalah kelas turunan dari tanaman
// Kelas ini mendeskripsikan salah satu jenis tanaman yaitu ganja

#ifndef GANJA_H
#define GANJA_H

#include "tanaman.h"

class Ganja: public Tanaman {
	
	public:
	
	// Konstruktor, copy konstruktor, destruktor
	
	Ganja();
	//Ganja(int,int,int,int,int,int,Point,int,int,int,int);
	Ganja(const Ganja&);
	~Ganja(){};
	
	// Method
	
	void showInformasi();
	// Menampilkan informasi tanaman ini yaitu
	// ID, happy meter, titik dewasa, titik panen, umur, tipe panen, harga bibit,
	// harga hasil panen, efek over dosis, efek sakaw, dan what is this

};

#endif
