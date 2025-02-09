#include <stdio.h>
#include "serial.h"
#include "display_ssd1306.h"
#include "led_control.h"
#include "pico/stdio_usb.h"

void handle_serial_input() {
    if (stdio_usb_connected()) {
        int c = getchar_timeout_us(0);
        if (c != PICO_ERROR_TIMEOUT) {
            if (c >= '0' && c <= '9') {
                display_number_on_matriz(c - '0');
            } else {
                display_char_on_ssd1306(c);
            }
            printf("Received: %c\n", c); // Envia o caractere recebido de volta ao Serial Monitor
        }
    }
}