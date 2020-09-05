//--------------------------------- INCLUDES ----------------------------------
#include "setup.h"
//---------------------------------- MACROS -----------------------------------
#define MIN_PLAYERS   '1'
#define MAX_PLAYERS   '5'
//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
void pick_color (PLAYER_T);
//------------------------- STATIC DATA & CONSTANTS ---------------------------
enum states{
  NUM_PLAYERS =         0U,
  PLAYER_COLOR =        1U,
  COUNTDOWN_TIME =      2U
};

static int state = NUM_PLAYERS;
static char key = 0;
static char perma_key = 0;
static int ite = 0;

//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
int phase_setup(void)
{
  switch (state)
  {
    case NUM_PLAYERS:
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
      
      num_players = perma_key - 48;
#ifndef DEBUG
      Serial.print("num_players: ");
      Serial.println(num_players);
#endif

      PLAYER_T *players = malloc (num_players * sizeof(PLAYER_T));
      
#ifndef DEBUG
      Serial.println("1");
#endif

      state = PLAYER_COLOR;
      break;
      
    case PLAYER_COLOR:

#ifndef DEBUG
      Serial.println("2");
#endif

      for (ite = 0; ite < num_players; ite++)
      {
#ifndef DEBUG
      Serial.println("3");
#endif
        pick_color(players[ite]);
      }
    
      break;
      
    case COUNTDOWN_TIME:
      return 1;
      break;
      
    default:
      break;
  }
}


//---------------------------- PRIVATE FUNCTIONS ------------------------------
void pick_color (PLAYER_T)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("player ");
  lcd.print(ite);
  while(1);
}
//---------------------------- INTERRUPT HANDLERS -----------------------------
