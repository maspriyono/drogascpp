/* 	File		: IOGame.h
 *	Nama		: ANS
 * 	NIM			: 13509064
 * 	Deskripsi	: */
#include "IOGame.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <dirent.h>

using namespace std;

/* Konstruktor */	
IOGame::IOGame(){
}
		
IOGame::IOGame(const string& namafile){
		namaf=namafile;
}
	
/* Destruktor */	
IOGame::~IOGame(){
		namaf="";
		folder="";
}
			
/* Other Method */	
string IOGame::GetName(){
		return namaf;
}
	
void IOGame::SetName(string namafile) {
		namaf=namafile;
}
	
string IOGame::GetFolder(){
		return folder;
}
	
void IOGame::SetFolder(){
    BROWSEINFO   bi; 
    ZeroMemory(&bi,   sizeof(bi)); 
    TCHAR   szDisplayName[MAX_PATH]; 
    //szDisplayName[0]    =   '';  

    bi.hwndOwner        =   NULL; 
    bi.pidlRoot         =   NULL; 
    bi.pszDisplayName   =   szDisplayName; 
    //bi.lpszTitle        =   _T("Please select a folder for storing received files :"); 
    bi.ulFlags          =   BIF_RETURNONLYFSDIRS;
    //bi.lParam           =   NULL; 
    bi.iImage           =   0;  

    LPITEMIDLIST   pidl   =   SHBrowseForFolder(&bi);
    TCHAR   szPathName[MAX_PATH]; 
    if   (NULL   !=   pidl)
    {
         BOOL bRet = SHGetPathFromIDList(pidl,szPathName);
         if(FALSE == bRet)
              return;
        // AfxMessageBox(szPathName);
		std::cout << szPathName;
    }			
	
	folder=szPathName;
}
	
void IOGame::OpenFarm(Player* org, waktu* tm, AllMap* am, string namafile){
	ifstream input;
	//string s="tanam.txt";

	input.open(namafile.c_str());
	if(!input) // if it didn't succeed in creating (and opening) the file
	{
		cerr << "Cannot open file.\n"; //print 'cannot open file'
	} else
	{		
		//string s;
		int i,j,temp;
		int p,pe,pa,c,s;
		char *ch;
		string h;
		
		for (i=6; i>=0; i--){
			for (j=0; j<=5; j++){
				input>>ch;
				//cout<<ch;
				h=ch[0];
				p=atoi(h.c_str());
				h=ch[1];
				pe=atoi(h.c_str());
				h=ch[2];
				pa=atoi(h.c_str());
				h=ch[3];
				c=atoi(h.c_str());
				h=ch[4];
				s=atoi(h.c_str());
				(*am).SetLFieldXY(j,i,p,pe,pa,c,s);
				//SetLFieldXY			(int x, int y, int P, int PE, int PA, int C, int S);
			}
		} //membaca lahan
		
		for (i=6; i>=0; i--){
			for (j=0; j<=5; j++){
				input>>ch;
				cout<<ch;
				//cout<<"id=";
				(*am).GetLFieldXY(j,i)->Kerja(int(ch[0])); //ini caranya cuk nanam
				input>>ch; cout<<ch;
				//cout<<"umur"
				(*am).GetLFieldXY(j,i)->GetPlant()->setUmur(atoi(ch));//umur dkk
				input>>ch;cout<<ch<<" ";
				//cout<<"happy"
				(*am).GetLFieldXY(j,i)->GetPlant()->setHappyMeter(atoi(ch));//happy dkk
				//cout<<ch<<" ";
			} //membaca id tanaman
		}
		cout<<".";
		input>>ch; cout<<ch<<endl; input>>ch;
		//membaca waktu, masih karakter
		input>>ch; temp=atoi(ch); //tgl
		cout<<ch;
		(*tm).SetHH(temp);
		input>>ch; temp=atoi(ch);//bln
		cout<<ch;(*tm).SetBB(temp);
		input>>ch; temp=atoi(ch);//msm
		cout<<ch;(*tm).SetMU(temp);
		input>>ch; temp=atoi(ch);//jam
		cout<<ch;(*tm).SetJJ(temp);
		input>>ch; temp=atoi(ch);//menit
		cout<<ch;(*tm).SetMM(temp);		
		getch();
		//membaca nama
		input>>ch;
		(*org).setName(ch);
		
		//membaca status meter
		input>>ch; temp=atoi(ch);
		(*org).setOD(temp); //ODmeter
		input>>ch; temp=atoi(ch);
		(*org).setSakaw(temp); //sakawmeter
		
		//membaca uang, 
		input>>ch; temp=atoi(ch);
		(*org).setMoney(temp);
		
		//memasukkan inventory
			input>>ch; temp=atoi(ch); //1
			
			(*org).getInventory()->setSlot1(KonvInv(temp));
		
			input>>ch; temp=atoi(ch);
			(*org).getInventory()->setAmount1(temp);
		
			input>>ch; temp=atoi(ch); //2
			(*org).getInventory()->setSlot2(KonvInv(temp));
		
			input>>ch; temp=atoi(ch);
			(*org).getInventory()->setAmount2(temp);
		
			input>>ch; temp=atoi(ch); //3
			(*org).getInventory()->setSlot3(KonvInv(temp));
		
			input>>ch; temp=atoi(ch);
			(*org).getInventory()->setAmount3(temp);
		
		//menutup file
		input.close();
	}
}
Tanaman* IOGame::KonvInv(int ID){
	switch (ID){
		case 1 : {
			Ganja* ganja = new Ganja;
			return ganja;
			break;						
		}
		case 2: {
			Opium* opium = new Opium;
			return opium;
			break;						
		}
		case 3: {
			Coca* coca = new Coca;
			return coca;
			break;						
		}
		case 4 : {
			Tobacco* tobacco = new Tobacco;
			return tobacco;
			break;						
		}
		case 5 : {
			Anggur* anggur = new Anggur;
			return anggur;
			break;						
		}
		case 6 : {
			Mushroom* mushroom = new Mushroom;
			return mushroom;
			break;						
		}
	}
}
/*void IOGame::Open_farm(){
		string s=GetName();
		if (s.compare("")==0){ //mengecek apakah baru, kosong namafile
			string name;
			ifstream tes;
			
			cout<<endl<<"Masukkan nama file yang ingin dibuka :"<<endl;
			cout<<"Nama file : "; cin>>name;
			
			tes.open(name.c_str());
			//BrowseFile(true); //Membuka browse dialog
			if(!tes){ //berarti dah ada filenya
				cerr<<"File opening failed"<<endl;
			}else{
				tes.close(name.c_str());
				Open_farm(name);
			}
		}else{
			Open_farm(GetName()); ///ngambil langsung
		}
}*/
	
void IOGame::SaveFarm(Player* org, waktu* tm, AllMap* am, string namafile){
	//char FileName[100];
	
	//cout << "\nEnter the name of the file you want to create: ";
    //cin >> FileName;

    ofstream output(namafile.c_str());
	if(!output) // if it didn't succeed in creating (and opening) the file
	{
		cerr << "Cannot open file.\n"; //print 'cannot open file'
	} else {
		int i,j,temp;
		int p,pe,pa,c,s;
		char *ch;
		string kt;
		
		for (i=6; i>=0; i--){ 
			for (j=0; j<=5; j++){ 
				temp=(*am).GetLFieldXY(j,i)->IsPlantable();//ambil semua IsPlantExist, IsPlantAlive, IsCangkul, IsSiram
				//"plantable="
				output<<temp;
				temp=(*am).GetLFieldXY(j,i)->IsPlantExist();
				//"plantexist="
				output<<temp;
				temp=(*am).GetLFieldXY(j,i)->IsPlantAlive();
				//"plantalive="
				output<<temp;
				temp=(*am).GetLFieldXY(j,i)->IsCangkul();
				//"cangkul="
				output<<temp;
				temp=(*am).GetLFieldXY(j,i)->IsSiram();
				//"siram="
				output<<temp<<" ";
			}
			output<<endl;
		} //menulis lahan
				
		for (i=6; i>=0; i--){ 
			for (j=0; j<=5; j++){ 
				temp=(*am).GetLFieldXY(j,i)->GetPlant()->getID(); //apa aja di tanaman.h
				//"id=";
				output<<temp<<" ";
				temp=(*am).GetLFieldXY(j,i)->GetPlant()->getUmur();
				//"umur=";
				output<<temp<<" ";
				temp=(*am).GetLFieldXY(j,i)->GetPlant()->getHappyMeter();
				//"happy=";
				output<<temp<<" ";
			}
			output<<endl;
		} //menulis prop tanaman
		
		//menulis waktu,
		//"curr_waktu=";
		temp=(*tm).GetHH(); output<<temp<<" ";
		temp=(*tm).GetBB(); output<<temp<<" ";
		temp=(*tm).GetMU(); output<<temp<<" ";
		temp=(*tm).GetJJ(); output<<temp<<" ";
		temp=(*tm).GetMM(); output<<temp<<endl;
		
		//menulis nama
		//"nama=";
		kt=(*org).getName(); output<<kt<<endl;
		
		//menulis status meter,
		//"od_meter=";
		temp=(*org).getOD(); output<<temp<<" ";
		//"sakaw_meter=";
		temp=(*org).getSakaw(); output<<temp<<endl;
		
		//"uang=";
		temp=(*org).getMoney(); output<<temp<<endl;
		
			//"jenis=";
		temp=(*org).getInventory()->getSlot1()->getID(); output<<temp<<" ";
			//"kuantitas=";
		temp=(*org).getInventory()->getAmount1(); output<<temp<<endl;
			//"jenis=";
		temp=(*org).getInventory()->getSlot2()->getID(); output<<temp<<" ";
			//"kuantitas=";
		temp=(*org).getInventory()->getAmount2(); output<<temp<<endl;
			//"jenis=";
		temp=(*org).getInventory()->getSlot3()->getID(); output<<temp<<" ";
			//"kuantitas=";
		temp=(*org).getInventory()->getAmount3(); output<<temp<<endl;
			
		//} //membaca inventory
		output<<"#";
		output.close();
	}
}
	
void IOGame::SaveFarmE(Player* org, waktu* tm, AllMap* am){
		string s=GetName();
		if (s.compare("")==0){ //berarti tidak ada di objek IO namafile-nya
			string name;
			//string add="allmap/";
			//string name = BrowseFile(false); //Membuka browse dialog
			//cout<<endl<<"Pilih lokasi folder penyimpanan :"<<endl;
			//SetFolder();
			cout<<endl<<"Masukkan nama file yang ingin disimpan :"<<endl;
			cout<<"Nama file : "; cin>>name;
			//string add=GetFolder();
			//add.append(name, 0, name.size());
			//cout<<add.c_str();
			ifstream tes;
			tes.open(name.c_str());
			
			if(tes){
				cerr<<"FIle sudah ada"<<endl;
				tes.close();
			}else{
				SaveFarm(org, tm, am, name); //harusnya exception handling
			}
		}else{
			SaveFarm(org, tm, am, GetName()); //berarti tidak kosong
		 }
}

	
	
void IOGame::OpenMap(AllMap* am){
	ifstream input;

	input.open("allmap/map.ld");
	if(!input) // if it didn't succeed in creating (and opening) the file
	{
		cerr << "Cannot open file.\n"; //print 'cannot open file'
	} else
	{		
		int i,j,temp;
		int m,s,b,jp,t;
		char *ch;
		char *h;
		
		//m0=extra, m1=rumah m2=toko
		for (i=2; i>=0; i--){
			for (j=0; j<=2; j++){
				input>>ch; 
				// *h=ch[0];
				// s=atoi(h);
				// *h=ch[1];
				// b=atoi(h);
				// *h=ch[2];
				// jp=atoi(h);
				// *h=ch[3];
				// t=atoi(h);
				// (*am).SetNLFieldXY(2,j,i,s,b,jp,t);
				// //void AllMap::SetNLFieldXY(int m, int x, int y, int S, int B, int J, int T)
			}
		} //membaca toko
		
		for (i=2; i>=0; i--){
			for (j=0; j<=2; j++){
				input>>ch; 
				*h=ch[0];
				s=atoi(h);
				*h=ch[1];
				b=atoi(h);
				*h=ch[2];
				jp=atoi(h);
				*h=ch[3];
				t=atoi(h);
		//		(*am).SetNLFieldXY(1,j,i,s,b,jp,t);
			}
		} //membaca rumah
		
		//extensi lahan
		for (i=0; i<=5; i++){
			input>>ch; 
				*h=ch[0];
				s=atoi(h);
				*h=ch[1];
				b=atoi(h);
				*h=ch[2];
				jp=atoi(h);
				*h=ch[3];
				t=atoi(h);
		//	(*am).SetNLFieldXY(0,i,0,s,b,jp,t);
		}
		//something here
		input.close();
	}
}
	
	/*string IOGame::BrowseFile(bool isOpen){
		//SOMETHING code's here
	}*/

	void IOGame::SearchFile(string namafile, bool& tes){
		try{
			ifstream coba;
			coba.open(namafile.c_str());
			if (!tes){
				throw (char*) "File can't be opened";
			}else{
				coba.close();
			}
		}
		catch(char* err){
			cout<<"Error caught : "<<err<<endl;
		}
		
	}
	
void IOGame::ListFile(){
		DIR *pDIR;
        struct dirent *entry;
        if( pDIR=opendir(".") ){
                while(entry = readdir(pDIR)){
                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
                        cout << entry->d_name << "\n";
                }
                closedir(pDIR);
        }
}
