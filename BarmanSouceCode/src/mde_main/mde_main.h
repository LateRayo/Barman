/*
 * mde_main.h
 *
 *  Created on: 31 oct. 2024
 *      Author: i_val
 */

#ifndef MDE_MAIN_MDE_MAIN_H_
#define MDE_MAIN_MDE_MAIN_H_

#define OFF 				0
#define ON 					1

#define	BOMBAS_ON			0
#define BOMBAS_OFF			1

#define	ON_BOMBAS			0
#define OFF_BOMBAS			1



#define ENTRADA 			0
#define SALIDA 				1

// 							SALIDAS
#define PINBOMBA1 			1,0		// ok DIG_OUT0
#define PINBOMBA2 			1,1		// ok DIG_OUT1
#define PINBOMBA3 			1,2		// ok DIG_OUT2
#define PINBOMBA4 			0,7	// ok DIG_OUT3

//							ENTRADAS
//#define PINPULSADOR1		0,5
//#define PINPULSADOR2		0,6

#define PINSENSORINFRAROJO 	0,19

//#define PINBALANZA 			0,9

void Reset 				(void);		//volver al est 0 de la maquina de estados principal
void cambioEstado2 		(void);


void Maq_Estado			(void);
void estadobienvenido	(void);
void estadoelegir0		(void);
void estadoelegir1		(void);
void estadoelegir2		(void);
void estadoelegir3		(void);
void estadoelegir4		(void);
void BuscandoDB();
void VolverAEstado0();
uint8_t detectarVaso	(void);
float calibracion		(void);

void llenarCampari  (void);
void llenarRon		(void);
void llenarVodka	(void);

void MostrarPorDisplay  (uint8_t, uint32_t, uint32_t, uint8_t*);

void Inicio         (void);
void EncenderBombas (uint8_t);

void cambioEstado3 (void);




#endif /* MDE_MAIN_MDE_MAIN_H_ */
