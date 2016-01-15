#include <iostream>
using namespace std;

#include <stdio.h>
#include <string>
#include <cstdlib>

#ifdef __WIN32__
#include <windows.h>
#include <conio.h>
#endif

#include "..\allmap\Area.h"

class Display {
	private :
		int FSave[8][10];
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
		int SkwMeter;
				
	public :
		//Konstruktor
		Display();
		
		//Method Get
		
		//Method Set
		void	SetODMeter						(int N)						{ODMeter = N;};
		void	SetSkwMeter						(int N)						{SkwMeter = N;};
		void 	operator<< 						(int FL[8][10]);
		
		//Rangkaian Set StKricer
		void 	SetPlayer						(int x, int y, int dir)		{StKricer[0][0] = dir;StKricer[0][1] = x; StKricer[0][2] = y;} 
		void 	SetKurcaci1						(int x, int y, int dir)		{StKricer[1][0] = dir;StKricer[1][1] = x; StKricer[1][2] = y;}  
		void 	SetKurcaci2						(int x, int y, int dir)		{StKricer[2][0] = dir;StKricer[2][1] = x; StKricer[2][2] = y;}  
		void 	SetKurcaci3						(int x, int y, int dir)		{StKricer[3][0] = dir;StKricer[3][1] = x; StKricer[3][2] = y;}  		
		void 	SetStKricer						(int i1, int i2, int isi)	{StKricer[i1][i2] = isi;};
		void	ChangeCharPos					(int c, int x1, int y1, int dir, int x2, int y2);
		
		//Method print ke layar
		void	StdStr							(string S, int N);
		void 	PrintBatas						(int A,int N,int P);
					//0 : atas
					//1 : tengah
					//2 : bawah
		void	PrintTemplate					();
		void	PrintJam						(int, int);
		void	PrintTgl						(int, int);
		void	PrintLoc						(int);
		void	PrintKor						(int, int);
		void	PrintCua						(int);
		void	PrintMus						(int);
		void	PrintName						(string); 
		void	PrintSt							(int);
		void	PrintBuck						(int);
		void	PrintInfoL						(LField*);
		void	PrintInfoNL						(int);
		void	PrintFlXY						(int, int);
		void	PrintAllFl						();
		void	PrintKur						(int,int,int);
		void	PrintInv						();
		void	PrintCharPos					(int);
		void	PrintAllChar					(int,int,int,int);
		void	PrintODSKW						();
		void	PrintInfoBox					(int , string);
		void	ClearInfoBox					();
		void	PrintInfo						(string);
		
		//Method Konversi
		string 	ToSTR							(int i);
		string	StKurcaci						(int s);			
		
		//Method Bantuan
		int 	GetTipeField					(int t);
		void 	PrintKsg						(int N);
		string 	Bar								(int A, int B);
		void 	PrintASCII						(int a);
		void 	SetWarna						(int fg, int bg);
		void 	ClearScr						();
		void	Go								(int, int);

};
