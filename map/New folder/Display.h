#ifndef Display_H
#define Display_H
#include <iostream>
using namespace std;

#include <stdio.h>
#include <string>
#include <cstdlib>

#ifdef __WIN32__
#include <windows.h>
#include <conio.h>
#endif

class Display {
	private :
		int FSave[6][8];
		int StKricer[4][3];
			//Index ke-1 untuk menunjukkan kricer
				//0 : Player
				//1 : Kurcaci 1
				//2 : Kurcaci 2
				//3 : Kurcaci 3
			//Index ke-2 untuk menunjukkan properties dari kricer
				//0 : Direction
				//1 : Posisi X
				//2 : Posisi Y
		int ODMeter;
		string 	ju;
			//Panel kiri atas 	--> P = 1
				string 	lu,		//n = 0		--> Nama Pemain
						lu1,	//n = 1		--> Status
						lu2;	//n = 2		-->	Uang
			
			//Panel kiri bawah 	--> P = 2
				string 	lb,		//n = 0		
						lb1,	//n = 1
						lb2,	//n = 2
						lb3,	//n = 3
						lb4,	//n = 4
						lb5,	//n = 5
						lb6,	//n = 6
						lb7;	//n = 7
			
			//Panel kanan atas 	--> p = 3
				string	ru,		//n = 0		--> Kurcaci 			
						ru1,	//n = 1		--> Kurcaci 1
						ru2,	//n = 2		--> Status Kurcaci 1
						ru3,	//n = 3		--> Kurcaci 2
						ru4,	//n = 4		-->	Status Kurcaci 2
						ru5,	//n = 5		--> Kurcaci 3
						ru6;	//n = 6		--> Status Kurcaci 3
			
			//Panel kanan bawah	--> p = 4
				string	rb,		//n = 0		--> Inventori
						rb1,	//n = 1		--> Barang 1
						rb1j,	//n = 2		--> Jumlah Barang 1
						rb2,	//n = 3		--> Barang 2
						rb2j,	//n = 2		--> Jumlah Barang 2
						rb3,	//n = 5		--> Barang 3
						rb3j;	//n = 2		--> Jumlah Barang 3
				
	public :
		//Konstruktor
		Display();
		
		//Method Get
		string 	GetJudul						()							{return ju;};
		int 	GetStKricer						(int i1, int i2)			{return StKricer[i1][i2];};
		
		//Method Set
		void 	SetJudul						(int TT, int BB, int HH, int Loc, int MM, int X, int Y, string musim, string cuaca);
		void 	SetStrPanel						(int P, int N, string S);
		void	SetODMeter						(int N)						{ODMeter = N;};
		void 	operator<< 						(int FL[6][8]);
		
		//Rangkaian Set StKricer
		void 	SetPlayer						(int x, int y, int dir)		{StKricer[0][0] = dir;StKricer[0][1] = x; StKricer[0][2] = y;} 
		void 	SetKurcaci1						(int x, int y, int dir)		{StKricer[1][0] = dir;StKricer[1][1] = x; StKricer[1][2] = y;}  
		void 	SetKurcaci2						(int x, int y, int dir)		{StKricer[2][0] = dir;StKricer[2][1] = x; StKricer[2][2] = y;}  
		void 	SetKurcaci3						(int x, int y, int dir)		{StKricer[3][0] = dir;StKricer[3][1] = x; StKricer[3][2] = y;}  		
		void 	SetStKricer						(int i1, int i2, int isi)	{StKricer[i1][i2] = isi;};
		
		//Method print ke layar
		void	StdStr							(string S, int N);
		void 	PrintBatas						(int A,int N,int P);
					//0 : atas
					//1 : tengah
					//2 : bawah
		int 	GetTipeField					(int);
		void 	PrintIsiField					(int brs);	
		void 	PrintJudul						();
		void 	PrintUtama						();	
		void	PrintBelow						();
		void	Print							();

		//Method Konversi
		string 	ToSTR							(int i);
		string 	MakeJam							(int jam,int mnt);
		string 	MakeTgl							(int tgl,int bln);
		string	MakeUmur						(int u);
		string	StKurcaci						(int s);			
		
		//Method Bantuan
		void 	PrintKsg						(int N);
		string 	Bar								(int A, int B);
		void 	PrintASCII						(int a);
		void 	SetWarna						(int fg, int bg);
		void 	ClearScr						();

};

#endif
