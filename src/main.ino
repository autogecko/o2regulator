

#include "o2Reg.h"
#include "esp_log.h"
#define pinBtnUp 25
#define pinBtnMenu 33
#define pinBtnDn 32
#define TASK1_TAG "TASK_1"

/* static const char *TAG = "myModule"; */
/* esp_log_level_set("*", ESP_LOG_INFO); */

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
  ESP_LOGW(TASK1_TAG,"hello loogoogogo from setup");
}

void loop() {
    btnUp.loop();
    btnDn.loop();
    btnMenu.loop();
  ESP_LOGW(TASK1_TAG,"hello loogoogogo from setup");
}


