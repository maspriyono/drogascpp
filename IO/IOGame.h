/* 	File		: IOGame.h
 *	Nama		: ANS
 * 	NIM			: 13509064
 * 	Deskripsi	: */


#ifndef IOGAME_H
#define IOGAME_H

#include <iostream>
#include <fstream>
#include <shlobj.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <dirent.h>

#include "../player/PLAYER.h"
#include "../waktu/waktu1.1.h"
#include "../allmap/Area.h"
#include "../tanaman/tanaman.h"
#include "../tanaman/ganja.h"
#include "../tanaman/anggur.h"
#include "../tanaman/mushroom.h"
#include "../tanaman/opium.h"
#include "../tanaman/tobacco.h"
#include "../tanaman/coca.h"


/*#ifdef __WIN32__
#include "..\Command\command.h"
#else
#include "../Command/command.h"
#endif
*/

/*#ifndef __WIN32__
#define getch() map::getch()
#endif
*/

using namespace std;

class IOGame{
	private :
		string namaf;
		string folder;
		
	public :
	/* Konstruktor */	
		IOGame();
		IOGame(const string&);
	
	/* Destruktor */	
		~IOGame();
	
	/* Cctor */
		//BuildSimulator(const BuildSimulator& b);
			
	/* Operator assingment */	
		//BuildSimulator& operator= (const BuildSimulator& b);
		
	/* Other Method */	
		
		string GetName();
		
		void SetName(string);
		
		void OpenFarm(Player*, waktu*, AllMap*, string);
		
		//void Open_farm();
		
		void SaveFarm(Player*, waktu*, AllMap*, string);
		
		void SaveFarmE(Player*, waktu*, AllMap*);
		
		void OpenMap(AllMap*);
		
		string GetFolder();
		
		void SetFolder();
		
		//string BrowseFile(bool); //ini bingung
		
		void SearchFile(string, bool&);
		
		void ListFile();
		
		Tanaman* KonvInv(int );
};

#endif
