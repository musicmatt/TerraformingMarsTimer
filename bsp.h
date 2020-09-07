#ifndef __BSP_H__
#define __BSP_H__
//--------------------------------- INCLUDES ----------------------------------
#include <LiquidCrystal.h>
#include <Keypad.h>
//---------------------------------- MACROS -----------------------------------

//-------------------------------- DATA TYPES ---------------------------------
typedef struct player {
  char *color;
  int led_color[3];
  long cd_time;
  boolean pass;
}PLAYER_T;

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------

//------------------------- STATIC DATA & CONSTANTS ---------------------------

//------------------------------- GLOBAL DATA ---------------------------------
char *colors[5] = {"BLACK", "BLUE", "RED", "YELLOW", "GREEN"};

int led_colors[5][3] = {
  {128, 128, 0},
  {0, 170, 0},
  {255, 0, 0},
  {128, 0, 255},
  {0, 0, 255}
};

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
void led_init (void);
void led_off (void);
void led_set (int red_val, int blue_val, int green_val);

//---------------------------- PRIVATE FUNCTIONS ------------------------------

//---------------------------- INTERRUPT HANDLERS -----------------------------
#endif
