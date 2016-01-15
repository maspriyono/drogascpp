// NIM : 13509044
// Nama : Bagus Rahman Aryabima
// Nama File : mPOINT.cpp
// Tanggal : 5 Maret 2011
// Deskripsi : Kelas POINT di Tugas Besar 1

#include "POINT.h"

// void F (Point _)
int main() {
	int newX;
	int newY;
	
	cout << "*** Constructor, copy constructor, destructor ***" << endl;
	cout << "Default constructor" << endl;
	Point P1;
	
	cout << "User-defined constructor" << endl;
	cout << "Masukkan nilai absis dari Point : " << endl;
	cin >> newX;
	cout << "Masukkan nilai ordinat dari Point : " << endl;
	cin >> newY;
	Point P2(newX, newY);
	
	cout << "Copy constructor" << endl;
	// Point P3 = P2;
	// F(P3);
	
	cout << "*** Fungsi get dan set ***" << endl;
	cout << "Mengambil nilai X dan Y dari P2" << endl;
	P2.getX();
	P2.getY();
	
	cout << "Memasukkan nilai (3,4) ke Point P1" << endl;
	P1.setX(3);
	P1.setY(4);
	cout << "Nilai absis P1 sekarang = " << P1.getX() << endl;
	cout << "Nilai ordinat P1 sekarang = " << P1.getY() << endl;

	cout << "Operator overloading" << endl;
	++P2;
	cout << "Nilai absis P2 sekarang = " << P2.getY() << endl;
	--P2;
	cout << "Nilai absis P2 sekarang = " << P2.getY() << endl;
	//P2>>;
	//P2.getX();
	//P2<<;
	//P2.getX();

	return 0;
}