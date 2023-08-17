/* 
 * File:   ecu_initialize.h
 * Author: ammar.yasser
 *
 * Created on 06 ?????, 2023, 05:59 ?
 */

#include "ecu_initialize.h"
keypad_t kp1 = {
    .keypad_ROWS_pins[0].direction = GPIO_OUTPUT,
    .keypad_ROWS_pins[0].logic = GPIO_LOW,
    .keypad_ROWS_pins[0].pin = GPIO_PIN0,
    .keypad_ROWS_pins[0].port = GPIO_PORT_C,
    .keypad_ROWS_pins[1].direction = GPIO_OUTPUT,
    .keypad_ROWS_pins[1].logic = GPIO_LOW,
    .keypad_ROWS_pins[1].pin = GPIO_PIN1,
    .keypad_ROWS_pins[1].port = GPIO_PORT_C,
    .keypad_ROWS_pins[2].direction = GPIO_OUTPUT,
    .keypad_ROWS_pins[2].logic = GPIO_LOW,
    .keypad_ROWS_pins[2].pin = GPIO_PIN2,
    .keypad_ROWS_pins[2].port = GPIO_PORT_C,
    .keypad_ROWS_pins[3].direction = GPIO_OUTPUT,
    .keypad_ROWS_pins[3].logic = GPIO_LOW,
    .keypad_ROWS_pins[3].pin = GPIO_PIN3,
    .keypad_ROWS_pins[3].port = GPIO_PORT_C,
    .keypad_coulmns_pins[0].direction = GPIO_INPUT,
    .keypad_coulmns_pins[0].logic = GPIO_LOW,
    .keypad_coulmns_pins[0].pin = GPIO_PIN4,
    .keypad_coulmns_pins[0].port = GPIO_PORT_C,
    .keypad_coulmns_pins[1].direction = GPIO_INPUT,
    .keypad_coulmns_pins[1].logic = GPIO_LOW,
    .keypad_coulmns_pins[1].pin = GPIO_PIN5,
    .keypad_coulmns_pins[1].port = GPIO_PORT_C,
    .keypad_coulmns_pins[2].direction = GPIO_INPUT,
    .keypad_coulmns_pins[2].logic = GPIO_LOW,
    .keypad_coulmns_pins[2].pin = GPIO_PIN6,
    .keypad_coulmns_pins[2].port = GPIO_PORT_C,
  
};
lcd_4bit_t lcd_1 = {
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_rs.pin = GPIO_PIN2,
    .lcd_rs.port = GPIO_PORT_D,
    .lcd_enable.direction = GPIO_OUTPUT,
    .lcd_enable.logic = GPIO_LOW,
    .lcd_enable.pin = GPIO_PIN3,
    .lcd_enable.port = GPIO_PORT_D,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[0].pin = GPIO_PIN4,
    .lcd_data[0].port = GPIO_PORT_D,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[1].pin = GPIO_PIN5,
    .lcd_data[1].port = GPIO_PORT_D,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[2].pin = GPIO_PIN6,
    .lcd_data[2].port = GPIO_PORT_D,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
    .lcd_data[3].pin = GPIO_PIN7,
    .lcd_data[3].port = GPIO_PORT_D,
    
};

led_t led_1 ={
    .pin_number = GPIO_PIN0,
    .port_name = GPIO_PORT_D,
    .pin_statues = LED_OFF
};

led_t led_2 ={
    .pin_number = GPIO_PIN1,
    .port_name = GPIO_PORT_D,
    .pin_statues = LED_OFF
};

dc_motor_t motor_1 = {
    .dc_motor_pin[0].direction = GPIO_OUTPUT,
    .dc_motor_pin[0].logic = GPIO_LOW,
    .dc_motor_pin[0].pin = GPIO_PIN0,
    .dc_motor_pin[0].port = GPIO_PORT_A,
    .dc_motor_pin[1].direction = GPIO_OUTPUT,
    .dc_motor_pin[1].logic = GPIO_LOW,
    .dc_motor_pin[1].pin = GPIO_PIN1,
    .dc_motor_pin[1].port = GPIO_PORT_A,
};

void ecu_initialize (void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = lcd_4bit_initialize(&lcd_1);
    ret = keypad_initialize(&kp1);
    ret = dc_motor_initialize(&motor_1);
    ret = led_initialize(&led_1);
    ret = led_initialize(&led_2);



}