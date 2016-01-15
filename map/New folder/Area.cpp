#include <iostream>
using namespace std;

//Pendefinisian Non Lahan

class Field {
	void		SetAllProp();
	int 		GetCond();
};

class NLField:public Field {
	private:
		int		PSave;
		int		PBuy;
		int		PSell;
		int		PSleep;
		
	public:
		//CTor
		NLField();
		
		//Method Get
		int		SaveAble()				{return PSave;};
		int		BuyAble()				{return PBuy;};
		int		SellAble()				{return PSell;};
		int		SleepAble()				{return PSleep;};
		int		GetCond();
		
		//Method Set
		void	SetAllProp(int S, int B, int J);
		void	SetSave(int a)			{PSave = a;};
		void	SetBuy(int a)			{PBuy = a;};
		void	SetSell(int a)			{PSell = a;};
		void	SetSleep(int a)			{PSleep = a;};
};

NLField::NLField() {
	PSave = 0;
	PBuy = 0;
	PSell = 0;
}

int NLField::GetCond() {
	//6 : Save dan Load
	//7 : BuyAble dan SellAble
	//8 : SellAble
	//9 : Save, Load, dan Sleep
	int temp;
	if 		(PSleep == 1) {
		temp = 9;
	}
	else if (PSave == 1) {
		temp = 6;
	}
	else if ((PBuy == 1) && (PSell == 1)) {
		temp = 7;
	}
	else if	((PSell == 1) && (PBuy == 0)) {
		temp = 8;
	}
	return temp;
}

void NLField::SetAllProp(int S, int B, int J) {
	PSave = S;
	PBuy = B;
	PSell = J;
}

//Selesai mendefinisikan non-Lahan

class LField:public Field {
	//Mendefinisikan kelas Field
	private:
		int 	Plantable;
		int		PlantExist;
		int		PlantAlive;
		int		Cangkul;
		int		Siram;	
			
		//Plant	PPlant;
	
	public:
		//CTOR
		LField();
		
		//Method Get
		int		IsPlantable()			{return Plantable;};
		int		IsPlantExist()			{return PlantExist;};
		int		IsPlantAlive()			{return PlantAlive;};
		int 	IsCangkul()				{return Cangkul;};
		int 	IsSiram()				{return Siram;};
		int		GetCond();
			//0 = Non-Plantable
			//1 = Plantable + Tidak ada tanaman + Belum dicangkul
			//2 = Plantable + Tidak ada tanaman + Sudah dicangkul
			//3 = Plantable + Ada Tanaman Hidup + Belum disiram
			//4 = Plantable + Ada Tanaman Hidup + Sudah disiram
			//5 = Plantable + Ada Tanaman Mati
		//Plant	GetPlant()				{return PPlant;};
		
		//Method Set
		void	SetAllProp(int P, int PE, int PA, int C, int S);
		int 	SetPlantable(int a)		{Plantable = a;};
		int		SetPlantExist(int a)	{PlantExist = a;};
		int		SetPlantAlive(int a)	{PlantAlive = a;};
		int		SetCangkul(int a)		{Cangkul = a;};
		int		SetSiram(int a)			{Siram = a;};
		
		//Method Kerja
		void	Kerja(char c, int* err);
		
		//Method Lain
		
		//Method Synchronous
		//void	Sync();
};

LField::LField() {
	Plantable = -1;
	PlantExist = -1;
	PlantAlive = -1;
	Cangkul = -1;
	Siram = -1;
}

void LField::SetAllProp(int P, int PE, int PA, int C, int S) {
	Plantable = P;
	PlantExist = PE;
	PlantAlive = PA;
	Cangkul = C;
	Siram = S;
}

//definisi method kerja
void LField::Kerja(char c, int* err) {
	//-1 = Tidak Valid
	//0 = Non-Plantable
	//1 = Plantable + Tidak ada tanaman + Belum dicangkul
	//2 = Plantable + Tidak ada tanaman + Sudah dicangkul
	//3 = Plantable + Ada Tanaman Hidup + Belum disiram
	//4 = Plantable + Ada Tanaman Hidup + Sudah disiram
	//5 = Plantable + Ada Tanaman Mati
																		//ERROR MESSAGE
	if (GetCond() == 0) {
		err = 0;														//Bukan lahan yang bisa dikerjakan...
	}
	else {
		if (c == 'w') { 												//Water
			if (GetCond() == 1 || GetCond() == 2) 		{*err = 1;}		//Tidak ada tanaman
			else if (GetCond() == 4)					{*err = 2;}		//Tanaman sudah disiram
			else if (GetCond() == 5)					{*err = 3;}		//Terdapat tanaman yang sudah sudah mati
			else if (GetCond() == 3) 					{Siram = 1;} 	//Tanaman disiram
		}
		else if (c == 'c') {											//Cangkul
			if (GetCond() == 1) 						{Cangkul = 1;}	//Tanaman dicangkul
			else if (GetCond() == 2)					{*err = 4;}		//Tanaman sudah dicangkul
			else if (GetCond() == 3 || GetCond() == 4)	{*err = 5;}		//Lahan ini sudah terdapat tanaman
			else if (GetCond() == 5)					{*err = 6;}		//Slash dulu tanaman yang sudah mati!
		}
		else if (c == 's') {											//Slash
			if (GetCond() == 1 || GetCond() == 2)		{*err = 1;}		//Tidak ada tanaman
			else if (GetCond() > 2 && GetCond() < 6)  	{				//Slash dilakukan
				PlantAlive = 0;
				PlantExist = 0;
			}
		}
		else if (c == 'p') {											//Plow
			if (GetCond() == 1)							{*err = 7;}		//Belum dicangkul bos
			else if (GetCond() == 2)					{				//Lakukan Plow
				PlantAlive = 1;
				PlantExist = 1;
				//TODO: PROSES PENANAMAN DILAKUKAN!
			}
			else 										{*err = 8;}		//Sudah terdapat tanaman
		}
		else 															//DO NOTHING to Field
		{
			*err = -1;													//error handling
		}
	}
	
}

//selesai definisi method kerja

//Definisi prosedur dan fungsi kelas Field
int LField::GetCond() {
		//-1 = Tidak Valid
		//0 = Non-Plantable
		//1 = Plantable + Tidak ada tanaman + Belum dicangkul
		//2 = Plantable + Tidak ada tanaman + Sudah dicangkul
		//3 = Plantable + Ada Tanaman Hidup + Belum disiram
		//4 = Plantable + Ada Tanaman Hidup + Sudah disiram
		//5 = Plantable + Ada Tanaman Mati
	//KAMUS LOKAL
		int Cond;
	//ALGORITMA
		if (Plantable == -1) {
			Cond = -1;	//error handling
		}
		else {
			if (PlantExist == 0, PlantAlive == 0, Cangkul == 0) {
				Cond = 1;
			}
			else if (PlantExist == 0, PlantAlive == 0, Cangkul == 1) {
				Cond = 2;
			}
			else if (PlantExist == 1, PlantAlive == 1, Siram == 0) {
				Cond = 3;
			}
			else if (PlantExist == 1, PlantAlive == 1, Siram == 1) {
				Cond = 4;
			}
			else if (PlantExist == 1, PlantAlive == 0, Cangkul == 1) {
				Cond = 5;
			}
			else {
				Cond = -1;	//error handling
			}
		}
		return Cond;
}

//selesai definisi fungsi dan prosedur untuk kelas Field

class AllMap {
	private:
		LField Lahan[8][8];
		NLField ELahan[8][2];
		NLField Rumah[5][5];
		NLField Toko[5][5];
		int KurcSt[4];
			//0 : sleep
			//1 : wake
		int Cuaca;
		int Waktu;
	public:
		//Method Set Untuk Lahan
			void 		SetLFieldProp		(LField, int, int);		
			void 		SetLFieldXY			(int x, int y, int P, int PE, int PA, int C, int S);
			
		//Method Get untuk Lahan
			LField 		GetLFieldXY			(int x, int y)	{return Lahan[x][y];};
			
		//Method Set untuk Non-Lahan
			void		SetNLFieldProp		(NLField, int, int, int);		
			void 		SetNLFieldXY		(int m, int x, int y, int S, int L, int J, int B);
		
		//Method Get untuk Non-Lahan
			NLField 	GetNLFieldXY		(int m, int x, int y);
			
		//Method Set Cuaca dan Waktu
			void 		SetCuaca			(int a)				{Cuaca = a;};
			void 		SetWaktu			(int a)				{Waktu = a;};
		
		//Method Get Cuaca dan Waktu
			int 		GetCuaca			()					{return Cuaca;};
			int 		GetWaktu			()					{return Waktu;};
			
		//Method Semua Kondisi Field
			int*		GetAllCond			();
			
		//Method Terkait Print
			void		KonvPrint			(int,int f[6][8]);
			
		//Method Terkait Kurcaci
			//Method Set
			void 		SetAllKurc			(int k1, int k2, int k3);
			
			//Method Get
			int			GetKurcX			(int x)				{return KurcSt[x];};
};

//Definisi Method Kerja

void AllMap::SetLFieldProp(LField PF, int x, int y) {
	Lahan[x][y].SetAllProp(PF.IsPlantable(), PF.IsPlantExist(), PF.IsPlantAlive(), PF.IsCangkul(), PF.IsSiram());
}

void AllMap::SetLFieldXY(int x, int y, int P, int PE, int PA, int C, int S) {
	LField TempField;
	TempField.SetAllProp(P, PE, PA, C, S);
	SetLFieldProp(TempField, x, y);
}

void AllMap::SetNLFieldProp(NLField PF,int m, int x, int y) {
	if (m == 0) {			//LAHAN EKSTRA
		ELahan[x][y].SetAllProp(PF.SaveAble(), PF.BuyAble(), PF.SellAble());
	}
	else if (m == 1) {		//RUMAH
		Rumah[x][y].SetAllProp(PF.SaveAble(), PF.BuyAble(), PF.SellAble());
	}
	else if (m == 2) {		//TOKO
		Toko[x][y].SetAllProp(PF.SaveAble(), PF.BuyAble(), PF.SellAble());
	}
}

void AllMap::SetNLFieldXY(int m, int x, int y, int S, int L, int B, int J) {
	NLField TempField;
	TempField.SetAllProp(S, B, J);
	SetNLFieldProp(TempField, m, x, y);
}

NLField AllMap::GetNLFieldXY(int m, int x, int y) {
	if 			(m == 0) 	{			//LAHAN EKSTRA
		return ELahan[x][y];
	}
	else if 	(m == 1) 	{		//RUMAH
		return Rumah[x][y];;
	}
	else if 	(m == 2) 	{		//TOKO
		return Toko[x][y];
	}
}

void AllMap::KonvPrint(int m, int f[6][8]) {
	int i,j,k;						//PASS
	if 			(m == 0)	{		//LAHAN + EKSTRA
		for (i = 0;i <= 5;i++) {
			for (j = 0;j <= 5;j++) {
				f[i][j] = Lahan[i+1][j+1].GetCond();
			}
		}
		for (i =0;i <= 5;i++) {
			f[i][j] = ELahan[i+1][0].GetCond();
		}
	}
	else if 	(m == 1) 	{		//RUMAH
		for (i = 0;i <= 5;i++) {
			for (j = 0; j <= 7;j++) {
				f[i][j] = 0;
			}
		}
		for (i = 3;i <= 5;i++) {
			for (j = 3; j <= 5; j++) {
				f[i][j] = Rumah[i-2][j-2].GetCond();
			}
		}
	}
	else if 	(m == 2) 	{		//TOKO
		for (i = 0;i <= 5;i++) {
			for (j = 0; j <= 7;j++) {
				f[i][j] = 0;
			}
		}
		for (i = 3;i <= 5;i++) {
			for (j = 3; j <= 5; j++) {
				f[i][j] = Toko[i-2][j-2].GetCond();
			}
		}
	}
}

//Selesai Definisi Method Kerja

int main() {
	
	return 0;
}
