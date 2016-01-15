// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: INVENTORY.h
// Tanggal 		: 4 Maret 2011
// Deskripsi 	: Kelas INVENTORY di Tugas Besar 1

#ifndef INVENTORY_H
#define	INVENTORY_H
#include "../tanaman/tanaman.h"
#include "../tanaman/anggur.h"
#include "../tanaman/coca.h"
#include "../tanaman/ganja.h"
#include "../tanaman/mushroom.h"
#include "../tanaman/opium.h"
#include "../tanaman/tobacco.h"
#include <iostream>
#include <string.h>
using namespace std;

class Inventory {
private :
    // Data member
    Tanaman* Slot1;
	Tanaman* Slot2;
	Tanaman* Slot3;
	int Amount1;
	int Amount2;
	int Amount3;
	
public :
	Inventory();                    							// Default constructor
    Inventory(Tanaman*, Tanaman*, Tanaman*, int, int, int);   	// User-defined constructor
    Inventory(const Inventory&);  								// Copy constructor
    ~Inventory();                   							// Destructor
	
	// Fungsi get
	Tanaman* getSlot1();		// Mengembalikan isi slot1
	Tanaman* getSlot2();		// Mengembalikan isi slot2
	Tanaman* getSlot3();		// Mengembalikan isi slot3
	int getAmount1();			// Mengembalikan isi amount1
	int getAmount2();			// Mengembalikan isi amount2
	int getAmount3();			// Mengembalikan isi amount3
	
	// Fungsi set
	void setSlot1(Tanaman*);		// Update isi slot1
	void setSlot2(Tanaman*);		// Update isi slot2
	void setSlot3(Tanaman*);		// Update isi slot3
	void setAmount1(int);			// Update isi amount1
	void setAmount2(int);			// Update isi amount2
	void setAmount3(int);			// Update isi amount3
	
	// Predikat
	int IsEmpty();					// Mengirimkan nilai 1 jika inventory kosong, 0 jika tidak
	int IsFull();					// Mengirimkan nilai 1 jika inventory penuh, 0 jika tidak
	int IsItemExist(Tanaman*);		// Mengirimkan nilai 1 jika item ada di inventory, 0 jika tidak
	
	// Fungsi-fungsi layanan
    string Naming(int,int);
	void Rucksack();					// Melihat rucksack (inventory PLAYER)
    void addItem(Tanaman*, int);		// Menambah jumlah barang
	void remItem(Tanaman*, int);		// Mengurangi jumlah barang
	void remItem(int, int);		// Mengurangi jumlah barang
	bool SlotIsi(int);					// Mengurangi jumlah barang
	Tanaman* adrSlotIsi(int slot); 
};

#endif	/* INVENTORY_H */
