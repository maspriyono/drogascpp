#ifndef PLAYGAME_H
#define PLAYGAME_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <time.h>
#include "../player/PLAYER.h"
#include "../player/SPRITES.h"
#include "../map/Display.h"
#include "../waktu/waktu1.1.h"
#include "../command/command.h"
#include "../allmap/Area.h"
#include "../tanaman/tanaman.h"
#include "../tanaman/anggur.h"
#include "../tanaman/mushroom.h"
#include "../tanaman/ganja.h"
#include "../tanaman/coca.h"
#include "../tanaman/opium.h"
#include "../tanaman/tobacco.h"
#include "../IO/IOGame.h"

class PlayGame {
	private:	
		Player Castro; // sebuah player yang akan terus bermain
		command Com; // sebuah objek yang mengatasi perintah yang akan divalidasi
		Display LCD; // sebuah objek yang berfungsi menampilkan display
		waktu time;	// sebuah objek waktu
		AllMap area; // sebuah objek tempat
		Tanaman InfoTanaman; // objek info tanaman
		Sprites Kurcaci1; // objek kurcaci 1
		Sprites Kurcaci2; // objek kurcaci 2
		Sprites Kurcaci3; //  objek kurcaci 3
		IOGame IO; // objek yang mengatasi permalahan save dan load
		
		
	public : 
	//definisi empat sekawan
	PlayGame(){}
	PlayGame(const PlayGame&);
	PlayGame& operator = (const PlayGame&);
	~PlayGame(){}
	
	//method-method menyatakan tempat
	int IsInRumah();
	int IsInLahan();
	int IsInToko();

	// method untuk menyatakan arah panah
	int IsArrowUp(int a);
	int IsArrowLeft(int a);
	int IsArrowRight(int a);
	int IsArrowDown(int a);
	
	// method-method untuk memulai permainan
	void Inisialisasi();
	void StartData(string nama);
	void StartGame(); // method untuk melakukan aksi saat permainan baru dimulai
	void StartRumah(bool &game1); // method untuk merlakukan aksi di rumah
	void StartLahan(); // method untuk merlakukan aksi di lahan
	void StartToko(); // method untuk merlakukan aksi di toko
	void GerakBebas(); // method untuk merlakukan aksi move
	void arrowstart(); // method untuk merlakukan aksi untuk masukan panah keyboard
	
	// method untuk IO
	void LoadingData();
	void SavingData();

	// method untuk aktivitas-aktivitas player
	void Sleeping();
	void Plowing();
	void PutOrSell();
	void Slashing();
	void Watering();
	void Harvesting();
	void WakeingUp();
	void SleepKurcaci();
	void Selling(int, int);
	void Buying(int, int);
	void ViewItem();

	 // method untuk menampilkan layar yang telah diatur
	void DisplayGame();
	void DisplayInterface();
	
	// method untuk alat bantu petunjuk
	void HelpArrowMode();
	void HelpNormalMode();
	
	void tambahwaktu();
};

#endif

