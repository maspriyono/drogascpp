// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: PLAYER.cpp
// Tanggal 		: 10 Maret 2011
// Deskripsi 	: Kelas PLAYER di Tugas Besar 1

#include "PLAYER.h"

// Default constructor
Player::Player() {
	setName("-");
	setPosition(0,0);
	setLocation(1);
	setStatus(0);
	setOD(0);
	setSakaw(0);
	setMoney(0);
	Brangkas = new Inventory;
	cout << "Player dengan atribut minimal berhasil dibuat" << endl;
}

// User-defined constructor
Player::Player(string newName, int newX, int newY, int newLocation, int newStatus, int newOD, int newSakaw, int newMoney) {
	setName(newName);
	setPosition(newX,newY);
	setLocation(newLocation);
	setStatus(newStatus);
	setOD(newOD);
	setSakaw(newSakaw);
	setMoney(newMoney);
	Brangkas = new Inventory;
	cout << "Player dengan masukan tertentu berhasil dibuat" << endl;
}

// Copy constructor
// Player::Player(const Player& P) {
//	setName(P.Name);
//	setPosition(P.X,P.Y);
//	setLocation(P.Location);
//	setStatus(P.Status);
//	setOD(P.OD_Meter);
//	setSakaw(P.Sakaw_Meter);
//	setMoney(P.Money);
// }

// Destructor
Player::~Player() {
	cout << "Player berhasil dimusnahkan" << endl;
}

// Fungsi get
string Player::getName() {
	return Name;
}

int Player::getLocation() {
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

int Player::getMoney() {
	return Money;
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
	if (newOD > 100) {newOD = 100;}
	OD_Meter = newOD;
}

void Player::setSakaw(int newSakaw) {
	if (newSakaw > 100) {newSakaw = 100;}
	Sakaw_Meter = newSakaw;
}

void Player::setMoney(int newMoney) {
	Money = newMoney;
}

// Fungsi-fungsi terkait uang
int Player::IsBroke() {
	if (getMoney() <= 0) {
		return 1;
	} else {
		return 0;
	}
}

int Player::addMoney(int M) {
	return (getMoney() + M);
}

int Player::decMoney(int M) {
	return (getMoney() - M);
}

// Fungsi-fungsi pergerakan
void Player::MoveUp() {
	Position.incY();
}

void Player::MoveLeft() {
	Position.decX();
}

void Player::MoveRight() {
	Position.incX(); 
}

void Player::MoveDown() {
	Position.decY();
}

void Player::Teleport(int newLocation) {
	if (newLocation == 0) {
		setPosition(2,1);
		setDirection(2);
		setLocation(newLocation);
		cout << "Player tiba di rumah" << endl;
	} else if (newLocation == 1) {
		if (Location==0){
		setPosition(0,7);
		setDirection(3);
		setLocation(newLocation);
		cout << "Player tiba di lahan" << endl;
		}
		else if (Location==2){
		setPosition(5,7);
		setDirection(2);
		setLocation(newLocation);
		cout << "Player tiba di lahan" << endl;
		}
	} else if (newLocation == 2) {
		setPosition(3,6);
		setDirection(3);
		setLocation(newLocation);
		cout << "Player tiba di toko" << endl;
	}
}

// void Player::CurrField() {
	// if (getDirection() == 1) {
		// Position.incY();
	// }
	// else if (getDirection() == 2) {
		// Position.decX();
	// }
	// else if (getDirection() == 3) {
		// Position.incX();
	// }
	// else if (getDirection() == 4) {
		// Position.decY();
	// }
// }

Inventory* Player::getInventory(){
	return Brangkas;
}

void Player::Plow(AllMap* am) {
	am->GetLFieldXY(FaceX(),FaceY())->Kerja('c');
}
void Player::Put(AllMap* am, int ID) {
	am->GetLFieldXY(FaceX(),FaceY())->Kerja(ID+48);
}
void Player::Harvest(AllMap* am) {
	am->GetLFieldXY(FaceX(),FaceY())->Kerja('h');
}

