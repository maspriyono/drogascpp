#include "command.h"

	void command::BacaCommand(){
		// KAMUS
		int i,k,JmlKrgBka,JmlKrgTtp,JmlPtk;
		int JmlSikuBk, JmlSikuTtp;
		string cmd;

		//ALGORITMA
		JumlahString = 0;
		k=1;
		string temp="";
		JmlKrgBka=0;
		JmlKrgTtp=0;
		JmlSikuBk=0;
		JmlSikuTtp=0;
		JmlPtk=0;
		
		getline(cin,cmd); // meminta masukan satu baris perintah
		
		// for (i=0;i<=cmd.length();i++){ // untuk menghitung tanda kurung
			// if(cmd[i]=='('){
				// JmlKrgBka++;
			// }
			// else if(cmd[i]==')'){
				// JmlKrgTtp++;
			// }
		// }
		
		// for (i=0;i<=cmd.length();i++){ // untuk menghitung tanda petik
			// if(cmd[i]=='"'){
				// JmlPtk++;
			// }
		// }
		// for (i=0;i<=cmd.length();i++){ // untuk menghitung tanda kurung siku buka
			// if(cmd[i]=='['){
				// JmlSikuBk++;
			// }
		// }
		// for (i=0;i<=cmd.length();i++){ // untuk menghitung tanda kurung siku tutup
			// if(cmd[i]==']'){
				// JmlSikuTtp++;
			// }
		// }
		
		
		// if (JmlKrgBka!=JmlKrgTtp){ // untuk validasi jumlah siku kurung buka dan tutup
			// cout<<"Input Tidak Valid"<<endl;
		// }
		// else
		// if (JmlPtk!=2 && JmlPtk!=0){ 
			// cout<<"Input Tidak Valid"<<endl;
		// }
		// else
		// if (JmlSikuBk!=JmlSikuTtp){
			// cout<<"Input Tidak Valid"<<endl;
		// }
		// else{
			for (i=0;i<(cmd.length());i++){
				
				if (cmd[i]!=' '){
					if ((cmd[i]!='(') && (cmd[i]!=')') && (cmd[i]!='"') && (cmd[i]!='[') && (cmd[i]!=']')){
						temp += cmd[i];
					}
				}
				else{
					ArrayOfCommand[k]=temp;
					temp="";
					JumlahString++;
					k++;
				}
			}
			ArrayOfCommand[k]=temp;
			JumlahString++;
			
			if(ArrayOfCommand[k][0]=='#'){
				k--;
				JumlahString--;
			}
		//}
	
	}
		bool command::IsArrow(string s){ // validasi kata arrow
		if (s.length()!=5) return false;
		if(s[0]!='a' && s[0]!='A') return false;
		if(s[1]!='r' && s[1]!='R') return false;
		if(s[2]!='r' && s[2]!='R') return false;
		if(s[3]!='o' && s[3]!='O') return false;
		if(s[4]!='w' && s[4]!='W') return false;
		
		return true;
	}
	bool command::IsMark(string s){ // validasi tanda mark
		if (s.length()!=1) return false;
		if(s[0]!='#' ) return false;
		
		return true;
	}
	
	bool command::IsLoad(string s){ // validasi kata load
		if (s.length()!=4) return false;
		if(s[0]!='l' && s[0]!='L') return false;
		if(s[1]!='o' && s[1]!='O') return false;
		if(s[2]!='a' && s[2]!='A') return false;
		if(s[3]!='d' && s[3]!='D') return false;

		
		return true;
	}bool command::IsNew(string s){ //validasi kata new
		if (s.length()!=3) return false;
		if(s[0]!='n' && s[0]!='N') return false;
		if(s[1]!='e' && s[1]!='E') return false;
		if(s[2]!='w' && s[2]!='W') return false;
		
		return true;
	}
	
	bool command::IsFile(string s){ // validasi kata file
		int i;
		i=s.length();
		if(s[i-1]=='t' && s[i-2]=='x' && s[i-3]=='t'&& s[i-4]=='.'){
			return true;
		}
		else{
			return false;
		}
	}
	
	
	bool command::IsSave(string s){ // validasi kata save
		if (s.length()!=4) return false;
		if (s[0]!='s' && s[0]!='S') return false;
		if (s[1]!='a' && s[1]!='A') return false;
		if (s[2]!='v' && s[2]!='V') return false;
		if (s[3]!='e' && s[3]!='E') return false;
		
		return true;
	}
	bool command::IsSleep(string s){ // validasi kata sleep
		if (s.length()!=5) return false;
		if (s[0]!='s' && s[0]!='S') return false;
		if (s[1]!='l' && s[1]!='L') return false;
		if (s[2]!='e' && s[2]!='E') return false;
		if (s[3]!='e' && s[3]!='E') return false;
		if (s[4]!='p' && s[4]!='P') return false;
		
		return true;
	}
	
	bool command::IsExit(string s){ // validasi kata exit
		if (s.length()!=4) return false;
		if (s[0]!='e' && s[0]!='E') return false;
		if (s[1]!='x' && s[1]!='X') return false;
		if (s[2]!='i' && s[2]!='I') return false;
		if (s[3]!='t' && s[3]!='T') return false;
		
		return true;
	}
	bool command::IsTeleport(string s){ // validasi kata teleport
		if (s.length()!=8) return false;
		if (s[0]!='t' && s[0]!='T') return false;
		if (s[1]!='e' && s[1]!='E') return false;
		if (s[2]!='l' && s[2]!='L') return false;
		if (s[3]!='e' && s[3]!='E') return false;
		if (s[4]!='p' && s[4]!='P') return false;
		if (s[5]!='o' && s[5]!='O') return false;
		if (s[6]!='r' && s[6]!='R') return false;
		if (s[7]!='t' && s[7]!='T') return false;
		
		return true;
	}
	bool command::IsPlow(string s){ // validasi kata plow
		if (s.length()!=4) return false;
		if (s[0]!='p' && s[0]!='P') return false;
		if (s[1]!='l' && s[1]!='L') return false;
		if (s[2]!='o' && s[2]!='O') return false;
		if (s[3]!='w' && s[3]!='W') return false;
		
		return true;
	}
	bool command::IsPut(string s){ // validasi kata put
		if (s.length()!=3) return false;
		if (s[0]!='p' && s[0]!='P') return false;
		if (s[1]!='u' && s[1]!='U') return false;
		if (s[2]!='t' && s[2]!='T') return false;
		
		return true;
	}
	bool command::IsInteger(string s){ // validasi masukan integer
		int i;
		for(i=0;i<=s.length();i++){
			if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9')
			{
				return true;
			}
			else{
				return false;
			}
		}
	}
	bool command::IsHarvest(string s){ // validasi kata harvest
		if (s.length()!=7) return false;
		if (s[0]!='h' && s[0]!='H') return false;
		if (s[1]!='a' && s[1]!='A') return false;
		if (s[2]!='r' && s[2]!='R') return false;
		if (s[3]!='v' && s[3]!='V') return false;
		if (s[4]!='e' && s[4]!='E') return false;
		if (s[5]!='s' && s[5]!='S') return false;
		if (s[6]!='t' && s[6]!='T') return false;
		
		return true;
	}
	bool command::IsSlash(string s){ // validasi kata slash
		if (s.length()!=5) return false;
		if (s[0]!='s' && s[0]!='S') return false;
		if (s[1]!='l' && s[1]!='L') return false;
		if (s[2]!='a' && s[2]!='A') return false;
		if (s[3]!='s' && s[3]!='S') return false;
		if (s[4]!='h' && s[4]!='H') return false;
			return true;
	}
	bool command::IsWater(string s){ // validasi kata water
		if (s.length()!=5) return false;
		if (s[0]!='w' && s[0]!='W') return false;
		if (s[1]!='a' && s[1]!='A') return false;
		if (s[2]!='t' && s[2]!='T') return false;
		if (s[3]!='e' && s[3]!='E') return false;
		if (s[4]!='r' && s[4]!='R') return false;
			return true;
	}
	bool command::IsWakeUp(string s){ // validasi kata wake up
		if (s.length()!=7) return false;
		if (s[0]!='w' && s[0]!='W') return false;
		if (s[1]!='a' && s[1]!='A') return false;
		if (s[2]!='k' && s[2]!='K') return false;
		if (s[3]!='e' && s[3]!='E') return false;
		if (s[4]!='_' && s[4]!='_') return false;
		if (s[5]!='u' && s[5]!='U') return false;
		if (s[6]!='p' && s[6]!='P') return false;
		
		return true;
	}
	bool command::IsStatus(string s){ // validasi kata status
		if (s.length()!=6) return false;
		if (s[0]!='s' && s[0]!='S') return false;
		if (s[1]!='t' && s[1]!='T') return false;
		if (s[2]!='a' && s[2]!='A') return false;
		if (s[3]!='t' && s[3]!='T') return false;
		if (s[4]!='u' && s[4]!='U') return false;
		if (s[5]!='s' && s[5]!='S') return false;
		
		return true;
	}
	bool command::IsKurcaci(string s){ // validasi kata kurcaci
		if (s.length()!=7) return false;
		if (s[0]!='k' && s[0]!='K') return false;
		if (s[1]!='u' && s[1]!='U') return false;
		if (s[2]!='r' && s[2]!='R') return false;
		if (s[3]!='c' && s[3]!='C') return false;
		if (s[4]!='a' && s[4]!='A') return false;
		if (s[5]!='c' && s[5]!='C') return false;
		if (s[6]!='i' && s[6]!='I') return false;
		
		return true;
	}
	bool command::IsSell(string s){ // validasi kata sell
		if (s.length()!=4) return false;
		if (s[0]!='s' && s[0]!='S') return false;
		if (s[1]!='e' && s[1]!='E') return false;
		if (s[2]!='l' && s[2]!='L') return false;
		if (s[3]!='l' && s[3]!='L') return false;
		
		return true;
	}
	bool command::IsBuy(string s){ // validasi kata buy
		if (s.length()!=3) return false;
		if (s[0]!='b' && s[0]!='B') return false;
		if (s[1]!='u' && s[1]!='U') return false;
		if (s[2]!='y' && s[2]!='Y') return false;
		
		return true;
	}
	bool command::IsStore(string s){ // validasi kata store
		if (s.length()!=5) return false;
		if (s[0]!='s' && s[0]!='S') return false;
		if (s[1]!='t' && s[1]!='T') return false;
		if (s[2]!='o' && s[2]!='O') return false;
		if (s[3]!='r' && s[3]!='R') return false;
		if (s[4]!='e' && s[4]!='E') return false;

		return true;
	}
	
	// validasi tempat lokasi
	bool command::IsLahan(string s){ // validasi kata lahan 
		if (s.length()!=5) return false;
		if (s[0]!='l' && s[0]!='L') return false;
		if (s[1]!='a' && s[1]!='A') return false;
		if (s[2]!='h' && s[2]!='H') return false;
		if (s[3]!='a' && s[3]!='A') return false;
		if (s[4]!='n' && s[4]!='N') return false;

		return true;
	}bool command::IsRumah(string s){ // validasi kata rumah
		if (s.length()!=5) return false;
		if (s[0]!='r' && s[0]!='R') return false;
		if (s[1]!='u' && s[1]!='U') return false;
		if (s[2]!='m' && s[2]!='M') return false;
		if (s[3]!='a' && s[3]!='A') return false;
		if (s[4]!='h' && s[4]!='H') return false;

		return true;
	}
	bool command::IsToko(string s){ // validasi kata toko
		if (s.length()!=4) return false;
		if (s[0]!='t' && s[0]!='T') return false;
		if (s[1]!='o' && s[1]!='O') return false;
		if (s[2]!='k' && s[2]!='K') return false;
		if (s[3]!='o' && s[3]!='O') return false;
	
		return true;
	}
	
	//validasi arah pergerakan
	bool command::IsLeft(string s){ // validasi kata left
		if (s.length()!=4) return false;
		if (s[0]!='l' && s[0]!='L') return false;
		if (s[1]!='e' && s[1]!='E') return false;
		if (s[2]!='f' && s[2]!='F') return false;
		if (s[3]!='t' && s[3]!='T') return false;
	
		return true;
	}
	bool command::IsRight(string s){ // validasi kata right
		if (s.length()!=5) return false;
		if (s[0]!='r' && s[0]!='R') return false;
		if (s[1]!='i' && s[1]!='I') return false;
		if (s[2]!='g' && s[2]!='G') return false;
		if (s[3]!='h' && s[3]!='H') return false;
		if (s[4]!='t' && s[4]!='T') return false;
	
		return true;
	}
	bool command::IsDown(string s){ // validasi kata down
		if (s.length()!=4) return false;
		if (s[0]!='d' && s[0]!='D') return false;
		if (s[1]!='o' && s[1]!='O') return false;
		if (s[2]!='w' && s[2]!='W') return false;
		if (s[3]!='n' && s[3]!='N') return false;
	
		return true;
	}
	bool command::IsUp(string s){ // validasi kata up
		if (s.length()!=2) return false;
		if (s[0]!='u' && s[0]!='U') return false;
		if (s[1]!='p' && s[1]!='P') return false;
	
		return true;
	}
	
	bool command::IsInventory(string s){ // validasi kata inventory
		if (s.length()!=9) return false;
		if (s[0]!='i' && s[0]!='I') return false;
		if (s[1]!='n' && s[1]!='N') return false;
		if (s[2]!='v' && s[2]!='V') return false;
		if (s[3]!='e' && s[3]!='E') return false;
		if (s[4]!='n' && s[4]!='N') return false;
		if (s[5]!='t' && s[5]!='T') return false;
		if (s[6]!='o' && s[6]!='O') return false;
		if (s[7]!='r' && s[7]!='R') return false;
		if (s[8]!='y' && s[8]!='Y') return false;
	
		return true;
	}
	
	bool command::IsEat(string s){ // validasi kata eat
		 if (s.length()!=3) return false;
		if (s[0]!='e' && s[0]!='T') return false;
		if (s[1]!='a' && s[1]!='A') return false;
		if (s[2]!='t' && s[2]!='T') return false;
		return true;
	}
	bool command::Is_Help(string s){ // validasi kata -help
		 if (s.length()!=5) return false;
		if (s[0]!='-' && s[0]!='-') return false;
		if (s[1]!='h' && s[1]!='H') return false;
		if (s[2]!='e' && s[2]!='E') return false;
		if (s[3]!='l' && s[3]!='L') return false;
		if (s[4]!='p' && s[4]!='P') return false;
		return true;
	}
	// jenis tanaman
	bool command::IsAnggur(string s){ // validasi kata anggur
		 if (s.length()!=6) return false;
		if (s[0]!='a' && s[0]!='A') return false;
		if (s[1]!='n' && s[1]!='N') return false;
		if (s[2]!='g' && s[2]!='G') return false;
		if (s[3]!='g' && s[3]!='G') return false;
		if (s[4]!='u' && s[4]!='U') return false;
		if (s[5]!='r' && s[5]!='R') return false;
		return true;
	}
	bool command::IsCoca(string s){ // validasi kata coca
		 if (s.length()!=4) return false;
		if (s[0]!='c' && s[0]!='C') return false;
		if (s[1]!='o' && s[1]!='O') return false;
		if (s[2]!='c' && s[2]!='C') return false;
		if (s[3]!='a' && s[3]!='A') return false;
		return true;
	}
	bool command::IsGanja(string s){ // validasi kata ganja
		 if (s.length()!=5) return false;
		if (s[0]!='g' && s[0]!='G') return false;
		if (s[1]!='a' && s[1]!='A') return false;
		if (s[2]!='n' && s[2]!='N') return false;
		if (s[3]!='j' && s[3]!='J') return false;
		if (s[4]!='a' && s[4]!='A') return false;
		return true;
	}
	bool command::IsMushroom(string s){ // validasi kata mushroom
		 if (s.length()!=8) return false;
		if (s[0]!='m' && s[0]!='M') return false;
		if (s[1]!='u' && s[1]!='U') return false;
		if (s[2]!='s' && s[2]!='S') return false;
		if (s[3]!='h' && s[3]!='H') return false;
		if (s[4]!='r' && s[4]!='R') return false;
		if (s[5]!='o' && s[5]!='O') return false;
		if (s[6]!='o' && s[6]!='O') return false;
		if (s[7]!='m' && s[7]!='M') return false;
		return true;
	}
	bool command::IsOpium(string s){ // validasi kata opium
		 if (s.length()!=5) return false;
		if (s[0]!='o' && s[0]!='O') return false;
		if (s[1]!='p' && s[1]!='P') return false;
		if (s[2]!='i' && s[2]!='I') return false;
		if (s[3]!='u' && s[3]!='U') return false;
		if (s[4]!='m' && s[4]!='M') return false;
		return true;
	}
	bool command::IsTobacco(string s){ // validasi kata tobacco
		 if (s.length()!=7) return false;
		if (s[0]!='t' && s[0]!='T') return false;
		if (s[1]!='o' && s[1]!='O') return false;
		if (s[2]!='b' && s[2]!='B') return false;
		if (s[3]!='a' && s[3]!='A') return false;
		if (s[4]!='c' && s[4]!='C') return false;
		if (s[5]!='c' && s[5]!='C') return false;
		if (s[6]!='o' && s[6]!='O') return false;
		return true;
	}

	// method untuk validasi kalimat perintah
	bool command::IsUserNew(){ // validasi kalimat perintah new
		return (IsNew(ArrayOfCommand[1]) && IsMark(ArrayOfCommand[3]) && JumlahString == 2);
	}
	bool command::IsUserLoad(){ // validasi kalimat perintah load
		return (IsLoad(ArrayOfCommand[1]) && IsFile(ArrayOfCommand[2]) && IsMark(ArrayOfCommand[3]) && JumlahString == 2);
	}
	bool command::IsUserSave(){ // validasi kalimat perintah save
		return (IsSave(ArrayOfCommand[1]) && IsMark(ArrayOfCommand[2]) && JumlahString == 1);
	}

	bool command::IsUserSleep(){ // validasi kalimat perintah sleep
		return (IsSleep(ArrayOfCommand[1]) && IsMark(ArrayOfCommand[2]) && JumlahString == 1);
	}
	bool command::IsUserExit(){ // validasi kalimat perintah exit
		return (IsExit(ArrayOfCommand[1]) && IsMark(ArrayOfCommand[2]) && JumlahString == 1);
	}
	int command::IsUserTeleport(){ // validasi kalimat perintah teleport yang menghasilkan integer
		if (IsTeleport(ArrayOfCommand[1]) && IsMark(ArrayOfCommand[3]) && (JumlahString == 2)){
			if (IsRumah(ArrayOfCommand[2])) {
					return 0; //rumah
				}
			else if (IsLahan(ArrayOfCommand[2])) {
					return 1; //lahan
				}
			else if (IsToko(ArrayOfCommand[2])) {
					return 2; // toko
				}
			
		}
		else return 3; // 3 adalah penanda error
								
	}
	
	bool command::IsUserHelp(){ // validasi kalimat teleport help
		return (IsTeleport(ArrayOfCommand[1]) && Is_Help(ArrayOfCommand[2]) && IsMark(ArrayOfCommand[3]) && (JumlahString == 2));
	}
	
	bool command::IsUserArrow(){ // validasi kalimat arrow
		return (IsArrow(ArrayOfCommand[1])  && JumlahString == 1);
	}
	bool command::IsUserEat(){ // validasi kalimat perintah eat
		return (IsEat(ArrayOfCommand[1])  && IsMark(ArrayOfCommand[2]) && JumlahString == 1);
	}
	bool command::IsUserPlow(){ // validasi kalimat perintah plow
		return (IsPlow(ArrayOfCommand[1]) && IsMark(ArrayOfCommand[2]) && JumlahString == 1);
	}
	bool command::IsUserPut(){ // validasi kalimat perintah put
		return (IsPut(ArrayOfCommand[1]) && IsInteger(ArrayOfCommand[2]) && IsInteger(ArrayOfCommand[3]) && IsMark(ArrayOfCommand[4]) && JumlahString == 3);
	}
	bool command::IsUserSlash(){ // validasi kalimat perintah slash
		return (IsSlash(ArrayOfCommand[1]) && IsMark(ArrayOfCommand[2]) && JumlahString == 1);
	}
	bool command::IsUserWater(){ // validasi kalimat perintah water
		return (IsWater(ArrayOfCommand[1])&& IsMark(ArrayOfCommand[2])  && JumlahString == 1);
	}
	bool command::IsUserHarvest(){ // validasi kalimat perintah harvest
		return (IsHarvest(ArrayOfCommand[1]) && IsMark(ArrayOfCommand[2]) && JumlahString == 1);
	}
	bool command::IsUserWakeUp(){ // validasi kalimat perintah wake up kurcaci
		return (IsWakeUp(ArrayOfCommand[1]) && IsInteger(ArrayOfCommand[2]) && IsMark(ArrayOfCommand[3]) && JumlahString == 2);
	}
	bool command::IsUserSleepKur(){ // validasi kalimat perintah sleep kurcaci
		return (IsSleep(ArrayOfCommand[1]) && IsInteger(ArrayOfCommand[2]) && IsMark(ArrayOfCommand[3]) && JumlahString == 2);
	}
	bool command::IsUserStatKur(){ // validasi kalimat perintah status kurcaci
		return (IsStatus(ArrayOfCommand[1]) && IsKurcaci(ArrayOfCommand[2]) && IsMark(ArrayOfCommand[3]) && JumlahString == 2);
	}
	bool command::IsUserSell(){ // validasi kalimat perintah sell
		return (IsSell(ArrayOfCommand[1]) && IsInteger(ArrayOfCommand[2])&& IsInteger(ArrayOfCommand[3])&& IsMark(ArrayOfCommand[4])&& JumlahString == 3);
		
		
	}
	int command::IsUserBuy(){ // validasi kalimat perintah buy
		if (IsBuy(ArrayOfCommand[1]) &&  IsMark(ArrayOfCommand[4])&& JumlahString == 3){ 
			if (IsInteger(ArrayOfCommand[3]) ){ // kata ketiga harus integer
				if (IsGanja(ArrayOfCommand[2])){ // validasi jenis tanaman mengembalikan nilai
					return 1;
				}
				else if (IsOpium(ArrayOfCommand[2])){
					return 2;				
				}
				else if(IsCoca(ArrayOfCommand[2])){
					return 3;
				
				}
				else if(IsTobacco(ArrayOfCommand[2])){
					return 4;
				}
				else if(IsAnggur(ArrayOfCommand[2])){
					return 5;
				}
				else if(IsMushroom(ArrayOfCommand[2])){
					return 6;
				}
				
			}
		
		
		}
		else return 0; // mengembalikan nol jika jenis tanaman salah
	}
	
	bool command::IsUserStore(){ // validasi kalimat perintah store
		return (IsStore(ArrayOfCommand[1]) && IsMark(ArrayOfCommand[2])&& JumlahString == 1);
	}
	bool command::IsUserInventory(){ // validasi kalimat perintah inventory
		return (IsInventory(ArrayOfCommand[1]) && IsMark(ArrayOfCommand[2])&& JumlahString == 1);
	}
	bool command::IsMoveRight(){ // validasi kalimat perintah move right
		return (IsRight(ArrayOfCommand[1]) && IsInteger(ArrayOfCommand[2])&& IsMark(ArrayOfCommand[3])&& JumlahString == 2);
	}
	bool command::IsMoveLeft(){ // validasi kalimat perintah move left
		return (IsLeft(ArrayOfCommand[1]) && IsInteger(ArrayOfCommand[2])&& IsMark(ArrayOfCommand[3])&& JumlahString == 2);
	}
	bool command::IsMoveUp(){ // validasi kalimat perintah move up
		return (IsUp(ArrayOfCommand[1]) && IsInteger(ArrayOfCommand[2])&& IsMark(ArrayOfCommand[3])&& JumlahString == 2);
	}
	bool command::IsMoveDown(){ // validasi kalimat perintah move down
		return (IsDown(ArrayOfCommand[1]) && IsInteger(ArrayOfCommand[2])&& IsMark(ArrayOfCommand[3])&& JumlahString == 2);
	}
	
	
