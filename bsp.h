#ifndef __BSP_H__
#define __BSP_H__
//--------------------------------- INCLUDES ----------------------------------
#include <LiquidCrystal.h>
#include <Keypad.h>
//---------------------------------- MACROS -----------------------------------

//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------

//------------------------- STATIC DATA & CONSTANTS ---------------------------

//------------------------------- GLOBAL DATA ---------------------------------
typedef struct player {
  int color;
  unsigned long cd_time;
}PLAYER_T;

typedef enum colors {
  BLACK =   0U,
  BLUE =    1U,
  RED =     2U,
  YELLOW =  3U,
  GREEN =   4U
}colors;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {13, A5, A4, A3}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {A2, A1, A0}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//------------------------------ PUBLIC FUNCTIONS -----------------------------

//---------------------------- PRIVATE FUNCTIONS ------------------------------

//---------------------------- INTERRUPT HANDLERS -----------------------------
#endif
