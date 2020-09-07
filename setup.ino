//--------------------------------- INCLUDES ----------------------------------
#include "setup.h"
//---------------------------------- MACROS -----------------------------------
#define MIN_PLAYERS   '1'
#define MAX_PLAYERS   '5'
//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
//------------------------- STATIC DATA & CONSTANTS ---------------------------
static char key = 0;
static char perma_key = 0;

//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void phase_setup(void)
{      
  // not implemented
}

int select_num_players (void)
{
#ifndef DEBUG
    Serial.println("Select num players");
#endif

  lcd.clear();
  lcd.print("Num players:");
  lcd.setCursor(0, 1);
  lcd.noCursor();
  while(1)
  {
    while((key = keypad.getKey()) == NO_KEY);
#ifndef DEBUG
    Serial.println(key);
#endif
    if (key == '#')
    {
      break;
    }
    if ((MIN_PLAYERS <= key) && (MAX_PLAYERS >= key))
    {
      perma_key = key;
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print(perma_key);
#ifndef DEBUG
      Serial.print("--------    ");
      Serial.println(perma_key);
#endif
    }
  }
  
  return perma_key - 48;
}

char* pick_color (int ite)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("player ");
  lcd.print(ite+1);
  lcd.print(" color:");
  while(1)
  {
    while((key = keypad.getKey()) == NO_KEY);
#ifndef DEBUG
    Serial.println(key);
#endif
    if (key == '#')
    {
      break;
    }
    if ((MIN_PLAYERS <= key) && (MAX_PLAYERS >= key))
    {
      perma_key = key - 48;
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print(colors[perma_key-1]);
#ifndef DEBUG
      Serial.print("--------    ");
      Serial.println(colors[perma_key-1]);
#endif
    }  
  }
  return colors[perma_key-1];
}

int countdown_timer_setup (void)
{
  static int setc = 0;
  int minutes = 0;
  String mins;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Minutes on timer");
  lcd.setCursor(0,1);
  while(1)
  {
    while((key = keypad.getKey()) == NO_KEY);
#ifndef DEBUG
    Serial.println(key);
#endif
    if (key == '*')   // reset query
    {
      mins = "";
      setc = 0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Minutes on timer");
      lcd.setCursor(0,1);
    }
    
    if (key == '#') // done with entering minutes
    {
      break;
    }
    
    if (('0' <= key) && ('9' >= key))
    {
      lcd.print(key);
      setc++;
      lcd.setCursor(setc, 1);
      mins = mins + key;
      
#ifndef DEBUG
      Serial.print("--------    ");
      Serial.println(key);
#endif
    }  
  }
  minutes = mins.toInt();
  return minutes;
}

void start_screen (int num_players, int minutes, PLAYER_T *players)
{
  lcd.clear();
  lcd.print("Start?");
  lcd.setCursor(0,1);
  lcd.print(num_players);
  lcd.print("P      ");
  lcd.print(minutes);
  lcd.print("min");
  
  while(1)
  {
    while((key = keypad.getKey()) == NO_KEY);
#ifndef DEBUG
    Serial.println(key);
#endif
    if (key == '#') // done with entering minutes
    {
      break;
    }
  }

  for (ite = 0; ite < num_players; ite++)
  {
    players[ite].cd_time = minutes * 60;
  }
}
//---------------------------- PRIVATE FUNCTIONS ------------------------------
//---------------------------- INTERRUPT HANDLERS -----------------------------
