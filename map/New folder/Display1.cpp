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
		string ju;
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
		string GetJudul()	{return ju;};
		
		//Method Set
		void SetJudul(int TT, int BB, int HH, int Loc, int MM, int X, int Y, string musim, string cuaca);
		void SetStrPanel(int P, int N, string S);
		void operator<< (int FL[6][8]);
		
		//Method print ke layar
		void StdStr(string S, int N);
		void PrintBatas(int A,int N,int P);
			//0 : atas
			//1 : tengah
			//2 : bawah
		int GetTipeField(int);
		void PrintIsiField(int brs);	
		void PrintJudul();
		void PrintUtama();	

		//Method Konversi
		string ToSTR(int i);
		string MakeJam(int jam,int mnt);
		string MakeTgl(int tgl,int bln);
		
		//Method Bantuan
		void PrintKsg(int N);
		void PrintBar(int A, int B);
		void PrintASCII(int a);
		void SetWarna(int fg, int bg);
		void ClearScr();

};

Display::Display() {
	int i,j;
	ju = "";
	lu = ""; lu1 = ""; lu2 = "";
	lb = ""; lb1 = ""; lb2 = ""; lb3 = ""; lb4 = ""; lb5 = ""; lb6 = ""; lb7 = "";
	ru = "KURCACI"; ru1 = "KURCACI [] :"; ru2 = ""; ru3 = "KURCACI [] :"; ru4 = ""; ru5 = "KURCACI [] :"; ru6 = "";
	rb = "INVENTORI"; rb1 = ""; rb1j = ""; rb2 = ""; rb2j = ""; rb3 = ""; rb3j = "";
	for (i = 0;i <= 5;i++) {
		for (j = 0;j <=7;j++) {
			FSave[i][j] = 0;
		}
	}
}

void Display::SetJudul(int TT, int BB, int HH, int MM, int Loc, int X, int Y, string musim, string cuaca) {
	string jam;
	string tgl;
	int i;
	char TempC;
	jam = MakeJam(HH,MM);
	tgl = MakeTgl(TT,BB);
	ju.append(jam);
	for (i = 1;i <= 10; i++) {
		ju.push_back(' ');
	}
	ju.append(tgl);
	for (i = 1;i <= 11; i++) {
		ju.push_back(' ');
	}
	if 		(Loc == 1) {
		ju.append("RUMAH");
	}
	else if (Loc == 2) {
		ju.append("SAWAH");
	}
	else if (Loc == 3) {
		ju.append("TOKO");
	}
	else if	(Loc == 4) {
		ju.append("SAWAH");
	}
	ju.push_back('<');
	TempC = X + 48;
	ju.push_back(TempC);
	ju.push_back(',');
	TempC = Y + 48;
	ju.push_back(TempC);
	ju.push_back('>');
	for (i = 1;i <= 10; i++) {
		ju.push_back(' ');
	}
	ju.append(musim);
	for (i = 1;i <= 10; i++) {
		ju.push_back(' ');
	}
	ju.append(cuaca);
}

void Display::SetStrPanel(int P, int N, string S) {
	if 			(P == 1) 		{
		if 			(N == 0) 	{lu = S;}		//NAMA PEMAIN
		else if 	(N == 1) 	{lu1 = S;}		//STATUS
		else if 	(N == 2) 	{lu2 = S;}		//UANG
	}
	else if 	(P == 2) 		{
		if 			(N == 0) 	{lb = S;}
		else if 	(N == 1) 	{lb1 = S;}
		else if 	(N == 2) 	{lb2 = S;}
		else if 	(N == 3) 	{lb3 = S;}
		else if 	(N == 4) 	{lb4 = S;}
		else if 	(N == 5) 	{lb5 = S;}
		else if 	(N == 6) 	{lb6 = S;}
	}
	else if 	(P == 3) 		{
		if 			(N == 0)	{ru = S;}		//KURCACI
		else if		(N == 1) 	{ru1 = S;}		//KURCACI 1
		else if 	(N == 2) 	{ru2 = S;}
		else if 	(N == 3) 	{ru3 = S;}		//KURCACI 2
		else if 	(N == 4) 	{ru4 = S;}
		else if 	(N == 5) 	{ru5 = S;}		//KURCACI 3
		else if 	(N == 6) 	{ru6 = S;}
	}
	else if 	(P == 4) 		{
		if 			(N == 0)	{rb = S;}		//INVENTORI
		else if		(N == 1) 	{rb1 = S;}		//BARANG 1
		else if 	(N == 2) 	{rb1j = S;}
		else if 	(N == 3) 	{rb2 = S;}		//BARANG 2
		else if 	(N == 4) 	{rb2j = S;}
		else if 	(N == 5) 	{rb3 = S;}		//BARANG 3
		else if 	(N == 6) 	{rb3j = S;}
	}
}

void Display::operator<< (int f[6][8]) {
	int i,j;
	for (i = 0;i <= 5; i++) {
		for (j = 0; j <=7; j++) {
			FSave[i][j] = f[i][j];
		}
	}
}

void Display::SetWarna(int fg, int bg) {
#ifdef __WIN32__    
    int Color = fg + (bg * 16);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, Color);
#else
	char command[13];
	int attr = 1;
	if (fg==0 && bg==15) {
		attr = 0;
	} else if (fg==15 && bg==4) {
		fg = 7;
	}
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg+30, bg+40);
	printf("%s", command);
#endif
    return;
	}
	
void Display::ClearScr() {
	#ifdef __WIN32__
		system("cls");
	#else
		system("clear");
	#endif
}

void Display::StdStr(string S, int N) {
	int i,j,k;
	i = (N - S.length()) / 2;
	for (k = 1;k <= i;k++) {
		cout << " ";
	}
	cout << S;
	for (j = 1;j <= i + ((N - S.length()) % 2);j++) {
		cout << " ";
	}
}

string Display::ToSTR(int i) {
	int Puluh;
	int Satu;
	int Leng;
	string TStr;
	char c;
	Puluh = i / 10;
	Satu = i % 10;
	if (Puluh != 0) {
		c = Puluh + 48;
		TStr.push_back(c);
	}
	else {
		c = 48;
		TStr.push_back(c);
	}
	c = Satu + 48;
	TStr.push_back(c);
	return TStr;
}

string Display::MakeJam(int jam, int mnt) {
	string TempS;
	TempS.append(ToSTR(jam));
	TempS.push_back(':');
	TempS.append(ToSTR(mnt));
	return TempS;
}

string Display::MakeTgl(int tgl, int bln) {
	string TempS;
	TempS.append(ToSTR(tgl));
	TempS.push_back('/');
	TempS.append(ToSTR(bln));
	return TempS;
}

void Display::PrintBatas(int A,int N,int P) {
	//0 : atas
	//1 : tengah
	//2 : bawah  
	char l,m,r,p;
	int i,j;
	p = 205;
	if (A == 0) {
		l = 201;
		m = 203;
		r = 187;
	}
	else if (A == 1) {
		l = 204;
		m = 206;
		r = 185;
	}
	else if (A == 2) {
		l = 200;
		m = 202;
		r = 188;
	}
	cout << l;
	for (i = 1; i <= N-1; i++) {
		for (j = 1; j <= P; j++) {
			cout << p;
		}
		cout << m;
	}
	for (j = 1; j <= P; j++) {
		cout << p;
	}
	cout << r;
}

int Display::GetTipeField(int t) {
	int p;
	if 		(t == 0)		{p = 219;}		//tidak bisa bergerak kesini			
	else if (t == 1)		{p = 178;}		//Non-plantable
	else if	(t == 2)		{p = 176;}		//plantable tanpa tanaman
	else if	(t == 3)		{p = 177;}		//sudah disiram
	else if (t == 4)		{p = 241;}		//sudah dicangkul
	else if (t == 5)		{p = 231;}		//bibit
	else if (t == 6)		{p = 222;}		//dewasa
	else if (t == 7)		{p = 226;}		//panen
	else if (t == 8)		{p = 156;}		//mati
	else if (t == 9)		{p = 167;}		//tempat tidur
	else if (t == 10)		{p = 254;}		//tempat save/load
	else					{p = 184;}		//error --> menampilkan huruf c dilingkari
	return p;
}

void Display::PrintIsiField(int brs) {
	int 		i,k;		//PASS
	
	for (i = 0;i <= 5;i++) {
		PrintASCII(186);
		for (k = 1; k <= 5;k++) {
			PrintASCII(GetTipeField(FSave[i][brs]));
		}
	}
	PrintASCII(186);
}

void Display::PrintASCII(int a) {
	char c;
	c = a;
	cout << c;
}

void Display::PrintBar(int A, int B) {
	int i,j;
	i = ((A*12) / B);
	for (j = 1; j <= i;j++) {
		PrintASCII(219);
	}
}

void Display::PrintKsg(int N) {
	int i;
	for (i = 1;i <= N;i++) {
		cout << " ";
	}
}

void Display::PrintJudul() {
	int i;
	char c = 186;
	SetWarna(1,10);
	PrintBatas(0,1,77); cout << endl;
	cout << c << "         _     _____ _____  ____________ _____ _____   ___   _____           " 		<< c << endl; 
	cout << c << "        | |   |  _  /  ___| |  _  \\ ___ \\  _  |  __ \\ / _ \\ /  ___|          "	 	<< c << endl;
	cout << c << "        | |   | | | \\ `--.  | | | | |_/ / | | | |  \\// /_\\ \\\\ `--.           " 		<< c << endl;
	cout << c << "        | |   | | | |`--. \\ | | | |    /| | | | | __ |  _  | `--. \\          " 		<< c << endl;
	cout << c << "        | |___\\ \\_/ /\\__/ / | |/ /| |\\ \\\\ \\_/ / |_\\ \\| | | |/\\__/ /          " 		<< c << endl;
	cout << c << "        \\_____/\\___/\\____/  |___/ \\_| \\_|\\___/ \\____/\\_| |_/\\____/           " 		<< c << endl;
	PrintASCII(204);
	SetWarna(1,11);
	for (i = 1;i <= 34;i++ ) {
		PrintASCII(205);
	}
	cout << "EL JUEGO!";
	for (i = 1;i <= 34;i++ ) {
		PrintASCII(205);
	}
	SetWarna(1,10);
	PrintASCII(185);
	cout << endl;
	PrintASCII(186);
	StdStr(ju,77);
	PrintASCII(186);
	cout << endl;
	PrintBatas(2,1,77);
	cout << endl;
	SetWarna(1,15);
}

void Display::PrintUtama() {
	//BARIS 1
		PrintBatas(0, 1, 20);		
		PrintBatas(0, 6, 5);		
		PrintBatas(0, 1, 18);																						cout << endl;
	
	//BARIS 2
		PrintASCII(186); 			StdStr(lu,20);			PrintASCII(186); 			
		PrintIsiField(7);
		PrintASCII(186);			StdStr(ru,18);			PrintASCII(186);										cout << endl;
	
	//BARIS 3
		PrintBatas(1,1,20);			
		PrintBatas(1,6,5);			
		PrintBatas(1,1,18);																							cout << endl;
	
	//BARIS 4
		PrintASCII(186); 			StdStr(lu1,20);			PrintASCII(186); 			
		PrintIsiField(6);
		PrintASCII(186);			StdStr(ru1,18);			PrintASCII(186);										cout << endl;
	
	//BARIS 5
		PrintASCII(186);			StdStr(lu2,20);			PrintASCII(186);			
		PrintBatas(1,6,5);			
		PrintASCII(186);			StdStr(ru2,18);			PrintASCII(186);										cout << endl;
	
	//BARIS 6
		PrintBatas(2, 1, 20);			
		PrintIsiField(5);
		PrintASCII(186);			StdStr(ru3,18);			PrintASCII(186);										cout << endl;
	
	//BARIS 7
		PrintBatas(0, 1, 20);			
		PrintBatas(1,6,5);			
		PrintASCII(186);			StdStr(ru4,18);			PrintASCII(186);										cout << endl;
	
	//BARIS 8
		PrintASCII(186);			StdStr(lb,20);			PrintASCII(186);			
		PrintIsiField(4);			
		PrintASCII(186);			StdStr(ru5,18);			PrintASCII(186);										cout << endl;

	//BARIS 9
		PrintBatas(1,1,20);	
		PrintBatas(1,6,5);			
		PrintASCII(186);			StdStr(ru6,18);			PrintASCII(186);										cout << endl;
	
	//BARIS 10
		PrintASCII(186);			StdStr(lb1,20);			PrintASCII(186);		
		PrintIsiField(3);			
		PrintBatas(2, 1, 18);																						cout << endl;
	
	//BARIS 11
		PrintASCII(186); 			StdStr(lb2,20);			PrintASCII(186); 			
		PrintBatas(1,6,5);	
		PrintBatas(0, 1, 18);																						cout << endl;

	//BARIS 12
		PrintASCII(186); 			StdStr(lb3,20);			PrintASCII(186); 			
		PrintIsiField(2);
		PrintASCII(186);			StdStr(rb,18);			PrintASCII(186);										cout << endl;
	
	//BARIS 13
		PrintASCII(186);			StdStr(lb4,20);			PrintASCII(186);			
		PrintBatas(1,6,5);			
		PrintBatas(1,1,18);																							cout << endl;
	
	//BARIS 14
		PrintASCII(186); 			StdStr(lb5,20);			PrintASCII(186); 			
		PrintIsiField(1);
		PrintASCII(186);			StdStr(rb1,10);			StdStr(rb1j,8);				PrintASCII(186);			cout << endl;
	
	//BARIS 15
		PrintASCII(186); 			StdStr(lb6,20);			PrintASCII(186); 			
		PrintBatas(1,6,5);
		PrintASCII(186);			StdStr(rb2,10);			StdStr(rb2j,8);				PrintASCII(186);			cout << endl;
	
	//BARIS 16
		PrintASCII(186); 			StdStr(lb7,20);			PrintASCII(186); 			
		PrintIsiField(0);
		PrintASCII(186);			StdStr(rb3,10);			StdStr(rb3j,8);				PrintASCII(186);			cout << endl;
	
	//BARIS 17
		PrintBatas(2,1,20);			
		PrintBatas(2,6,5);			
		PrintBatas(2,1,18);																							cout << endl;
	
	}

	
	
int main() {
	int fil[6][8];
	int i,j;
	//inisialisasi
	for (i = 0;i <= 5;i++) {
		for (j = 0;j <= 7;j++) {
			fil[i][j] = 1;
		}
	}
	Display LCD;
	LCD.SetJudul(3, 5, 4, 10, 2, 2, 4, "PANAS", "TERANG");
	LCD.SetWarna(1,15);
	
	//UBAH NAMA
	LCD.SetStrPanel(1,0,"FIDEL CASTRO");
	
	//UBAH STATUS
	LCD.SetStrPanel(1,1,"NORMAL");
	
	//UBAH UANG
	LCD.SetStrPanel(1,2,"65.000 BUCK");
	
	//UBAH NAMA TANAMAN
	LCD.SetStrPanel(2,0,"CANABIS");
	
	LCD.ClearScr();
	//string jud;
	/*jud = "TT/BB            HH:MM          RUMAH< , >           MUSIM           CUACA";
	a[1]= "COBAA"				;	b[1]= "ABISA";
	a[2]= "AJAA"					;	b[2]= "INIA";
	a[3]= "NIHA"					;	b[3]= "COBAA";
	a[4]= "TESTINGA"				;	b[4]= "TRUAS";
	a[5]= "YUHUA"				;	b[5]= "MAMPUAS";*/
	LCD << fil;
	LCD.PrintJudul();
	LCD.PrintUtama();
	return 0;
}
