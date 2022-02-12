#include <genesis.h>

int main(){
	char textScreen[26] = "Maycon Carlete Hello world";

	SYS_disableInts();
	VDP_init();
	SPR_init();
	VDP_setScreenWidth320();
	VDP_setScreenHeight224();

	while(TRUE){
		VDP_drawText(textScreen, 10, 10);
		SYS_doVBlankProcess();
	}
	return 0;
}