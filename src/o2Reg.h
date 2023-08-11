#ifndef O2REG_H_
#define O2REG_H_



#endif // O2REG_H_

#define MENU_MODE 1
#define BOOT_MODE 2
#define RUNNING_MODE 3
#define WARN_CHANGE_MODE 4
#define INFO_MODE 5
#define SETTING_MODE 6
#define NET_SETTING_MODE 7
#define NET_CHECK_MODE 8
#define REBOOT_MODE 9
#define WARN_CONFIRM_MODE 10

#include "Button2.h"

Button2 btnUp, btnMenu, btnDn ;


extern const int nMainMenu ;
extern const int nSubMenu ;
extern int CUR_MODE ;
extern int warnLevel ;

char MODE_ITEM[10][20];;
//char MODE_SUB_SETTING_ITEM[3][20] =

char mainMenuItem[nMainMenu][12];
char subMenuItem[nSubMenu][12] ;
int nItemMainMenu ;
int nItemSubMenu ;

// ------------------------------------------------------------------
const int MIN_WARN_LEVEL;
const int MAX_WARN_LEVEL ;

void set_mode(int _CUR_){
  CUR_MODE = _CUR_;
}

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
      if (CUR_MODE == MENU_MODE && nItemMainMenu == 0) set_mode(INFO_MODE);
      if (CUR_MODE == MENU_MODE && nItemMainMenu == 1) set_mode(SETTING_MODE);
      if (CUR_MODE == MENU_MODE && nItemMainMenu == 2) set_mode(RUNNING_MODE);

      if (CUR_MODE == SETTING_MODE && nItemSubMenu == 0) set_mode(NET_SETTING_MODE);
      if (CUR_MODE == SETTING_MODE && nItemSubMenu == 1) set_mode(WARN_CHANGE_MODE);
      if (CUR_MODE == SETTING_MODE && nItemSubMenu == 2) set_mode(RUNNING_MODE);

      if (CUR_MODE == RUNNING_MODE) set_mode(RUNNING_MODE);
      if (CUR_MODE == WARN_CHANGE_MODE ) set_mode(MENU_MODE);
      if (CUR_MODE == INFO_MODE ) set_mode(RUNNING_MODE);
      if (CUR_MODE == NET_SETTING_MODE) set_mode(REBOOT_MODE);
      if (CUR_MODE == WARN_CONFIRM_MODE) set_mode(RUNNING_MODE);
      break;

  }
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
  switch (CUR_MODE) {
      case MENU_MODE :{
        Serial.printf("CUR_MODE: %s ", MODE_ITEM[CUR_MODE] );
        for(int i=0; i<nItemMainMenu ;i++) {
          if (i == nItemMainMenu) Serial.printf("* %d  MODE_ITEM[i]", i);
          else Serial.println(MODE_ITEM[i]);
        }
    }
       break;
    }
}
