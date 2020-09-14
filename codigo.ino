#include "Keyboard.h" // inclui a biblioteca de controle do teclado

//declaraçao de variaveis

unsigned long lastmillis1 = 0;
unsigned long lastmillis2 = 0;
unsigned long lastmillis3 = 0;

bool lastRead1 = 0;
bool lastRead2 = 0;
bool lastRead3 = 0;

bool buttonState1 = 0;
bool buttonState2 = 0;
bool buttonState3 = 0;

//tempo para evitar interferencia
#define debounceDelay 50

void setup() {
//declara os pinos dos botoes como entrada
pinMode(2, INPUT);
pinMode(3, INPUT);
pinMode(4, INPUT);

Keyboard.begin(); // inicia a keyboard

}

void loop() {
//armazena os valores dos botoes
bool leitura1 = digitalRead(2);
bool leitura2 = digitalRead(3);
bool leitura3 = digitalRead(4);

//verifica a quanto tempo foi pressionado pela ultima
if (leitura1 != lastRead1) {
lastmillis1 = millis();
}
if (leitura2 != lastRead2) {
lastmillis2 = millis();
}
if (leitura3 != lastRead3) {
lastmillis3 = millis();
}

if ((millis() - lastmillis1) > debounceDelay) { //se ja faz 50 milisegundos
if (leitura1 != buttonState1) {// e o botao foi precionado ou mudou de estado
buttonState1 = leitura1;

if (buttonState1 == HIGH) { // e tiver em high
Keyboard.press(KEY_LEFT_CTRL); // pressiona a tecla ctrl
Keyboard.press('c'); // preciona a tecla c
delay(500); // espera 500 ms
Keyboard.releaseAll(); // solta os botoes

Serial.println("ctrl c");
}
}
}

lastRead1 = leitura1;// atribui para o valor anterior

//repete esse mesmo processo para os outros botoes

if ((millis() - lastmillis2) > debounceDelay) {
if (leitura2 != buttonState2) {
buttonState2 = leitura2;

if (buttonState2 == HIGH) {
Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press('v');
delay(500);
Keyboard.releaseAll();

Serial.println("ctrl v");
}
}
}

lastRead2 = leitura2;

if ((millis() - lastmillis3) > debounceDelay) {
if (leitura3 != buttonState3) {
buttonState3 = leitura3;

if (buttonState3 == HIGH) {
Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press('a');
delay(500);
Keyboard.releaseAll();

Serial.println("ctrl a");
}
}
}

lastRead3 = leitura3;

}
