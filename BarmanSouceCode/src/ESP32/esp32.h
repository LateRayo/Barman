/*
 * esp32.h
 *
 *  Created on: 31 oct. 2024
 *      Author: i_val
 */

#ifndef ESP32_ESP32_H_
#define ESP32_ESP32_H_

#define PALABRA_MAX_TAM 				15 // Máximo tamaño de la palabra a buscar


// Variables para la máquina de estados de recepcion
#define ESP_WIFI_CONFIGURA_TCP 0
#define ESP_WIFI_ESPERA_RESPUESTA 1
#define ESP_WIFI_CONFIGURA_RED 2
#define ESP_WIFI_CONECTADO_OK 3
#define ESP_WIFI_ENVIAR_HTTP 4
#define ESP_WIFI_FIN 5


//					PROTOTIPOS
void buscarBebida();
void strncpy(uint8_t* dest, const uint8_t* src, size_t n);
//void iniciar_busqueda_palabra(uint8_t *palabra);
void buscarBebidaActivar(uint8_t * tarjeta);
void cambioDeEstado3a2(void);
void cambioDeEstado1a0(void);
//void maquinaDeEstadosRecepcionUart(void);
//void conectarseWifi(void);
void eliminarPedido(void);
void cambioDeEstadoEliminar1a0(void);
void eliminaPedidoActivar(void);

//void Esp32_Timer(void);



typedef enum
{
	INACTIVO, BUSCANDO, ENCONTRADO
} Estado;







#endif /* ESP32_ESP32_H_ */
