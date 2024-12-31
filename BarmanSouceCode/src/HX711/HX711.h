/*
 * HX711.h
 *
 *  Created on: 5 sep. 2024
 *      Author: Franco
 */
#ifndef HX711_H
#define HX711_H

//#include "gpio.h"

class HX711 {
private:
    Gpio clkPin;  // Pin de reloj
    Gpio dataPin; // Pin de datos
    uint8_t _gain;

public:
    // Constructor que inicializa los pines de CLK y DATA
    HX711(uint32_t clkPort, uint32_t clkPinNum, uint32_t dataPort, uint32_t dataPinNum);

    void begin();         // Inicializar el sensor
    bool isReady();       // Verificar si el sensor está listo
    int32_t read();       // Leer el valor del sensor
    void setGain(uint8_t gain = 128);  // Configurar la ganancia (128 por defecto)
    void powerDown();     // Apagar el sensor
    void powerUp();       // Encender el sensor

private:
    void pulseClock();    // Generar un pulso en el pin de reloj
};

#endif // HX711_H
