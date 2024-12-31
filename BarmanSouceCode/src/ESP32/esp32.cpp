/*
 * esp32.cpp
 *
 *  Created on: 31 oct. 2024
 *      Author: i_val
 */

#include "Defines.h"

#define IP  "192.168.216.121"
TIMERSW Timer1;
TIMERSW BuscarBebidaTimer;
TIMERSW Timer3;

extern int8_t flag_tarjeta_id; // para que esta variable sea global

uint8_t palabra_a_buscar[PALABRA_MAX_TAM]; // Palabra que se va a buscar
uint8_t indice_palabra = 0; // Índice de búsqueda en la palabra
uint8_t flag_palabra_encontrada = 0; // Flag que se activa al encontrar la palabra

uint8_t WifiEstado = 0;
//uint8_t palabraOK[] = { 'O', 'K', '\0' };
Estado estado_actual = INACTIVO;
uint16_t contError = 0;
// variable maquina de estados buscar bebida
uint8_t IDtarjeta[11];

//CString IDtarjeta[11];

uint8_t estadoBebida = 2;

// maquina de estados eliminarPedido
uint8_t estadoEliminar=2;

//uint32_t TimerEsp32 = 0;

void error(void);

void strncpy(uint8_t* dest, const uint8_t* src, size_t n)
{
    // Copia hasta n caracteres de src a dest
    while (n && *src)
    {
        *dest++ = *src++;
        n--;
    }
    // Rellena el resto de dest con '\0' si aún hay espacio
    while (n--)
    {
        *dest++ = '\0';
    }
}

//////////////////////////////////////////////////////////////////


//void conectarseWifi()
//{
//    switch(WifiEstado)
//    {
//        case ESP_WIFI_CONFIGURA_TCP:
//            UART0_Send((uint8_t*)"AT+CWMODE=1\r\n", 0);
//            iniciar_busqueda_palabra((uint8_t*)"OK");
//            Timer1.Start(10000, 0, cambioDeEstado1a0); // 10 segundos
//            WifiEstado = ESP_WIFI_ESPERA_RESPUESTA;
//            break;
//
//        case ESP_WIFI_ESPERA_RESPUESTA:
//            if (flag_palabra_encontrada)
//            {
//                WifiEstado = ESP_WIFI_CONFIGURA_RED;
//                flag_palabra_encontrada = 0;
//                Timer1.Stop();
//            }
//            break;
//
//        case ESP_WIFI_CONFIGURA_RED:
//            UART0_Send((uint8_t*)"AT+CWJAP=\"nicolas\",\"hora14159\"\r\n", 0);//TeleCentro-d942
//            iniciar_busqueda_palabra((uint8_t*)"WIFI GOT IP");
//            Timer3.Start(10000, 0, cambioDeEstado3a2); // 10 segundos
//            WifiEstado = ESP_WIFI_CONECTADO_OK;
//            break;
//
//        case ESP_WIFI_CONECTADO_OK:
//            if (flag_palabra_encontrada)
//            {
//                WifiEstado = ESP_WIFI_ENVIAR_HTTP;
//                flag_palabra_encontrada = 0;
//                Timer3.Stop();
//
//                char buffer[128];
//                sprintf(buffer, "AT+HTTPCLIENT=2,3,\"http://%s:8080/get?msg=conectado\",\"%s\",\"/get\",1\r\n", IP, IP);
//                UART0_Send((uint8_t*)buffer, 0);
//
//                iniciar_busqueda_palabra((uint8_t*)"OK");
//            }
//            break;
//
//        case ESP_WIFI_ENVIAR_HTTP:
//            if (flag_palabra_encontrada)
//            {
//                WifiEstado = ESP_WIFI_FIN;
//            }
//            break;
//
//        case ESP_WIFI_FIN:
//            // Aquí termina la conexión al WiFi
//            break;
//
//        default:
//            WifiEstado = ESP_WIFI_CONFIGURA_TCP;
//            break;
//    }
//}

//////////////////////////////////////////////////////////////////

// Función para inicializar la búsqueda de una palabra
//void iniciar_busqueda_palabra(uint8_t *palabra)
//{
//	uint8_t longitud = strlen(palabra); // Calcula la longitud de la palabra
//    strncpy(palabra_a_buscar, palabra, longitud + 1); // Copia completa incluyendo '\0'
//    indice_palabra = 0;
//    estado_actual = BUSCANDO;
//
//}
//
//
//void maquinaDeEstadosRecepcionUart(void) {
//    switch (estado_actual) {
//        case INACTIVO:
//            break;
//
//        case BUSCANDO: {
//            int32_t dato = UART0_PopRx();
//            if (dato >= 0) {
//                if (dato == palabra_a_buscar[indice_palabra]) {
//                    indice_palabra++;
//                    // Si completamos la búsqueda
//                    if (palabra_a_buscar[indice_palabra] == '\0') {
//                        flag_palabra_encontrada = 1;
//                        estado_actual = ENCONTRADO;
//                    }
//                } else {
//                    // Reiniciar si hay un desajuste
//                    indice_palabra = 0;
//                }
//            }
//        } break;
//
//        case ENCONTRADO:
//            estado_actual = INACTIVO; // Reinicia la búsqueda
//            break;
//    }
//}
//
//void cambioDeEstado1a0(void)
//{
//	WifiEstado = 0;
//}
//
//void cambioDeEstado3a2(void)
//{
//	WifiEstado = 2;
//}

//////////////////////////////////////////////////////////////////
//			TODAVIA FALTAN VERIFICAR

void buscarBebidaActivar(uint8_t *tarjeta)
{
	estadoBebida = 0; // con un 1 la maquina se activa
	strncpy(IDtarjeta, tarjeta, PALABRA_MAX_TAM);

	//IDtarjeta = (CString*) tarjeta;
}


void buscarBebida(){
	switch(estadoBebida)
	{
		case 0:{
			uint8_t comando[150];

			sprintf((char*)comando, "AT+HTTPCLIENT=2,3,\"http://%s:8080/get?IDT=%s\",\"%s\",\"/get\",1\r\n", IP,(char*)IDtarjeta,IP);

			UART0_Send(comando, 0);

			BuscarBebidaTimer.Start(1000*3,0,error);
			estadoBebida = 1;
		break;
		}
		case 1:{
			//+HTTPCLIENT:size,data
			static int32_t  dato=0;
			static int32_t  dato1=0;
			static int32_t  dato2=0;
			dato = UART0_PopRx();
			//letra adelante
			if(dato>0)
			{
				dato2=dato1;
				dato1=dato;
			}

			// se puede hacer un comprobacion para que empieze a contar cuando encuentra el +

			//if (dato > 0) {
				if(dato2 == 'C' && dato1 == 'a')
				{
					estadoBebida = 2;//2
					BuscarBebidaTimer.Stop();
				    char buffer[128]; // Asegúrate de que el tamaño sea suficiente
				    sprintf(buffer, "AT+HTTPCLIENT=2,3,\"http://%s:8080/get?msg=sirviendoCampari\",\"%s\",\"/get\",1\r\n", IP, IP);
				    UART0_Send((uint8_t*)buffer, 0);
					flag_tarjeta_id = 1;
				}

				if(dato2 == 'R' && dato1 == 'o')
				{
					estadoBebida = 2;//2
					BuscarBebidaTimer.Stop();
					char buffer[128]; // Asegúrate de que el tamaño sea suficiente
					sprintf(buffer, "AT+HTTPCLIENT=2,3,\"http://%s:8080/get?msg=sirviendoRon\",\"%s\",\"/get\",1\r\n", IP, IP);
					UART0_Send((uint8_t*)buffer, 0);
					flag_tarjeta_id = 2;
				}
				if(dato2 == 'V' && dato1 == 'o')
				{
					estadoBebida = 2;//2
					BuscarBebidaTimer.Stop();
					char buffer[128]; // Asegúrate de que el tamaño sea suficiente
					sprintf(buffer, "AT+HTTPCLIENT=2,3,\"http://%s:8080/get?msg=sirviendoVodka\",\"%s\",\"/get\",1\r\n", IP, IP);
					UART0_Send((uint8_t*)buffer, 0);
					flag_tarjeta_id = 3;
				}


			//}
		//if(contError>=30){
		//flag_tarjeta_id = 111;		//si el ID es incorrecto porque no matchea bebida, devuelve error
		//estadoBebida = 2;
		//contError = 0;
		//}
		//contError++;
		break;
	}
	default:
	case 2: // estado de maquina desactivada
		;
//		break;

	}
}

void error(void)
{
	// uint32 static contadorDeIntentos, si despues de 5 veces no conecta bien chau
	flag_tarjeta_id = 111;
	estadoBebida = 2;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void Esp32_Timer(void)
//{
//	if(TimerEsp32)
//	{
//		TimerEsp32--;
//	}
//}

void eliminaPedidoActivar()
{
	estadoEliminar = 0; // con un 1 la maquina se activa}
}


void eliminarPedido()
{
	switch(estadoEliminar){
		case 0: // enviar el comando de eliminar con el id de la targjeta
			{
				uint8_t comando[150];
				sprintf((char*)comando,"AT+HTTPCLIENT=2,3,\"http://%s:8080/get?IDTDEL=%s\",\"%s\",\"/get\",1\r\n", IP,(char*)IDtarjeta,IP);
				UART0_Send(comando, 0);
				Timer1.Start(1000*5,0,cambioDeEstadoEliminar1a0);
				//iniciar_busqueda_palabra((uint8_t *)"OK");
				estadoEliminar = 1;
			}
			break;
		case 1:
		{
			static int32_t  dato=0;
			static int32_t  dato1=0;
			static int32_t  dato2=0;
			dato = UART0_PopRx();
			//letra adelante
			if(dato>0)
			{
				dato2=dato1;
				dato1=dato;
			}

			if(dato2 == 'd' && dato1 == 'e')
			{
				Timer1.Stop();
				estadoEliminar = 2; // va a el default
			}

		}
			break;
		default:
			;
	}
}

void cambioDeEstadoEliminar1a0(void)
{
	estadoEliminar = 0;
}

