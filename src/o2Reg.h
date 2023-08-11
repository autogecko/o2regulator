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

char MODE_ITEM[10][20] = {"MEMU_MODE","BOOT_MODE","RUNNING_MODE","WARN_CHANGE","INFO_MODE","SETTING_MODE","NETSETTING_MODE","NET_CHECK_MODE","REBOOT_MODE","WARN_CONFIRM_MODE"};
char mainMenuItem[nMainMenu][12] = {"Inforamtion","Setting", "Return" };
char subMenuItem[nSubMenu][12] = {"Networks","Warn Level","Return" };

int nItemMainMenu = 0;
int nItemSubMenu = 0;
// #25 pin
void hndlr_btnUp(Button2 &btn) {
  switch (btn.getType()) {
    case single_click:
      if(CUR_MODE == MENU_MODE)

    case long_click:
      Serial.print("");
      break;
  }
}
// #33 pin
void hndlr_btnMenu(Button2 &btn) {
}
// #32 pin
void hndlr_btnDn(Button2 &btn) {
  switch (btn.getType()) {
    case single_click:
      Serial.print("single clicked \n");
      break;
    case long_click:
      Serial.print("long clicked \n");
      break;
  }
}

void update_display(){
Serial.printf("CURRENT MODE: %s /n", MODE_ITEM[CUR_MODE]);

}
