// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: PLAYER.cpp
// Tanggal 		: 10 Maret 2011
// Deskripsi 	: Kelas PLAYER di Tugas Besar 1

#include "PLAYER.h"

// Default constructor
Player::Player() {
	setName("-");
	setLocation(1);
	setStatus(0);
	setOD(0);
	setSakaw(0);
	cout << "Player dengan atribut minimal berhasil dibuat" << endl;
}
// User-defined constructor
Player::Player(string newName, int newLocation, int newStatus, int newOD, int newSakaw) {
	setName(newName);
	setLocation(newLocation);
	setStatus(newStatus);
	setOD(newOD);
	setSakaw(newSakaw);
	cout << "Player dengan masukan tertentu berhasil dibuat" << endl;
}

// Copy constructor
Player::Player(const Player& P) {
	setName(P.Name);
	setLocation(P.Location);
	setStatus(P.Status);
	setOD(P.OD_Meter);
	setSakaw(P.Sakaw_Meter);
}

// Destructor
Player::~Player() {
	cout << "Player berhasil dimusnahkan" << endl;
}
void Player::setpoint(int x, int y){
		Position.setX(x);
		Position.setY(y);
	}
	void Player::setpointx(int x){
		Position.setX(x);
	}
	void Player::setpointy(int y){
		Position.setY(y);
	}
	// Point Player::getpoint(int a, int b){
		// return Position.MakePoint(a, b);
	// }
	// Fungsi get
	string Player::getName() {
		return Name;
	}
	int Player::getpointx(){
		return Position.getX();
	}
	int Player::getpointy(){
		return Position.getY();
	}
	int Player::getDirection(){
		return Direction;
	}
	int Player::getLocation(){
		return Location;
	}
	int Player::getStatus() {
		return Status;
	}
	int Player::getOD() {
		return OD_Meter;
	}

	int Player::getSakaw() {
		return Sakaw_Meter;
	}
	
	// Fungsi set
	void Player::setName(string newName) {
		Name = newName;
	}

	void Player::setLocation(int newLocation) {
		Location = newLocation;
	}

	void Player::setStatus(int newStatus) {
		Status = newStatus;
	}

	void Player::setOD(int newOD) {
		OD_Meter = newOD;
	}
	void Player::setDirection(int a){
		Direction = a;
	}
	void Player::setSakaw(int newSakaw) {
		Sakaw_Meter = newSakaw;
	}

	// Fungsi-fungsi tambahan
	void Player::Teleport(int newLocation) {
		setLocation(newLocation);
		if (newLocation == 1) {
			cout << "Player tiba di rumah" << endl;
		} else if (newLocation == 2) {
			cout << "Player tiba di lahan" << endl;
		} else if (newLocation == 3) {
			cout << "Player tiba di toko" << endl;
		}
	}

