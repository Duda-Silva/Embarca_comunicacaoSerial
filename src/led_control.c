#include "pico/stdlib.h"
#include "led_control.h"

#define GREEN_LED_PIN 11 //LED VERDE
#define BLUE_LED_PIN 12 //LED AZUL
#define RED_LED_PIN 13 //LED VERMELHO
#define WS2812_PIN 7 //MATRX DE LEDS

void init_leds(){
    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    //Iniciar ws2812 led matrix aqui
}

void toggle_green_led(){
    gpio_xor_mask(1 << GREEN_LED_PIN);
}

void toggle_blue_led(){
    gpio_xor_mask(1 << BLUE_LED_PIN);
}

void display_number_on_matriz(int number){
    //Código para exibir o número na matriz WS2812
}
