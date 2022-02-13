#include <genesis.h>

static void setUpInit();
static void joystick(u16 joy, u16 changed, u16 state);
static void setDevHUD();
static void showFps();
// static void joystick_inside_loop(u16* x, u16* y, int* screenY);

int main(){
	setUpInit();

	JOY_init();
	setDevHUD();
	JOY_setEventHandler(&joystick);

	while(TRUE){
		// BMP_showFPS(3);
		showFps();
		SYS_doVBlankProcess();
	}
	return 0;
}

static void setUpInit(){
	SYS_disableInts(); // desabilita Interrupt quando acessa a vdp
	VDP_init(); // inicia Processador de video VDP e estabelece a resolucao de tela 320x224
	SPR_init();
	VDP_setScreenWidth320();
	VDP_setScreenHeight224();
	SYS_enableInts(); // reabilita Interrupts quando finalizar acesso VDP
}

static void joystick(u16 joy, u16 changed, u16 state){
	int off_set_up_button = 3;
	if(joy == JOY_1){
		if(state & BUTTON_UP){
			VDP_clearText(off_set_up_button, 26, 1);
			VDP_drawText("^", off_set_up_button, 26);
		} else if (changed & BUTTON_UP){
			VDP_clearText(off_set_up_button, 26, 1);
			VDP_drawText(".", off_set_up_button, 26);
		}
		if(state & BUTTON_DOWN){
			VDP_clearText(off_set_up_button + 1, 26, 1);
			VDP_drawText("D", off_set_up_button + 1, 26);
		} else if (changed & BUTTON_DOWN){
			VDP_clearText(off_set_up_button + 1, 26, 1);
			VDP_drawText(".", off_set_up_button + 1, 26);
		}
		if(state & BUTTON_LEFT){
			VDP_clearText(off_set_up_button + 2, 26, 1);
			VDP_drawText("<", off_set_up_button + 2, 26);
		} else if (changed & BUTTON_LEFT){
			VDP_clearText(off_set_up_button + 2, 26, 1);
			VDP_drawText(".", off_set_up_button + 2,  26);
		}
		if(state & BUTTON_RIGHT){
			VDP_clearText(off_set_up_button + 3, 26, 1);
			VDP_drawText(">", off_set_up_button + 3, 26);
		} else if (changed & BUTTON_RIGHT){
			VDP_clearText(off_set_up_button + 3, 26, 1);
			VDP_drawText(".", off_set_up_button + 3, 26);
		}
		if(state & BUTTON_START){
			// VDP_clearTextLine(5);  apagara os texto da linha indicada, se nao colocar podera ocorrer sobreposicao
			VDP_clearText(off_set_up_button + 4, 26, 1);
			VDP_drawText("S", off_set_up_button + 4 , 26);
		} else if (changed & BUTTON_START){
			VDP_clearTextLine(5); // apagara os texto da linha indicada, se nao colocar podera ocorrer sobreposicao
			VDP_drawText(".", off_set_up_button + 4, 26);
		}
		if(state & BUTTON_A){
			VDP_clearText(off_set_up_button + 5, 26, 1);
			VDP_drawText("A", off_set_up_button + 5, 26);
		} else if (changed & BUTTON_A){
			VDP_clearText(off_set_up_button + 5, 26, 1);
			VDP_drawText(".", off_set_up_button + 5, 26);
		}
		if(state & BUTTON_B){
			VDP_clearText(off_set_up_button + 6, 26, 1);
			VDP_drawText("B", off_set_up_button + 6, 26);
		} else if (changed & BUTTON_B){
			VDP_clearText(off_set_up_button + 6, 26, 1);
			VDP_drawText(".", off_set_up_button + 6, 26);
		}
		if(state & BUTTON_C){
			VDP_clearText(off_set_up_button + 7, 26, 1);
			VDP_drawText("C", off_set_up_button + 7, 26);
		} else if (changed & BUTTON_C){
			VDP_clearText(off_set_up_button + 7, 26, 1);
			VDP_drawText(".", off_set_up_button + 7, 26);
		}
	}
}
static void setDevHUD(){
	int off_set_button_up = 3;
	VDP_clearTextLine(27);
	int i;
	VDP_drawText("P1", 1, 26);
	for(i=3; i<11; i++){
		VDP_drawText(".", i ,26);
	}
	VDP_drawText("X:33", 1, 27);
	VDP_drawText("Y:66", 6, 27);
	VDP_drawText("P2", 29 , 27);
	for(i=31; i<39; i++){
		VDP_drawText(".", i ,27);
	}
}

static void showFps(){
    char str[16];
    const u16 y = 1;
    fix32ToStr(SYS_getFPSAsFloat(), str, 1);
		VDP_drawText("FPS:", 14, 27);
    VDP_clearText(18, 27, 4);
		VDP_drawText(str, 18, 27);
}

// static void joystick_inside_loop(u16* x, u16* y,int* screenY){
// 	u16 value = JOY_readJoypad(JOY_1);
// 	VDP_clearTextLine(1);
// 	VDP_drawText()
// 	char str[16];
// 	int off_set_up_button = 7;
// 	if(value & BUTTON_UP && ((*y) > -1)){
// 		VDP_clearTextLine(*y);
// 		VDP_drawText(".", *x, --(*y));
// 		--(*screenY);
// 		VDP_clearText(off_set_up_button, 27, 1);
// 		VDP_drawText("^", off_set_up_button, 27);
// 	} else{
// 		VDP_clearText(off_set_up_button, 27, 1);
// 		VDP_drawText(".", off_set_up_button, 27);
// 	}
// 	if(value & BUTTON_DOWN && ((*y) > 208)){
// 		VDP_clearTextLine(*y);
// 		VDP_drawText(".", *x, ++(*y));
// 		++(*screenY);
// 		VDP_clearText(off_set_up_button + 2, 27, 1);
// 		VDP_drawText("d", off_set_up_button + 2 , 27);
// 	} else {
// 		VDP_clearText(off_set_up_button + 2, 27, 1);
// 		VDP_drawText(".", off_set_up_button +2 , 27);
// 	}
// 	if(value & BUTTON_LEFT){
// 		VDP_clearTextLine(*y);
// 		VDP_drawText(".", --(*x), *y);
// 		VDP_clearText(off_set_up_button + 1, 27, 1);
// 		VDP_drawText("<", off_set_up_button +1 , 27);
// 	} else {
// 		VDP_clearText(off_set_up_button + 1, 27, 1);
// 		VDP_drawText(".", off_set_up_button + 1, 27);
// 	}

// 	if(value & BUTTON_RIGHT){
// 		VDP_clearTextLine(*y);
// 		VDP_drawText(".", ++(*x), *y);
// 		VDP_clearText(off_set_up_button + 3, 27, 1);
// 		VDP_drawText(">", off_set_up_button + 3, 27);
// 	} else {
// 		VDP_clearText(off_set_up_button + 3, 27, 1);
// 		VDP_drawText(".",  off_set_up_button + 3, 27);
// 	}
// 	if(value & BUTTON_A){
// 		VDP_clearTextLine(0);
// 		VDP_drawText("Button A was pressed", 0, 0);
// 	}
// };