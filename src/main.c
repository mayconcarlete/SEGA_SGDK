#include <genesis.h>

static void setUpInit();
static void joystick(u16 joy, u16 changed, u16 state);

int main(){
	char textScreen[26] = "Maycon Carlete Hello world";

	setUpInit();

	JOY_init();
	JOY_setEventHandler(&joystick);

	while(TRUE){
		VDP_drawText(textScreen, 10, 10);
		SYS_doVBlankProcess();
	}
	return 0;
}

void setUpInit(){
	SYS_disableInts(); // desabilita Interrupt quando acessa a vdp
	VDP_init(); // inicia Processador de video VDP e estabelece a resolucao de tela 320x224
	SPR_init();
	VDP_setScreenWidth320();
	VDP_setScreenHeight224();
	SYS_enableInts(); // reabilita Interrupts quando finalizar acesso VDP
}

void joystick(u16 joy, u16 changed, u16 state){
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