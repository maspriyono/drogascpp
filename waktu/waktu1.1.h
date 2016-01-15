//FIle : waktu.h
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#ifndef waktu_H
#define waktu_H
class waktu
{
public:
	//konstruktor kelas waktu
	waktu();
	//konstruktor lain kelas waktu
	//HH : tanggal, BB : bulan, MU : musim, JJ : jam, MM : menit
	waktu(int HH,int BB,int MU,int JJ,int MM);
	//copy konstruktor	
	waktu(const waktu&);
	
	//destruktor
	//destruktor waktu
	~waktu();
	
	//keterangan:
	//musim semi = 1
	//musim badai = 2
	//musim gugur = 3
	//musim penghujan = 4
	
	//method Get dan Set
	//mengambil keterangan tanggal
	int GetHH();
	//mengambil keterangan bulan
	int GetBB();
	//mengambil keterangan musim
	int GetMU();
	//mengambil keterangan jam
	int GetJJ();
	//mengambil keterangan menit
	int GetMM();
	//mengembalikan jenis bencana
	int GetBencana();
	//mengambil keterangan seluruh waktu
	int GetMusim();
	//mengambil keterangan counter bencana hujan
	int GetHujan();
	//mengambil keterangan counter bencana hujan
	int GetTopan();
	//mengambil keterangan counter bencana hujan
	int GetRazia();
	//mengambil keterangan counter bencana hujan
	int GetCC();
	//mengatur isi tanggal
	void SetHH(int NewHH);
	//mengatur isi bulan
	void SetBB(int NewBB);
	//mengatur isi musim
	void SetMU(int NewMU);
	//mengatur isi jam
	void SetJJ(int NewJJ);
	//mengatur isi menit
	void SetMM(int NewMM);
	//mengatur isi bencana
	void SetBencana(int NewBencana);
	
	//mehod lain yang berhubungan dengan jam
	//inisialisasi waktu mulai permainan
	void waktuMulai();
	//inisialisasi waktu bencana
	void initBencana();
	//penambah setiap satuan aksi dalam kondisi normal (1 aksi = 1 satuan waktu)
	void penambahWktNormal();
	//1 aksi = 2 satuan waktu
	void penambahWktCepat();
	//1 aksi = 1/2 satuan waktu
	void penambahWktLambat();
	//prosedur tidur
	void sleep();
	//menyimpan informasi mengenai musim
	int musim();
	//pengganti musim setiap 3 x 30 hari
	void gantiMusim();
	//ganti bulan
	void gantiBulan();
	//menampilkan waktu
	void printWaktu();
	//penyebab bencana
	void bencana();
	//menampilkan bencana apa saja yang terjadi dalam satu tahun
	void printBencana();
	
	//predikat MUSIM
	//musim semi
	int isSemi();
	//musim badai
	int isBadai();
	//musim gugur
	int isGugur();
	//musim penghujan
	int isPenghujan();
	//sedang hujan
	int isHujan();
	//sedang topan
	int isTopan();
	//sedang razia
	int isRazia();
	//sedang crop circle
	int isCropCircle();
	//method menghitung terjadinya bencana
	void countBencana();
	//buat menginisialisasi counter
	void resetCounter();
		//method gejala alam
		//Hujan. tanaman tidak perlu lagi disiram
		void Hujan();
		//ada angin topan (random). tanaman akan rusak secara random
		void Topan();
		//ada razia, jika membayar polisi yang sedang merazia, maka tanaman yang sedang ditanam tidak akan diambil. jika sebaliknya, maka tanaman akan diambil.
		void Polisi();
		//crop circle. beberapa tanaman akan rusak di beberapa tempat tertentu
		void cropCircle();
private:
	int tgl, bln,msm, jam, mnt; //tanggal, bulan , musim, jam, menit
	int bnc; //current bencana
	int tglb, blnb, msmb, jamb, mntb; //waktu terjadinya crop circle
	int tglh, blnh, msmh, jamh, mnth; //waktu terjadinya hujan
	int tglr, blnr, msmr, jamr, mntr; //waktu terjadinya razia polisi
	int tglt, blnt, msmt, jamt, mntt; //waktu terjadinya topan
	int cb, ch, cr, ct; //counter cropcircle, hujan, razia, atau topan
};
#endif
