// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: PLAYER.h
// Tanggal 		: 2 Maret 2011
// Deskripsi 	: Kelas PLAYER di Tugas Besar 1

#ifndef PLAYER_H
#define	PLAYER_H
#include <iostream>
#include <string.h>
#include "CREATURE.h"
#include "INVENTORY.h"
using namespace std;

class Player : public Creature {
private :
    // Data member
	string Name;
	int Location;
    int Status;
	int OD_Meter;
	int Sakaw_Meter;
	int Money;
	Inventory* Brangkas;

public :
    Player();												// Default constructor
	Player(string, int, int, int, int, int, int, int);		// User-defined constructor
	Player(const Player&);									// Copy constructor
	~Player();												// Destructor
	
	// Fungsi get
	string getName();					// Mengembalikan nama PLAYER
	int getLocation();    				// Mengembalikan area dimana PLAYER berada; 1 : rumah, 2 : lahan, 3 : toko
	int getStatus();      				// Mengembalikan status player terkait makanan yang dimakan; misal 1 : lambat, 2 : rabun, dst.
	int getOD();						// Mengembalikan OD_Meter PLAYER
	int getSakaw();						// Mengembalikan sakaw_Meter PLAYER
	int getMoney();						// Mengembalikan jumlah uang
	
	// Fungsi set
	void setName(string);				// Mengeset nama PLAYER
	void setLocation(int);				// Mengeset identifier lokasi baru tempat PLAYER berada
	void setStatus(int);				// Mengeset status baru yang diidap PLAYER
    void setOD(int);					// Mengeset OD_Meter PLAYER
	void setSakaw(int);					// Mengeset sakaw_Meter PLAYER
	void setMoney(int);					// Mengeset jumlah uang
	
	// Fungsi-fungsi terkait uang
	int IsBroke();						// Mengirimkan nilai 1 jika jumlah uang <= 0, 0 jika tidak
	int addMoney(int);					// Menambah jumlah uang
	int decMoney(int);					// Mengurangi jumlah uang
	
	// Fungsi-fungsi pergerakan
	void MoveUp();						// Bergerak ke atas
	void MoveLeft();					// Bergerak ke kiri
	void MoveRight();					// Bergerak ke kanan
	void MoveDown();					// Bergerak ke bawah
	
	// Fungsi-fungsi tambahan
	void Teleport(int);					// Fungsi yang mengubah nilai Location; 1 -> 2, 2-> 3, dst.
    //void CurrField();					// Melihat posisi field yang dihadapi karakter
	
	// Fungsi aktivitas
	void Plow(AllMap* am);
	void Put(AllMap* am, int ID);
	void Harvest(AllMap*);
	
	Inventory* getInventory();
};

#endif	/* PLAYER_H */
