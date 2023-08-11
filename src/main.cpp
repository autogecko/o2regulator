

#include "o2Reg.h"

#define pinBtnUp 25
#define pinBtnMenu 33
#define pinBtnDn 32



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  delay(50);

  // Buton Setup
  btnUp.begin(pinBtnUp);
  btnMenu.begin(pinBtnMenu);
  btnDn.begin(pinBtnDn);

  btnUp.setClickHandler(hndlr_btnUp);
  btnUp.setLongClickHandler(hndlr_btnUp);

  btnDn.setClickHandler(hndlr_btnDn);
  btnDn.setLongClickHandler(hndlr_btnDn);

  btnMenu.setClickHandler(hndlr_btnMenu);
  btnMenu.setLongClickHandler(hndlr_btnMenu);
  Serial.print("-- Button Setup\n");
  delay(1000);




  // Network Setup
  //
  Serial.println("-- Network Setup");
  delay(1000);
  //Network Check
  Serial.println("-- Network Check ");
  CUR_MODE = RUNNING_MODE;
}

void loop() {
    btnUp.loop();
    btnDn.loop();
    btnMenu.loop();
}


