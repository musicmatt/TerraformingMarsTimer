//--------------------------------- INCLUDES ----------------------------------
#include "main.h"
//---------------------------------- MACROS -----------------------------------

//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------

//------------------------- STATIC DATA & CONSTANTS ---------------------------

//------------------------------- GLOBAL DATA ---------------------------------
int num_players = 1;
//------------------------------ PUBLIC FUNCTIONS -----------------------------

//---------------------------- PRIVATE FUNCTIONS ------------------------------
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.print("TerraformingMars");
  lcd.setCursor(0, 1);
  lcd.print("Timer     v00.01");

  while(keypad.getKey() != '0')
  {
  } 
  while (phase_setup() != 1);  // koliko igraca, raspored/boja, vrijeme po igracu
  
}

void loop() {
  #if 0
  next_player();
  next_generation();
  #endif
}



//---------------------------- INTERRUPT HANDLERS -----------------------------
