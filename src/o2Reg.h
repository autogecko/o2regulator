#ifndef O2REG_H_
#define O2REG_H_



#endif // O2REG_H_

#define MENU_MODE 1
#define BOOT_MODE 2
#define RUNNING_MODE 3
#define WARN_CHANGE_MODE 4
#define INFO_MODE 5
#define SETTING_MODE 6
#define NETSETTING_MODE 7
#define NET_CHECK_MODE 8
#define REBOOT_MODE 9
#define WARN_CONFIRM_MODE 10

#include "Button2.h"

Button2 btnUp, btnMenu, btnDn ;

int CUR_MODE = 0;
const int nMainMenu = 3;
const int nSubMenu = 3;

char MODE_ITEM[10][20] = {"MEMU_MODE","BOOT_MODE","RUNNING_MODE","WARN_CHANGE_MODE","INFO_MODE","SETTING_MODE","NET_SETTING_MODE","NET_CHECK_MODE","REBOOT_MODE","WARN_CONFIRM_MODE"};
char MODE_SUB_SETTING_ITEM[3][20] =  *
char mainMenuItem[nMainMenu][12] = {"Inforamtion","Setting", "Return" };
char subMenuItem[nSubMenu][12] = {"Networks","Warn Level","Return" };

int nItemMainMenu = 0;
int nItemSubMenu = 0;

// ------------------------------------------------------------------
const int MIN_WARN_LEVEL = 3;  // default 최저 경고레벨
const int MAX_WARN_LEVEL = 12; // default 최고 경고레벨
int warnLevel = 3;

// 25 pin
void hndlr_btnUp(Button2 &btn) {
  switch (btn.getType()) {
    case single_click:
      if(CUR_MODE == MENU_MODE) nItemMainMenu = nItemMainMenu == nMainMenu ? nMainMenu : nItemMainMenu + 1;
      if(CUR_MODE == WARN_CHANGE_MODE) warnLevel = warnLevel == MAX_WARN_LEVEL ? \
                                           warnLevel : warnLevel + 1 ;
    case long_click:
      break;
  }
}
// #33 pin
void hndlr_btnMenu(Button2 &btn) {

  switch (btn.getType()) {
    case single_click:
      if (CUR_MODE == MENU_MODE && nItemMainMenu == 0) SET_MODE(INFO_MODE);
      if (CUR_MODE == MENU_MODE && nItemMainMenu == 1) SET_MODE(SETTING_MODE);
      if (CUR_MODE == MENU_MODE && nItemMainMenu == 2) SET_MODE(RUNNING_MODE);

      if (CUR_MODE == SETTING_MODE && nItemSubMenu == 0) SET_MODE(NET_SETTING_MODE);
      if (CUR_MODE == SETTING_MODE && nItemSubMenu == 1) SET_MODE(WARN_CHANGE_MODE);
      if (CUR_MODE == SETTING_MODE && nItemSubMenu == 2) SET_MODE(RUNNING_MODE);

      if (CUR_MODE == RUNNING_MODE) SET_MODE(RUNNING_MODE);
      if (CUR_MODE == WARN_CHANGE_MODE ) SET_MODE(MENU_MODE);
      if (CUR_MODE == INFO_MODE ) SET_MODE(RUNNING_MODE);
      if (CUR_MODE == NET_SETTING_MODE) SET_MODE(REBOOT_MODE);
      if (CUR_MODE == WARN_CONFIRM_MODE) SET_MODE(RUNNING_MODE);
      break

}
// #32 pin
void hndlr_btnDn(Button2 &btn) {

  switch (btn.getType()) {
    case single_click:
      if(CUR_MODE == MENU_MODE) nItemMainMenu = nItemMainMenu == 0 ? 0 : nItemMainMenu - 1;
      if(CUR_MODE == WARN_CHANGE_MODE) warnLevel = warnLevel == MIN_WARN_LEVEL ? \
                                          warnLevel : warnLevel - 1 ;
    case long_click:
      break;
  }

}

void update_display(){
 chat * itemToDisplay ;
  switch CUR_MODE {
      case: MENU_MODE {
        Serial.printf("CUR_MODE: %s ", MODE_ITEM[CUR_MODE] );
        for(int i=0; i<MAX_MENU_ITEMS;i++) {

        }


        }
       break;

      case: MENU_MODE {
        Serial.printf("CUR_MODE: %s ", MODE_ITEM[CUR_MODE] );
        }
       break;
    }
}

void SET_MODE(int _CUR_){
  CUR_MODE = _CUR_

}
