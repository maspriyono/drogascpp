// Penanggung jawab : Dimas Gilang Saputra / 13509038

// Kelas ini adalah kelas turunan dari tanaman
// Kelas ini mendeskripsikan salah satu jenis tanaman yaitu opium

#ifndef OPIUM_H
#define OPIUM_H

#include "tanaman.h"

class Opium: public Tanaman {
	
	public:
	
	// Konstruktor, copy konstruktor, destruktor
	
	Opium();
	//Opium(int,int,int,int,int,int,Point,int,int,int,int);
	Opium(const Opium&);
	~Opium(){};
	
	// Method
	
	void showInformasi();
	// Menampilkan informasi tanaman ini yaitu
	// ID, happy meter, titik dewasa, titik panen, umur, tipe panen, harga bibit,
	// harga hasil panen, efek over dosis, efek sakaw, dan what is this

};

#endif
