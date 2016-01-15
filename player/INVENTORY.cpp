// NIM 			: 13509044
// Nama 		: Bagus Rahman Aryabima
// Nama File 	: INVENTORY.cpp
// Tanggal 		: 5 Maret 2011
// Deskripsi 	: Kelas INVENTORY di Tugas Besar 1

#include "INVENTORY.h"

// Default constructor
Inventory::Inventory() {
	Slot1 = new Tanaman;
	Slot2 = new Tanaman;
	Slot3 = new Tanaman;
	setAmount1(0);
	setAmount2(0);
	setAmount3(0);
	cout << "Inventory kosong berhasil dibuat" << endl;
}

// User-defined constructor
Inventory::Inventory(Tanaman* S1, Tanaman* S2, Tanaman* S3, int A1, int A2, int A3) {
	Slot1 = new Tanaman;
	Slot2 = new Tanaman;
	Slot3 = new Tanaman;
	setSlot1(S1);
	setSlot2(S2);
	setSlot3(S3);
	setAmount1(A1);
	setAmount2(A2);
	setAmount3(A3);
	cout << "Inventory dengan atribut " << S1 << ", " << S2 << ", " << S3 << ", " << A1 << ", " << A2 << ", " << A3 << "berhasil dibuat" << endl;
}

// Copy constructor
/* Inventory::Inventory(const Inventory& I) {
	Slot1 = new Tanaman;
	Slot2 = new Tanaman;
	Slot3 = new Tanaman;
	setSlot1(I.Slot1);
	setSlot2(I.Slot2);
	setSlot3(I.Slot3);
	setAmount1(I.Amount1);
	setAmount2(I.Amount2);
	setAmount3(I.Amount3);
	cout << "Inventory berhasil disalin" << endl;
} */

// Destructor
Inventory::~Inventory() {
	cout << "Inventory berhasil dimusnahkan" << endl;
}

// Fungsi get
Tanaman* Inventory::getSlot1() {
	return Slot1;
}

Tanaman* Inventory::getSlot2() {
	return Slot2;
}

Tanaman* Inventory::getSlot3() {
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

// Fungsi set
void Inventory::setSlot1(Tanaman* newS1) {
	Slot1 = newS1;
}

void Inventory::setSlot2(Tanaman* newS2) {
	Slot2 = newS2;
}

void Inventory::setSlot3(Tanaman* newS3) {
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

int Inventory::IsItemExist(Tanaman* newS) {
	int i;
	i = 0;
	if (((getSlot1()->getID()) == newS->getID()) && ((getSlot1()->getwhatisthis() == newS->getwhatisthis()))) {
		i = 1;
	}
	else if (((getSlot2()->getID()) == newS->getID()) && ((getSlot2()->getwhatisthis() == newS->getwhatisthis()))) {
		i = 1;
	}
	else if (((getSlot3()->getID()) == newS->getID()) && ((getSlot3()->getwhatisthis() == newS->getwhatisthis()))) {
		i = 1;
	}
	return i;
}

// Fungsi-fungsi layanan
string Inventory::Naming (int C1, int C2) {
	string N;
	if (C1 == 0) {
		N = "B-";
	}
	else if (C1 == 1) {
		N = "D-";
	}
	
	if (C2 == 1) {
		N.append("GAN");
	}
	else if (C2 == 2) {
		N.append("OPI");
	}
	else if (C2 == 3) {
		N.append("COC");
	}
	else if (C2 == 4) {
		N.append("TOB");
	}
	else if (C2 == 5) {
		N.append("ANG");
	}
	else if (C2 == 6) {
		N = "MUS";
	}
	return N;
}

void Inventory::Rucksack() {
	cout << "*-*-*-*-* MY INVENTORY *-*-*-*-*" << endl;
	cout << "1. " << Naming(getSlot1()->getwhatisthis(),getSlot1()->getID()) << ": " << getAmount1() << " buah." << endl;
	cout << "2. " << Naming(getSlot2()->getwhatisthis(),getSlot2()->getID()) << ": " << getAmount2() << " buah." << endl;
	cout << "3. " << Naming(getSlot3()->getwhatisthis(),getSlot3()->getID()) << ": " << getAmount3() << " buah." << endl;
}

void Inventory::addItem(Tanaman* newS, int newA) {
	if (IsItemExist(newS) == 1) {
		if ((getSlot1()->getID() == newS->getID()) && (getSlot1()->getwhatisthis() == newS->getwhatisthis())) {
			setAmount1(getAmount1()+newA);
		}
		else if ((getSlot2()->getID() == newS->getID()) && (getSlot2()->getwhatisthis() == newS->getwhatisthis())) {
			setAmount2(getAmount2()+newA);
		}
		else if ((getSlot3()->getID() == newS->getID()) && (getSlot3()->getwhatisthis() == newS->getwhatisthis())) {
			setAmount3(getAmount3()+newA);
		}
	}
	else if (IsItemExist(newS) == 0) {
		if (getSlot1()->getID() == 0) {
			setSlot1(newS);
			setAmount1(newA);
		}
		else if (getSlot2()->getID() == 0) {
			setSlot2(newS);
			setAmount2(newA);
		}
		else if (getSlot3()->getID() == 0) {
			setSlot3(newS);
			setAmount3(newA);
		}
		else if (IsFull()) {}
	}
}

void Inventory::remItem(Tanaman* newS, int newA) {
	if (IsItemExist(newS) == 1) {
		if ((getSlot1()->getID() == newS->getID()) && (getSlot1()->getwhatisthis() == newS->getwhatisthis())) {
			setAmount1(getAmount1() - newA);
			setAmount1(getAmount1() - newA);
		}
		else if ((getSlot2()->getID() == newS->getID()) && (getSlot2()->getwhatisthis() == newS->getwhatisthis())) {
			setAmount2(getAmount2() - newA);
		}
		else if ((getSlot3()->getID() == newS->getID()) && (getSlot3()->getwhatisthis() == newS->getwhatisthis())) {
			setAmount3(getAmount3() - newA);
		}
	}
	else if (IsItemExist(newS) == 0) {
		cout<<"Item tidak ditemukan";
		
	}
}
void Inventory::remItem(int slot, int newA) {
	switch (slot){
								case 1 : {
									(
									setAmount1(getAmount1()-newA));
									if (getAmount1()==0)
										getSlot1()->setID(0);
										break;
								}
								case 2 : {
									(setAmount2(getAmount2()-newA));
									break;
								}
								case 3 : {
									(setAmount3(getAmount3()-newA));
									break;
								}
								
}
}
bool Inventory::SlotIsi(int slot) {
	if (getSlot1()->getID() ==0)
	return false;
	else return true;
}
Tanaman* Inventory::adrSlotIsi(int slot) {
	if (slot==1)
	return getSlot1();
	else if (slot ==2)
	return getSlot2();
	else if (slot == 3)
	return getSlot3();
}
