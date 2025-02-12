``` c

//#include <stdio.h>
//#include "pico/stdlib.h"
//#include "hardware/gpio.h"
#include "Keypad.h"  // Biblioteca Keypad

// Define os pinos GPIO dos LEDs e buzzer
#define LED_AZUL 2
#define LED_VERMELHO 3
#define LED_BRANCO 4
#define BUZZER 5

// Configura o teclado matricial
#define LINHAS 4
#define COLUNAS 4

byte linhas_pins[LINHAS] = {6, 7, 8, 9};
byte colunas_pins[COLUNAS] = {10, 11, 12, 13};
char teclas[LINHAS][COLUNAS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};
Keypad keypad = Keypad(makeKeymap(teclas), linhas_pins, colunas_pins, LINHAS, COLUNAS);

void init_perifericos() {
    // Inicializa os LEDs e o BUZEER como saída
    pinMode(LED_AZUL, OUTPUT);
    pinMode(LED_VERMELHO, OUTPUT);
    pinMode(LED_BRANCO, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    // Inicializa os LEDs e o BUZZER como deligados
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_BRANCO, LOW);
    digitalWrite(BUZZER, LOW);
}

void manipula_tecla(char tecla) {
    // Apaga todos os LEDs
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_BRANCO, LOW);
    digitalWrite(BUZZER, LOW);

    switch (tecla) {
        case '1':
            digitalWrite(LED_AZUL, HIGH);
            break;
        case '2':
            digitalWrite(LED_VERMELHO, HIGH);
            break;
        case '3':
            digitalWrite(LED_BRANCO, HIGH);
            break;
        default:
            digitalWrite(BUZZER, HIGH);
            delay(500);
            digitalWrite(BUZZER, LOW);
            break;
    }
}

void setup() {
    Serial.begin(9600);
    init_perifericos();
    Serial.println("Sistema iniciado. Pressione uma tecla para testar.");
}

void loop() {
    char tecla = keypad.getKey();
    if (tecla != NO_KEY) {
        Serial.print("Tecla pressionada: ");
        Serial.println(tecla);
        manipula_tecla(tecla);
    }
    delay(50);
}

```
