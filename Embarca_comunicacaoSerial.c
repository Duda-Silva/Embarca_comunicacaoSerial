#include <stdio.h>
#include "pico/stdlib.h"
#include "src/serial.h"
#include "src/led_control.h"
#include "src/button_interaction.h"
#include "src/display_ssd1306.h"



int main(){
    stdio_init_all();
    init_leds();
    init_buttons();
    init_display();

    while (true) {
        handle_serial_input();
        handle_button_a();
        handle_button_b();
        sleep_ms(100);
    }
}




