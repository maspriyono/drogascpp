#ifndef AREA_H
#define AREA_H
#include <iostream>
using namespace std;

#include <typeinfo>
//Pendefinisian Non Lahan

#include "../tanaman/tanaman.h"
#include "../tanaman/ganja.h"
#include "../tanaman/coca.h"
#include "../tanaman/mushroom.h"
#include "../tanaman/tobacco.h"
#include "../tanaman/opium.h"
#include "../tanaman/anggur.h"

class Field {
	protected:
		int			MoveAble;
	public:
		//CTOR
		Field();

		//
		int			GetMoveAble()		{return MoveAble;};
		void		SetMoveAble(int a) 	{MoveAble = a;};
};


class NLField:public Field {
	public:
		int		PSave;
		int		PBuy;
		int		PSell;
		int		PSleep;
		
		//CTor
		NLField();
		
		//Method Get
		int		SaveAble()				{return PSave;};
		int		BuyAble()				{return PBuy;};
		int		SellAble()				{return PSell;};
		int		SleepAble()				{return PSleep;};
		int		GetCond();
		
		//Method Set
		void	SetAllProp(int S, int B, int J, int T);
		void	SetSave(int a)			{PSave = a;};
		void	SetBuy(int a)			{PBuy = a;};
		void	SetSell(int a)			{PSell = a;};
		void	SetSleep(int a)			{PSleep = a;};
};


class LField:public Field {
	//Mendefinisikan kelas Field
	public:
		int 		Plantable;
		int			PlantExist;
		int			PlantAlive;
		int			Cangkul;
		int			Siram;
	
		Tanaman*		PPlant;
		
		//CTOR
		LField();
		
		//Method Get
		int		IsPlantable()			{return Plantable;};
		int		IsPlantExist()			{return PlantExist;};
		int		IsPlantAlive()			{return PlantAlive;};
		int 	IsCangkul()				{return Cangkul;};
		int 	IsSiram()				{return Siram;};
		int		GetCond();
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
		void	SetAllProp(int P, int PE, int PA, int C, int S);
		void 	SetPlantable(int a)		{Plantable = a;};
		void	SetPlantExist(int a)	{PlantExist = a;};
		void	SetPlantAlive(int a)	{PlantAlive = a;};
		void	SetCangkul(int a)		{Cangkul = a;};
		void	SetSiram(int a)			{Siram = a;};
		void	SetPlant(Tanaman* TPlant)		{PPlant = TPlant;};
		
		//Method Kerja
		Tanaman* GetPlant() 			{return PPlant;};
		void 	Kerja(char c);
		
		//Method Synchronous
		void	Sync();
};

class AllMap {
	private:
		LField *Lahan[6][7];
		NLField *ELahan[6][1];
		NLField *Rumah[3][3];
		NLField *Toko[3][3];
		int KurcSt[4];
			//0 : sleep
			//1 : wake
		int Cuaca;
		int Waktu;
	public:
		//CTOR
		AllMap();
		
		//Method Set Untuk Lahan
			void 		SetLFieldProp		(LField, int, int);		
			void 		SetLFieldXY			(int x, int y, int P, int PE, int PA, int C, int S);
			void		SetLField			(LField*, int, int);
		//Method Get untuk Lahan
			LField* 	GetLFieldXY			(int x, int y)		{return Lahan[x][y];};
			
		//Method Set untuk Non-Lahan
			void		SetNLFieldProp		(NLField, int, int, int);		
			void 		SetNLFieldXY		(int m, int x, int y, int S, int L, int J, int B, int T);
		
		//Method Get untuk Non-Lahan
			NLField* 	GetNLFieldXY		(int m, int x, int y);
			
		//Method Set Cuaca dan Waktu
			void 		SetCuaca			(int a)				{Cuaca = a;};
			void 		SetWaktu			(int a)				{Waktu = a;};
		
		//Method Get Cuaca dan Waktu
			int 		GetCuaca			()					{return Cuaca;};
			int 		GetWaktu			()					{return Waktu;};
			
		//Method Semua Kondisi Field
			int*		GetAllCond			();
			void		Kerja				(int x, int y, char c);
			int			GetXYCond			(int x, int y);
				
		//Method Terkait Print
			void		KonvPrint			(int m, int f[8][10]);
			
		//Method Terkait Kurcaci
			//Method Set
			void 		SetAllKurc			(int k1, int k2, int k3);
			int			GetStKurc			(int s)				{return KurcSt[s];}
			LField*		GetFieldwProp		(int);		
			
		//Method Sinkronisasi Waktu
			//int			GetKurcX			(int x)				{return KurcSt[x];};
			void		SyncAll				();
};
#endif
