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
    //gpio_init(RED_LED_PIN);
    //gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    //Iniciar ws2812 led matrix aqui
    gpio_init(WS2812_PIN);
    gpio_set_dir(WS2812_PIN, GPIO_OUT);
}

void toggle_green_led(){
    gpio_xor_mask(1 << GREEN_LED_PIN);
}

void toggle_blue_led(){
    gpio_xor_mask(1 << BLUE_LED_PIN);
}

static inline void ws2812_send_bit(bool bit){
    if(bit){
        gpio_put(WS2812_PIN, 1);
        sleep_us(0.8); //T1H
        gpio_put(WS2812_PIN, 0);
        sleep_us(0.45); //T0L
    } else {
        gpio_put(WS2812_PIN, 1);
        sleep_us(0.4); //T1H
        gpio_put(WS2812_PIN, 0);
        sleep_us(0.85); //T0L
    }
}

static inline void ws2813_send_byte(uint8_t byte){
    for(int i = 0; i <8; i++){
        ws2812_send_bit(byte & (1 << (7 - i)));
    }
}

static void ws2812_send_color(uint8_t r, uint8_t g, uint8_t b){
    ws2813_send_byte(g);
    ws2813_send_byte(r);
    ws2813_send_byte(b);
}

void display_number_on_matriz(int number){
    //Código para exibir o número na matriz WS2812
    uint8_t colors[5][5][3] = {0};

    switch (number){
    case 0:
        //defina os leds para exibir o número 0
        colors[0][0][0] = 255;
        colors[0][1][0] =255;
        colors[0][2][0] =255;
        colors[0][3][0] =255;
        colors[0][4][0] =255;
        break;
    case 1:
        colors[0][2][0] = 255; // Vermelho
        colors[1][2][0] = 255;
        colors[2][2][0] = 255;
        colors[3][2][0] = 255;
        colors[4][2][0] = 255;
        break;
    
    case 2:
        colors[0][0][0] = 255; // Vermelho
        colors[0][1][0] = 255;
        colors[0][2][0] = 255;
        colors[1][2][0] = 255;
        colors[2][0][0] = 255;
        colors[2][1][0] = 255;
        colors[2][2][0] = 255;
        colors[3][0][0] = 255;
        colors[4][0][0] = 255;
        colors[4][1][0] = 255;
        colors[4][2][0] = 255;
        break;

    case 3:
        colors[0][0][0] = 255; // Vermelho
        colors[0][1][0] = 255;
        colors[0][2][0] = 255;
        colors[1][2][0] = 255;
        colors[2][0][0] = 255;
        colors[2][1][0] = 255;
        colors[2][2][0] = 255;
        colors[3][2][0] = 255;
        colors[4][0][0] = 255;
        colors[4][1][0] = 255;
        colors[4][2][0] = 255;
        break;

    case 4:
        colors[0][0][0] = 255; // Vermelho
        colors[0][1][0] = 255;
        colors[0][2][0] = 255;
        colors[1][0][0] = 255;
        colors[1][2][0] = 255;
        colors[2][0][0] = 255;
        colors[2][1][0] = 255;
        colors[2][2][0] = 255;
        colors[3][2][0] = 255;
        colors[4][2][0] = 255;
        break;

    case 5:
        colors[0][0][0] = 255; // Vermelho
        colors[0][1][0] = 255;
        colors[0][2][0] = 255;
        colors[1][0][0] = 255;
        colors[2][0][0] = 255;
        colors[2][1][0] = 255;
        colors[2][2][0] = 255;
        colors[3][2][0] = 255;
        colors[4][0][0] = 255;
        colors[4][1][0] = 255;
        colors[4][2][0] = 255;
        break;

    case 6:
        colors[0][0][0] = 255; // Vermelho
        colors[0][1][0] = 255;
        colors[0][2][0] = 255;
        colors[1][0][0] = 255;
        colors[2][0][0] = 255;
        colors[2][1][0] = 255;
        colors[2][2][0] = 255;
        colors[3][0][0] = 255;
        colors[3][2][0] = 255;
        colors[4][0][0] = 255;
        colors[4][1][0] = 255;
        colors[4][2][0] = 255;
        break;

    case 7:
        colors[0][0][0] = 255; // Vermelho
        colors[0][1][0] = 255;
        colors[0][2][0] = 255;
        colors[1][2][0] = 255;
        colors[2][2][0] = 255;
        colors[3][2][0] = 255;
        colors[4][2][0] = 255;
        break;

    case 8:
        colors[0][0][0] = 255; // Vermelho
        colors[0][1][0] = 255;
        colors[0][2][0] = 255;
        colors[1][0][0] = 255;
        colors[1][2][0] = 255;
        colors[2][0][0] = 255;
        colors[2][1][0] = 255;
        colors[2][2][0] = 255;
        colors[3][0][0] = 255;
        colors[3][2][0] = 255;
        colors[4][0][0] = 255;
        colors[4][1][0] = 255;
        colors[4][2][0] = 255;
        break;

    case 9:
        colors[0][0][0] = 255; // Vermelho
        colors[0][1][0] = 255;
        colors[0][2][0] = 255;
        colors[1][0][0] = 255;
        colors[1][2][0] = 255;
        colors[2][0][0] = 255;
        colors[2][1][0] = 255;
        colors[2][2][0] = 255;
        colors[3][2][0] = 255;
        colors[4][0][0] = 255;
        colors[4][1][0] = 255;
        colors[4][2][0] = 255;
        break;
    
    default:
        break;
    }


for(int y = 0; y < 5; y++){
    for(int x = 0; x < 5; x++){
        ws2812_send_color(colors[y][x][0], colors[y][x][1], colors[y][x][2]);
    }
}
}