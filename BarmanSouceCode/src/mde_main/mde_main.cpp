/*
 * mde_main.cpp
 *
 *  Created on: 31 oct. 2024
 *      Author: i_val
 */

#include "Defines.h"

extern TIMERSW 	Timer1;
extern TIMERSW 	Timer2;

#define 		ESTADOELEGIR0			0
#define 		ESTADOELEGIR1			1
#define 		ESTADOELEGIR2	 		2
#define 		ESTADOELEGIR3 			3
#define 		ESTADOELEGIR4 			4
#define 		RETENCION				6

uint32_t 		ESTADOELEGIR			= ESTADOELEGIR0;

uint8_t			flag_tarjeta_id 		= 0;
uint8_t 		mostrarDisplay 			= 1;
//uint16_t 		contCambioDeEstado 		= 0;
uint8_t 		contadorBalanza 		= 0;
uint8_t 		flag_infrarrojo			= 1;
uint8_t			flag_terminado			= 1;
float 			pesoFiltrado 			= 0;

uint8_t 		TarjetaID[16];
uint8_t 		tarjeta 				= 0;

float	 		tara_balanza;
int32_t 		peso;
float 			peso1;

Gpio 			bombaNaranja			(PINBOMBA1,SALIDA);
Gpio 			bombaCampari			(PINBOMBA2,SALIDA);
Gpio 			bombaVodka				(PINBOMBA3,SALIDA);
Gpio 			bombaRon				(PINBOMBA4,SALIDA);

HX711 			hx711					(0,16,0,17);

Gpio 			sensor_infrarojo		(PINSENSORINFRAROJO,ENTRADA);

enum liquido {
	Ninguna = 0,
	Naranja,
	Campari,
	Vodka,
	Ron
};


/* 	MÁQUINA DE ESTADOS MAIN */

void Maq_Estado(void){

    switch(ESTADOELEGIR){

		case ESTADOELEGIR0:		
			estadoelegir0();
			break;

		case ESTADOELEGIR1:
			estadoelegir1();
			break;

		case ESTADOELEGIR2:
			estadoelegir2();
			break;

		case ESTADOELEGIR3:
			estadoelegir3();
			break;

		case ESTADOELEGIR4:
			estadoelegir4();
			break;

		case RETENCION:
			BuscandoDB();
			break;

		default:
			return;
    }
}


void estadoelegir0(void)			// estado inicial
{   
	if (mostrarDisplay) Inicio();					// muestra cartel de "Bienvenido a Barman"

    tarjeta = showSerialNumber(TarjetaID);	// si detecta tarjeta y la manda a buscarBebidaActivar me cambia

	if(tarjeta)
	{
		buscarBebidaActivar(TarjetaID);
		ESTADOELEGIR = RETENCION;
		mostrarDisplay = 1;
	}
}

void BuscandoDB()
{
	if (mostrarDisplay) {									// muestra una sola vez
		MostrarPorDisplay(1,0,0,(uint8_t*) "Buscando");
		MostrarPorDisplay(0,1,0,(uint8_t*) TarjetaID);
		mostrarDisplay = 0;
	}

    if (flag_tarjeta_id != 0){
    	ESTADOELEGIR=ESTADOELEGIR1;
    	mostrarDisplay = 1;
    }
}				// hasta aca viene bien :thumbsup:

void estadoelegir1(){
    if(flag_tarjeta_id == 111)// caso error
    {
    	if (mostrarDisplay){
			MostrarPorDisplay(1,0,0,(uint8_t*) "Tarjeta invalida");
			Timer1.Start(1000*3,0,VolverAEstado0);
			mostrarDisplay = 0;
    	}
    }

    if(flag_tarjeta_id != 111 && flag_tarjeta_id != 0)
    {
    	if(flag_tarjeta_id==1){
			MostrarPorDisplay(1,0,0,(uint8_t*)"Trago: campari");
    	}
    	if(flag_tarjeta_id==2){
			MostrarPorDisplay(1,0,0,(uint8_t*)"Trago: ron");
    	}
    	if(flag_tarjeta_id==3){
			MostrarPorDisplay(1,0,0,(uint8_t*)"Trago: vodka");
    	}

		MostrarPorDisplay(0,1,0,(uint8_t*)"Apoye el vaso");		// sin limpiar, renglon de abajo

		ESTADOELEGIR = ESTADOELEGIR2;
    }
}


void estadoelegir2(){
	if(detectarVaso()){
		if(flag_infrarrojo==1){
			flag_infrarrojo=0;
			Timer2.Start(3000,0,cambioEstado3);
			mostrarDisplay = 1;
		}
	}
}

void cambioEstado3 (void) {
	tara_balanza = calibracion();
	MostrarPorDisplay(1,0,0,(uint8_t*)"Sirviendo...");
	ESTADOELEGIR=ESTADOELEGIR3;
}


void estadoelegir3(){
	if(detectarVaso()){			//para que no saque el vaso

	    switch(flag_tarjeta_id){
	    case 1:
	    	llenarCampari();
	    	break;
	    case 2:
	    	llenarRon();
	    	break;
	    case 3:
	    	llenarVodka();
	    	break;
	    default:
			if (mostrarDisplay){
				MostrarPorDisplay(1,0,0,(uint8_t*)"Bebida invalida");
				Timer1.Start(1000*3,0,VolverAEstado0);
				mostrarDisplay = 0;
			}
	    }
	}else{	
		if (mostrarDisplay){
				MostrarPorDisplay(1,0,0,(uint8_t*)"Vaso Retirado");
				Timer1.Start(1000*3,0,VolverAEstado0);
				mostrarDisplay = 0;
		}
	}
}


uint8_t detectarVaso(void){
	return !sensor_infrarojo.Read();
}

float calibracion(void){
	int32_t tara;
	float tara1;
if (hx711.isReady()) {
			tara = (hx711.read());
		}
	tara1 = (float)((929.0 / 100000.0) * tara);
	return tara1;
}

void llenarCampari(void){

	if (hx711.isReady())
		{
			peso = (hx711.read());
			peso1 = (float)((((929.0 / 100000.0) * peso) - tara_balanza)/10);

			if(contadorBalanza<5)
			{
				contadorBalanza++;
				if((peso1 > 100 + (pesoFiltrado/contadorBalanza)) || (peso1 < (pesoFiltrado/contadorBalanza) - 100))
				{
					contadorBalanza--;
				}else
				{

					pesoFiltrado += peso1;
					if(contadorBalanza>=5)
					{

						pesoFiltrado /= 5;
						contadorBalanza=0;

						if(pesoFiltrado<=60)
						{					//30% del vaso
							EncenderBombas(Campari);
						}
						if((pesoFiltrado<200) && (pesoFiltrado>60)){					//100% del vaso
							EncenderBombas(Naranja);
						}

						if(pesoFiltrado>200)
						{					//100% del vaso
							EncenderBombas(Ninguna);
							ESTADOELEGIR=ESTADOELEGIR4;
						}
					}
				}
			}
		}

}
//void llenarRon(void){
//	if (hx711.isReady()) {
//		peso = (hx711.read());
//		peso1 = (float)((((929.0 / 100000.0) * peso) - tara_balanza)/10);
//
//		if(contadorBalanza < 10) {
//			contadorBalanza++;
//			if((peso1 > 50 + (pesoFiltrado/contadorBalanza)) || (peso1 < (pesoFiltrado/contadorBalanza) - 50))
//			{
//				contadorBalanza--;
//			}else
//			{
//				pesoFiltrado += peso1;
//				if(contadorBalanza>=10) {
//
//					pesoFiltrado 	/= 	10;
//					contadorBalanza	=	0;
//
//
//					if(pesoFiltrado<=60){
//						EncenderBombas(Ron);
//					}
//					if((pesoFiltrado<200) && (pesoFiltrado>60)){
//						EncenderBombas(Naranja);
//					}
//					if(pesoFiltrado>200){
//						EncenderBombas(Ninguna);
//						ESTADOELEGIR=ESTADOELEGIR4;
//					}
//				}
//			}
//		}
//	}
//}


void llenarRon(void)
{
	if (hx711.isReady())
	{
		peso = (hx711.read());
		peso1 = (float)((((929.0 / 100000.0) * peso) - tara_balanza)/10);

		if(contadorBalanza<5)
		{
			contadorBalanza++;
			if((peso1 > 100 + (pesoFiltrado/contadorBalanza)) || (peso1 < (pesoFiltrado/contadorBalanza) - 100))
			{
				contadorBalanza--;
			}else
			{

				pesoFiltrado += peso1;
				if(contadorBalanza>=5)
				{

					pesoFiltrado /= 5;
					contadorBalanza=0;

					if(pesoFiltrado<=60)
					{					//30% del vaso
						EncenderBombas(Ron);
					}
					if((pesoFiltrado<200) && (pesoFiltrado>60)){					//100% del vaso
						EncenderBombas(Naranja);
					}

					if(pesoFiltrado>200)
					{					//100% del vaso
						EncenderBombas(Ninguna);
						ESTADOELEGIR=ESTADOELEGIR4;
					}
				}
			}
		}
	}
}




void llenarVodka(void){
	if (hx711.isReady())
		{
			peso = (hx711.read());
			peso1 = (float)((((929.0 / 100000.0) * peso) - tara_balanza)/10);

			if(contadorBalanza<5)
			{
				contadorBalanza++;
				if((peso1 > 100 + (pesoFiltrado/contadorBalanza)) || (peso1 < (pesoFiltrado/contadorBalanza) - 100))
				{
					contadorBalanza--;
				}else
				{

					pesoFiltrado += peso1;
					if(contadorBalanza>=5)
					{

						pesoFiltrado /= 5;
						contadorBalanza=0;

						if(pesoFiltrado<=60)
						{					//30% del vaso
							EncenderBombas(Vodka);
						}
						if((pesoFiltrado<200) && (pesoFiltrado>60)){					//100% del vaso
							EncenderBombas(Naranja);
						}

						if(pesoFiltrado>200)
						{					//100% del vaso
							EncenderBombas(Ninguna);
							ESTADOELEGIR=ESTADOELEGIR4;
						}
					}
				}
			}
		}
}

void estadoelegir4	(void){

	uint8_t vaso = detectarVaso();

	if(vaso){
		if (mostrarDisplay){
			MostrarPorDisplay(1,0,0,(uint8_t*)"Trago terminado");
			MostrarPorDisplay(0,1,0,(uint8_t*)"Retirar vaso");
			mostrarDisplay = 0;
		}
	} else if (!vaso){
		if (flag_terminado){
			Timer2.Start(3000,0,VolverAEstado0); // posible problema
			eliminaPedidoActivar();
			flag_terminado = 0;
		}
	}
}

void MostrarPorDisplay (uint8_t limpiar, uint32_t row, uint32_t col, uint8_t *str){
	if (limpiar)
		LCD_Clear();
	LCD_SetCursor(row, col);
	LCD_WriteString(str);
}

void EncenderBombas (uint8_t accion){
	switch (accion){
		case Naranja:
			bombaNaranja.Set(BOMBAS_ON);
			bombaCampari.Set(BOMBAS_OFF);
			bombaVodka.Set(BOMBAS_OFF);
			bombaRon.Set(BOMBAS_OFF);
			break;
		case Campari:
			bombaNaranja.Set(BOMBAS_OFF);
			bombaCampari.Set(BOMBAS_ON);
			bombaVodka.Set(BOMBAS_OFF);
			bombaRon.Set(BOMBAS_OFF);
			break;
		case Vodka:
			bombaNaranja.Set(BOMBAS_OFF);
			bombaCampari.Set(BOMBAS_OFF);
			bombaVodka.Set(BOMBAS_ON);
			bombaRon.Set(BOMBAS_OFF);
			break;
		case Ron:
			bombaNaranja.Set(BOMBAS_OFF);
			bombaCampari.Set(BOMBAS_OFF);
			bombaVodka.Set(BOMBAS_OFF);
			bombaRon.Set(BOMBAS_ON);
			break;
		default:						// ninguna
			bombaNaranja.Set(BOMBAS_OFF);
			bombaCampari.Set(BOMBAS_OFF);
			bombaVodka.Set(BOMBAS_OFF);
			bombaRon.Set(BOMBAS_OFF);
			break;
	}
}

void Inicio	(void){

	MostrarPorDisplay(1,0,2,(uint8_t*) "Bienvenido al");
	MostrarPorDisplay(0,1,5,(uint8_t*) "Barman");

	EncenderBombas(Ninguna);

	pesoFiltrado		= 0;
	flag_tarjeta_id 	= 0;
	mostrarDisplay 		= 0;
	flag_terminado 		= 1;
	contadorBalanza 	= 0;
	flag_infrarrojo 	= 1;
}

void VolverAEstado0(void){

	EncenderBombas(Ninguna);

	ESTADOELEGIR = ESTADOELEGIR0;
	mostrarDisplay = 1;
}
