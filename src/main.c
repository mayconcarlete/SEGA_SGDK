#include <genesis.h>

static void setUpInit();

int main(){
	char textScreen[26] = "Maycon Carlete Hello world";
	setUpInit();
	while(TRUE){
		VDP_drawText(textScreen, 10, 10);
		SYS_doVBlankProcess();
	}
	return 0;
}

static void setUpInit(){
	SYS_disableInts();
	VDP_init();
	SPR_init();
	VDP_setScreenWidth320();
	VDP_setScreenHeight224();
}