#include <Arduino.h>
#include "Keyboard.h"

const int buttonPinMAC = 6;
const int buttonPinWin = 7;
const int buttonPinLin = 8;

void setup(){
  pinMode(buttonPinMAC, INPUT_PULLUP);
  pinMode(buttonPinWin, INPUT_PULLUP);
  pinMode(buttonPinLin, INPUT_PULLUP);  
  Keyboard.begin();
}

void loop(){
  int buttonStateMAC = digitalRead(buttonPinMAC);
  int buttonStateWin = digitalRead(buttonPinWin);
  int buttonStateLin = digitalRead(buttonPinLin);

  if(buttonStateWin == LOW) {

    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_KP_2);
    Keyboard.press(KEY_KP_5);
    Keyboard.press(KEY_KP_0);
    delay(100);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.release(KEY_KP_2);
    Keyboard.release(KEY_KP_5);
    Keyboard.release(KEY_KP_0);
    Keyboard.releaseAll();
    delay(100);

    buttonStateWin = HIGH;
  }

  else if(buttonStateMAC == LOW){
    Keyboard.press(129);
    Keyboard.press(130);
    Keyboard.press(102);
    delay(100);
    Keyboard.releaseAll();
    delay(100);

    buttonStateMAC = HIGH;
  }

  else if(buttonStateLin == LOW){
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press('&');
    delay(100);
    Keyboard.releaseAll();
    delay(100);

    buttonStateLin = HIGH;
  }
  
  else{
    Keyboard.releaseAll();
  }
  
}