#include <msp430.h> 
#include <LCD.h>
#include"Timer.h"
#include"SoftwareI2C.h"
#include"PCF8574.h"

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    I2C_SOFTWARE_INIT();

    LCD4bit_Init();

    LCD4bit_SendString("Hello");
    LCD4bit_Cursor_Position(1,4);
    LCD4bit_SendString("World");

    Timer_Delay(65535);             //~2sec delay
    LCD4bit_Clear();
    LCD4bit_Cursor_Off();
    Timer_Delay(65535);             //~2sec delay

    LCD4bit_SendString("Line 1");
    LCD4bit_Cursor_Position(1,4);
    LCD4bit_SendString("Line 2");


    return 0;

}

