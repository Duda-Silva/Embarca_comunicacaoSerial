#include <stdio.h>
#include "pico/stdlib.h"
#include "display_ssd1306.h"
#include "font.h"
#include "hardware/uart.h"

#define UART_ID uart0
#define BAUD_RATE 115200
#define UART_TX_PIN 14
#define UART_RX_PIN 15

// Função para enviar um comando ao display via UART
void uart_write_command(uint8_t command) {
    uart_putc_raw(UART_ID, command);
}

// Função para enviar dados ao display via UART
void uart_write_data(uint8_t *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        uart_putc_raw(UART_ID, data[i]);
    }
}

// Função para inicializar o display SSD1306
void init_display() {
    // Inicialize a UART aqui
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    // Sequência de inicialização do SSD1306 via UART
    uart_write_command(0xAE); // Display off
    uart_write_command(0xD5); // Set display clock divide ratio/oscillator frequency
    uart_write_command(0x80); // Set divide ratio
    uart_write_command(0xA8); // Set multiplex ratio(1 to 64)
    uart_write_command(0x3F); // 1/64 duty
    uart_write_command(0xD3); // Set display offset
    uart_write_command(0x00); // No offset
    uart_write_command(0x40); // Set start line address
    uart_write_command(0x8D); // Enable charge pump regulator
    uart_write_command(0x14);
    uart_write_command(0x20); // Set Memory Addressing Mode
    uart_write_command(0x00); // Horizontal addressing mode
    uart_write_command(0xA1); // Set segment re-map 0 to 127
    uart_write_command(0xC8); // Set COM Output Scan Direction
    uart_write_command(0xDA); // Set COM Pins hardware configuration
    uart_write_command(0x12);
    uart_write_command(0x81); // Set contrast control register
    uart_write_command(0xCF);
    uart_write_command(0xD9); // Set pre-charge period
    uart_write_command(0xF1);
    uart_write_command(0xDB); // Set VCOMH deselect level
    uart_write_command(0x40);
    uart_write_command(0xA4); // Entire display ON
    uart_write_command(0xA6); // Set normal display
    uart_write_command(0x2E); // Deactivate scroll
    uart_write_command(0xAF); // Display ON
}

// Função para exibir um caractere no display SSD1306
void display_char_on_ssd1306(char c) {
    const uint8_t *bitmap;
    if (c >= 'A' && c <= 'Z') {
        bitmap = font_uppercase[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        bitmap = font_lowercase[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        bitmap = font_numbers[c - '0'];
    } else {
        return;
    }
    uart_write_data((uint8_t *)bitmap, 5);
}

// Função para exibir uma mensagem no display SSD1306
void display_message_on_ssd1306(const char* message) {
    while (*message) {
        display_char_on_ssd1306(*message++);
    }
}