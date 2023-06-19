/*
 * bedlight_simple_colors.c
 *
 *  Created on: Oct 18, 2020
 *      Author: hello
 */


#include "bedlight.h"
#include <string.h>

bedlight_t g_bedlight;
LED_t LED_1;
LED_t LED_2;

__weak void button1_callback()
{

}

__weak void button2_callback()
{

}

__weak void button3_callback()
{

}

__weak void button4_callback()
{

}

__weak void cycle_callback()
{

}


void init_LEDs()
{
	LED_1.red = LED_RED1_Pin;
	LED_1.red_port = GPIOA;
	LED_1.green = LED_GREEN1_Pin;
	LED_1.green_port = GPIOB;
	LED_1.blue = LED_BLUE1_Pin;
	LED_1.blue_port = GPIOB;
	strcpy((char*) LED_1.name, "LED1");

	LED_2.red = LED_RED2_Pin;
	LED_2.red_port = GPIOB;
	LED_2.green = LED_GREEN2_Pin;
	LED_2.green_port = GPIOA;
	LED_2.blue = LED_BLUE2_Pin;
	LED_2.blue_port = GPIOA;
	strcpy((char*) LED_2.name, "LED2");

	g_bedlight.led = LED_1;

}

void switch_LEDs()
{
	uint8_t red_state = 0;
	uint8_t green_state = 0;
	uint8_t blue_state = 0;

	// check status of the current LED
	red_state = HAL_GPIO_ReadPin(g_bedlight.led.red_port, g_bedlight.led.red);
	green_state = HAL_GPIO_ReadPin(g_bedlight.led.green_port, g_bedlight.led.green);
	blue_state = HAL_GPIO_ReadPin(g_bedlight.led.blue_port, g_bedlight.led.blue);

	// turn off current LED
	HAL_GPIO_WritePin(g_bedlight.led.red_port, g_bedlight.led.red, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(g_bedlight.led.green_port, g_bedlight.led.green, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(g_bedlight.led.blue_port, g_bedlight.led.blue, GPIO_PIN_RESET);

	// switch LED
	if (strcmp((char*) g_bedlight.led.name, "LED1") == 0){
		g_bedlight.led = LED_2;
	}
	else
		g_bedlight.led = LED_1;


	// light new LED with the same color as the previous LED for easier comparison
	if (red_state)
	{
		 button1_callback();
	}
	if (green_state)
	{
		 button2_callback();
	}
	if (blue_state)
	{
		 button3_callback();
	}

}


uint8_t pressed_button1()
{
	  if (HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin) == GPIO_PIN_RESET)
	  {
		  return 1;
	  }

	  else
	  {
		  return 0;
	  }
}

uint8_t pressed_button2()
{
	  if (HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin) == GPIO_PIN_RESET)
	  {
		  return 1;
	  }

	  else
	  {
		  return 0;
	  }
}


uint8_t pressed_button3()
{
	  if (HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin) == GPIO_PIN_RESET)
	  {
		  return 1;
	  }

	  else
	  {
		  return 0;
	  }
}

uint8_t pressed_button4()
{
	  if (HAL_GPIO_ReadPin(BUTTON4_GPIO_Port, BUTTON4_Pin) == GPIO_PIN_RESET)
	  {
		  return 1;
	  }

	  else
	  {
		  return 0;
	  }
}

uint8_t pressed_button_count()
{
	return (pressed_button1() + pressed_button2() + pressed_button3() + pressed_button4());
}
