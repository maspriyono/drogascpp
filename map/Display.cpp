#include "Display.h"

Display::Display() {
	int i,j;
	for (i = 0;i <= 5;i++) {
		for (j = 0;j <= 7;j++) {
			FSave[i][j] = 0;
		}
	}
	for (i = 0;i <= 3;i++) {
		for (j = 0;j <= 2;j++) {
			StKricer[i][j] = -1;
		}
	}
}

void Display::operator<< (int f[8][10]) {
	int i,j;
	for (i = 0;i <= 7; i++) {
		for (j = 0; j <=9; j++) {
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

void Display::Go(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void Display::StdStr(string S, int N) {
	int i,j,k;
	if (S.length() <= N) {
		i = (N - S.length()) / 2;
		for (k = 1;k <= i;k++) {
			cout << " ";
		}
		cout << S;
		for (j = 1;j <= i + ((N - S.length()) % 2);j++) {
			cout << " ";
		}
	}
}

string Display::ToSTR(int i) {
	char TStr[9];
	itoa(i,TStr,10);
	return TStr;
}

string Display::Bar(int A, int B) {
	int i,j;
	string TempS;
	i = ((A*15) / B);
	for (j = 1; j <= 16;j++) {
		if (j <= i) {
			TempS.push_back(219);
		}
		else {
			TempS.push_back(' ');
		}
	}
	if (A != B) {TempS.push_back(' ');};
	TempS.append(ToSTR(i*100/15));		
	TempS.push_back('%');
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

void Display::PrintASCII(int a) {
	char c;
	c = a;
	cout << c;
}

void Display::PrintKsg(int N) {
	int i;
	for (i = 1;i <= N;i++) {
		cout << " ";
	}
}

void Display::PrintTemplate() {
	int i;
	int x,y;
	ClearScr();
	SetWarna(1,10);
	/* BARIS 1 */	PrintBatas(0,1,77);	SetWarna(1,15); cout << endl;
	SetWarna(1,10);
	/* BARIS 2 */	PrintASCII(186); cout << "          _     _____ _____  ____________ _____ _____   ___   _____          "; PrintASCII(186);	SetWarna(1,15); cout << endl;
	SetWarna(1,10);
	/* BARIS 3 */	PrintASCII(186); cout << "         | |   |  _  /  ___| |  _  \\ ___ \\  _  |  __ \\ / _ \\ /  ___|         "; PrintASCII(186);	SetWarna(1,15); cout << endl;
	SetWarna(1,10);
	/* BARIS 4 */	PrintASCII(186); cout << "         | |   | | | \\ `--.  | | | | |_/ / | | | |  \\// /_\\ \\\\ `--.          "; PrintASCII(186); SetWarna(1,15); cout << endl;	
	SetWarna(1,10);
	/* BARIS 5 */	PrintASCII(186); cout << "         | |   | | | |`--. \\ | | | |    /| | | | | __ |  _  | `--. \\         " ; PrintASCII(186); SetWarna(1,15); cout << endl;
	SetWarna(1,10);
	/* BARIS 6 */	PrintASCII(186); cout << "         | |___\\ \\_/ /\\__/ / | |/ /| |\\ \\\\ \\_/ / |_\\ \\| | | |/\\__/ /         "; PrintASCII(186); SetWarna(1,15); cout << endl;
	SetWarna(1,10);
	/* BARIS 7 */	PrintASCII(186); cout << "         \\_____/\\___/\\____/  |___/ \\_| \\_|\\___/ \\____/\\_| |_/\\____/          "; PrintASCII(186); SetWarna(1,15);cout << endl;
	SetWarna(1,10);
	/* BARIS 8 */	PrintASCII(204);	
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
					SetWarna(1,15);
					cout << endl;
	SetWarna(1,10);
	/* BARIS 9 */	PrintASCII(186); PrintKsg(77); PrintASCII(186); SetWarna(1,15); cout << endl;
	SetWarna(1,10);
	/* BARIS 10 */	PrintBatas(2,1,77); SetWarna(1,15); cout << endl;
	SetWarna(1,15);
	/* BARIS 11 */	PrintBatas(0,1,20); PrintBatas(0,6,5); PrintBatas(0,1,18); cout << endl;
	/* BARIS 12 */	PrintASCII(186);PrintKsg(20);PrintASCII(186); 
					for (x = 1; x<=6;x++) {
						PrintASCII(186);PrintKsg(5);
					}
					PrintASCII(186);PrintASCII(186);StdStr("KURCACI",18);PrintASCII(186); cout << endl;
	/* BARIS 13 */	PrintBatas(1,1,20);PrintBatas(1,6,5);PrintBatas(1,1,18); cout << endl;
	/* BARIS 14 */	PrintASCII(186);PrintKsg(20);PrintASCII(186);
					for (x = 1; x<=6;x++) {
						PrintASCII(186);PrintKsg(5);
					}
					PrintASCII(186);PrintASCII(186);SetWarna(10,15);StdStr("[WATER]",18);SetWarna(1,15);PrintASCII(186); cout << endl;
	/* BARIS 15 */	PrintASCII(186);PrintKsg(20);PrintASCII(186);
					PrintBatas(1,6,5);PrintASCII(186);PrintKsg(18);PrintASCII(186); cout << endl;
	/* BARIS 16 */	PrintBatas(2,1,20);
					for (x = 1; x<=6;x++) {
						PrintASCII(186);PrintKsg(5);
					}
					PrintASCII(186);PrintASCII(186);SetWarna(13,15);StdStr("[HARVEST]",18);	SetWarna(1,15);PrintASCII(186); cout << endl;
	/* BARIS 17 */	PrintBatas(0,1,20);
					PrintBatas(1,6,5);PrintASCII(186);PrintKsg(18);PrintASCII(186); cout << endl;
	/* BARIS 18 */	PrintASCII(186);PrintKsg(20);PrintASCII(186);
					for (x = 1; x<=6;x++) {
						PrintASCII(186);PrintKsg(5);
					}
					PrintASCII(186);PrintASCII(186);SetWarna(11,15);StdStr("[SLASH]",18);SetWarna(1,15);PrintASCII(186); cout << endl;
	/* BARIS 19 */	PrintBatas(1,1,20);
					PrintBatas(1,6,5);PrintASCII(186);PrintKsg(18);PrintASCII(186); cout << endl;
	/* BARIS 20 */	PrintASCII(186);PrintKsg(20);PrintASCII(186);
					for (x = 1; x<=6;x++) {
						PrintASCII(186);PrintKsg(5);
					}
					PrintASCII(186);PrintBatas(2,1,18); cout << endl;
	/* BARIS 21 */	PrintASCII(186);PrintKsg(20);PrintASCII(186);
					PrintBatas(1,6,5);PrintBatas(0,1,18); cout << endl;
	/* BARIS 22 */	PrintASCII(186);PrintKsg(20);PrintASCII(186);
					for (x = 1; x<=6;x++) {
						PrintASCII(186);PrintKsg(5);
					}
					PrintASCII(186);PrintASCII(186);StdStr("BRANGKAS",18);PrintASCII(186); cout << endl;
	/* BARIS 23 */	PrintASCII(186);PrintKsg(20);PrintASCII(186);
					PrintBatas(1,6,5);PrintBatas(1,1,18); cout << endl;
	/* BARIS 24 */	PrintASCII(186);PrintKsg(20);PrintASCII(186);
					for (x = 1; x<=6;x++) {
						PrintASCII(186);PrintKsg(5);
					}
					PrintASCII(186);PrintASCII(186);PrintKsg(18);PrintASCII(186); cout << endl;
	/* BARIS 25 */	PrintASCII(186);PrintKsg(20);PrintASCII(186);
					PrintBatas(1,6,5);PrintASCII(186);PrintKsg(18);PrintASCII(186); cout << endl;
	/* BARIS 26 */	PrintASCII(186);PrintKsg(20);PrintASCII(186);
					for (x = 1; x<=6;x++) {
						PrintASCII(186);PrintKsg(5);
					}
					PrintASCII(186);PrintASCII(186);PrintKsg(18);PrintASCII(186); cout << endl;
	/* BARIS 27 */	PrintBatas(2,1,20);
					PrintBatas(2,6,5);
					PrintBatas(2,1,18); cout << endl;
	/* BARIS 29 */	PrintBatas(0,1,77); cout << endl;
	/* BARIS 30 */	PrintASCII(186);PrintKsg(77);PrintASCII(186); cout << endl;
	/* BARIS 31 */	PrintBatas(2,1,77); cout << endl;
	/* BARIS 32 */	PrintBatas(0,1,77); cout << endl;
	/* BARIS 33 */	PrintASCII(186);PrintKsg(77);PrintASCII(186); cout << endl;
	/* BARIS 34 */	PrintBatas(2,1,77);	cout << endl;	
	/* BARIS 28 */	cout << " ";SetWarna(1,11);PrintKsg(76);SetWarna(1,15);cout << endl;
	/* INFO BAR */	PrintBatas(0,1,77);
					for (i = 1; i<=11;i++) {
					cout << endl;
					PrintASCII(186);PrintKsg(77); PrintASCII(186);
					}
					cout << endl;
					PrintBatas(2,1,77);
	//CURSOR PINDAH
}
	
void	Display::PrintJam(int j, int m) {
	Go(3,8);SetWarna(1,10);
	if ((j/10) == 0) 	{cout << "0" << j;}
	else				{cout << j;}
	cout << ":";
	if ((m/10) == 0)	{cout << "0" << m;}
	else				{cout << m;}
	Go(2,33);SetWarna(1,11);
}

void	Display::PrintTgl(int d, int m) {
	Go(18,8);SetWarna(1,10);
	if ((d/10) == 0) 	{cout << "0" << d;}
	else				{cout << d;}
	cout << "/";
	if ((m/10) == 0)	{cout << "0" << m;}
	else				{cout << m;}
	Go(2,33);SetWarna(1,11);
}

void	Display::PrintLoc(int l) {
	Go(33,8);SetWarna(1,10);
	cout << "     ";
	Go(33,8);
	if (l == 0) {cout << "RUMAH";}
	else if (l == 1) {cout << "SAWAH";}
	else if (l == 2) {cout << " TOKO";}
	Go(2,33);SetWarna(1,11);
}

void 	Display::PrintKor(int x, int y) {
	Go(39,8);SetWarna(1,10);
	cout << "     ";
	Go(39,8);
	cout << "<" << x << "," << y << ">";
	Go(2,33);SetWarna(1,11);
}

void	Display::PrintCua(int x) {
//1 cropcircle 2 hujan 3 razia 4 topan
	Go(52,8);SetWarna(1,10);
	cout << "          ";
	Go(52,8);
	if (x == 1) {cout << "CROPCIRCLE";}
	else if (x == 2) {cout << "     HUJAN";}
	else if (x == 3) {cout << "     RAZIA";}
	else if (x == 4) {cout << "     TOPAN";}
	Go(2,33);SetWarna(1,11);
}

void	Display::PrintMus(int x) {
//1 semi 2 badai 3 gugur 4 hujan
	Go(65,8);SetWarna(1,10);
	cout << "          ";
	Go(65,8);
	if (x == 1) {cout << "      SEMI";}
	else if (x == 2) {cout << "     BADAI";}
	else if (x == 3) {cout << "     GUGUR";}
	else if (x == 4) {cout << "     HUJAN";}
	Go(2,33);SetWarna(1,11);
}

void	Display::PrintName(string nama) {
	Go(3,11);SetWarna(1,15);
	PrintKsg(17);
	Go(3,11);
	StdStr(nama,17);
	Go(2,33);SetWarna(1,11);
}

void	Display::PrintSt(int s) {
	Go(3,13);SetWarna(1,15);
	PrintKsg(17);
	Go(3,13);
	StdStr("BLOM OI",17);
	Go(2,33);SetWarna(1,11);
}

void	Display::PrintBuck(int b) {
	Go(3,14);SetWarna(1,15);
	PrintKsg(17);
	Go(3,14);
	StdStr((ToSTR(b)).append(" BUCKS"),17);
	Go(2,33);SetWarna(1,11);
}

int Display::GetTipeField(int t) {
	int p;
	if 		(t == 0)					{p = 219;}		//tidak bisa bergerak kesini			
	else if (t == 1)					{p = 178;}		//Non-plantable
	else if	((t == 2) || (t == 10))		{p = 176;}		//plantable tanpa tanaman
	else if ((t == 3) || (t == 11))		{p = 241;}		//sudah dicangkul
	else if ((t == 4) || (t == 12))		{p = 231;}		//bibit
	else if ((t == 5) || (t == 13))		{p = 222;}		//dewasa 			--> tidak bisa bergerak kesini
	else if ((t == 6) || (t == 14))		{p = 226;}		//panen  			--> tidak bisa bergerak kesini
	else if ((t == 7) || (t == 15))		{p = 156;}		//mati   			--> tidak bisa bergerak kesini
	else if (t == 8)					{p = 167;}		//tempat tidur		--> tidak bisa bergerak kesini
	else if (t == 9)					{p = 254;}		//tempat save/load
	else								{p = 184;}		//error 			--> menampilkan huruf c dilingkari
	return p;
}

void	Display::PrintFlXY(int x, int y) {
	int i;
	char c;
	Go(23+(6*x),25-(2*y));SetWarna(1,15);
	PrintKsg(5);
	Go(23+(6*x),25-(2*y));
	c = GetTipeField(FSave[x+1][y+1]);
	for (i=1;i<=5;i++) {
	if ((FSave[x+1][y+1] > 9) && (FSave[x+1][y+1] < 16)) {SetWarna(10,15);}
	cout << c;
	}
	Go(2,33);SetWarna(1,11);
}

void	Display::PrintAllFl() {
	int i,j;
	for (i = 0;i <= 5;i++) {
		for (j=0; j <= 7;j++) {
			PrintFlXY(i,j);
		}
	}
}

void	Display::PrintKur(int k1, int k2, int k3) {
	Go(60,14); SetWarna(1,15);
	if (k1 == 0) {StdStr("SLEEP",18);}
	else if (k1 == 1) {StdStr("AWAKE",18);}
	Go(60,16);
	if (k2 == 0) {StdStr("SLEEP",18);}
	else if (k2 == 1) {StdStr("AWAKE",18);}
	Go(60,18);
	if (k3 == 0) {StdStr("SLEEP",18);}
	else if (k3 == 1) {StdStr("AWAKE",18);}
	SetWarna(1,11);
	Go(2,33);
}

void	Display::PrintODSKW() {
	int c,i,j,k;
	Go(2,28);
		if	(ODMeter > 89) {
		c = 12;
		}
		else if (ODMeter > 49) {
			c = 10;
		}
		else {
			c = 11;
		}
		SetWarna(1,c);
		i=(ODMeter*72/100);
		if (i > 72) {i = 72;};
		for	(j=1;j<=i;j++) {
				if ((j%9 == 0) || (j == 1)) {
					SetWarna(15,c);
				if ((j == 1) || (j/9 == 5)) {
					cout << "O";
				}
				else if (j/9 == 1) {
					cout << "V";
				}
				else if (j/9 == 2) {
					cout << "E";
				}
				else if (j/9 == 3) {
					cout << "R";
				}
				else if (j/9 == 4) {
					cout << "D";
				}
				else if ((j/9 == 6) || (j/9 == 8)) {
					cout << "S";
				}
				else if (j/9 == 7) {
					cout << "I";
				}
				SetWarna(1,c);
			}
			else {
				cout << " ";
			}
		}
		SetWarna(1,15);
		for (k=i;k < 72;k++) {
			cout << " ";
		}
		if (ODMeter < 100) {
			cout << " ";
		}
		cout << ODMeter << "%";
	Go(2,31);
		if	(SkwMeter > 89) {
			c = 12;
		}
		else if (SkwMeter > 49) {
			c = 10;
		}
		else {
			c = 11;
		}
		SetWarna(1,c);
		i=(SkwMeter*72/100);
		for	(j=1;j<=i;j++) {
			if ((j+5)%14 == 0) {
				SetWarna(15,c);
				if ((j+5)/14 == 1) {
					cout << "S";
				}
				else if (((j+5)/14 == 2) || ((j+5)/14==4)) {
					cout << "A";
				}
				else if ((j+5)/14 == 3) {
					cout << "K";
				}
				else if ((j+5)/14 == 5) {
					cout << "W";
				}
				SetWarna(1,c);
			}
			else {
				cout << " ";
			}
		}
		SetWarna(1,15);
		for (k=i;k < 72;k++) {
			cout << " ";
		}
		if (SkwMeter != 100) {
			cout << " ";
		}
		cout <<SkwMeter << "%";
		cout << endl;
		PrintBatas(2,1,77);
		cout << endl;
	SetWarna(1,11);
	Go(2,33);
}

void	Display::ChangeCharPos(int c, int x1, int y1, int dir, int x2, int y2) {
	char TempC;
	Go(25+(6*StKricer[c][1]),25-(2*StKricer[c][2]));SetWarna(1,15);
	//IS SIRAM TARO SINI!
	PrintASCII(GetTipeField(FSave[x1+1][y1+1]));
	//SELESAI IS SIRAM DISINI
	StKricer[c][0] = dir;
	StKricer[c][1] = x2;
	StKricer[c][2] = y2;
	PrintCharPos(c);
}

void	Display::PrintCharPos(int c) {
	Go(25+(6*StKricer[c][1]),25-(2*StKricer[c][2]));
	if (c == 0) {SetWarna(12,15);}
	else if (c == 1) {SetWarna(10,15);}
	else if (c == 2) {SetWarna(13,15);}
	else if (c == 3) {SetWarna(11,15);}
	
	if (StKricer[c][0] == 1) {PrintASCII(30);}
	else if (StKricer[c][0] == 2) {PrintASCII(17);}
	else if (StKricer[c][0] == 3) {PrintASCII(16);}
	else if (StKricer[c][0] == 4) {PrintASCII(31);}
	SetWarna(1,15);
	Go(2,33);SetWarna(1,11);
}

void	Display::PrintAllChar(int m, int k1, int k2, int k3) {
	int i;
	PrintCharPos(0);
	if (m == 1) {
		if  	(k1 == 1)		PrintCharPos(1);
		if		(k2 == 1)		PrintCharPos(2);
		if 		(k3 == 1)		PrintCharPos(3);
	}
}

void 	Display::PrintInfoBox(int i, string s) {
	Go(3,(34+i));SetWarna(1,15);
		cout << s;
	Go(3,33);SetWarna(1,11);
}

void	Display::ClearInfoBox() {
	int i;
	for (i=1;i<=11;i++) {
	Go(3,(34+i));SetWarna(1,15);
		StdStr(" ",75);
	Go(3,33);SetWarna(1,11);
	}
}

void	Display::PrintInfo(string s) {
	Go(2,33);
	SetWarna(1,11);
	PrintKsg(75);
	Go(2,33);
	cout << s;
	Sleep(2000);
	Go(2,33);
	PrintKsg(75);
	Go(2,33);
}

void	Display::PrintInfoL(LField* L) {
	Go(2,17);
	SetWarna(1,15);
	if (L->GetMoveAble()) {
		if (((L->GetPlant())->getID()) == 0) {
			StdStr("NO PLANT HERE",19);
		}
		else if (((L->GetPlant())->getID()) == 1) {
			StdStr("GANJA",19);
		}
		else if (((L->GetPlant())->getID()) == 2) {
			StdStr("OPIUM",19);
		}
		else if (((L->GetPlant())->getID()) == 3) {
			StdStr("COCA",19);
		}
		else if (((L->GetPlant())->getID()) == 4) {
			StdStr("TOBACCO",19);
		}
		else if (((L->GetPlant())->getID()) == 5) {
			StdStr("ANGGUR",19);
		}
		else if (((L->GetPlant())->getID()) == 6) {
			StdStr("MUSHROOM",19);
		}
	}
	Go(2,33);
	SetWarna(1,11);
}
