#include <stdio.h>
#include "pico/stdlib.h"
#include "button_interaction.h"
#include "led_control.h"
#include "display_ssd1306.h"

#define BUTTON_A_PIN 5 //Botão A
#define BUTTON_B_PIN 6 //Botão B

void button_a_callback(uint gpio, uint32_t events){
    toggle_green_led();
    display_message_on_ssd1306("LED verde alternado");
    printf("LED verde alternado\n");
}
void button_b_callback(uint gpio, uint32_t events){
    toggle_blue_led();
    display_message_on_ssd1306("LED azul alternado");
    printf("LED azul alternado\n");
}
void init_buttons(){
    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);
    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &button_a_callback);
    
    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);
    gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, &button_b_callback);
}
void handle_button_a(){
    // Debouncing logic for button A
    absolute_time_t last_press_time = {0};
    absolute_time_t current_time = get_absolute_time();
    if(absolute_time_diff_us(last_press_time, current_time) > 200000){
        if(gpio_get(BUTTON_A_PIN) == 0){
            button_a_callback(BUTTON_A_PIN, 0);
        }
        last_press_time = current_time;
    }
}
void handle_button_b(){
    // Debouncing logic for button B
    absolute_time_t last_press_time = {0};
    absolute_time_t current_time = get_absolute_time();
    if(absolute_time_diff_us(last_press_time, current_time) > 200000){
        if(gpio_get(BUTTON_B_PIN) == 0){
            button_a_callback(BUTTON_B_PIN, 0);
        }
        last_press_time = current_time;
    }
}