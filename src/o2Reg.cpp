#include "o2Reg.h"

// const int nMainMenu = 3;
// const int nSubMenu = 3;

int warnLevel = 3;


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
}

// 25 pin
void hndlr_btnUp(Button2 &btn) {
  switch (btn.getType()) {
    case single_click:
      if(CUR_MODE == MENU_MODE) nSelectedMainMenu = nSelectedMainMenu == nMainMenu ? nMainMenu : nSelectedMainMenu + 1;
      if(CUR_MODE == WARN_CHANGE_MODE) warnLevel = warnLevel == MAX_WARN_LEVEL ? \
                                           warnLevel : warnLevel + 1 ;
    case long_click:
      break;
  }

  Serial.printf("Selecte #: %d\n", nSelectedMainMenu);
  update_display();
}
// #33 pin
void hndlr_btnMenu(Button2 &btn) {

  switch (btn.getType()) {
    case single_click:
      if (CUR_MODE == MENU_MODE && nSelectedMainMenu == 0) set_mode(INFO_MODE);
      if (CUR_MODE == MENU_MODE && nSelectedMainMenu == 1) set_mode(SETTING_MODE);
      if (CUR_MODE == MENU_MODE && nSelectedMainMenu == 2) set_mode(RUNNING_MODE);

      if (CUR_MODE == SETTING_MODE && nSelectedSubMenu == 0) set_mode(NET_SETTING_MODE);
      if (CUR_MODE == SETTING_MODE && nSelectedSubMenu == 1) set_mode(WARN_CHANGE_MODE);
      if (CUR_MODE == SETTING_MODE && nSelectedSubMenu == 2) set_mode(RUNNING_MODE);

      if (CUR_MODE == RUNNING_MODE) set_mode(MENU_MODE);
      if (CUR_MODE == WARN_CHANGE_MODE ) set_mode(MENU_MODE);
      if (CUR_MODE == INFO_MODE ) set_mode(RUNNING_MODE);
      if (CUR_MODE == NET_SETTING_MODE) set_mode(REBOOT_MODE);
      if (CUR_MODE == WARN_CONFIRM_MODE) set_mode(RUNNING_MODE);
      break;

  }

  update_display();
}


void hndlr_btnDn(Button2 &btn) {
  switch (btn.getType()) {
  case single_click:
    if (CUR_MODE == MENU_MODE)
      nSelectedMainMenu = nSelectedMainMenu == 0 ? 0 : nSelectedMainMenu - 1;
    if (CUR_MODE == WARN_CHANGE_MODE)
      warnLevel = warnLevel == MIN_WARN_LEVEL ? warnLevel : warnLevel - 1;
  case long_click:
    break;
  }

  Serial.printf("Selecte #: %d\n", nSelectedMainMenu);
  update_display();
}



void update_display(){
  if (CUR_MODE == MENU_MODE) {
        Serial.printf("** CUR_MODE: %s \n", MODE_ITEM[CUR_MODE] );
        for(int i=0; i < nSubMenu; i++) {
          if (i == nSelectedMainMenu) Serial.printf("* %s\n", mainMenuItem[i]);
          else Serial.printf("%s\n",mainMenuItem[i]);
       }
  }
  else Serial.printf("CURMODE: %s %d\n", MODE_ITEM[CUR_MODE], CUR_MODE);
}
