#include "waktu1.1.h"
#include <iostream>
using namespace std;
//konstruktor kelas waktu
	waktu::waktu(){}
	//konstruktor lain kelas waktu
	//HH : tanggal, BB : bulan, MU : musim, JJ : jam, MM : menit
	waktu::waktu(int HH,int BB,int MU,int JJ,int MM ){
		tgl = HH;
		bln = BB;
		msm = MU;
		jam = JJ;
		mnt = MM;
	}
	//copy konstruktor	
	waktu::waktu(const waktu&){}
	
	//destruktor
	//destruktor waktu
	waktu::~waktu(){}
	
	//keterangan:
	//musim semi = 1
	//musim badai = 2
	//musim gugur = 3
	//musim penghujan = 4
	
	//method Get dan Set
	//mengambil keterangan tanggal
	int waktu::GetHH(){
		return tgl;
	}
	//mengambil keterangan bulan
	int waktu::GetBB(){
		return bln;
	}
	//mengambil keterangan musim
	int waktu::GetMU(){
		return msm;
	}
	//mengambil keterangan jam
	int waktu::GetJJ(){
		return jam;
	}
	//mengambil keterangan menit
	int waktu::GetMM(){
		return mnt;
	}
	//mengembalikan jenis bencana
	int waktu::GetBencana(){
		return bnc;
	}
	//mengambil keterangan seluruh waktu
	int waktu::GetMusim(){
		if(msm==1){
			return 1;
		}
		if(msm==2){
			return 2;
		}
		if(msm==3){
			return 3;
		}
		if(msm==4){
			return 4;
		}
	}
	//mengambil keterangan counter bencana hujan
	int waktu::GetHujan(){
		return ch;
	}
	//mengambil keterangan counter bencana topan
	int waktu::GetTopan(){
		return ct;
	}
	//mengambil keterangan counter bencana razia
	int waktu::GetRazia(){
		return cr;
	}
	//mengambil keterangan counter bencana crop circle
	int waktu::GetCC(){
		return cb;
	}
	//mengatur isi tanggal
	void waktu::SetHH(int NewHH){
		tgl = NewHH;
	}
	//mengatur isi bulan
	void waktu::SetBB(int NewBB){
		bln = NewBB;
	}
	//mengatur isi musim
	void waktu::SetMU(int NewMU){
		msm = NewMU;
	}
	//mengatur isi jam
	void waktu::SetJJ(int NewJJ){
		jam = NewJJ;
	}
	//mengatur isi menit
	void waktu::SetMM(int NewMM){
		mnt = NewMM;
	}
	//mengatur isi bencana
	void waktu::SetBencana(int NewBencana){
		bnc = NewBencana;
	}
	
	//mehod lain yang berhubungan dengan jam
	//inisialisasi waktu mulai permainan
	void waktu::waktuMulai(){
		SetHH(1);
		SetBB(1);
		SetMU(1);
		SetJJ(4);
		SetMM(0);
	}
	//inisialisasi waktu bencana
	void waktu::initBencana(){
		tglb=1; blnb=1; msmb=1; jamb=1; mntb=1; //waktu terjadinya crop circle
		tglh=1; blnh=1; msmh=1; jamh=1; mnth=1; //waktu terjadinya hujan
		tglr=1; blnr=1; msmr=1; jamr=1; mntr=1; //waktu terjadinya razia polisi
		tglt=1; blnt=1; msmt=1; jamt=1; mntt=1;
	}
	//penambah setiap satuan aksi dalam kondisi normal (1 aksi = 1 satuan waktu)
	void waktu::penambahWktNormal(){
	if(mnt==30){
			if(jam == 23){
				if(tgl == 30){
					if((bln % 3) == 0){
//						sleep();
						jam = 4;
						mnt = 0;
						tgl=1;
						gantiBulan();
						gantiMusim();
					}else{
				//		sleep();
						jam =4;
						mnt = 0;
					tgl=1;
						gantiBulan();
					}
				}else{
	//				sleep();
					jam=4;
					mnt=0;
					tgl=tgl+1;
				}
			}else{
				jam=jam+1;
				mnt=0;
			}
		}else{
			mnt=mnt+30;
		}

}
	//1 aksi = 2 satuan waktu
	void waktu::penambahWktCepat(){
		if(mnt==30){
			if(jam == 23){
				if(tgl == 30){
					if((bln % 3) == 0){
					//	sleep();
		jam = 4;
		mnt = 0;
						tgl=1;
						gantiBulan();
						gantiMusim();
					}else{
					//	sleep();
						jam=4;
						mnt=0;
						tgl=1;
						gantiBulan();
					}
				}else{
				//	sleep();
					jam=4;
					mnt=0;
					tgl=tgl+1;
				}
			}else{
				jam=jam+1;
			}
		}else{
			jam=jam+1;
		}
	}
	
	//1 aksi = 1/2 satuan waktu
	void waktu::penambahWktLambat(){
		if(mnt==45){
			if(jam == 23){
				if(tgl == 30){
					if((bln % 3) == 0){
					//	sleep();
						jam =4;
						mnt = 0;
						tgl=1;
						gantiBulan();
						gantiMusim();
					}else{
//						sleep();
						jam =4;
						mnt = 0;
						tgl=1;
						gantiBulan();
					}
				}else{
					sleep();
					jam =4;
					mnt = 0;
					tgl=tgl++;
				}
			}else{
				jam=jam++;
				mnt=0;
			}
		}else{
			mnt=mnt+15;
		}
	}
	//prosedur tidur
	void waktu::sleep(){
		if(tgl == 30){
			if((bln % 3) == 0){
				//	sleep();
					jam =4;
					mnt = 0;
					tgl=1;
					gantiBulan();
					gantiMusim();
			}else{
//					sleep();
					jam =4;
					mnt = 0;
					tgl=1;
					gantiBulan();
			}
		}//		cout << "sedang tidur. Akan bangun lagi pada 04.00 A.M." << endl;
		else{
					jam =4;
					mnt = 0;
					tgl=tgl+1;
				}
	}
	//pengganti musim setiap 3 x 30 hari
	void waktu::gantiMusim(){
		if (msm<4){
			msm=msm+1;
		}else{
			msm=1;
		}
	}
	void waktu::gantiBulan(){
		if(bln<12){
			bln=bln+1;
		}else{
			bln=1;
		}
	}
	//menampilkan waktu
	void waktu::printWaktu(){
		cout << tgl << "/" << bln << "/" << msm << "," << jam << ":" << mnt << endl;
	}
	//penyebab bencana
	void waktu::bencana(){
		if ((tgl==1)&&(bln==1)&&(msm==1)&&(jam==4)&&(mnt==0)){
			resetCounter();
		}
		Hujan();
		Topan();
		Polisi();
		cropCircle();
		if (isHujan()){
			SetBencana(0);
			ch=ch+1;
//			cout << "HUUUUUJAAAAAAAAAANNNNNN!!!" << endl;
		}
		if (isTopan()){
			SetBencana(1);
			ct=ct+1;
//			cout << "TOPAAAAAAAAAAAAAAANNNNNNN!!" << endl;
		}
		if (isRazia()){
			SetBencana(2);
			cr=cr+1;
//			cout << "KAMTIIIIIIIIIIIIIIIIIIBBBBBBBBBBBBBBBBBB!!!!" << endl;
		}
		if (isCropCircle()){
			SetBencana(3);
			cb=cb+1;
//			cout << "ALIEEEEEEEEEEEEEEEEEEEEENNNNNNNNNN!!!!" << endl;
		}
	}
	//menampilkan bencana apa saja yang terjadi dalam satu tahun
	void waktu::printBencana(){
		char c;
		cout << tglb << "/" << blnb << "/" << msm << "," << jamb << ":" << mntb << endl;
	}
	
	//predikat MUSIM
	//musim semi
	int waktu::isSemi(){
		return ((msm==1)&&((bln==1)||(bln==2)||(bln==3)));
	}
	//musim badai
	int waktu::isBadai(){
		return (msm==2&&((bln==4)||(bln==5)||(bln==6)));
	}
	//musim gugur
	int waktu::isGugur(){
		return (msm==3&&((bln==7)||(bln==8)||(bln==9)));
	}
	//musim penghujan
	int waktu::isPenghujan(){
		return (msm==4&&((bln==10)||(bln==11)||(bln==12)));
	}
	//buat menginisialisasi counter
	void waktu::resetCounter(){
		cb = 0;
		ch = 0;
		cr = 0;
		ct = 0;
	}
		//method gejala alam
		//Hujan. tanaman tidak perlu lagi disiram
		void waktu::Hujan(){
			srand(time(NULL));
			int next;
			next = rand() % 4;
				tglh=12+next;
				mnth=mnt;
				blnh=3;
				jamh=jam;
				mnth=mnt;
		}
		//ada angin topan (random). tanaman akan rusak secara random
		void waktu::Topan(){
			int next;
			srand(time(NULL));
			next = rand() % 3;
			tglt = tgl+next;
			mntt=mnt;
			blnt=2;
			jamt=11;
			msmt=2;
		}
		//ada razia, jika membayar polisi yang sedang merazia, maka tanaman yang sedang ditanam tidak akan diambil. jika sebaliknya, maka tanaman akan diambil.
		void waktu::Polisi(){
			srand(time(NULL));
			int next;
			next = rand() % 2;
			tglr = tglr+next;
			jamr=10;
			mnt=30;
			}
		//crop circle. beberapa tanaman akan rusak di beberapa tempat tertentu
		void waktu::cropCircle(){
			srand (time(NULL));
			int next;
			next = rand() % 2;
			blnb = bln+next;
			tglb = 13;
		}
		
	//PREDIKAT untuk bencana
	//sedang hujan
	int waktu::isHujan(){
		return (((tgl == tglh)&&(bln==blnh))||(bln == blnh)||(tgl==tglh));
	}
	//sedang topan
	int waktu::isTopan(){
		return (((tgl==tglt)&&(jam==jamt))||((tgl==tglt)&&(bln==blnt)&&(msm==msmt)));
	}
	//sedang razia
	int waktu::isRazia(){
		return(tgl==tglr);
	}
	//sedang crop circle
	int waktu::isCropCircle(){
		return ((tgl==tglb)&&(bln==blnb));
	}
	
