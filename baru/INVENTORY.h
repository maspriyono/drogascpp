// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: INVENTORY.h
// Tanggal 		: 4 Maret 2011
// Deskripsi 	: Kelas INVENTORY di Tugas Besar 1

#ifndef INVENTORY_H
#define	INVENTORY_H
#include <iostream>
#include <string.h>
using namespace std;

class Inventory {
private :
    // Data member
    string Slot1;
	string Slot2;
	string Slot3;
	int Amount1;
	int Amount2;
	int Amount3;
	int Money;

public :
	Inventory();                    							// Default constructor
    Inventory(string, string, string, int, int, int, int);   	// User-defined constructor
    Inventory(const Inventory&);  								// Copy constructor
    ~Inventory();                   							// Destructor
	
	// Fungsi get
	string getSlot1();			// Mengembalikan isi slot1
	string getSlot2();			// Mengembalikan isi slot2
	string getSlot3();			// Mengembalikan isi slot3
	int getAmount1();			// Mengembalikan isi amount1
	int getAmount2();			// Mengembalikan isi amount2
	int getAmount3();			// Mengembalikan isi amount3
	int getMoney();				// Mengembalikan jumlah uang

	// Fungsi set
	void setSlot1(string);		// Update isi slot1
	void setSlot2(string);		// Update isi slot2
	void setSlot3(string);		// Update isi slot3
	void setAmount1(int);		// Update isi amount1
	void setAmount2(int);		// Update isi amount2
	void setAmount3(int);		// Update isi amount3
	void setMoney(int);			// Update jumlah uang
	
	// Predikat
	int IsEmpty();					// Mengirimkan nilai 1 jika inventory kosong, 0 jika tidak
	int IsFull();					// Mengirimkan nilai 1 jika inventory penuh, 0 jika tidak
	int IsItemExist(string);		// Mengirimkan nilai 1 jika item ada di inventory, 0 jika tidak
	int IsBroke();					// Mengirimkan nilai 1 jika jumlah uang <= 0, 0 jika tidak
	
	// Fungsi-fungsi layanan
    Inventory Rucksack(Inventory I);						// Melihat rucksack (inventory PLAYER)
    Inventory Store();       								// Melihat inventory toko
    void addItem(Inventory I, string newS, int newA);		// Menambah jumlah barang
	void redItem(Inventory I, string newS, int newA);		// Mengurangi jumlah barang
	void operator+(int);									// Menambah jumlah uang
	void operator-(int);									// Mengurangi jumlah uang
};

#endif	/* INVENTORY_H */