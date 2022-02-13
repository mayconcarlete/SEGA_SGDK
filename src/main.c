#include <genesis.h>

static void setUpInit();
static void joystick(u16 joy, u16 changed, u16 state);
static void joystick_inside_loop(u16* x, u16* y, int* screenY);

int main(){
	setUpInit();

	JOY_init();
	JOY_setEventHandler(&joystick);

	// player 1 status without struct
	char up = ".";
	char left = ".";
	char down = ".";
	char right = ".";
	char button_a = ".";
	char button_b = ".";
	char button_c = ".";

	u16 x = 0;
	u16 y = 0;
	u16* xp = &x;
	u16* yp = &y;
	u16 xInit = 0;
	u16 xLimit = 40;
	u16 yInit = 0;
	u16 yLimit = 28;
	int screenY = 0;
	int* screenYPointer = &screenY;
	char p1PositionY[4];
		// VDP_clearTextLine(x);
	while(TRUE){
		VDP_drawText("P1", 1, 27);
		// BMP_showFPS(6);
		sprintf(p1PositionY, "%d", screenY);
		VDP_clearTextLine(0);
		VDP_drawText(p1PositionY, 4 , 27);
		VDP_drawText(".", x, y);

		joystick_inside_loop(xp, yp, screenYPointer);
		// VDP_drawText(".", x, y);
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
	if(joy == JOY_1){
		if(state & BUTTON_START){
			VDP_clearTextLine(5); // apagara os texto da linha indicada, se nao colocar podera ocorrer sobreposicao
			VDP_drawText("Start Button was pressed", 3, 5);
		} else if (changed & BUTTON_START){
			VDP_clearTextLine(5); // apagara os texto da linha indicada, se nao colocar podera ocorrer sobreposicao
			VDP_drawText("Start Button was liberated", 3, 5);
		}
		if(state & BUTTON_UP){
			VDP_clearTextLine(5);
			VDP_drawText("Button up was pressed", 3, 5);
		} else if (changed & BUTTON_UP){
			VDP_clearTextLine(5);
			VDP_drawText("Button up was liberated", 3, 5);
		}
		if(state & BUTTON_DOWN){
			VDP_clearTextLine(5);
			VDP_drawText("Button Down was pressed", 3, 5);
		} else if (changed & BUTTON_DOWN){
			VDP_clearTextLine(5);
			VDP_drawText("Button Down was liberated", 3, 5);
		}
		if(state & BUTTON_LEFT){
			VDP_clearTextLine(5);
			VDP_drawText("Button Left was pressed", 3, 5);
		} else if (changed & BUTTON_LEFT){
			VDP_clearTextLine(5);
			VDP_drawText("Button Left was liberated", 3, 5);
		}
		if(state & BUTTON_RIGHT){
			VDP_clearTextLine(5);
			VDP_drawText("Button Right was pressed", 3, 5);
		} else if (changed & BUTTON_RIGHT){
			VDP_clearTextLine(5);
			VDP_drawText("Button Right was liberated", 3, 5);
		}
		if(state & BUTTON_A){
			VDP_clearTextLine(5);
			VDP_drawText("Button A was pressed", 3, 5);
		} else if (changed & BUTTON_A){
			VDP_clearTextLine(5);
			VDP_drawText("Button A was liberated", 3, 5);
		}
		if(state & BUTTON_B){
			VDP_clearTextLine(5);
			VDP_drawText("Button B was pressed", 3, 5);
		} else if (changed & BUTTON_B){
			VDP_clearTextLine(5);
			VDP_drawText("Button B was liberated", 3, 5);
		}
		if(state & BUTTON_C){
			VDP_clearTextLine(5);
			VDP_drawText("Button C was pressed", 3, 5);
		} else if (changed & BUTTON_C){
			VDP_clearTextLine(5);
			VDP_drawText("Button C was liberated", 3, 5);
		}
	}
}

static void joystick_inside_loop(u16* x, u16* y,int* screenY){
	u16 value = JOY_readJoypad(JOY_1);
	char str[16];
	int off_set_up_button = 7;
	if(value & BUTTON_UP && ((*y) > -1)){
		VDP_clearTextLine(*y);
		VDP_drawText(".", *x, --(*y));
		--(*screenY);
		VDP_clearText(off_set_up_button, 27, 1);
		VDP_drawText("^", off_set_up_button, 27);
	} else{
		VDP_clearText(off_set_up_button, 27, 1);
		VDP_drawText(".", off_set_up_button, 27);
	}
	if(value & BUTTON_DOWN && ((*y) > 208)){
		VDP_clearTextLine(*y);
		VDP_drawText(".", *x, ++(*y));
		++(*screenY);
		VDP_clearText(off_set_up_button + 2, 27, 1);
		VDP_drawText("d", off_set_up_button + 2 , 27);
	} else {
		VDP_clearText(off_set_up_button + 2, 27, 1);
		VDP_drawText(".", off_set_up_button +2 , 27);
	}
	if(value & BUTTON_LEFT){
		VDP_clearTextLine(*y);
		VDP_drawText(".", --(*x), *y);
		VDP_clearText(off_set_up_button + 1, 27, 1);
		VDP_drawText("<", off_set_up_button +1 , 27);
	} else {
		VDP_clearText(off_set_up_button + 1, 27, 1);
		VDP_drawText(".", off_set_up_button + 1, 27);
	}

	if(value & BUTTON_RIGHT){
		VDP_clearTextLine(*y);
		VDP_drawText(".", ++(*x), *y);
		VDP_clearText(off_set_up_button + 3, 27, 1);
		VDP_drawText(">", off_set_up_button + 3, 27);
	} else {
		VDP_clearText(off_set_up_button + 3, 27, 1);
		VDP_drawText(".",  off_set_up_button + 3, 27);
	}
	if(value & BUTTON_A){
		VDP_clearTextLine(0);
		VDP_drawText("Button A was pressed", 0, 0);
	}
};