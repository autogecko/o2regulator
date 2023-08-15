#ifndef O2REG_H_
#define O2REG_H_

#endif // O2REG_H_
#include "Arduino.h"
#include "Button2.h"

//#include "secrets.h"
#include <WiFiMQTTManager.h>

enum Mode_Type {
  MENU_MODE = 0,
  BOOT_MODE,
  RUNNING_MODE,
  WARN_CHANGE_MODE,
  INFO_MODE ,
  SETTING_MODE,
  NET_SETTING_MODE,
  NET_CHECK_MODE,
  REBOOT_MODE,
  WARN_CONFIRM_MODE
};

static Mode_Type CUR_MODE = MENU_MODE;

#define nMainMenu 3
#define nSubMenu 3
#define MIN_WARN_LEVEL 3
#define MAX_WARN_LEVEL 12
#define RESET_BUTTON  26

static char * AP_PASSWORD ="CHANGEME";  // This is the password for your configuration access point, change as desired



extern int warnLevel ;
extern int nSelectedMainMenu ;
extern int nSelectedSubMenu ;

extern char MODE_ITEM[10][20];;
//char MODE_SUB_SETTING_ITEM[3][20] =

extern char mainMenuItem[nMainMenu][12];
extern char subMenuItem[nSubMenu][12] ;

static Button2 btnUp, btnMenu, btnDn ;

extern WiFiMQTTManager wmm;
static int pressureValue = 100;
// ------------------------------------------------------------------
//
// extern "C" void set_mode(int _CUR_);
// extern "C" void hndlr_btnUp(Button2 &btn) ;
// extern "C" void hndlr_btnMenu(Button2 &btn);
// extern "C" void hndlr_btnDn(Button2 &btn) ;
// extern "C" void update_display();

void set_mode(int _CUR_);
void hndlr_btnUp(Button2 &btn) ;
void hndlr_btnMenu(Button2 &btn);
void hndlr_btnDn(Button2 &btn) ;
void update_display();

void subscribeTo() ;
void subscriptionCallback(char* topic, byte* message, unsigned int length) ;
bool initWiFi();
