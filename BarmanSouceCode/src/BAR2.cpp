#include "Defines.h"


SYSTICK Systick(1000);
TIMERSW Timer2;


extern void EncenderBombas(uint8_t);
void Init (void);



int main(void) {

	Init();

    while(1)
    {
    	//maquinaDeEstadosRecepcionUart();
    	//conectarseWifi();
    	buscarBebida();
    	eliminarPedido();

    	Maq_Estado();
    }
    return 0 ;
}


void Init (void){

	EncenderBombas(0);		// apago todas las bombas

	LCD_Init();
	LCD_Clear();

	UART0_Init(9600);
}
