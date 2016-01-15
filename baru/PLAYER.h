// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: PLAYER.h
// Tanggal 		: 2 Maret 2011
// Deskripsi 	: Kelas PLAYER di Tugas Besar 1

#ifndef PLAYER_H
#define	PLAYER_H
#include "CREATURE.h"
#include "POINT.h"
#include <iostream>
using namespace std;

class Player:public Creature {
private :
    // Data member
	string Name;
	int Location;
    int Status;
	int OD_Meter;
	int Sakaw_Meter;

public :
    Player();							// Default constructor
	Player(string, int, int, int, int);		// User-defined constructor
	Player(const Player&);					// Copy constructor
	~Player();								// Destructor
	void setpoint(int x, int y);
	void setpointx(int x);
	void setpointy(int y);
	Point getpoint(int a, int b);
	int getpointx();
	int getpointy();
	
	// Fungsi get dan set name
	string getName();						// Mengembalikan nama PLAYER
	void setName(string);					// Mengeset nama PLAYER
	// Fungsi get dan set position
	int getPosition();						// Mengembalikan titik dimana PLAYER berada
	void setPosition(int,int);				// Mengeset titik baru dimana PLAYER berada
	// Fungsi get dan set direction
	int getDirection();   					// Mengembalikan arah PLAYER menghadap; 1 : atas, 2 : kiri, 3 : kanan, 4 : bawah
	void setDirection(int);					// Mengeset arah baru yang PLAYER hadapi
	// Fungsi get dan set location
    int getLocation();    					// Mengembalikan area dimana PLAYER berada; 1 : rumah, 2 : lahan, 3 : toko
	void setLocation(int);					// Mengeset identifier lokasi baru tempat PLAYER berada
	// Fungsi get dan set status
    int getStatus();      					// Mengembalikan status player terkait makanan yang dimakan; misal 1 : lambat, 2 : rabun, dst.
	void setStatus(int);					// Mengeset status baru yang diidap PLAYER
    // Fungsi get dan set OD_Meter
	int getOD();							// Mengembalikan OD_Meter PLAYER
	void setOD(int);						// Mengeset OD_Meter PLAYER
	// Fungsi get dan set sakaw_Meter
	int getSakaw();							// Mengembalikan sakaw_Meter PLAYER
	void setSakaw(int);						// Mengeset sakaw_Meter PLAYER
	
	// Fungsi-fungsi tambahan
	void Teleport(int);			// Fungsi yang mengubah nilai Location; 1 -> 2, 2-> 3, dst.
    void Move();					// Membaca masukan dari keyboard (arah) atau perintah langsung
    Point CurrField();			// Melihat posisi field yang dihadapi karakter
	void SetPlayerOff();			// Mengubah posisi karakter menjadi tidak terdefinisi
};
#endif	/* PLAYER_H */

// Player::Player() : Creature(){
	// // setName("-");
	 // setLocation(1);
	// // setStatus(0);
	// // setOD(0);
	// // setsakaw(0);	
	// // cout << "Player dengan atribut minimal berhasil dibuat" << endl;
// }
// void Player::setpoint(int x, int y){
		// Position.setX(x);
		// Position.setY(y);
	// }
	// void Player::setpointx(int x){
		// Position.setX(x);
	// }
	// void Player::setpointy(int y){
		// Position.setY(y);
	// }
	// // Point Player::getpoint(int a, int b){
		// // return Position.MakePoint(a, b);
	// // }
	// int Player::getpointx(){
		// return Position.getX();
	// }
	// int Player::getpointy(){
		// return Position.getY();
	// }
	// int Player::getDirection(){
		// return Direction;
	// }
	// void Player::setDirection(int a){
		// Direction = a;
	// }
	// void Player::setLocation(int x){
		// Location = x;

// }
	// int Player::getLocation(){
		// return Location;

// }
