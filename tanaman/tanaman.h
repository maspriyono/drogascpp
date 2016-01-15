// Penanggung jawab : Dimas Gilang Saputra / 13509038

// Kelas ini mendeskripsikan tentang tanaman secara general
// Kelas ini akan diturunkan menjadi jenis-jenisnya seperti
// ganja, opium, coca, tobacco, anggur, dan mushroom

#ifndef TANAMAN_H
#define TANAMAN_H

#include <iostream>
using namespace std;

class Tanaman {

	// Atribut
	
	private:
	
	int DaftarInfo [5][3];
		// Menunjukkan info-info tanaman yang berupa array dua dimensi
		// Dimensi pertama menunnjukkan jenis tanaman :
		//	0 = ganja, 1 = opium, 2 = coca, 3 = tobacco, 4 = anggur, 5 = mushroom
		// Dimensi kedua menunjukkan info tanaman
		//	0 = harga bibit, 1 = harga hasil panen,
		//	2 = jumlah penambahan overdosis meter, 3 = jumlah penambahan sakaw meter

	protected:
	
	int ID;
		// Menunjukkan nomor ID tanaman
		// 1 = ganja, 2 = opium, 3 = coca, 4 = tobacco, 5 = anggur, 6 = mushroom
	int HappyMeter;
		// Menunjukkan happy meter tanaman
		// Happy meter awal adalah 0 dan bertambah jika tanaman telah disiram dan hari telah berganti
	int TitikDewasa;
		// Menunjukkan titik dewasa tanaman
		// Jika happy meter tanaman telah mencapai titik dewasanya maka tanaman sudah dewasa
	int TitikPanen;
		// Menunjukkan titik panen tanaman
		// Jika happy meter tanaman telah mencapai titik panennya maka tanaman sudah saatnya panen
	int Umur;
		// Menunjukkan umur tananam
		// Jika umur tanaman mencapai 0 maka tanaman sudah mati
	int TipePanen;
		// Menunjukkan tipe panen tanaman
		// Jika tipe panen = 0 maka panen dapat dilakukan berulang-ulang
		// Jika tipe panen = 1 maka tidak bisa dipanen berulang-ulang karena tanaman langsung hilang
	//Point Posisi;
		// Menunjukkan posisi tanaman dalam point (x,y)
	int HargaBibit;
		// Menunjukkan harga bibit tanaman
	int HargaPanen;
		// Menunjukkan harga hasil panen tanaman
	int EfekOverDosis;
		// Menunjukkan berapa banyak penambahan overdosis dalam overdosis meter
	int EfekSakaw;
		// Menunjukkan berapa banyak penambahan sakaw dalam sakaw meter
	int whatisthis;
		// Menunjukkan tipe tanaman
		// 0 = bibit, 1 = hasil panen, 9 = belum ditentukan
	
	// Method
	
	public:
	
	// Konstruktor
	
	Tanaman();
	
	// Show
	
	void showHargaBibit();
		// Menampilkan harga bibit semua jenis tanaman
	void showHargaPanen();
		// Menampilkan harga hasil panen semua jenis tanaman
	
	// Get
	
	int getDaftarInfo(int,int);
		// Mengembalikan info tanaman yang diambil dari array ke int dan int
	int getID();
		// Mengembalikan ID tanaman
	int getHappyMeter();
		// Mengembalikan nilai happy meter tanaman
	int getTitikDewasa();
		// Mengembalikan nilai titik dewasa tanaman
	int getTitikPanen();
		// Mengembalikan nilai titik panen tanaman
	int getUmur();
		// Mengembalikan sisa umur tanaman
	int getTipePanen();
		// Mengembalikan jenis tipe panen tanaman
	//Point getPosisi();
		// Mengembalikan posisi tanaman
	int getHargaBibit();
		// Mengembalikan nilai harga bibit tanaman
	int getHargaPanen();
		// Mengembalikan nilai harga hasil panen tanaman
	int getEfekOverDosis();
		// Mengembalikan nilai efek overdosis tanaman
	int getEfekSakaw();
		// Mengembalikan nilai efek sakaw tanaman
	int getwhatisthis();
		// Mengembalikan nilai tipe tanaman
	
	// Set
	
	void setID(int);
		// Mengeset nilai ID tanaman
	void setHappyMeter(int);
		// Mengeset nilai happy meter tanaman
	void setTitikDewasa(int);
		// Mengeset nilai titik dewasa tanaman
	void setTitikPanen(int);
		// Mengeset nilai titik panen tanaman
	void setUmur(int);
		// Mengeset nilai umur tanaman
	void setTipePanen(int);
		// Mengeset nilai tipe panen tanaman
	//void setPosisi(Point);
		// Mengeset nilai posisi tanaman
	void setHargaBibit(int);
		// Mengeset nilai harga bibit tanaman
	void setHargaPanen(int);
		// Mengeset nilai harga panen tanaman
	void setEfekOverDosis(int);
		// Mengeset nilai efek overdosis tanaman
	void setEfekSakaw(int);
		// Mengeset nilai efek sakaw tanaman
	void setAll(int, int, int, int, int,
						int, int, int, int, int, int);
		// Mengeset nilai semua atribut tanaman tanaman
	void setwhatisthis(int);
		// Mengeset nilai tipe tanaman
	
	// Predikat
	
	int isDewasa();
		// Mengembalikan 1 jika tanaman sudah dewasa, 0 jika belum
	int isPanen();
		// Mengembalikan 1 jika tanaman sudah waktunya panen, 0 jika belum
	int isMati();
		// Mengembalikan 1 jika tanaman sudah mati, 0 jika belum
	
	// Method lain
	
	void tambahHappyMeter(int);
		// Menambah happy meter sejumlah int
	void gantiTitikDewasa(int);
		// Mengganti titik dewasa menjadi int
	void gantiTitikPanen(int);
		// Mengganti titik panen menjadi int
	void kurangiUmur(int);
		// Mengurangi umur sejumlah int
	virtual void showInformasi() {};
		// Menampilkan informasi tanaman yaitu nilai semua atributnya
		// Merupakan method virtual yang akan direalisasikan di turunan kelas ini

};

#endif
