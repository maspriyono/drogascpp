// Penanggung jawab : Dimas Gilang Saputra / 13509038

#include "anggur.h"

int main() {
	// Kamus
	Anggur a;
	// Algoritma
	cout<<endl<<"** Show Informasi **"<<endl;
	a.showInformasi();
	cout<<endl<<"isDewasa = "<<a.isDewasa()<<endl;
	cout<<"isPanen = "<<a.isPanen()<<endl;
	cout<<"isMati = "<<a.isMati()<<endl;
	cout<<endl<<"** tambahHappyMeter jadi 4 **"<<endl;
	a.tambahHappyMeter(4);
	cout<<"isDewasa = "<<a.isDewasa()<<endl;
	cout<<"isPanen = "<<a.isPanen()<<endl;
	cout<<"isMati = "<<a.isMati()<<endl;
	cout<<endl<<"** tambahHappyMeter jadi 6 **"<<endl;
	a.tambahHappyMeter(2);
	cout<<"isDewasa = "<<a.isDewasa()<<endl;
	cout<<"isPanen = "<<a.isPanen()<<endl;
	cout<<"isMati = "<<a.isMati()<<endl;
	cout<<endl<<"** kurangiUmur jadi 0 **"<<endl;
	a.kurangiUmur(10);
	cout<<"isDewasa = "<<a.isDewasa()<<endl;
	cout<<"isPanen = "<<a.isPanen()<<endl;
	cout<<"isMati = "<<a.isMati()<<endl;
	cout<<endl<<"** setwhatisthis(0) **"<<endl;
	a.setwhatisthis(0);
	cout<<"What is this = "<<a.getwhatisthis()<<endl;
	cout<<endl<<"** setwhatisthis(1) **"<<endl;
	a.setwhatisthis(1);
	cout<<"What is this = "<<a.getwhatisthis()<<endl;
	return 0;
}
