#include "o2Reg.h"

// const int nMainMenu = 3;
// const int nSubMenu = 3;

int warnLevel = 3;

WiFiMQTTManager wmm(RESET_BUTTON, AP_PASSWORD);  // AP_PASSWORD is defined in the secrets.h file

char MODE_ITEM[10][20] = {"MEMU_MODE","BOOT_MODE","RUNNING_MODE","WARN_CHANGE_MODE","INFO_MODE","SETTING_MODE","NET_SETTING_MODE","NET_CHECK_MODE","REBOOT_MODE","WARN_CONFIRM_MODE"};
//char MODE_SUB_SETTING_ITEM[3][20] =

char mainMenuItem[nMainMenu][12] = {"Inforamtion","Setting", "Return" };
char subMenuItem[nSubMenu][12] = {"Networks","Warn Level","Return" };

int nSelectedMainMenu = 0;
int nSelectedSubMenu = 0;

// ------------------------------------------------------------------
// const int MIN_WARN_LEVEL = 3;  // default 최저 경고레벨
// const int MAX_WARN_LEVEL = 12; // default 최고 경고레벨
void set_mode(Mode_Type _CUR_){
  CUR_MODE = _CUR_;
  Serial.printf("### CURRENT SET MODE from setmode(%s) \n", MODE_ITEM[CUR_MODE]);
  if(CUR_MODE == REBOOT_MODE){
    for(int i=0; i<3; i++){
      delay(500);
      Serial.printf("%d sec to reboot\n", i);
//      wmm->resetSettings();
    }
//    CUR_MODE = RUNNING_MODE; //debug
  }

}

// 25 pin
// #33 pin
void hndlr_btnMenu(Button2 &btn) {

  switch (btn.getType()) {
    case single_click:
      if (CUR_MODE == MENU_MODE && nSelectedMainMenu == 0) set_mode(INFO_MODE);
      else if (CUR_MODE == MENU_MODE && nSelectedMainMenu == 1) set_mode(SETTING_MODE);
      else if (CUR_MODE == MENU_MODE && nSelectedMainMenu == 2) set_mode(RUNNING_MODE);

      else if (CUR_MODE == SETTING_MODE && nSelectedSubMenu == 0) set_mode(NET_SETTING_MODE);
      else if (CUR_MODE == SETTING_MODE && nSelectedSubMenu == 1) set_mode(WARN_CHANGE_MODE);
      else if (CUR_MODE == SETTING_MODE && nSelectedSubMenu == 2) set_mode(RUNNING_MODE);

      else if (CUR_MODE == RUNNING_MODE) set_mode(MENU_MODE);
      else if (CUR_MODE == WARN_CHANGE_MODE ) set_mode(MENU_MODE);
      else if (CUR_MODE == INFO_MODE ) set_mode(MENU_MODE);
      else if (CUR_MODE == NET_SETTING_MODE) set_mode(REBOOT_MODE);
      else if (CUR_MODE == WARN_CONFIRM_MODE) set_mode(RUNNING_MODE);
      break;

    case long_click:{
      if (CUR_MODE == WARN_CHANGE_MODE) set_mode(WARN_CONFIRM_MODE);
    }
  }

  update_display();//debug
}

void hndlr_btnUp(Button2 &btn) {
  switch (btn.getType()) {
    case single_click:
      if (CUR_MODE == MENU_MODE){
        nSelectedMainMenu = nSelectedMainMenu == nMainMenu - 1 ? nMainMenu - 1  : nSelectedMainMenu + 1;
      Serial.printf("### Selected MainMenu item: %d", nSelectedMainMenu);//debug
      }

      else if (CUR_MODE == WARN_CHANGE_MODE)
        warnLevel = warnLevel == MAX_WARN_LEVEL ? MAX_WARN_LEVEL : warnLevel + 1;

      else if (CUR_MODE == SETTING_MODE){
        nSelectedSubMenu = nSelectedSubMenu == nSubMenu - 1 ? nSubMenu - 1 : nSelectedSubMenu + 1;
        Serial.printf("### Selected Submenu item: %d", nSelectedSubMenu);//debug
      }
    case long_click:
      break;
  }

  Serial.printf("Selecte #: %d\n", nSelectedMainMenu);
  update_display();//debug
}

void hndlr_btnDn(Button2 &btn) {
  switch (btn.getType()) {
  case single_click:
    if (CUR_MODE == MENU_MODE)
      nSelectedMainMenu = nSelectedMainMenu == 0 ? 0 : nSelectedMainMenu - 1;

    else if (CUR_MODE == SETTING_MODE)
      nSelectedSubMenu = nSelectedSubMenu == 0 ? 0 : nSelectedSubMenu - 1;

    else if (CUR_MODE == WARN_CHANGE_MODE)
      warnLevel = warnLevel == MIN_WARN_LEVEL ? warnLevel : warnLevel - 1;

      Serial.printf("### Selected Sub Menu item: %d", nSelectedSubMenu);//debug
  case long_click:
    break;
  }

  update_display();//debug
}



void update_display(){
  Serial.printf("------- %s -------\n", MODE_ITEM[CUR_MODE]);
  if (CUR_MODE == BOOT_MODE){
   Serial.printf("Welcome IO2 \n [M] to Set \n");
  }

  else if (CUR_MODE == MENU_MODE) {
    Serial.printf("** CUR_MODE: %s \n", MODE_ITEM[CUR_MODE]);
    for (int i = 0; i < nMainMenu; i++) {
      if (i == nSelectedMainMenu)
        Serial.printf("* %s\n", mainMenuItem[i]);
      else
        Serial.printf("%s\n", mainMenuItem[i]);
    }
  }

  else if (CUR_MODE == SETTING_MODE) {
    Serial.printf("** CUR_MODE: %s \n", MODE_ITEM[CUR_MODE]);
    for (int i = 0; i < nSubMenu; i++) {
      if (i == nSelectedSubMenu)
        Serial.printf("* %s\n", subMenuItem[i]);
      else
        Serial.printf("%s\n", subMenuItem[i]);
   }
  }

  else if (CUR_MODE == WARN_CHANGE_MODE) {
   Serial.printf("WARN LEVEL: %d L/min\n", warnLevel);
   Serial.printf("HOLD menu to Set /n Click to Return\n");
  }

  else if (CUR_MODE == WARN_CONFIRM_MODE) {
   Serial.printf(
       "*** SET WARN_LEVEL : %d *** \n Return to RUNNING_MODE in 3 sec\n",
       warnLevel);
   delay(3000);
   set_mode(RUNNING_MODE);
  }

  else if (CUR_MODE == RUNNING_MODE) {
   Serial.printf(" %d L/min [%d]\n", pressureValue, warnLevel);
  }

  else if (CUR_MODE == INFO_MODE) {
   Serial.printf(
       "INFORMATION\n -ID:xxxx1234\n -GasService:30L\n [M] to Return");
  }

  else if (CUR_MODE == NET_CHECK_MODE){
    Serial.printf("CHECKING NETWORK \n");
  }

  else if (CUR_MODE == REBOOT_MODE){
    Serial.printf("REBOOT 5,4,3,2,1");
}
}

// optional function to subscribe to MQTT topics
void subscribeTo() {
  Serial.println("subscribing to some topics...");
  // subscribe to some topic(s)
  char topic[100];
  snprintf(topic, sizeof(topic), "%s%s%s", "switch/", wmm.deviceId, "/led1/output");
  wmm.client->subscribe(topic);
}

// optional function to process MQTT subscribed to topics coming in
void subscriptionCallback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  //if (String(topic) == "switch/esp1234/led1/output") {
  //  Serial.print("Changing led1 output to ");
  //}
}
