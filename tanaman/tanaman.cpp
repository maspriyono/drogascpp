// Penanggung jawab : Dimas Gilang Saputra / 13509038

#include "tanaman.h"

// Konstruktor
Tanaman::Tanaman() {
	ID = 0;
	HappyMeter = 0;
	TitikDewasa = 0;
	TitikPanen = 0;
	Umur = 0;
	TipePanen = 0;
	//Point Posisi;
	HargaBibit = 0;
	HargaPanen = 0;
	EfekOverDosis = 0;
	EfekSakaw = 0;
	whatisthis = 9;
	//Daftar Info
	//ganja
	DaftarInfo[0][0] = 5; // harga bibit
	DaftarInfo[0][1] = 10; // harga hasil panen
	DaftarInfo[0][2] = 10; // OD meter ; plus berarti nambahin OD meter
	DaftarInfo[0][3] = -20; // sakaw meter ; minus berarti ngurangin sakaw meter
	//opium
	DaftarInfo[1][0] = 10;
	DaftarInfo[1][1] = 20;
	DaftarInfo[1][2] = 15;
	DaftarInfo[1][3] = -27;
	//coca
	DaftarInfo[2][0] = 8;
	DaftarInfo[2][1] = 15;
	DaftarInfo[2][2] = 13;
	DaftarInfo[2][3] = -25;
	//tobacco
	DaftarInfo[3][0] = 3;
	DaftarInfo[3][1] = 6;
	DaftarInfo[3][2] = -15;
	DaftarInfo[3][3] = -1;
	//anggur
	DaftarInfo[4][0] = 3;
	DaftarInfo[4][1] = 6;
	DaftarInfo[4][2] = -20;
	DaftarInfo[4][3] = -3;
	//mushroom
	DaftarInfo[5][0] = 4;
	DaftarInfo[5][1] = 8;
	DaftarInfo[5][2] = 8;
	DaftarInfo[5][3] = -15;
}

// Show
void Tanaman::showHargaBibit(){
	cout << "\nHarga bibit :" << endl;
	cout << "Ganja    = " << getDaftarInfo(0,0) << " bucks" << endl;
	cout << "Opium    = " << getDaftarInfo(1,0) << " bucks" << endl;
	cout << "Coca     = " << getDaftarInfo(2,0) << " bucks" << endl;
	cout << "Tobacco  = " << getDaftarInfo(3,0) << " bucks" << endl;
	cout << "Anggur   = " << getDaftarInfo(4,0) << " bucks" << endl;
	cout << "Mushroom = " << getDaftarInfo(5,0) << " bucks" << endl;
}
void Tanaman::showHargaPanen(){
	cout << "\nHarga hasil panen :" << endl;
	cout << "Ganja    = " << getDaftarInfo(0,1) << " bucks" << endl;
	cout << "Opium    = " << getDaftarInfo(1,1) << " bucks" << endl;
	cout << "Coca     = " << getDaftarInfo(2,1) << " bucks" << endl;
	cout << "Tobacco  = " << getDaftarInfo(3,1) << " bucks" << endl;
	cout << "Anggur   = " << getDaftarInfo(4,1) << " bucks" << endl;
	cout << "Mushroom = " << getDaftarInfo(5,1) << " bucks" << endl;
}
	
// Get
int Tanaman::getDaftarInfo(int a, int b)	{return DaftarInfo[a][b];}
int Tanaman::getID()						{return ID;}
int Tanaman::getHappyMeter() 				{return HappyMeter;}
int Tanaman::getTitikDewasa() 				{return TitikDewasa;}
int Tanaman::getTitikPanen() 				{return TitikPanen;}
int Tanaman::getUmur() 						{return Umur;}
int Tanaman::getTipePanen() 				{return TipePanen;}
//Point Tanaman::getPosisi()				{return Posisi;}
int Tanaman::getHargaBibit() 				{return HargaBibit;}
int Tanaman::getHargaPanen() 				{return HargaPanen;}
int Tanaman::getEfekOverDosis() 			{return EfekOverDosis;}
int Tanaman::getEfekSakaw() 				{return EfekSakaw;}
int Tanaman::getwhatisthis()				{return whatisthis;}

// Set
void Tanaman::setID(int a) 				{ID = a;}
void Tanaman::setHappyMeter(int a) 		{HappyMeter = a;}
void Tanaman::setTitikDewasa(int a) 	{TitikDewasa = a;}
void Tanaman::setTitikPanen(int a) 		{TitikPanen = a;}
void Tanaman::setUmur(int a) 			{Umur = a;}
void Tanaman::setTipePanen(int a) 		{TipePanen = a;}
//void Tanaman::setPosisi(Point a)		{Posisi = a;}
void Tanaman::setHargaBibit(int a)		{HargaBibit = a;}
void Tanaman::setHargaPanen(int a) 		{HargaPanen = a;}
void Tanaman::setEfekOverDosis(int a)	{EfekOverDosis = a;}
void Tanaman::setEfekSakaw(int a) 		{EfekSakaw = a;}
void Tanaman::setwhatisthis(int a)		{whatisthis = a;}
void Tanaman::setAll(int I, int HM, int TD, int TP, int U,
						int Tipan, int HB, int HP, int EOD, int ES, int WIT){
	ID	= I;
	HappyMeter = HM;
	TitikDewasa = TD;
	TitikPanen = TP;
	Umur = U;
	TipePanen = Tipan;
	HargaBibit = HB;
	HargaPanen = HP;
	EfekOverDosis = EOD;
	EfekSakaw = ES;
	whatisthis = WIT;
}

// Predikat
int Tanaman::isDewasa() {
	// Kamus
	int i,j;
	// Algoritma
	i = (HappyMeter*100)/TitikDewasa;
	if (i >= 100) {
		j = 1;
	}
	else {
		j = 0;
	}
	return j;
}
int Tanaman::isPanen(){
	// Kamus
	int i,j;
	// Algoritma
	i = (HappyMeter*100)/TitikPanen;
	if (i >= 100) {
		j = 1;
	}
	else {
		j = 0;
	}
	return j;
}
int Tanaman::isMati() {
	// Kamus
	int i;
	// Algoritma
	if (Umur <= 0) {
		i = 1;
	}
	else {
		i = 0;
	}
	return i;
}

// Method lain
void Tanaman::tambahHappyMeter(int param)	{ HappyMeter += param; }
void Tanaman::gantiTitikDewasa(int param)	{ TitikDewasa = param; }
void Tanaman::gantiTitikPanen(int param)	{ TitikPanen = param; }
void Tanaman::kurangiUmur(int param) 		{ Umur -= param; }
