#ifndef DISPLAY_SSD1306_H
#define DISPLAY_SSD1306_H

void init_display();
void display_char_on_ssd1306(char c); //Mostra um caractere na tela
void display_message_on_ssd1306(const char* display_message); //Mostra uma mensagem na tela

#endif