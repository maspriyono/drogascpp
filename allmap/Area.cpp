#include "Area.h"

///////////////////////////////////////////////////////////////////////
/////KELAS FIELD                                            ///////////
///////////////////////////////////////////////////////////////////////

//Karena definisi beberapa method hanya 1 line,
//untuk method berikut sudah didefinisikan di header file :
//	- GetMoveAble(void)
//	- SetMoveAble(int)

//Definisi method lain :

Field::Field() {
//Konstruktor dari kelas Field
//Melakukan perubahan MoveAble = 0 (Default Field)
	MoveAble = 0;		
}

////SELESAI METHOD KELAS FIELD                               //////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
/////KELAS NLFIELD                                          ///////////
///////////////////////////////////////////////////////////////////////

//Karena definisi beberapa method hanya 1 line,
//untuk method berikut sudah didefinisikan di header file :
//	- SaveAble(void)		- SetSave(int)
//	- BuyAble(void)			- SetBuy(int)
//	- SellAble(void)		- SetSell(int)
//	- SleepAble(void)		- SetSleep(int)

//Definisi method lain :

NLField::NLField() {
//Konstruktor dari kelas NLField
//Melakukan perubahan yang bersifat default untuk NLField
	MoveAble = 1;
	PSave = 0;
	PBuy = 0;
	PSell = 0;
	PSleep = 0;
}

int NLField::GetCond() {
//Metode mendapatkan informasi dari kelas NLField
//Kondisi NLField merangkum seluruh nilai atribut dari kelas NLField
//dan dapat digunakan sebagai informasi oleh objek dari kelas lain

//Kondisi - kondisi yang valid :
	//8 = tempat tidur/SleepAble
	//9 = tempat save/load
	//16 = tempat sell/buy
	//17 = tempat sell
	//18 = tempat tanpa kondisi khusus
	int temp;									//variabel temporari
	temp = 0;									//inisialisasi
	if 		(PSleep == 1) {						//Diperbolehkan menggunakan perintah sleep saja
		temp = 8;
	}
	else if (PSave == 1) {						//Diperbolehkan menggunakan perintah Save(dan load) saja		
		temp = 9;
	}
	else if ((PBuy == 1) && (PSell == 1)) {		//Boleh menjual dan membeli
		temp = 16;
	}
	else if	((PSell == 1) && (PBuy == 0)) {		//Boleh menjual tapi tidak boleh membeli
		temp = 17;
	}
	else if ((PSave == 0) && (PBuy == 0) && (PSell == 0) && (PSleep == 0) && (MoveAble == 1)) {
	//NLField tidak memiliki karakteristik yang spesial, digunakan sebagai tempat berjalan oleh Creature
		temp = 18;
	}
	return temp;
}

void NLField::SetAllProp(int S, int B, int J, int T) {
//Method untuk melakukan perubahan untuk SEMUA atribut dari NLField
//S = nilai baru untuk PSave
//B = nilai baru untuk PBuy
//J = nilai baru untuk PSell
//T = nilai baru untuk PSleep
	PSave = S;
	PBuy = B;
	PSell = J;
	PSleep = T;
}

////SELESAI METHOD KELAS NLFIELD                             //////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
/////KELAS LFIELD                                           ///////////
///////////////////////////////////////////////////////////////////////

//Karena definisi beberapa method hanya 1 line,
//untuk method berikut sudah didefinisikan di header file :
//	- IsPlantable(void)		- SetPlantable(int)
//	- IsPlantExist(void)	- SetPlantExist(int)
//	- IsPlantAlive(void)	- SetPlantAlive(int)
//	- IsCangkul(void)		- SetCangkul(int)
//  - IsSiram(void)			- SetSiram
//	- GetPlant(void)

//Definisi method lain :

LField::LField() {
//Konstruktor untuk kelas LField
//Melakukan perubahan nilai menjadi default dari kelas LField
//dan menyiapkan objek baru tanaman untuk dimodifikasi oleh LField
	MoveAble = 1;
	Plantable = 1;
	PlantExist = 0;
	PlantAlive = 0;
	Cangkul = 0;
	Siram = 0;
	
	PPlant = new Tanaman;
}

void LField::SetAllProp(int P, int PE, int PA, int C, int S) {
//Melakukan perubahan nilai untuk SEMUA atribut dari kelas LField
//P 	= nilai baru dari Plantable
//PE 	= nilai baru dari PlantExist
//PA	= nilai baru dari PlantAlive
//C		= nilai baru dari Cangkul
//S		= nilai baru dari Siram 
	Plantable = P;
	PlantExist = PE;
	PlantAlive = PA;
	Cangkul = C;
	Siram = S;
}

int LField::GetCond() {
//Mengembalikan nilai tertentu sesuai dengan kondisi LField
//Method ini digunakan sebagai informasi efektif 
//yang dikirimkan dan digunakan oleh kelas lain
//Berikut daftar nilai dan artinya :
		//-1= tidak valid
		//0 = Non-MoveAble
		//1 = Non-PlantAble					
		//2 = Plantable belum dicangkul		--> #10 jika sudah disiram
		//3 = Plantable sudah dicangkul		--> #11 jika sudah disiram
		//4 = sudah berupa bibit			--> #12 jika sudah disiram
		//5 = sudah dewasa					--> #13 jika sudah disiram
		//6 = sudah panen					--> #14 jika sudah disiram
		//7 = sudah mati					--> #15 jika sudah disiram
	//KAMUS LOKAL
		int Cond;			//variabel temporari dari nilai kondisi
	//ALGORITMA
		if 			(MoveAble == 0) 	{Cond = 0;}			//<- tidak dapat bergerak ke LField ini 												= 0
		else if 	(Plantable == 0) 	{Cond = 1;}			//<- tidak bisa menanam disini															= 1
		else if 	(Plantable == 1 && Cangkul == 0) {		//bisa ditanami dan belum dicangkul,
			if 		(Siram == 0) 		{Cond = 2;}			//		<- belum disiram 																= 2
			else						{Cond = 10;}		//		<- sudah disiram 																= 10
		}
		else if		(Plantable == 1 && Cangkul == 1 && PlantExist == 0) {	//bisa ditanami dan sudah dicangkul,
			if		(Siram == 0)		{Cond = 3;}			//		<- belum disiram																= 3
			else						{Cond = 11;}		//		<- sudah disiram																= 11
		}
		else if		(Plantable == 1 && PlantExist == 1 && PlantAlive == 1) {//bisa ditanami, ada tanaman tertentu, dan tanaman tersebut hidup,
			if		(PPlant->isPanen()) {									//tanaman yang hidup sudah siap panen,
					if (Siram == 0) 	{Cond = 6;}			//		<- belum disiram																= 6
					else				{Cond = 14;}		//		<- sudah disiram																= 14
			}
			else if	(PPlant->isDewasa()) {									//tanaman yang hidup sudah dewasa namun belum siap panen,
					if (Siram == 0)		{Cond = 5;}			//		<- belum disiram																= 5
					else				{Cond = 13;}		//		<- sudah disiram																= 13
			}
			else	{														//tanaman yang hidup masih berupa bibit	
					if (Siram == 0)		{Cond = 4;}			//		<- belum disiram																= 4
					else				{Cond = 12;}		//		<- sudah disiram																= 12
			}
		}
		else if		(Plantable == 1 && PlantExist == 1 && PlantAlive == 0) {//tanaman yang ada di LField sudah mati
			if		(Siram == 0)		{Cond = 7;}			//		<- belum disiram																= 7
			else 						{Cond = 15;}		//		<- sudah disiram																= 15
		}
		return Cond;
}

void LField::Kerja(char c) {
//Method yang melakukan sebuah set dari perubahan yang di triget oleh karakter c,
//karakter c dapat berupa:
//		'w' -> untuk mentrigger operasi Siram pada lahan
//		'c' -> untuk mentrigger operasi Cangkul pada lahan
//		's' -> untuk mentrigger operasi Slash pada lahan
//		'1' -> untuk mentrigger operasi menanam Ganja pada lahan
//		'2' -> untuk mentrigger operasi menanam Opium pada lahan
//		'3' -> untuk mentrigger operasi menanam Coca pada lahan
//		'4' -> untuk mentrigger operasi menanam Tobacco pada lahan
//		'5' -> untuk mentrigger operasi menanam Anggur pada lahan
//		'6' -> untuk mentrigger operasi menanam Mushroom pada lahan
//Untuk kondisi yang tidak valid, tidak dilakukan perubahan apapun dan tidak mengembalikan
//nilai apapun.
	//INFORMASI TAMBAHAN,
	//Daftar nilai kondisi yang dikembalikan oleh fungsi GetCond() dan artinya:
		//-1 = Tidak Valid
		//0 = Non-MoveAble
		//1 = Non-PlantAble					
		//2 = Plantable belum dicangkul		--> #10 sudah disiram
		//3 = Plantable sudah dicangkul		--> #11 sudah disiram
		//4 = sudah berupa bibit			--> #12 sudah disiram
		//5 = sudah dewasa					--> #13 sudah disiram
		//6 = sudah panen					--> #14 sudah disiram
		//7 = sudah mati					--> #15 sudah disiram
	if (c == 'c') {				//Operasi Cangkul
		if 		(GetCond() == 2) 					{Cangkul = 1;}	//Kondisi wajar, tidak ada tanaman dan LField bisa ditanami
		else if (GetCond() == 4 || GetCond() == 12) {Cangkul = 1;PlantExist = 0;PlantAlive = 0;PPlant = new Tanaman;}
				//kondisi tidak wajar, jika sudah ada bibit tanaman tertentu di LField dan dilakukan cangkul
				//maka bibit akan hilang dari LField
	}
	else if (c == 'w') {		//Operasi Siram
		if		((GetCond() > 1) && (GetCond() < 8)){Siram = 1;};	//kondisi wajar, untuk LField yang bersifat plantable pasti bisa disiram
	}
	else if (c == 's') {		//Operasi Slash
		if		(
				((GetCond() > 3) && (GetCond() < 8))				//kondisi wajar, ada tanaman dan belum di siram 
				|| 
				((GetCond() > 11) && (GetCond() < 16))				//kondisi wajar, ada tanaman dan sudah di siram
				)
				{PlantExist = 0;PlantAlive = 0;PPlant = new Tanaman;};	//set menjadi tidak ada tanaman tertentu di LField
	}
	//MENANAM SESUAI ID
	//1 = Ganja, 2 = Opium, 3 = Coca, 4 = Tobacco, 5 = Anggur, 6 = Mushroom
	else if ((c > 47) && (c < 54)) {								//Karakteristik karakter untuk menanam
		if (GetCond() == 3) {
			PlantExist = 1;
			PlantAlive = 1;
			if (c == '1') {			//Tanam Ganja
				PPlant = new Ganja;
			}
			else if (c == '2') {	//Tanam Opium
				PPlant = new Opium;
			}
			else if (c == '3') {	//Tanam Coca
				PPlant = new Coca;
			}
			else if (c == '4') {	//Tanam Tobacco
				PPlant = new Tobacco;
			}
			else if (c == '5') {	//Tanam Anggur
				PPlant = new Anggur;
			}
			else if (c == '6') {	//Tanam Mushroom
				PPlant = new Mushroom;
			}
		}
	}
}

void LField::KerjaPaksa(int c) {
//Method ini digunakan oleh operasi load (IO),
//tanpa melihat kondisi lahan, melakukan set tanaman dari lahan bersangkutan
	//MENANAM SESUAI ID
	//1 = Ganja, 2 = Opium, 3 = Coca, 4 = Tobacco, 5 = Anggur, 6 = Mushroom
			if (c == 1) {		//GANJA
				PPlant = new Ganja;
			}
			else if (c == 2) {	//OPIUM
				PPlant = new Opium;
			}
			else if (c == 3) {	//COCA
				PPlant = new Coca;
			}
			else if (c == 4) {	//TOBACCO
				PPlant = new Tobacco;
			}
			else if (c == 5) {	//ANGGUR
				PPlant = new Anggur;
			}
			else if (c == 6) {	//MUSHROOM
				PPlant = new Mushroom;
			}
}

void LField::Sync() {
//Method ini digunakan untuk interaksi dengan kelas Waktu
//melakukan sinkronisasi tanaman di lahan jika kondisi yang diminta dipenuhi,
	if (((GetCond() > 3) && (GetCond() < 7)) ||		//jika memang ada tanaman dan belum disiram atau
		((GetCond() > 11) && (GetCond() < 15)))	{	//jika memang ada tanaman dan sudah disiram
		//Terkait umur dari tanaman
		if 		(GetPlant()->getUmur() > 1) 	{GetPlant()->kurangiUmur(1);}
		else									{GetPlant()->kurangiUmur(1);PlantAlive = 0;}
		//Terkait happymeter dari tanaman
		if 		(IsSiram()) 					{GetPlant()->tambahHappyMeter(1);}
	}	
	Siram = 0;	//set lagi siram menjadi 0
}

////SELESAI METHOD KELAS LFIELD                              //////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
/////KELAS ALLMAP                                           ///////////
///////////////////////////////////////////////////////////////////////

//Karena definisi beberapa method hanya 1 line,
//untuk method berikut sudah didefinisikan di header file :
//	- GetLFieldXY(void)			- SetCuaca(int)
//	- GetCuaca(void)			- SetWaktu(int)
//	- GetWaktu(void)			- GetStKurc(int)

//Definisi method lain :

AllMap::AllMap() {
//Konstruktor untuk kelas AllMap
//inti konsturktor ini adalah membuat masing - masing objekt baru
//sebagai reference dari tiap atribut pointer
	int x,y;							//pass
	for (x=0;x<=7;x++) {				//perulangan untuk reference lahan
		for (y=0;y<=7;y++) {
			Lahan[x][y] = new LField; 
		}
	}
	for (x=0;x<=4;x++) {				//perulangan untuk reference rumah dan toko
		for (y=0;y<=4;y++) {
			Rumah[x][y] = new NLField;
			Toko[x][y] = new NLField;
		}
	}
	for (x=0;x<=7;x++) {				//perulangan untuk reference extensi lahan
		ELahan[x][0] = new NLField;
		ELahan[x][1] = new NLField;
	}
	for (y=0;y<=3;y++) {				//perulangan untuk reference status kurcaci
		KurcSt[y] = 0;
	}
	//inisialisasi dari cuaca dan waktu yang dicatat oleh AllMap
	Cuaca = 0;
	Waktu = 0;
}

void AllMap::SetLFieldProp(LField PF, int x, int y) {
	//Memasukkan nilai baru ke LField koordinat x,y dengan referensi properti LField lain
	Lahan[x][y]->SetAllProp(PF.IsPlantable(), PF.IsPlantExist(), PF.IsPlantAlive(), PF.IsCangkul(), PF.IsSiram());
}

void AllMap::SetLFieldXY(int x, int y, int P, int PE, int PA, int C, int S) {
	//memasukkan nilai baru di seluruh atribut LField x,y. 
	//P adalah nilai Plantable baru
	//PE adalah nilai PlantExist baru
	//PA adalah nilai PlantAlive baru
	//C adalah nilai Cangkul baru
	//S adalah nilai Siram baru
	LField TempField;
	TempField.SetAllProp(P, PE, PA, C, S);
	SetLFieldProp(TempField, x, y);
}

void AllMap::SetLField(LField* PF, int x, int y) {
	//set referensi baru untuk LField x,y
	Lahan[x][y] = PF;
}

void AllMap::SetNLFieldProp(NLField PF,int m, int x, int y) {
	//memasukkan nilai baru ke NLField di map tertentu dengan koordinat x,y dengan referensi properti NLField lain
	if (m == 0) {			//LAHAN EKSTRA
		ELahan[x][y]->SetAllProp(PF.SaveAble(), PF.BuyAble(), PF.SellAble(),PF.SleepAble());
	}
	else if (m == 1) {		//RUMAH
		Rumah[x][y]->SetAllProp(PF.SaveAble(), PF.BuyAble(), PF.SellAble(),PF.SleepAble());
	}
	else if (m == 2) {		//TOKO
		Toko[x][y]->SetAllProp(PF.SaveAble(), PF.BuyAble(), PF.SellAble(),PF.SleepAble());
	}
}

void AllMap::SetNLFieldXY(int m, int x, int y, int S, int B, int J, int T) {
	//memasukkan nilai baru di NLField map tertentu koordinat x,y
	//S adalah nilai PSave baru
	//B adalah nilai PBuy baru
	//J adalah nilai PSell baru
	//T adalah nilai PSleep baru
	NLField TempField;
	TempField.SetAllProp(S, B, J, T);
	SetNLFieldProp(TempField, m, x, y);
}

NLField* AllMap::GetNLFieldXY(int m, int x, int y) {
//mengembalikan pointer to NLField di map tertentu dengan koordinat x,y
	if 			(m == 0) 	{		//LAHAN EKSTRA
		return ELahan[x][y];
	}
	else if 	(m == 1) 	{		//RUMAH
		return Rumah[x][y];
	}
	else if 	(m == 2) 	{		//TOKO
		return Toko[x][y];
	}
}

void AllMap::KonvPrint(int m, int f[8][10]) {
//method ini digunakan untuk mengembalikan kondisi dari seluruh field yang diinginkan
//akan dibentuk sebuah array of array of integer berukuran 8x10 
//dengan setiap elemennya merepresentasikan field di map dan koordinat tertentu.
	int i,j,k;						//PASS
	for (i = 0;i<= 7;i++) {
		for (j = 0;j <= 9;j++) {
			f[i][j] = 0;
		}
	}
	if (m == 0) {	//Rumah
		for (i = 1;i <= 3;i++) {
			for (j = 1;j <= 3;j++) {
				f[i][j] = Rumah[i-1][j-1]->GetCond();
			}
		}
	}
	else if (m == 1) {		//Lahan + ELahan
		for (i = 1;i <= 6 ;i++) {
			for (j = 1;j <= 7;j++) {
				f[i][j] = Lahan[i-1][j-1]->GetCond();
			}
		}
		for (i = 1;i <= 6;i++) {
			f[i][8] = ELahan[i-1][0]->GetCond();	
		}
	}
	else if (m == 2) {	//Toko
		for (i = 4;i <= 6;i++) {
			for (j = 6;j <= 8;j++) {
				f[i][j] = Toko[i-4][j-6]->GetCond();
			}
		}
	}
}

int AllMap::GetXYCond(int x, int y) {
//method untuk mendapatkan kondisi dari field lahan di koordinat x,y
	return Lahan[x][y]->GetCond();
}

void AllMap::SetAllKurc (int k1, int k2, int k3) {
//method untuk melakukan set nilai dari seluruh kondisi kurcaci yang hidup di map
	KurcSt[1] = k1;
	KurcSt[2] = k2;
	KurcSt[3] = k3;
}

LField* AllMap::GetFieldwProp(int p) {
//mendapatkan field dengan properti tertentu:
// 1.field yang belum disiram
// 2.field yang belum diharvest padahal sudah siap panen
// 3.field yang belum dislash padahal tanaman sudah mati
//proses pencarian dilakukan sekuensial, mencari dirunut berdasarkan vertikal per horisontal
	int i,j,x,y;
	int Found;
	i = 0; j = 0;Found = 0;
	if (p == 0) {			//Water
		for (i = 1;i <= 7;i++) {
			for (j = 1;j <= 7;j++) {
				if (((GetLFieldXY(i,j)->IsSiram()) == 0) && (Found == 0)) {
					Found = 1;
					x = i;
					y = j;
					}
			}
		}
	}
	else if (p == 1) {		//Harvest
		for (i = 1;i <= 7;i++) {
			for (j = 1;j <= 7;j++) {
				if ((((GetLFieldXY(i,j)->GetPlant())->isPanen()) == 1) && (Found == 0)) {
					Found = 1;
					x = i;
					y = j;
					}
			}
		}
	}
	else if (p == 2) {		//Slash
		for (i = 1;i <= 7;i++) {
			for (j = 1;j <= 7;j++) {
				if ((((GetLFieldXY(i,j)->GetPlant())->isMati()) == 0) && (Found == 0)) {
					Found = 1;
					x = i;
					y = j;
					}
			}
		}
	}
	return (GetLFieldXY(x,y));
}

void AllMap::SyncAll() {
//method untuk sinkronisasi seluruh lahan yang ada di map
//dengan cara memanggil method Sync yang dimiliki class LField
	int x, y;
	for (x = 0;x <= 7;x++) {
		for (y = 0;y <= 7;y++) {
			Lahan[x][y]->Sync();
		}
	}
}

