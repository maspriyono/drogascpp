#include "playgame.h"
#include <windows.h>
#include <mmsystem.h>


void PlayGame::Inisialisasi(){
		bool begin;
		begin = true;
		// mciSendString("open 1.mp3 type mpegvideo alias song1",NULL,0,0);
		// mciSendString("open 3.mp3 type mpegvideo alias song2",NULL,0,0);
		// mciSendString("open 5.wav type mpegvideo alias song3",NULL,0,0);
		// mciSendString("play song1",NULL,0,0);
					// mciSendString("stop song1",NULL,0,0);
					// mciSendString("play song3",NULL,0,0);
				// mciSendString("play song3",NULL,0,0);
	
		while(begin){ 
		system("cls");
		DisplayInterface();
		cout<<"Pilihan > ";
		Com.BacaCommand();

			if (Com.IsUserNew){
					cout<< "Permainan dimulai - Inisialisasi dilakukan"<<endl;
					begin = false;
					StartData();
			}
			else if (Com.IsUserLoad){
					cout<< "Loading Data..."<<endl;
					IO.OpenFarm(&Castro, &time, &area, Com.ArrayOfCommand[2]);
					begin = false;	
			}
			else {
				cout<<"tidak valid... \n";
			}
		}
	}
void PlayGame::StartGame(){
		bool *game = new bool;
		*game = true;
		// system("cls");
		LCD.PrintTemplate();
		Castro.setPosition(0,1);
		Castro.setLocation(0);
		Castro.setDirection(3);

	
		while (*game){

			LCD.Go(2,33);
			DisplayGame();

			cout<<endl;
			//cout<<time.GetBencana();
			//LCD.PrintJudul();LCD.PrintUtama();
			HelpNormalMode();
			//time.printWaktu();
			Com.BacaCommand();
			if (IsInRumah()){
					 StartRumah(*game);

			}
			else if (IsInLahan()){
					 StartLahan();
			}
			else if (IsInToko()){
					 StartToko();
			}
		Sleep(200);
		}
	}
void PlayGame::StartRumah(bool &gameplay){ //display rumah belum ada
	
					if (Com.IsUserSave()){
							 LCD.PrintInfo("IO.SaveGame()");
		 					IO.SaveFarmE(&Castro, &time, &area);

					}
					else if (Com.IsUserSleep()){
							Sleeping();
							 LCD.PrintInfo("Sleeping()");
					}
					else if (Com.IsUserExit()){
							LCD.PrintInfo("Permainan Selesai...");
							LCD.SetWarna(1,15);
							gameplay = false;
					}
					else if (Com.IsUserTeleport()==1){
									LCD.PrintInfo("~~Ngeeeeennggg");
									Castro.Teleport(1);
					}
					else if (Com.IsUserHelp()){
							LCD.PrintInfo("Anda hanya dapat berpindah ke Lahan");
					}
					
					else if (Com.IsUserArrow()){
								arrowstart();
					}
					else if (Com.IsUserEat()){
								time.penambahWktNormal();
								
					}
					
					else {
						GerakBebas();
					}		
			
	}
void PlayGame::StartLahan(){ // display lahan beluma ada
				if (Com.IsUserPlow()){
					time.penambahWktNormal();
					cout << endl << endl <<(area.GetLFieldXY(Castro.FaceX()+1,Castro.FaceY()+1))->GetCond() << endl;
					(Castro.Plow(&area));	
					cout << endl << endl <<(area.GetLFieldXY(Castro.FaceX()+1,Castro.FaceY()+1))->GetCond() << endl;
				}
				else if (Com.IsUserPut()){
					time.penambahWktNormal();// put(); ->>> kerja
					//cout << endl << area.GetLFieldXY(Castro.FaceX(), Castro.FaceY())->GetCond() << endl;
					(Castro.Put(&area,1));
					//cout << endl << area.GetLFieldXY(Castro.FaceX(), Castro.FaceY())->GetCond() << endl;
				}
				else if (Com.IsUserSlash()){
					time.penambahWktNormal();// IsKosong(); CleanArea(); ->>> kerja
					(Castro.Slash(&area));	
				}
				else if (Com.IsUserWater()){
					time.penambahWktNormal();// IsPlantable(); IsWatered(); WaterArea(); ->>> kerja
					(Castro.Water(&area));	
				}
				else if (Com.IsUserHarvest()){
					time.penambahWktNormal();// IsPanen(); ->>>> kerja
					(Castro.Harvest(&area));	
				}
				else if (Com.IsUserWakeUp()){
						LCD.PrintInfo("SetKurcaciOn...");
					// setkurcaci on
					// method gerak AI
				}
				else if (Com.IsUserSleepKur()){
						LCD.PrintInfo("SetKurcaciOff...");
						//set kurcaci belum ada
				}
				else if (Com.IsUserStatKur()){
						LCD.PrintInfo("GetStatus...");
						// getstatus kurcaci belum ada
						/*
							mendapatkan status kurcaci
						*/
				}
				else if (Com.IsUserTeleport()==0){
									LCD.PrintInfo("~~Ngeeeeennggg");
									Castro.Teleport(0);
				}
				else if (Com.IsUserTeleport()==2){
									LCD.PrintInfo("~~Ngeeeennggg");
									Castro.Teleport(2);
				}
				else if (Com.IsUserHelp()){
							LCD.PrintInfo("Anda hanya dapat berpindah ke Rumah/Toko");
				}

					else if (Com.IsUserEat()){
								time.penambahWktNormal();
					}
				else if (Com.IsUserArrow()){
								arrowstart();
				}
				else {
					GerakBebas();
				}
				
		
	}
void PlayGame::StartToko(){ // display toko belum ada
			int jumlah =0;
				int barang =0;
				int uang =0;
				int ID =0;
				int slot =0;
				
				if (Com.IsUserSell()){
						slot = atoi(Com.ArrayOfCommand[2].c_str());
						jumlah = atoi(Com.ArrayOfCommand[3].c_str());
						Selling(slot, jumlah);
						Castro.getInventory()->Rucksack();
						cout<<"Tekan Enter...";
						getch();
						/*
							ngurangin barang tambah uang. ngecek harga dari tanaman
						*/
				}
				else if (Com.IsUserBuy()!=0){  //// ganti jadi ID tanaman, -> boolean
						jumlah = atoi(Com.ArrayOfCommand[3].c_str());
						ID = Com.IsUserBuy();
						Buying(ID, jumlah);
						(Castro.getInventory())->Rucksack();
						getch();
						///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// algoritma masih bisa disingkat lagi.... kondisi uang di cek pertama kali
				}
				else if (Com.IsUserStore()){
						InfoTanaman.showHargaBibit();
						InfoTanaman.showHargaPanen();
						cout<<"Tekan Enter untuk lanjut..."<<endl;
						getch();
				}
				
				else if (Com.IsUserTeleport() == 1){
									cout<< "CastroTravel()"<<endl;
									Castro.Teleport(1);
								//else cout<<"Hanya boleh transport ke lahan"<<endl;
					}
					else if (Com.IsUserHelp()){
							cout<<"Anda hanya dapat berpindah ke Lahan"<<endl;
					}

					else if (Com.IsUserEat()){
								time.penambahWktNormal();
					}
				else if (Com.IsUserArrow()){
								arrowstart();
								
				}
				else {
					GerakBebas();
					
				}	
	}
void PlayGame::GerakBebas(){
		if (Com.IsRight(Com.ArrayOfCommand[1]) && Com.IsInteger(Com.ArrayOfCommand[2])  && Com.IsMark(Com.ArrayOfCommand[3]) && Com.JumlahString == 2){
						cout<< atoi(Com.ArrayOfCommand[2].c_str())<<endl;
						// set kordinat dan arah hadap
				}
		else if (Com.IsLeft(Com.ArrayOfCommand[1]) && Com.IsInteger(Com.ArrayOfCommand[2])  && Com.IsMark(Com.ArrayOfCommand[3]) && Com.JumlahString == 2){
						LCD.PrintInfo("IO.SaveGame()");
						// set kordinat dan arah hadap
				}
		else if (Com.IsDown(Com.ArrayOfCommand[1]) && Com.IsInteger(Com.ArrayOfCommand[2])  && Com.IsMark(Com.ArrayOfCommand[3]) && Com.JumlahString == 2){
						LCD.PrintInfo("IO.SaveGame()");
						// set kordinat dan arah hadap
				}
		else if (Com.IsUp(Com.ArrayOfCommand[1]) && Com.IsInteger(Com.ArrayOfCommand[2])  && Com.IsMark(Com.ArrayOfCommand[3]) && Com.JumlahString == 2){
						LCD.PrintInfo("IO.SaveGame()");
						// set kordinat dan arah hadap
				}
		else if (Com.IsInventory(Com.ArrayOfCommand[1]) && Com.IsMark(Com.ArrayOfCommand[2]) && Com.JumlahString == 1){
						//ShowInventory(); belum ada
				}
		else{
			LCD.PrintInfo("tidak valid..");
		}	
	}
void PlayGame::arrowstart(){
		int ar[8][10];
		int TempX;
		int TempY;
		area.KonvPrint(Castro.getLocation(),ar);
		/*if (Castro.getLocation()==0){
						area.KonvPrint(1,ar);
					}
					else if (Castro.getLocation()==1){
						area.KonvPrint(0,ar);
					}
					else if (Castro.getLocation()==2){
						area.KonvPrint(2,ar);
					}*/
		
		bool arrowmode = true;
		int arrowmotion;
		HelpArrowMode();
		while (arrowmode){
			// system("cls");
			// DisplayGame();
			// cout<<endl;
			// //			LCD.PrintJudul();LCD.PrintUtama();
			//time.printWaktu();

			while(!kbhit());
						  arrowmotion = getch();
					
						  if( arrowmotion == '0')
						break;

						if( arrowmotion == 224 ) //whenever an arrow key is pressse my
				 arrowmotion = getch(); //system returns 224 prior to the key val
				 TempX = Castro.getPositionX();
				 TempY = Castro.getPositionY();
			if (arrowmotion ==72){
				if (Castro.getDirection()!=1){
					
					Castro.setDirection(1);

				}
				else {time.penambahWktNormal();
					Castro.setSakaw(Castro.getSakaw()+1);
					if (
						((ar[Castro.getPositionX()+1][Castro.getPositionY()+2] > 0)  && (ar[Castro.getPositionX()+1][Castro.getPositionY()+2] < 4)) ||
						((ar[Castro.getPositionX()+1][Castro.getPositionY()+2] > 7)  && (ar[Castro.getPositionX()+1][Castro.getPositionY()+2] < 10)) ||
						((ar[Castro.getPositionX()+1][Castro.getPositionY()+2] > 15)  && (ar[Castro.getPositionX()+1][Castro.getPositionY()+2] < 18)))	
					{
					Castro.setPosition(Castro.getPositionX(), Castro.getPositionY()+1);
					}

				}
				}
				// set kordinat dan arah hadap
				//pengecekan kordinat di lahan
			else if (arrowmotion==75)
				{
				if (Castro.getDirection()!=2){
					
					Castro.setDirection(2);
				}
				else {		time.penambahWktNormal();
							Castro.setSakaw(Castro.getSakaw()+1);
					if (
						((ar[Castro.getPositionX()][Castro.getPositionY()+1] > 0)  && (ar[Castro.getPositionX()][Castro.getPositionY()+1] < 4)) ||
						((ar[Castro.getPositionX()][Castro.getPositionY()+1] > 7)  && (ar[Castro.getPositionX()][Castro.getPositionY()+1] < 10)) ||
						((ar[Castro.getPositionX()][Castro.getPositionY()+1] > 15)  && (ar[Castro.getPositionX()][Castro.getPositionY()+1] < 18)))
					Castro.setPosition((Castro.getPositionX())-1, Castro.getPositionY());
				}
				}				//set kordinat dan arah hadap
				// pengencekan kordinat di lahan
			else if (arrowmotion==77)
				{
				if (Castro.getDirection()!=3){
					Castro.setDirection(3);
				}
				else {		time.penambahWktNormal();
							Castro.setSakaw(Castro.getSakaw()+1);
					if (
						((ar[Castro.getPositionX()+2][Castro.getPositionY()+1] > 0)  && (ar[Castro.getPositionX()+2][Castro.getPositionY()+1] < 4)) ||
						((ar[Castro.getPositionX()+2][Castro.getPositionY()+1] > 7)  && (ar[Castro.getPositionX()+2][Castro.getPositionY()+1] < 10)) ||
						((ar[Castro.getPositionX()+2][Castro.getPositionY()+1] > 15)  && (ar[Castro.getPositionX()+2][Castro.getPositionY()+1] < 18)))
					Castro.setPosition((Castro.getPositionX())+1, Castro.getPositionY());
				}
				}
				//set kordinat dan arah hadap
				// pengencekan kordinat di lahan
				else if (arrowmotion==80){
				if (Castro.getDirection()!=4){
					Castro.setDirection(4);
				}
				else {		time.penambahWktNormal();
							Castro.setSakaw(Castro.getSakaw()+1);
					if (
						((ar[Castro.getPositionX()+1][Castro.getPositionY()] > 0)  && (ar[Castro.getPositionX()+1][Castro.getPositionY()] < 4)) ||
						((ar[Castro.getPositionX()+1][Castro.getPositionY()] > 7)  && (ar[Castro.getPositionX()+1][Castro.getPositionY()] < 10)) ||
						((ar[Castro.getPositionX()+1][Castro.getPositionY()] > 15)  && (ar[Castro.getPositionX()+1][Castro.getPositionY()] < 18)))
					Castro.setPosition(Castro.getPositionX(), Castro.getPositionY()-1);
					LCD.PrintInfoL(area.GetLFieldXY(Castro.FaceX(),Castro.FaceY()));
				}
				}
				//set kordinat dan arah hadap
				// pengencekan kordinat di lahan
				else if (arrowmotion==27)
				{arrowmode = false;
				}
			 else { LCD.PrintInfo("do nothing");	}
			LCD.ChangeCharPos(0,TempX, TempY,Castro.getDirection(), Castro.getPositionX(), Castro.getPositionY());
			LCD.PrintJam(time.GetJJ(),time.GetMM());
			LCD.PrintTgl(time.GetHH(),time.GetBB());
			LCD.PrintLoc(Castro.getLocation());
			LCD.PrintKor(Castro.getPositionX(),Castro.getPositionY());
			LCD.PrintCua(time.GetBencana());
			LCD.PrintMus(time.GetMU());
			LCD.PrintSt(Castro.getStatus());
			LCD.PrintBuck(Castro.getMoney());
			LCD.SetODMeter(Castro.getOD());
			LCD.SetSkwMeter(Castro.getSakaw());
			LCD.PrintODSKW();
			LCD.PrintKur(area.GetStKurc(1),area.GetStKurc(2),area.GetStKurc(3));
			
			//LCD.PrintInfoL(area.GetLFieldXY(Castro.FaceX(),Castro.FaceY()));
			Sleep(200);
		}
		 
		 
		 
		 // if (IsArrowUp(Com.GetArrow())){
			// cout<<"Ke atas";
		// }
		// else if (IsArrowRight(Com.GetArrow())){
			// cout<<"Ke kanan";
		// }
		// else if (IsArrowLeft(Com.GetArrow())){
			// cout<<"Ke kiri";
		// }
		// else if (IsArrowDown(Com.GetArrow())){
			// cout<<"Ke bawah";
		// }
		// else cout<<"salah panah";
	}
void PlayGame::DisplayGame(){
		
	int a,b;
	int fil[8][10];
	//INISIALISASI
	LCD.SetPlayer(Castro.getPositionX(),Castro.getPositionY(),Castro.getDirection());
	area.SetAllKurc(1,1,0);
	LCD.SetKurcaci1(3,3,2);
	LCD.SetKurcaci2(4,4,3);
	LCD.SetKurcaci3(1,5,4);
	LCD.SetODMeter(Castro.getOD());
	LCD.SetSkwMeter(Castro.getSakaw());
	//
	area.KonvPrint(Castro.getLocation(), fil);
	LCD.PrintName(Castro.getName());
	LCD << fil;
	LCD.PrintAllFl();
	LCD.PrintAllChar(Castro.getLocation(),area.GetStKurc(1),area.GetStKurc(2),area.GetStKurc(3));
	//INFO SELESAI
	LCD.PrintJam(time.GetJJ(),time.GetMM());
	LCD.PrintTgl(time.GetHH(),time.GetBB());
	LCD.PrintLoc(Castro.getLocation());
	LCD.PrintKor(Castro.getPositionX(),Castro.getPositionY());
	LCD.PrintCua(time.GetBencana());
	LCD.PrintMus(time.GetMU());
	LCD.PrintName(Castro.getName());
	LCD.PrintSt(Castro.getStatus());
	LCD.PrintBuck(Castro.getMoney());
	LCD.PrintODSKW();
	LCD.PrintKur(area.GetStKurc(1),area.GetStKurc(2),area.GetStKurc(3));
	//LCD.PrintInfoL(area.GetLFieldXY(Castro.FaceX(),Castro.FaceY()));
	LCD.Go(2,33);
	}
void PlayGame::DisplayInterface(){
	
		// int fil[6][8];
		// int i,j;
		// //inisialisasi
		// for (i = 0;i <= 5;i++) {
			// for (j = 0;j <= 7;j++) {
				// fil[i][j] = 1;
			// }
		// }
		
		// // LCD.SetJudul(3, 5, 4, 10, 2, 2, 4, "PANAS", "TERANG");
		 // LCD.SetWarna(1,15);
		
		// // //UBAH NAMA
		// // LCD.SetStrPanel(1,0,"FIDEL CASTRO");
		
		// // //UBAH STATUS
		// // LCD.SetStrPanel(1,1,"NORMAL");
		
		// // //UBAH UANG
		// // LCD.SetStrPanel(1,2,"65.000 BUCK");
		
		// // //UBAH NAMA TANAMAN
		// // LCD.SetStrPanel(2,0,"CANABIS");
		
		// LCD.ClearScr();
		// //string jud;
		// /*jud = "TT/BB            HH:MM          RUMAH< , >           MUSIM           CUACA";
		// a[1]= "COBAA"				;	b[1]= "ABISA";
		// a[2]= "AJAA"					;	b[2]= "INIA";
		// a[3]= "NIHA"					;	b[3]= "COBAA";
		// a[4]= "TESTINGA"				;	b[4]= "TRUAS";
		// a[5]= "YUHUA"				;	b[5]= "MAMPUAS";*/
		// LCD << fil;
	// LCD.PrintJudul();
	
	cout<<"\n - new #"<<endl;
	cout<<" - load <nama file> #"<<endl;
	cout<<"\n***** < LOS_DROGAS > *****\n"<<endl;
		
	}
void PlayGame::HelpArrowMode(){
			LCD.ClearInfoBox();
			if (IsInRumah(Castro.getLocation())){
					LCD.PrintInfoBox(1,"<Home_Arrow_Mode> ");
				}
				else if (IsInLahan(Castro.getLocation())){
					LCD.PrintInfoBox(1,"<Lahan_Arrow_Mode> ");
				}
				else if (IsInToko(Castro.getLocation())){
					LCD.PrintInfoBox(1,"<Toko_Arrow_Mode> ");
				}
			LCD.PrintInfoBox(3,"ARROW MODE");
			LCD.PrintInfoBox(4,"< Arrow Mode memperbolehkan aksi yang dilakukan melalui panah");
			LCD.PrintInfoBox(5,"(atas/kanan/kiri/bawah) pada keyboard >");
			LCD.PrintInfoBox(7,"< tekan tombol ESC untuk mengakhiri arrow mode ...>");

		}	
void PlayGame::HelpNormalMode(){
			LCD.ClearInfoBox();
			if (IsInRumah(Castro.getLocation())){
						 LCD.PrintInfoBox(1,"Perintah yang dapat dilakukan :");
						 LCD.PrintInfoBox(2,"\t- save #");
						 LCD.PrintInfoBox(3,"\t- sleep #");
						 LCD.PrintInfoBox(4,"\t- exit #");
						 LCD.PrintInfoBox(5,"\t- teleport lahan #");
						 LCD.PrintInfoBox(6,"\t- inventory #");
						 LCD.PrintInfoBox(7,"\t- (right/left/down/up) (jumlah langkah) #");
						 LCD.PrintInfoBox(8,"\t- arrow");
						 LCD.Go(2,33);LCD.SetWarna(1,11);
						 LCD.PrintKsg(77);
						 LCD.Go(2,33);
						 cout << "Rumah > ";
				}
				else if (IsInLahan(Castro.getLocation())){
						 LCD.PrintInfoBox(1,"Perintah yang dapat dilakukan :");
						 LCD.PrintInfoBox(2,"\t- plow #");
						 LCD.PrintInfoBox(3,"\t- put #");
						 LCD.PrintInfoBox(4,"\t- slash #");
						 LCD.PrintInfoBox(5,"\t- harvest #");
						 LCD.PrintInfoBox(6,"\t- water #");
						 LCD.PrintInfoBox(7,"\t- wake_up (nomor kurcaci) #");
						 LCD.PrintInfoBox(8,"\t- status kurcaci #");
						 LCD.PrintInfoBox(9,"\t- teleport (rumah/toko) #");
						 LCD.PrintInfoBox(10,"\t- inventory #");
						 LCD.PrintInfoBox(11,"\t- arrow");
						 LCD.Go(2,33);LCD.SetWarna(1,11);
						 LCD.PrintKsg(77);
						 LCD.Go(2,33);
						 cout<<"Lahan > ";
				}
				else if (IsInToko(Castro.getLocation())){
						 LCD.PrintInfoBox(1,"Perintah yang dapat dilakukan :");
						 LCD.PrintInfoBox(2,"\t- store #");
						 LCD.PrintInfoBox(3,"\t- sell #");
						 LCD.PrintInfoBox(4,"\t- buy #");
						 LCD.PrintInfoBox(5,"\t- inventory #");
						 LCD.PrintInfoBox(6,"\t- teleport lahan #");
						 LCD.PrintInfoBox(7,"\t- arrow");
						 LCD.Go(2,33);LCD.SetWarna(1,11);
						 LCD.PrintKsg(77);
						 LCD.Go(2,33);
						 cout << "Toko > ";
				}
		}
	void PlayGame::StartData(){
	time=waktu(1,1,1,4,0);
	time.bencana();
	Castro.setMoney(50);
	
	
	
	
}
void PlayGame::Sleeping(){
	time.sleep();
}
void PlayGame::Selling(int slot, int jumlah){
	if ((Castro.getInventory())->adrSlotIsi(slot)->getwhatisthis()==1){
	int uang = InfoTanaman.getDaftarInfo((Castro.getInventory())->adrSlotIsi(slot)->getID() -1,1)*jumlah;
	if (jumlah>0){
							if ((slot <4) && (slot>0)){
									if ((Castro.getInventory())->SlotIsi(slot)){
										(Castro.getInventory())->remItem(slot, jumlah);
										Castro.setMoney(Castro.getMoney()+uang);
									}
									else cout<<"tidak ada item di dalam slot";
							}
							else{
									cout<<"Nomor Slot tidak terdefinisi"<<endl;
							}
						}
					
						else cout<<"jumlah barang tidak valid"<<endl;
	}
	else cout<<"item bukanlah hasil panen";
}
void PlayGame::Buying(int ID, int jumlah){
	int uang = InfoTanaman.getDaftarInfo(ID-1,0)*jumlah;
	if (Castro.getMoney()>=uang){
	if (ID==1){
		Ganja *ganja = new Ganja;
		(Castro.getInventory())->addItem(ganja, jumlah);
		cout<<"\njumlah = "<<(Castro.getInventory())->getAmount1();
		cout<<"\nID = "<<((Castro.getInventory())->getSlot1())->getID();
		Castro.setMoney(Castro.getMoney()-uang );
		cout<<"\nMoney = "<<Castro.getMoney();getch();
	}
	else if (ID==2){
		Opium *opium = new Opium;
		(Castro.getInventory())->addItem(opium, jumlah);
		cout<<"\njumlah = "<<(Castro.getInventory())->getAmount1();
		cout<<"\nID = "<<((Castro.getInventory())->getSlot1())->getID();
		Castro.setMoney(Castro.getMoney()-uang );
		cout<<"\nMoney = "<<Castro.getMoney();getch();
	}
	else if (ID==3){
		Coca *coca = new Coca;
		(Castro.getInventory())->addItem(coca, jumlah);
		cout<<"\njumlah = "<<(Castro.getInventory())->getAmount1();
		cout<<"\nID = "<<((Castro.getInventory())->getSlot1())->getID();
		Castro.setMoney(Castro.getMoney()-uang );
		cout<<"\nMoney = "<<Castro.getMoney();getch();
	}
	else if (ID==4){
		Tobacco *tobacco = new Tobacco;
		(Castro.getInventory())->addItem(tobacco, jumlah);
		cout<<"\njumlah = "<<(Castro.getInventory())->getAmount1();
		cout<<"\nID = "<<((Castro.getInventory())->getSlot1())->getID();
		Castro.setMoney(Castro.getMoney()-uang );
		cout<<"\nMoney = "<<Castro.getMoney();getch();
						}
	else if (ID==5){
		Anggur *anggur = new Anggur;
		(Castro.getInventory())->addItem(anggur,jumlah);
		cout<<"\njumlah = "<<(Castro.getInventory())->getAmount1();
		cout<<"\nID = "<<((Castro.getInventory())->getSlot1())->getID();
		Castro.setMoney(Castro.getMoney()-uang );
		cout<<"\nMoney = "<<Castro.getMoney();getch();
	}
	else if (ID==6){
		Mushroom *mushroom = new Mushroom;
		(Castro.getInventory())->addItem(mushroom, jumlah);
		cout<<"\njumlah = "<<(Castro.getInventory())->getAmount1();
		cout<<"\nID = "<<((Castro.getInventory())->getSlot1())->getID();
		Castro.setMoney(Castro.getMoney()-uang );
		cout<<"\nMoney = "<<Castro.getMoney();getch();
	}
	else cout<<"Nama bibit salah"<<endl;
	}
	else cout<<"Uang tidak cukup";
}

int PlayGame::IsInLahan(){
		return (Castro.getLocation()==1);
	}
	int PlayGame::IsInToko(){
		return (Castro.getLocation()==2);
	}
	
int PlayGame::IsInRumah(){
		return (Castro.getLocation()==0);
	}

	
