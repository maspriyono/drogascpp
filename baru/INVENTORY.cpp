// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: INVENTORY.cpp
// Tanggal 		: 5 Maret 2011
// Deskripsi 	: Kelas INVENTORY di Tugas Besar 1

#include "INVENTORY.h"

// Default constructor
Inventory::Inventory() {
	setSlot1("-");
	setSlot2("-");
	setSlot3("-");
	setAmount1(0);
	setAmount2(0);
	setAmount3(0);
	setMoney(0);
	cout << "Inventory kosong berhasil dibuat" << endl;
}

// User-defined constructor
Inventory::Inventory(string S1, string S2, string S3, int A1, int A2, int A3, int M) {
	setSlot1(S1);
	setSlot2(S2);
	setSlot3(S3);
	setAmount1(A1);
	setAmount2(A2);
	setAmount3(A3);
	setMoney(M);
	cout << "Inventory dengan atribut " << S1 << ", " << S2 << ", " << S3 << ", " << A1 << ", " << A2 << ", " << A3 << ", " << M << ", " << "berhasil dibuat" << endl;
}

// Copy constructor
Inventory::Inventory(const Inventory& I) {
	setSlot1(I.Slot1);
	setSlot2(I.Slot2);
	setSlot3(I.Slot3);
	setAmount1(I.Amount1);
	setAmount2(I.Amount2);
	setAmount3(I.Amount3);
	setMoney(I.Money);
	cout << "Inventory berhasil disalin" << endl;
}

// Destructor
Inventory::~Inventory() {
	cout << "Inventory berhasil dimusnahkan" << endl;
}

// Fungsi get
string Inventory::getSlot1() {
	return Slot1;
}

string Inventory::getSlot2() {
	return Slot2;
}

string Inventory::getSlot3() {
	return Slot3;
}

int Inventory::getAmount1() {
	return Amount1;
}

int Inventory::getAmount2() {
	return Amount2;
}

int Inventory::getAmount3() {
	return Amount3;
}

int Inventory::getMoney() {
	return Money;
}

// Fungsi set
void Inventory::setSlot1(string newS1) {
	Slot1 = newS1;
}

void Inventory::setSlot2(string newS2) {
	Slot2 = newS2;
}

void Inventory::setSlot3(string newS3) {
	Slot3 = newS3;
}

void Inventory::setAmount1(int newA1) {
	Amount1 = newA1;
}

void Inventory::setAmount2(int newA2) {
	Amount2 = newA2;
}

void Inventory::setAmount3(int newA3) {
	Amount3 = newA3;
}

void Inventory::setMoney(int newM) {
	Money = newM;
}

// Predikat
int Inventory::IsEmpty() {
	if ((getAmount1() == 0) && (getAmount2() == 0) && (getAmount3() == 0)) {
		return 1;
	} else {
		return 0;
	}
}

int Inventory::IsFull() {
	if ((getAmount1() > 0) && (getAmount2() > 0) && (getAmount3() > 0)) {
		return 1;
	} else {
		return 0;
	}
}

int Inventory::IsItemExist(string newS) {
	if ((getSlot1() == newS) || (getSlot2() == newS) || (getSlot3() == newS)) {
		return 1;
	} else {
		return 0;
	}
}

int Inventory::IsBroke() {
	if (getMoney() <= 0) {
		return 1;
	} else {
		return 0;
	}
}

// Fungsi-fungsi layanan
Inventory Inventory::Rucksack(Inventory I) {
	cout << "*-*-*-*-* MY INVENTORY *-*-*-*-*" << endl;
	cout << "1. " << I.getSlot1() << ": " << I.getAmount1() << "buah." << endl;
	cout << "2. " << I.getSlot2() << ": " << I.getAmount2() << "buah." << endl;
	cout << "3. " << I.getSlot3() << ": " << I.getAmount3() << "buah." << endl;
	cout << "Jumlah uang : " << I.getMoney() << endl;
}

void Inventory::addItem(Tanaman* newS, int newA) {
	if (getSlot1() == "-") {
		setSlot1(newS);
		setAmount1(newA);
	}
	if (getSlot1() == newS) {
		setAmount1(getAmount1() + newA);
	}
	if (getSlot1() != newS) {
		if (getSlot2() == "-") {
			setSlot2(newS);
			setAmount2(newA);
		}
		if (getSlot2() == newS) {
			setAmount2(getAmount2() + newA);
		}
		if (getSlot2() != newS) {
			if (getSlot3() == "-") {
				setSlot3(newS);
				setAmount3(newA);
			}
			if (getSlot3() == newS) {
				setAmount3(getAmount3() + newA);
			}
			if (getSlot3() != newS) {
				cout << "Maaf, inventory sudah penuh, tidak bisa menambah item" << endl;
			}
		}
	}
}

void Inventory::redItem(Inventory I, string newS, int newA) {
	if (I.getSlot1() == newS) {
		I.setAmount1(I.getAmount1() - newA);
		if (I.getAmount1() <= 0) {
			I.setSlot1("-");
		}
	}
	if ((I.getSlot1() != newS) || (I.getSlot1() == "-")) {
		if (I.getSlot2() == newS) {
			I.setAmount2(I.getAmount2() - newA);
			if (I.getAmount2() <= 0) {
				I.setSlot2("-");
			}
		}
		if ((I.getSlot2() != newS) || (I.getSlot2() == "-")) {
			if (I.getSlot3() == newS) {
				I.setAmount3(I.getAmount3() - newA);
				if (I.getAmount3() <= 0) {
					I.setSlot3("-");
				}
			}
			if ((I.getSlot3() != newS) || (I.getSlot3() == "-")) {
				cout << "Maaf, barang yang ingin dikeluarkan tidak ada di inventory" << endl;
			}
		}
	}
}

void Inventory::operator+(int D) {
	Money + D;
}

void Inventory::operator-(int D) {
	Money - D;
}
