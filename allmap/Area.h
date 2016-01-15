#ifndef AREA_H
#define AREA_H
#include <iostream>
using namespace std;

#include <typeinfo>

#include "../tanaman/tanaman.h"
#include "../tanaman/ganja.h"
#include "../tanaman/coca.h"
#include "../tanaman/mushroom.h"
#include "../tanaman/tobacco.h"
#include "../tanaman/opium.h"
#include "../tanaman/anggur.h"

///////////////////////////////////////////////////////////////////////
/////KELAS FIELD                                            ///////////
///////////////////////////////////////////////////////////////////////

//Kelas Field adalah kelas abstrak

class Field {
	protected:
		int			MoveAble;									//Apakah Field dapat diakses oleh creature atau tidak
	public:
		//CTOR
		Field();											

		//Fungsi Get dan Set
		int			GetMoveAble()		{return MoveAble;};		//Mendapatkan nilai MoveAble dari Field
		void		SetMoveAble(int a) 	{MoveAble = a;};		//Melakukan perubahan terhadap nilai MoveAble
};

///////////////////////////////////////////////////////////////////////
/////KELAS NLFIELD : TURUNAN KELAS FIELD                    ///////////
///////////////////////////////////////////////////////////////////////


class NLField:public Field {
	public:
		int		PSave;											//Apakah player bisa melakukan save
		int		PBuy;											//Apakah player bisa melakukan buy
		int		PSell;											//Apakah player bisa melakukan sell
		int		PSleep;											//Apakah player bisa melakukan sleep
		
		//CTOR
		NLField();
		
		//Method Get
		int		SaveAble()				{return PSave;};		//Mendapatkan nilai PSave
		int		BuyAble()				{return PBuy;};			//Mendapatkan nilai PBuy
		int		SellAble()				{return PSell;};		//Mendapatkan nilai PSell
		int		SleepAble()				{return PSleep;};		//Mendapatkan nilai PSleep
		int		GetCond();
		
		//Method Set
		void	SetAllProp(int S, int B, int J, int T);			//Melakukan set nilai untuk empat atribut secara langsung
		void	SetSave(int a)			{PSave = a;};			//Melakukan set nilai untuk PSave
		void	SetBuy(int a)			{PBuy = a;};			//Melakukan set nilai untuk PBuy
		void	SetSell(int a)			{PSell = a;};			//Melakukan set nilai untuk PSell
		void	SetSleep(int a)			{PSleep = a;};			//Melakukan set nilai untuk PSleep
};

///////////////////////////////////////////////////////////////////////
/////KELAS LFIELD : TURUNAN KELAS FIELD                     ///////////
///////////////////////////////////////////////////////////////////////


class LField:public Field {
	//Mendefinisikan kelas Field
	public:
		int 		Plantable;									//Apakah LField bersangkutan bisa ditanami
		int			PlantExist;									//Apakah ada tanaman di LField bersangkutan
		int			PlantAlive;									//Apakah ada tanaman HIDUP di LField bersangkutan
		int			Cangkul;									//Apakah LField sudah dicangkul
		int			Siram;										//Apakah LField sudah disiram
	
		Tanaman*		PPlant;									//Menyimpan data Tanaman pada LField bersangkutan
		
		//CTOR
		LField();
		
		//Method Get
		int		IsPlantable()			{return Plantable;};	//Mendapatkan nilai Plantable
		int		IsPlantExist()			{return PlantExist;};	//Mendapatkan nilai PlantExist
		int		IsPlantAlive()			{return PlantAlive;};	//Mendapatkan nilai PlantAlive
		int 	IsCangkul()				{return Cangkul;};		//Mendapatkan nilai Cangkul
		int 	IsSiram()				{return Siram;};		//Mendapatkan nilai Siram
		int		GetCond();
			//INFORMASI KONDISI :
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
		
		//Method Set
		void	SetAllProp(int P, int PE, int PA, int C, int S);//Melakukan set nilai untuk semua atribut LField
		void 	SetPlantable(int a)		{Plantable = a;};		//Melakukan set nilai untuk atribut Plantable
		void	SetPlantExist(int a)	{PlantExist = a;};		//Melakukan set nilai untuk atribut PlantExist
		void	SetPlantAlive(int a)	{PlantAlive = a;};		//Melakukan set nilai untuk atribut PlantAlive
		void	SetCangkul(int a)		{Cangkul = a;};			//Melakukan set nilai untuk atribut Cangkul
		void	SetSiram(int a)			{Siram = a;};			//Melakukan set nilai untuk atribut Siram
		void	SetPlant(Tanaman* TPlant){PPlant = TPlant;};	//Merubah referensi terhadap objek tanaman lain
		
		//Method Kerja
		Tanaman* GetPlant() 			{return PPlant;};		//Mendapatkan alamat referensi tanaman pada LField bersangkutan
		void 		Kerja(char c);								//Melakukan Kerja tertentu(sesuai karakter 'c') pada LField 
		void 		KerjaPaksa(int c);							//Melakukan Kerja tertentu(sesuai integer 'c') pada LField khusus untuk kasus Load File
			
		//Method Synchronous
		void	Sync();											//Sinkronisasi lahan dengan perubahan waktu
};

///////////////////////////////////////////////////////////////////////
/////KELAS ALLMAP                                           ///////////
///////////////////////////////////////////////////////////////////////

class AllMap {
	private:
		LField *Lahan[6][7];						//POINTER TO LFIELD[LAHAN]		 	6x7
			//////////////////////////////////
			//GAMBARAN LAHAN :			    //
			//////////////////////////////////
			//[0,6][1,6][2,6][3,6][4,6][5,6]//
			//[0,5][1,5][2,5][3,5][4,5][5,5]//
			//[0,4][1,4][2,4][3,4][4,4][5,4]//
			//[0,3][1,3][2,3][3,3][4,3][5,3]//
			//[0,2][1,2][2,2][3,2][4,2][5,2]//
			//[0,1][1,1][2,1][3,1][4,1][5,1]//
			//[0,0][1,0][2,0][3,0][4,0][5,0]//
			//////////////////////////////////
		NLField *ELahan[6][1];						//POINTER TO NLFIELD[ELAHAN]		6x1
			//////////////////////////////////
			//GAMBARAN EKSTENSI LAHAN :     //
			//////////////////////////////////
			//[0,0][1,0][2,0][3,0][4,0][5,0]//
			//////////////////////////////////
		NLField *Rumah[3][3];						//POINTER TO NLFIELD[RUMAH] 		3x3
			///////////////////
			//GAMBARAN RUMAH://
			///////////////////
			//[0,2][1,2][2,2]//
			//[0,1][1,1][2,1]//
			//[0,0][1,0][2,0]//
			///////////////////
		NLField *Toko[3][3];						//POINTER TO NLFIELD[TOKO]			3x3
			///////////////////
			//GAMBARAN TOKO ://
			///////////////////
			//[0,2][1,2][2,2]//
			//[0,1][1,1][2,1]//
			//[0,0][1,0][2,0]//
			///////////////////
		int KurcSt[4];								//ARRAY OF INTEGER MENYIMPAN STATUS KURCACI
			//0 : sleep
			//1 : wake
			////////////////////////////////////
			//MENYIMPAN STATUS KURCACI        //
			////////////////////////////////////
			//KURCACI 1 : INDEX 1 || WATER    //
			//KURCACI 2 : INDEX 2 || HARVEST  //
			//KURCACI 3 : INDEX 3 || SLASH	  //
			////////////////////////////////////
		int Cuaca;
			////////////////////////////////////
			//INFORMASI CUACA                 //
			////////////////////////////////////
		int Waktu;
			////////////////////////////////////
			//INFORMASI WAKTU                 //
			////////////////////////////////////
	public:
		//CTOR
		AllMap();
		
		//Method untuk Lahan (LField)
			//Method Set Untuk Lahan
				void 		SetLFieldProp		(LField, int, int);		
				void 		SetLFieldXY			(int x, int y, int P, int PE, int PA, int C, int S);
				void		SetLField			(LField*, int, int);
				
			//Method Get untuk Lahan
				LField* 	GetLFieldXY			(int x, int y)		{return Lahan[x][y];};
				
			//Method Lain Berkaitan dengan Lahan
				void		Kerja				(int x, int y, char c);
				int			GetXYCond			(int x, int y);
			
		//Method untuk Toko, Rumah, dan ELahan (NLField)
			//Method Set untuk Non-Lahan
				void		SetNLFieldProp		(NLField, int, int, int);		
				void 		SetNLFieldXY		(int m, int x, int y, int S,  int J, int B, int T);
			
			//Method Get untuk Non-Lahan
				NLField* 	GetNLFieldXY		(int m, int x, int y);
			
		//Method Berkaitan Cuaca dan Waktu
			//Method Set Cuaca dan Waktu
				void 		SetCuaca			(int a)				{Cuaca = a;};
				void 		SetWaktu			(int a)				{Waktu = a;};
			
			//Method Get Cuaca dan Waktu
				int 		GetCuaca			()					{return Cuaca;};
				int 		GetWaktu			()					{return Waktu;};
				
			//Method Sinkronisasi Waktu
				LField*		GetFieldwProp		(int);		
				void		SyncAll				();
						
		//Method Terkait Informasi AllMap secara keseluruhan
			//Method Print untuk di pass ke display
				void		KonvPrint			(int m, int f[8][10]);
			
		//Method Terkait Kurcaci
			//Method Set
			void 		SetAllKurc			(int k1, int k2, int k3);
			
			//Method Get
			int			GetStKurc			(int s)				{return KurcSt[s];}
		
};
#endif
