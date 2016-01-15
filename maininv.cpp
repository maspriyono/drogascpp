#include "player/PLAYER.h"
#include "player/INVENTORY.h"
#include "tanaman/anggur.h"

int main(){
	Player Ucup;
	Ganja *ganja = new Ganja;	
	Anggur *anggur = new Anggur;	
						(Ucup.getInventory())->addItem(ganja, 2);
						(Ucup.getInventory())->addItem(anggur, 2);
						cout<<(Ucup.getInventory())->getAmount1();
						cout<<((Ucup.getInventory())->getSlot1())->getID();
						

return 0;
}
