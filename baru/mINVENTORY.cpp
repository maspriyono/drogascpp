// NIM : 13509044
// Nama : Bagus Rahman Aryabima
// Nama File : mINVENTORY.cpp
// Tanggal : 7 Maret 2011
// Deskripsi : Kelas INVENTORY di Tugas Besar 1

#include "INVENTORY.h"

int main() {
	string newS;
	string newS1;
	string newS2;
	string newS3;
	int newA1;
	int newA2;
	int newA3;
	int newM;

	cout << "***** Constructor, copy constructor, destructor *****" << endl;
	cout << "*** Default constructor ***" << endl;
	Inventory I;
	Inventory I1;
	
	cout << "*** User-defined constructor ***" << endl;
	Inventory I2 ("apel", "jeruk", "anggur", 2, 3, 4, 500);
	
	cout << "***** Fungsi get dan set *****" << endl;
	cout << "*** Fungsi get atribut I2 ***" << endl;
	cout << "Isi slot 1 I2 = " << I2.getSlot1() << endl;
	cout << "Isi slot 2 I2 = " << I2.getSlot2() << endl;
	cout << "Isi slot 3 I2 = " << I2.getSlot3() << endl;
	cout << "Jumlah barang di slot 1 I2 = " << I2.getAmount1() << endl;
	cout << "Jumlah barang di slot 2 I2 = " << I2.getAmount2() << endl;
	cout << "Jumlah barang di slot 3 I2 = " << I2.getAmount3() << endl;
	cout << "Jumlah uang I2 = " << I2.getMoney() << endl;
	
	cout << "*** Fungsi set atribut I1 ***" << endl;
	cout << "Masukkan nama barang di slot 1 I1 = " << endl;
	cin >> newS1;
	I1.setSlot1(newS1);
	cout << "Masukkan nama barang di slot 2 I1 = " << endl;
	cin >> newS2;
	I1.setSlot2(newS2);
	cout << "Masukkan nama barang di slot 3 I1 = " << endl;
	cin >> newS3;
	I1.setSlot3(newS3);
	cout << "Masukkan jumlah barang di slot 1 I1 = " << endl;
	cin >> newA1;
	I1.setAmount1(newA1);
	cout << "Masukkan jumlah barang di slot 2 I1 = " << endl;
	cin >> newA2;
	I1.setAmount2(newA2);
	cout << "Masukkan jumlah barang di slot 3 I1 = " << endl;
	cin >> newA3;
	I1.setAmount3(newA3);
	cout << "Masukkan jumlah uang I1 = " << endl;
	cin >> newM;
	I1.setMoney(newM);
	
	cout << "Isi slot 1 I1 sekarang = " << I1.getSlot1() << endl;
	cout << "Isi slot 2 I1 sekarang = " << I1.getSlot2() << endl;
	cout << "Isi slot 3 I1 sekarang = " << I1.getSlot3() << endl;
	cout << "Jumlah barang di slot 1 I1 sekarang = " << I1.getAmount1() << endl;
	cout << "Jumlah barang di slot 2 I1 sekarang = " << I1.getAmount2() << endl;
	cout << "Jumlah barang di slot 3 I1 sekarang = " << I1.getAmount3() << endl;
	cout << "Jumlah uang I1 sekarang = " << I1.getMoney() << endl;
	
	cout << "***** Predikat *****" << endl;
	cout << "Mengecek apakah Inventory I kosong" << endl;
	if (I.IsEmpty() == 1) {
		cout << "Ternyata, Inventory I kosong" << endl;
	} else {
		cout << "Invnetory I tidak kosong" << endl;
	}
	
	cout << "Mengecek apakah Inventory I1 kosong" << endl;
	if (I1.IsFull() == 1) {
		cout << "Ternyata, Inventory I1 penuh" << endl;
	} else {
		cout << "Inventory I1 tidak penuh" << endl;
	}
	
	cout << "Mengecek apakah Inventory I2 mengandung suatu item" << endl;
	cout << "Masukan nama item yang ingin dicari = " << endl;
	cin >> newS;
	if (I2.IsItemExist(newS) == 1) {
		cout << "Ternyata, item bernama " << newS << " ada di Inventory I2" << endl;
	} else {
		cout << "Item bernama " << newS << " tidak ada di Inventory I2" << endl;
	}
	
	cout << "Mengecek apakah pemain memiliki uang di Inventory I1" << endl;
	if (I1.IsBroke() == 1) {
		cout << "Ternyata, pemain tidak memiliki uang" << endl;
	} else {
		cout << "Pemain masih memiliki sejumlah uang" << endl;
	}
	
	cout << "***** Operator overloading *****" << endl;
	cout << "Menambah uang di Inventory I2 sejumlah 5000 dengan menggunakan operator +" << endl;
	cout << "Jumlah uang di Inventory I2 sekarang = " << I2.getMoney() + 5000 << endl;
	cout << "Mengurangi uang di Inventory I2 sejumlah 250 dengan menggunakan operator -" << endl;
	cout << "Jumlah uang di Inventory I2 sekarang = " << I2.getMoney() - 250 << endl;
}