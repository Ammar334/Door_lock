/* 
 * File:   application.c
 * Author: Ammar.Yasser
 *
 * Created on 21 ?????, 2023, 06:12 ?
 */

#include "applications.h"

void loading();

Std_ReturnType ret = E_NOT_OK;
uint8 value=0;
uint8 i=0;
uint8 number_of_digits=0;
uint8 entered_password_arr[11];
uint32 entered_password=0;
uint32 password = 123456;
uint8 l=0;
uint8 k=0;
int main(){
    application_initialize();
    ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Enter Password :");

    while(1)
    {
        ret = keypad_get_value(&kp1,&value);
        __delay_ms(DEBOUNE_TIME);
        if(6 == number_of_digits)
        {
            if(entered_password == password)
            {
                value=0;
                if(l==0)
                {
                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                    ret = lcd_4bit_send_string_pos(&lcd_1,1,7,"Welcome");
                    __delay_ms(1000);
                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                    l=1;
                }
                ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Open The Lock");
                ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Close The Lock");
                ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"3-Exit");
                ret = keypad_get_value(&kp1,&value);
                ret = lcd_4bit_send_char_pos(&lcd_1,4,1,value);
                if(value == '1')
                {
                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                    __delay_ms(100);
                    ret = dc_motor_move_right(&motor_1);
                    ret = led_turn_on(&led_1);
                    ret = led_turn_off(&led_2);
                    loading();
                    ret = dc_motor_stop(&motor_1);
                }else if(value == '2')
                {
                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                    __delay_ms(100);
                    ret = dc_motor_move_left(&motor_1);
                    ret = led_turn_on(&led_2);
                    ret = led_turn_off(&led_1);
                    loading();
                    ret = dc_motor_stop(&motor_1);
                }else if(value == '3')
                {
                    entered_password=0;
                    number_of_digits=0;
                    l=0;
                    value=0;
                    loading();
                    ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Enter Password :");

                }
            }
            else
            {
                ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Wrong Password !");
                ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"Try again");
                entered_password=0;
                number_of_digits=0;
                l=0;
                value=0;
                 __delay_ms(900);
                ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                __delay_ms(100);
                ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Enter Password :");

            }
        }
        else
        {
            if(strlen(entered_password_arr)==6)
            {
                entered_password = atoi(entered_password_arr);
                number_of_digits = 6;
                memset(entered_password_arr,'\0',11);
                i=0;
            }
            else if (value == '#')
            {
                ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Enter Password :");
                entered_password=0;
                number_of_digits=0;
                l=0;
                value=0;
                memset(entered_password_arr,'\0',11);
                i=0;
            }
            else if(value!=0)
            {
                entered_password_arr[i] = value;
                ret = lcd_4bit_send_char_pos(&lcd_1,2,(i+1),'*');
                value=0;
                i++;
            }
            
            if(k==0)
            {
                ret = led_turn_on(&led_2);
                k=1;
            }
                 
        }
        
    }

    return (EXIT_SUCCESS);
}

void application_initialize (void)
{
    ecu_initialize();
}

void loading()
{
    Std_ReturnType ret = E_NOT_OK;

    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
    for(int j=0;j<2;j++)
    {
        ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Please Wait");
        for(int i=11;i<=15;i++)
       {
           ret = lcd_4bit_send_char_pos(&lcd_1,1,i,'.');
           __delay_ms(200);
       }
        __delay_ms(400);
        ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
    }
    
}