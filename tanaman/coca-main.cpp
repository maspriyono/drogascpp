// Penanggung jawab : Dimas Gilang Saputra / 13509038

#include "coca.h"

int main() {
	// Kamus
	Coca a;
	// Algoritma
	cout<<endl<<"** Show Informasi **"<<endl;
	a.showInformasi();
	cout<<endl<<"isDewasa = "<<a.isDewasa()<<endl;
	cout<<"isPanen = "<<a.isPanen()<<endl;
	cout<<"isMati = "<<a.isMati()<<endl;
	cout<<endl<<"** tambahHappyMeter jadi 5 **"<<endl;
	a.tambahHappyMeter(5);
	cout<<"isDewasa = "<<a.isDewasa()<<endl;
	cout<<"isPanen = "<<a.isPanen()<<endl;
	cout<<"isMati = "<<a.isMati()<<endl;
	cout<<endl<<"** tambahHappyMeter jadi 10 **"<<endl;
	a.tambahHappyMeter(5);
	cout<<"isDewasa = "<<a.isDewasa()<<endl;
	cout<<"isPanen = "<<a.isPanen()<<endl;
	cout<<"isMati = "<<a.isMati()<<endl;
	cout<<endl<<"** kurangiUmur jadi 0 **"<<endl;
	a.kurangiUmur(15);
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
