#include <iostream>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

int main(){
	mciSendString("open C:\\Users\\TOSHIBA\\Desktop\\produk\\test.mp3 type mpegvideo alias song1",NULL,0,0);
	mciSendString("open C:\\Users\\TOSHIBA\\Desktop\\produk\\monkey.wav type mpegvideo alias song2",NULL,0,0);
	mciSendString("play song1",NULL,0,0);
	mciSendString("play song2",NULL,0,0);
	int a;
	cin>>a;
	cout<<a<<endl;
	mciSendString("pause song1",NULL,0,0);
	cin>>a;
	cout<<a<<endl;
	mciSendString("play song1",NULL,0,0);
	cin>>a;
	cout<<a<<endl;
	// int a;
	// PlaySound("test.wav",NULL,SND_LOOP|SND_ASYNC);
	// cout << "insert a : " ;
	// cin >> a;
	// cout << "a : " << a << endl;
	// cout << "insert a : " ;
	// cin >> a;
	// cout << "a : " << a << endl;
	// cout << "insert 23 to stop music : " ;
	// cin >> a;
	// if (a==23)
	// {
		// PlaySound(NULL,0,0);
		// cout << "music stopped" << endl;
	// }
	// cout << "insert a : " ;
	// cin >> a;
	// cout << "Monkey!!!" << endl;
	// PlaySound("monkey.wav",NULL,SND_SYNC);
	// cout << "insert a : " ;
	// cin >> a;
	// cout << "a : " << a << endl;
	return 0;
}