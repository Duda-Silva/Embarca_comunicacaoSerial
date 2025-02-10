# Projeto BitDogLab: Interação com Display, Matriz de LEDs e Botões
Este projeto demonstra a utilização da placa BitDogLab para interagir com um display SSD1306, uma matriz de LEDs 5x5 WS2812 e botões, utilizando comunicação serial UART e interrupções.

## Componentes
* Placa BitDogLab
* Matriz de LEDs 5x5 WS2812 (GPIO 7)
* LED RGB (GPIO 11, 12 e 13)
* Botão A (GPIO 5)
* Botão B (GPIO 6)
* Display SSD1306 (GPIO 14 e 15)
## Funcionalidades
* Biblioteca font.h: Caracteres minúsculos adicionados para exibição no display.
+ Entrada de caracteres via PC:
* Caracteres digitados no Serial Monitor são exibidos no display SSD1306.
* Números de 0 a 9 exibem símbolos correspondentes na matriz 5x5 WS2812.
* Botão A:
* Alterna o estado do LED RGB Verde.
* Exibe mensagem no display e envia texto descritivo para o Serial Monitor.
* Botão B:
* Alterna o estado do LED RGB Azul.
* Exibe mensagem no display e envia texto descritivo para o Serial Monitor.
## Requisitos
* Interrupções (IRQ) para tratamento dos botões.
* Debouncing de software para os botões.
* Controle de LEDs comuns e endereçáveis (WS2812).
* Utilização do display 128x64 com fontes maiúsculas e minúsculas.
* Envio de informações pela UART.
* Código organizado e comentado.
## Instruções
* Clone este repositório.
* Certifique-se de ter as bibliotecas necessárias (font.h modificada).
* Conecte os componentes à placa BitDogLab conforme as definições no código.
* Compile e carregue o código para a placa.
* Abra o Serial Monitor do VS Code para interagir com o projeto.
