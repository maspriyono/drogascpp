#ifndef _COMMAND_H
#define _COMMAND_H
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

class command
{
	public:
	command(){}
	command(const command &);
	command & operator = (const command &);
	~command(){}
	
	static const int MaxArray=10;
	string ArrayOfCommand[MaxArray];
	int JumlahString;
	void BacaCommand(); // method untuk membaca masukan user
	
	bool IsArrow(string s);
	bool IsMark(string s);
	
	// method saat permainan baru saja dimulai
	bool IsLoad(string s);
	bool IsNew(string s);
	bool IsFile(string s); // validasi untuk mengidentifikasi masukan berupa file
	
	// validasi kata saat di rumah
	bool IsSave(string s);
	bool IsSleep(string s);
	bool IsExit(string s);

	// validasi kata saat di lahan
	bool IsPlow(string s);
	bool IsPut(string s);
	bool IsHarvest(string s);
	bool IsSlash(string s);
	bool IsWater(string s);
	bool IsWakeUp(string s);
	bool IsStatus(string s);
	bool IsKurcaci(string s);

	// validasi kata saat di toko
	bool IsSell(string s);
	bool IsBuy(string s);
	bool IsStore(string s);
	
	// validasi kata umum
	bool IsInventory(string s);
	bool IsEat(string s);
	bool Is_Help(string s);
	bool IsTeleport(string s);
	bool IsInteger(string s);

	// validasi serangkaian kalimat perintah
	bool IsUserLoad();
	bool IsUserNew();
	bool IsUserSave();
	bool IsUserSleep();
	bool IsUserExit();
	int IsUserTeleport();
	bool IsUserHelp();
	bool IsUserArrow();
	bool IsUserEat();
	bool IsUserPlow();
	bool IsUserPut();
	bool IsUserSlash();
	bool IsUserWater();
	bool IsUserHarvest();
	bool IsUserWakeUp();
	bool IsUserSleepKur();
	bool IsUserStatKur();
	bool IsUserSell();
	int IsUserBuy();
	bool IsUserStore();
	bool IsUserInventory();
	bool IsMoveRight();
	bool IsMoveLeft();
	bool IsMoveUp();
	bool IsMoveDown();
	
	
	// validasi tempat lokasi
	bool IsLahan(string s);
	bool IsRumah(string s);
	bool IsToko(string s);
	
	//validasi arah pergerakan
	bool IsLeft(string s);
	bool IsRight(string s);
	bool IsDown(string s);
	bool IsUp(string s);
	
	
	// validasi masukan jenis tanaman
	bool IsGanja(string s);
	bool IsAnggur(string s);
	bool IsCoca(string s);
	bool IsMushroom(string s);
	bool IsTobacco(string s);
	bool IsOpium(string s);
	
	
	
	
	
	
};
#endif
