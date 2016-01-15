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
	// int arrowsign;
	// int arrowboolean; // inisialisasi jadiin off
	
	void BacaCommand();
	// int getiarrow(){
		// return getiarrow;
	// }
	// void arrowcommand (){
			
				
					 
		
	// }
	// void SetArrow(int arrow){
		// arrowboolean = arrow;
	// }
	// int GetArrow(){
		// return arrowsign;
	// }
	// int GetArrowboolean(){
		// return arrowboolean;
	// }
	
		bool IsArrow(string s);
		bool IsBuild(string s);
	
	bool IsMark(string s);
	
	bool IsPlay(string s);
	
	bool IsMode(string s);
	
	bool IsKeluar(string s);
	bool IsLoad(string s);
	bool IsNew(string s);

	// bool IsCls(string s){
		// if (s.length()!=3) return false;
		// if(s[0]!='c' && s[0]!='C') return false;
		// if(s[1]!='l' && s[1]!='L') return false;
		// if(s[2]!='s' && s[2]!='S') return false;
		
		// return true;
	// }
	
	bool IsFile(string s);
	
	//////////////// RUMAH
	bool IsSave(string s);
	bool IsSleep(string s);
	bool Is_Help(string s);
	bool IsExit(string s);
	bool IsTeleport(string s);
	bool IsPlow(string s);
	bool IsPut(string s);
	bool IsInteger(string s);
	bool IsHarvest(string s);
	bool IsSlash(string s);
	bool IsWater(string s);
	bool IsWakeUp(string s);
	bool IsSleepKurcaci(string s);
	bool IsStatus(string s);
	bool IsKurcaci(string s);
	bool IsSell(string s);
	bool IsBuy(string s);
	bool IsStore(string s);
	
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
	
	
	// validasi tempat lokasi
	bool IsLahan(string s);
	bool IsRumah(string s);
	bool IsToko(string s);
	
	//validasi arah pergerakan
	bool IsLeft(string s);
	bool IsRight(string s);
	bool IsDown(string s);
	bool IsUp(string s);
	
	bool IsInventory(string s);
	
	bool IsEat(string s);
	
	// jenis tanaman
	bool IsGanja(string s);
	bool IsAnggur(string s);
	bool IsCoca(string s);
	bool IsMushroom(string s);
	bool IsTobacco(string s);
	bool IsOpium(string s);
	
	
	
	
	
	
};
#endif
