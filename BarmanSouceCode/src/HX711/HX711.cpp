/*
 * HX711.cpp
 *
 *  Created on: 5 sep. 2024
 *      Author: Franco
 */
//#include "HX711.h"
#include "Defines.h"
// Constructor modificado para recibir los puertos y pines
HX711::HX711(uint32_t clkPort, uint32_t clkPinNum, uint32_t dataPort, uint32_t dataPinNum)
    : clkPin(clkPort, clkPinNum, 1),  // Configuración del pin de reloj como salida
      dataPin(dataPort, dataPinNum, 0)  // Configuración del pin de datos como entrada
{
    setGain(128);  // Ganancia por defecto
}

void HX711::begin() {
    // No se necesita configurar los pines aquí porque ya se hace en el constructor
}

bool HX711::isReady() {
    // Verificar si el sensor está listo
    return !dataPin.Read();  // Leer el pin de datos (sin paréntesis extra)
}

void HX711::setGain(uint8_t gain) {
    switch (gain) {
        case 128: _gain = 1; break;
        case 64:  _gain = 3; break;
        case 32:  _gain = 2; break;
    }
}

int32_t HX711::read() {
    // Esperar a que el HX711 esté listo
    while (!isReady());

    int32_t value = 0;
    for (uint8_t i = 0; i < 24; i++) {
        pulseClock();  // Generar un pulso de reloj
        value = (value << 1) | dataPin.Read();  // Leer un bit del pin de datos
    }

    // Ajustar el valor leído para un número de 24 bits con signo
    value ^= 0x800000;  // Corregir el valor si es negativo

    // Aplicar los pulsos adicionales para configurar la ganancia
    for (uint8_t i = 0; i < _gain; i++) {
        pulseClock();
    }

    return value;  // Devolver el valor leído
}

void HX711::pulseClock() {
    clkPin.Set(1);   // Generar un pulso de reloj (subir)
    clkPin.Set(0);   // Generar un pulso de reloj (bajar)
}

void HX711::powerDown() {
    clkPin.Set(1);  // Mantener alto por más de 60 microsegundos para apagar
    // Implementa un retraso si es necesario
}

void HX711::powerUp() {
    clkPin.Set(0);  // Bajar el pin de reloj para encender
}

