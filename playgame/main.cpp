#include "playgame.h"

int main(){

	PlayGame LosDrogas;
	int x;
	//method-method menyatakan tempat
	cout<<"Masukkan lokasi player (0/1/2) = ";
	cin>>x;
	if (LosDrogas.IsInRumah())
		cout<<"\nPlayer ada di rumah";
	else if (LosDrogas.IsInLahan())
		cout<<"\nPlayer ada di lahan ";
	else if (LosDrogas.IsInToko())
		cout<<"\nPlayer ada di toko";

	LosDrogas.Inisialisasi();
	// void StartData();
	// void StartGame(); // method untuk melakukan aksi saat permainan baru dimulai
	// void StartRumah(bool &game1); // method untuk merlakukan aksi di rumah
	// void StartLahan(); // method untuk merlakukan aksi di lahan
	// void StartToko(); // method untuk merlakukan aksi di toko
	// void GerakBebas(); // method untuk merlakukan aksi move
	// void arrowstart(); // method untuk merlakukan aksi untuk masukan panah keyboard
	
	// method untuk IO
	// void LoadingData();
	// void SavingData();

	// method untuk aktivitas-aktivitas player
	// void Sleeping();
	// void Plowing();
	// void PutOrSell();
	// void Slashing();
	// void Watering();
	// void Harvesting();
	// void WakeingUp();
	// void SleepKurcaci();
	// void Selling(int, int);
	// void Buying(int, int);
	// void ViewItem();

	 // method untuk menampilkan layar yang telah diatur
	// void DisplayGame();
	// void DisplayInterface();
	
	// method untuk alat bantu petunjuk
	// void HelpArrowMode();
	// void HelpNormalMode();
	
	// void tambahwaktu();
return 0;
}
