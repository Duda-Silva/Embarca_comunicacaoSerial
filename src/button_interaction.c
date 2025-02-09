#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "button_interaction.h"
#include "led_control.h"
#include "display_ssd1306.h"

#define BUTTON_A_PIN 5 // Botão A
#define BUTTON_B_PIN 6 // Botão B

void uart_log(const char* message) {
    // Envia a mensagem pela UART
    printf("%s\n", message);
}

void button_a_callback(uint gpio, uint32_t events) {
    toggle_green_led(); // Alterna o estado do LED verde
    display_message_on_ssd1306("LED verde alternado"); // Exibir a mensagem no display OLED SSD1306
    uart_log("LED verde alternado"); // Exibir a mensagem no console
}

void button_b_callback(uint gpio, uint32_t events) {
    toggle_blue_led(); // Alterna o estado do LED azul
    display_message_on_ssd1306("LED azul alternado"); // Exibir a mensagem no display OLED SSD1306
    uart_log("LED azul alternado"); // Exibir a mensagem no console
}

void init_buttons() {
    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);
    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &button_a_callback);
    
    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);
    gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, &button_b_callback);
}

void handle_button_a() {
    // Lógica de debounce para o botão A
    static absolute_time_t last_press_time = {0}; // Variável estática para armazenar o tempo da última pressão do botão A
    absolute_time_t current_time = get_absolute_time(); // Obtém o tempo atual

    // Verifica se o tempo desde a última pressão é maior que 200 ms
    if (absolute_time_diff_us(last_press_time, current_time) > 200000) {
        // Verifica se o botão A está pressionado (nível lógico baixo)
        if (gpio_get(BUTTON_A_PIN) == 0) {
            // Chama a função de callback para o botão A
            button_a_callback(BUTTON_A_PIN, 0);
        }
        // Atualiza o tempo da última pressão para o tempo atual
        last_press_time = current_time;
    }
}

void handle_button_b() {
    // Lógica de debounce para o botão B
    static absolute_time_t last_press_time = {0}; // Variável estática para armazenar o tempo da última pressão do botão B
    absolute_time_t current_time = get_absolute_time(); // Obtém o tempo atual

    // Verifica se o tempo desde a última pressão é maior que 200 ms
    if (absolute_time_diff_us(last_press_time, current_time) > 200000) {
        // Verifica se o botão B está pressionado (nível lógico baixo)
        if (gpio_get(BUTTON_B_PIN) == 0) {
            // Chama a função de callback para o botão B
            button_b_callback(BUTTON_B_PIN, 0);
        }
        // Atualiza o tempo da última pressão para o tempo atual
        last_press_time = current_time;
    }
}