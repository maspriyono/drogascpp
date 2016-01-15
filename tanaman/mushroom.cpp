// Penanggung jawab : Dimas Gilang Saputra / 13509038

#include "mushroom.h"

// Konstruktor, copy konstruktor, destruktor
Mushroom::Mushroom() {
	ID = 6;
	HappyMeter = 0;
	TitikDewasa = 5;
	TitikPanen = 7;
	Umur = 10;
	TipePanen = 0;
	//Posisi = 0;
	HargaBibit = 4;
	HargaPanen = 8;
	EfekOverDosis = 8;
	EfekSakaw = 15;
}
/*Mushroom::Mushroom(int I,int HM,int TD,int TP,int U,int Tipan,Point P,int HB,int HP,int EOD,int ES) {
	ID	= I;
	HappyMeter = HM;
	TitikDewasa = TD;
	TitikPanen = TP;
	Umur = U;
	TipePanen = Tipan;
	//Posisi = P;
	HargaBibit = HB;
	HargaPanen = HP;
	EfekOverDosis = EOD;
	EfekSakaw = ES;
}*/
Mushroom::Mushroom(const Mushroom& copied) {
	ID = copied.ID;
	HappyMeter = copied.HappyMeter;
	TitikDewasa = copied.TitikDewasa;
	TitikPanen = copied.TitikPanen;
	Umur = copied.Umur;
	TipePanen = copied.TipePanen;
	//Posisi = copied.Posisi;
	HargaBibit = copied.HargaBibit;
	HargaPanen = copied.HargaPanen;
	EfekOverDosis = copied.EfekOverDosis;
	EfekSakaw = copied.EfekSakaw;
}

// Method
void Mushroom::showInformasi() {
	cout << "Mushroom :" << endl;
	cout << "ID                = " << getID() << endl;
	cout << "Happy meter       = " << getHappyMeter() << endl;
	cout << "Titik dewasa      = " << getTitikDewasa() << endl;
	cout << "Titik panen       = " << getTitikPanen() <<endl;
	cout << "Umur              = " << getUmur() << endl;
	cout << "Tipe Panen        = ";
		if (getTipePanen() == 1) { cout << "Berulang *kayanya *lupa"; }
		else if (getTipePanen() == 0) { cout << "Hilang *kayanya *lupa"; }
		cout << endl;
	//cout << "Posisi            = " << getPosisi() << endl;
	cout << "Harga bibit       = " << getHargaBibit() << endl;
	cout << "Harga hasil panen = " << getHargaPanen() << endl;
	cout << "Efek over dosis   = " << getEfekOverDosis() << endl;
	cout << "Efek sakaw        = " << getEfekSakaw() << endl;
	cout << "What is this      = ";
		if (getwhatisthis() == 0) { cout << "Bibit *kayanya *lupa"; }
		else if (getwhatisthis() == 1) { cout << "Hasil panen *kayanya *lupa"; }
		else if (getwhatisthis() == 9) { cout << "Undefined"; }
		cout << endl;
}
