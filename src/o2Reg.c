#include "o2Reg.h"




const int nMainMenu = 3;
const int nSubMenu = 3;

int CUR_MODE = 0;
int warnLevel = 3;

char MODE_ITEM[10][20] = {"MEMU_MODE","BOOT_MODE","RUNNING_MODE","WARN_CHANGE_MODE","INFO_MODE","SETTING_MODE","NET_SETTING_MODE","NET_CHECK_MODE","REBOOT_MODE","WARN_CONFIRM_MODE"};
//char MODE_SUB_SETTING_ITEM[3][20] =

char mainMenuItem[nMainMenu][12] = {"Inforamtion","Setting", "Return" };
char subMenuItem[nSubMenu][12] = {"Networks","Warn Level","Return" };

int nItemMainMenu = 0;
int nItemSubMenu = 0;

// ------------------------------------------------------------------
const int MIN_WARN_LEVEL = 3;  // default 최저 경고레벨
const int MAX_WARN_LEVEL = 12; // default 최고 경고레벨
