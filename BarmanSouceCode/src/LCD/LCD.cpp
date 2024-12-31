/*
 * LCD.cpp
 *
 *  Created on: 5 sep. 2024
 *      Author: Franco
 */

#include "Defines.h"
//#include "LCD.h"

// Definición de los pines del LCD
Gpio RS(0, 1, 1);   // Puerto 0, Pin 1, Salida
Gpio EN(0, 14, 1);  // Puerto 0, Pin 14, Salida
Gpio D4(0, 9, 1);   // Puerto 0, Pin 9, Salida
Gpio D5(0, 10, 1);  // Puerto 0, Pin 10, Salida
Gpio D6(0, 11, 1);  // Puerto 0, Pin 11, Salida
Gpio D7(0, 13, 1);  // Puerto 0, Pin 13, Salida

// Función de retardo simple
void delay(int ms) {
    for (volatile int i = 0; i < ms * 1000; i++);
}

// Función para enviar un comando al LCD
void LCD_SendCmd(uint8_t cmd) {
    RS.Set(0);  // RS = 0 para enviar un comando

    // Enviar la parte alta del comando
    D4.Set((cmd >> 4) & 0x01);
    D5.Set((cmd >> 5) & 0x01);
    D6.Set((cmd >> 6) & 0x01);
    D7.Set((cmd >> 7) & 0x01);

    // Generar pulso en EN
    EN.Set(1);
    delay(1);
    EN.Set(0);

    // Enviar la parte baja del comando
    D4.Set(cmd & 0x01);
    D5.Set((cmd >> 1) & 0x01);
    D6.Set((cmd >> 2) & 0x01);
    D7.Set((cmd >> 3) & 0x01);

    // Generar pulso en EN
    EN.Set(1);
    delay(1);
    EN.Set(0);

    delay(2);  // Tiempo para que el LCD procese el comando
}

// Función para enviar un dato al LCD
void LCD_SendData(uint8_t data) {
    RS.Set(1);  // RS = 1 para enviar un dato

    // Enviar la parte alta del dato
    D4.Set((data >> 4) & 0x01);
    D5.Set((data >> 5) & 0x01);
    D6.Set((data >> 6) & 0x01);
    D7.Set((data >> 7) & 0x01);

    // Generar pulso en EN
    EN.Set(1);
    delay(1);
    EN.Set(0);

    // Enviar la parte baja del dato
    D4.Set(data & 0x01);
    D5.Set((data >> 1) & 0x01);
    D6.Set((data >> 2) & 0x01);
    D7.Set((data >> 3) & 0x01);

    // Generar pulso en EN
    EN.Set(1);
    delay(1);
    EN.Set(0);

    delay(2);  // Tiempo para que el LCD procese el dato
}

// Función para inicializar el LCD
void LCD_Init(void) {
    delay(20);  // Esperar 20ms después de encender el LCD

    // Modo de inicialización
    LCD_SendCmd(0x03);
    delay(5);
    LCD_SendCmd(0x03);
    delay(1);
    LCD_SendCmd(0x03);
    delay(1);
    LCD_SendCmd(0x02);  // Cambiar a modo de 4 bits

    // Configurar el LCD
    LCD_SendCmd(0x28);  // 4 bits, 2 líneas, 5x8 puntos
    LCD_SendCmd(0x0C);  // Display encendido, cursor apagado
    LCD_SendCmd(0x06);  // Incrementar el cursor
    LCD_SendCmd(0x01);  // Limpiar display
    delay(2);
}

// Función para limpiar el LCD
void LCD_Clear(void) {
    LCD_SendCmd(0x01);  // Comando para limpiar el display
    delay(2);
}

// Función para mover el cursor a una posición específica
void LCD_SetCursor(uint8_t row, uint8_t col) {
    uint8_t address = 0;

    // Calcular la dirección de la memoria correspondiente
    switch (row) {
        case 0:
            address = 0x80 + col;
            break;
        case 1:
            address = 0xC0 + col;
            break;
    }

    LCD_SendCmd(address);
}

// Función para escribir una cadena en el LCD
void LCD_WriteString(uint8_t *str) {
    while (*str) {
        LCD_SendData(*str++);
    }
}
