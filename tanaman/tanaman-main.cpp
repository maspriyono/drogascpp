// Penanggung jawab = Dimas Gilang Saputra / 13509038

#include "tanaman.h"

int main() {
	// Kamus
	Tanaman a;
	// Algoritma
	cout<<endl<<"** Get Daftar Info **"<<endl;
	cout<<endl<<"* Ganja *"<<endl;
	cout<<"Harga bibit       = "<<a.getDaftarInfo(0,0)<<endl;
	cout<<"Harga hasil panen = "<<a.getDaftarInfo(0,1)<<endl;
	cout<<"OD meter          = "<<a.getDaftarInfo(0,2)<<endl;
	cout<<"Sakaw meter       = "<<a.getDaftarInfo(0,3)<<endl;
	cout<<endl<<"* Opium *"<<endl;
	cout<<"Harga bibit       = "<<a.getDaftarInfo(1,0)<<endl;
	cout<<"Harga hasil panen = "<<a.getDaftarInfo(1,1)<<endl;
	cout<<"OD meter          = "<<a.getDaftarInfo(1,2)<<endl;
	cout<<"Sakaw meter       = "<<a.getDaftarInfo(1,3)<<endl;
	cout<<endl<<"* Coca *"<<endl;
	cout<<"Harga bibit       = "<<a.getDaftarInfo(2,0)<<endl;
	cout<<"Harga hasil panen = "<<a.getDaftarInfo(2,1)<<endl;
	cout<<"OD meter          = "<<a.getDaftarInfo(2,2)<<endl;
	cout<<"Sakaw meter       = "<<a.getDaftarInfo(2,3)<<endl;
	cout<<endl<<"* Tobacco *"<<endl;
	cout<<"Harga bibit       = "<<a.getDaftarInfo(3,0)<<endl;
	cout<<"Harga hasil panen = "<<a.getDaftarInfo(3,1)<<endl;
	cout<<"OD meter          = "<<a.getDaftarInfo(3,2)<<endl;
	cout<<"Sakaw meter       = "<<a.getDaftarInfo(3,3)<<endl;
	cout<<endl<<"* Anggur *"<<endl;
	cout<<"Harga bibit       = "<<a.getDaftarInfo(4,0)<<endl;
	cout<<"Harga hasil panen = "<<a.getDaftarInfo(4,1)<<endl;
	cout<<"OD meter          = "<<a.getDaftarInfo(4,2)<<endl;
	cout<<"Sakaw meter       = "<<a.getDaftarInfo(4,3)<<endl;
	cout<<endl<<"* Mushroom *"<<endl;
	cout<<"Harga bibit       = "<<a.getDaftarInfo(5,0)<<endl;
	cout<<"Harga hasil panen = "<<a.getDaftarInfo(5,1)<<endl;
	cout<<"OD meter          = "<<a.getDaftarInfo(5,2)<<endl;
	cout<<"Sakaw meter       = "<<a.getDaftarInfo(5,3)<<endl;
	cout<<endl<<"** Show Harga Bibit **"<<endl;
	a.showHargaBibit();
	cout<<endl<<"** Show Harga Hasil Panen **"<<endl;
	a.showHargaPanen();
	return 0;
}
