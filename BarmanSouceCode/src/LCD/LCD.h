/*
 * LCD.h
 *
 *  Created on: 5 sep. 2024
 *      Author: Franco
 */

#ifndef LCD_H
#define LCD_H

//#include "Defines.h"
//#include "gpio.h"  // Incluye la clase Gpio

// Definiciones de pines del LCD
#define LCD_RS_PORT 0
#define LCD_RS_PIN 1
#define LCD_EN_PORT 0
#define LCD_EN_PIN 14
#define LCD_D4_PORT 0
#define LCD_D4_PIN 9
#define LCD_D5_PORT 0
#define LCD_D5_PIN 10
#define LCD_D6_PORT 0
#define LCD_D6_PIN 11
#define LCD_D7_PORT 0
#define LCD_D7_PIN 13

// Definición de comandos del LCD
#define LCD_CMD_CLEAR_DISPLAY 0x01
#define LCD_CMD_RETURN_HOME 0x02
#define LCD_CMD_ENTRY_MODE 0x06
#define LCD_CMD_DISPLAY_ON 0x0C
#define LCD_CMD_DISPLAY_OFF 0x08
#define LCD_CMD_FUNCTION_SET 0x28

// Prototipos de funciones
void LCD_Init(void);
void LCD_Command(uint8_t cmd);
void LCD_WriteChar(char data);
void LCD_WriteString(uint8_t* str);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Clear(void);

#endif
