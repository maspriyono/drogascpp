#ifndef PLAYGAME_H
#define PLAYGAME_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <time.h>
#include "player/PLAYER.h"
#include "player/SPRITES.h"
#include "map/Display.h"
#include "waktu/waktu1.1.h"
#include "command.h"
#include "allmap/Area.h"
#include "tanaman/tanaman.h"
#include "tanaman/anggur.h"
#include "tanaman/mushroom.h"
#include "tanaman/ganja.h"
#include "tanaman/coca.h"
#include "tanaman/opium.h"
#include "tanaman/tobacco.h"
#include "IO/IOGame.h"

class PlayGame {
	private:	
		Player Ucup; // sebuah player yang akan terus bermain
		command Com; // perintah yang akan divalidasi
		Display LCD;
		waktu time;	
		AllMap area;
		Tanaman InfoTanaman;
		Sprites Kurcaci1;
		Sprites Kurcaci2;
		Sprites Kurcaci3;
		IOGame IO;
		
		
	public : 
	//definisi empat sekawan
	PlayGame(){}
	PlayGame(const PlayGame&);
	PlayGame& operator = (const PlayGame&);
	~PlayGame(){}
	// void cobain(){
		// Player::playyer();
	// }
	
	void tambahwaktu();
	
	int IsInRumah(int x);
	int IsInLahan(int x);
	int IsArrowUp(int a);
	int IsArrowLeft(int a);
	int IsArrowRight(int a);
	int IsInToko(int x);
	int IsArrowDown(int a);
	
	// prosedur untuk memulai permainan. berbagai data disiapkan
	void Inisialisasi();
	
	void StartGame();
	
	void StartRumah(bool &game1);
	void StartLahan();
	void StartToko();
	void GerakBebas();
	
	void arrowstart();
	
	void StartData();
	void LoadingData();
	void SavingData();
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

	 
	void DisplayGame();
	
	void DisplayInterface();
	
	void HelpArrowMode();
	void HelpNormalMode();
	
};
		
// void PlayGame::tambahwaktu(){
		// time=waktu(1,1,1,4,0);
		
	// time.initBencana();
	// time.bencana();
	// int i=1;
	// char a;
	// while(i < 200){
		// time.penambahWktNormal();
// //		time.bencana();
		// time.printWaktu();
// //		cout << "hujan\t\t" << "topan\t\t" <<  "razia\t\t" << "cropcircle" << endl;
// //		cout << "-----------------------------------------------------------------------------" << endl;
		// cout << "\t\t" <<time.isHujan() << time.isTopan()  << time.isRazia() << time.isCropCircle() << endl;
		// i=i+1;
	// }
	// cout << "ch = " << time.GetHujan() << endl;
	// cout << "cr = " << time.GetRazia() << endl;
	// cout << "ct = " << time.GetTopan() << endl;
	// cout << "cb = " << time.GetCC() << endl;
	// }
// void PlayGame::Inisialisationdata(){
	// Ucup.setpoint(0	, 6);
	// Ucup.setLocation(0);
	// Ucup.setDirection(3);
	// time=waktu(1,1,1,4,0);
// }
#endif

