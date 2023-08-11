#ifndef O2REG_H_
#define O2REG_H_

#endif // O2REG_H_

#include "Button2.h"

extern Button2 btnUp, btnMenu, btnDn ;

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


#define nMainMenu 3
#define nSubMenu 3
#define MIN_WARN_LEVEL 3
#define MAX_WARN_LEVEL 12





extern int CUR_MODE ;
extern int warnLevel ;
extern int nItemMainMenu ;
extern int nItemSubMenu ;

extern char MODE_ITEM[10][20];;
//char MODE_SUB_SETTING_ITEM[3][20] =

extern char mainMenuItem[nMainMenu][12];
extern char subMenuItem[nSubMenu][12] ;

// ------------------------------------------------------------------
void set_mode(int _CUR_);
void hndlr_btnUp(Button2 &btn) ;
void hndlr_btnMenu(Button2 &btn);
void hndlr_btnDn(Button2 &btn) ;
void update_display();
