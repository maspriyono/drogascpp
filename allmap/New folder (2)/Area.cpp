#include "Area.h"
Field::Field() {
	MoveAble = 0;
}

NLField::NLField() {
	MoveAble = 1;
	PSave = 1;
	PBuy = 0;
	PSell = 0;
	PSleep = 0;
}

int NLField::GetCond() {
	//8 = tempat tidur/SleepAble
	//9 = tempat save/load
	//16 = tempat sell/buy
	//17 = tempat sell
	int temp;
	if 		(PSleep == 1) {
		temp = 8;
	}
	else if (PSave == 1) {
		temp = 9;
	}
	else if ((PBuy == 1) && (PSell == 1)) {
		temp = 16;
	}
	else if	((PSell == 1) && (PBuy == 0)) {
		temp = 17;
	}
	return temp;
}

void NLField::SetAllProp(int S, int B, int J, int T) {
	PSave = S;
	PBuy = B;
	PSell = J;
	PSleep = T;
}

//Selesai mendefinisikan non-Lahan



LField::LField() {
	MoveAble = 1;
	Plantable = 1;
	PlantExist = 0;
	PlantAlive = 0;
	Cangkul = 0;
	Siram = 0;
	
	PPlant = new Tanaman;
}

void LField::SetAllProp(int P, int PE, int PA, int C, int S) {
	Plantable = P;
	PlantExist = PE;
	PlantAlive = PA;
	Cangkul = C;
	Siram = S;
}

void LField::Kerja(char c) {
	//DAFTAR KONDISI :
		//-1 = Tidak Valid
		//0 = Non-MoveAble
		//1 = Non-PlantAble					
		//2 = Plantable belum dicangkul		--> #10 sudah disiram
		//3 = Plantable sudah dicangkul		--> #11 sudah disiram
		//4 = sudah berupa bibit			--> #12 sudah disiram
		//5 = sudah dewasa					--> #13 sudah disiram
		//6 = sudah panen					--> #14 sudah disiram
		//7 = sudah mati					--> #15 sudah disiram
	if (c == 'c') {				//cangkul
		if 		(GetCond() == 2) 					{Cangkul = 1;}
		else if (GetCond() == 4 || GetCond() == 12) {Cangkul = 1;PlantExist = 0;PlantAlive = 0;}
	}
	else if (c == 'w') {		//water
		if		((GetCond() > 1) && (GetCond() < 8)){Siram = 1;};
	}
	else if (c == 's') {		//slash
		if		(
				((GetCond() > 3) && (GetCond() < 8)) 
				|| 
				((GetCond() > 11) && (GetCond() < 16))
				)
				{PlantExist = 0;PlantAlive = 0;};
	}
	else if (c == 'h') {
		if		((GetCond() == 6) || (GetCond() == 14)) {
				if (PPlant->getTipePanen()) {
					PPlant->setHappyMeter(0);
				}
				else {
					PlantAlive = 0;
				}
		}
	}
	//MENANAM SESUAI ID
	//1 = Ganja, 2 = Opium, 3 = Coca, 4 = Tobacco, 5 = Anggur, 6 = Mushroom
	else if ((c > 47) && (c < 54)) {
		if (GetCond() == 3) {
			PlantExist = 1;
			PlantAlive = 1;
			if (c == '1') {			//GANJA
				PPlant = new Ganja;
			}
			else if (c == '2') {	//OPIUM
				PPlant = new Opium;
			}
			else if (c == '3') {	//COCA
				PPlant = new Coca;
			}
			else if (c == '4') {	//TOBACCO
				PPlant = new Tobacco;
			}
			else if (c == '5') {	//ANGGUR
				PPlant = new Anggur;
			}
			else if (c == '6') {	//MUSHROOM
				PPlant = new Mushroom;
			}
		}
	}
}

//Definisi prosedur dan fungsi kelas Field
int LField::GetCond() {
		//-1 = Tidak Valid
		//0 = Non-MoveAble
		//1 = Non-PlantAble					
		//2 = Plantable belum dicangkul		--> #10 sudah disiram
		//3 = Plantable sudah dicangkul		--> #11 sudah disiram
		//4 = sudah berupa bibit			--> #12 sudah disiram
		//5 = sudah dewasa					--> #13 sudah disiram
		//6 = sudah panen					--> #14 sudah disiram
		//7 = sudah mati					--> #15 sudah disiram
		//8 = tempat tidur/SleepAble		--> NLFIELD
		//9 = tempat save/load				--> NLFIELD
	//KAMUS LOKAL
		int Cond;
	//ALGORITMA
		if 			(MoveAble == 0) 	{Cond = 0;}
		else if 	(Plantable == 0) 	{Cond = 1;}
		else if 	(Plantable == 1 && Cangkul == 0) {
			if 		(Siram == 0) 		{Cond = 2;}
			else						{Cond = 10;}
		}
		else if		(Plantable == 1 && Cangkul == 1 && PlantExist == 0) {
			if		(Siram == 0)		{Cond = 3;}
			else						{Cond = 11;}
		}
		else if		(Plantable == 1 && PlantExist == 1 && PlantAlive == 1) {
			if		(PPlant->isPanen()) {
					if (Siram == 0) 	{Cond = 6;}
					else				{Cond = 14;}
			}
			else if	(PPlant->isDewasa()) {
					if (Siram == 0)		{Cond = 5;}
					else				{Cond = 13;}
			}
			else	{
					if (Siram == 0)		{Cond = 4;}
					else				{Cond = 12;}
			}
		}
		else if		(Plantable == 1 && PlantExist == 1 && PlantAlive == 0) {
			if		(Siram == 0)		{Cond = 7;}
			else 						{Cond = 15;}
		}
		return Cond;
}

void LField::Sync() {
	if (((GetCond() > 3) && (GetCond() < 7)) ||
		((GetCond() > 11) && (GetCond() < 15)))	{
		GetPlant()->kurangiUmur(1);
		if (IsSiram()) {
			GetPlant()->tambahHappyMeter(1);
		}
	}
	Siram = 0;	
}

//selesai definisi fungsi dan prosedur untuk kelas Field



//Definisi Method Kerja

AllMap::AllMap() {
	int x,y;
	for (x=0;x<=7;x++) {
		for (y=0;y<=7;y++) {
			Lahan[x][y] = new LField; 
		}
	}
	for (x=0;x<=4;x++) {
		for (y=0;y<=4;y++) {
			Rumah[x][y] = new NLField;
			Toko[x][y] = new NLField;
		}
	}
	for (x=0;x<=7;x++) {
		ELahan[x][0] = new NLField;
		ELahan[x][1] = new NLField;
	}
	for (y=0;y<=3;y++) {
		KurcSt[y] = 0;
	}
	Cuaca = 0;
	Waktu = 0;
}

void AllMap::SetLFieldProp(LField PF, int x, int y) {
	Lahan[x][y]->SetAllProp(PF.IsPlantable(), PF.IsPlantExist(), PF.IsPlantAlive(), PF.IsCangkul(), PF.IsSiram());
}

void AllMap::SetLFieldXY(int x, int y, int P, int PE, int PA, int C, int S) {
	LField TempField;
	TempField.SetAllProp(P, PE, PA, C, S);
	SetLFieldProp(TempField, x, y);
}

void AllMap::SetLField(LField* PF, int x, int y) {
	Lahan[x][y] = PF;
}

void AllMap::SetNLFieldProp(NLField PF,int m, int x, int y) {
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

void AllMap::SetNLFieldXY(int m, int x, int y, int S, int L, int B, int J, int T) {
	NLField TempField;
	TempField.SetAllProp(S, B, J, T);
	SetNLFieldProp(TempField, m, x, y);
}

NLField* AllMap::GetNLFieldXY(int m, int x, int y) {
	if 			(m == 0) 	{			//LAHAN EKSTRA
		return ELahan[x][y];
	}
	else if 	(m == 1) 	{		//RUMAH
		return Rumah[x][y];
	}
	else if 	(m == 2) 	{		//TOKO
		return Toko[x][y];
	}
}

//TODO : BELUM JALAN
void AllMap::KonvPrint(int m, int f[8][10]) {
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
	return Lahan[x][y]->GetCond();
}

//Selesai Definisi Method Kerja

void AllMap::SetAllKurc (int k1, int k2, int k3) {
	KurcSt[1] = k1;
	KurcSt[2] = k2;
	KurcSt[3] = k3;
}

LField* AllMap::GetFieldwProp(int p) {
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
	int x, y;
	for (x = 0;x <= 7;x++) {
		for (y = 0;y <= 7;y++) {
			Lahan[x][y]->Sync();
		}
	}
}

