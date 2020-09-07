
//--------------------------------- INCLUDES ----------------------------------
#include "timer.h"
//---------------------------------- MACROS -----------------------------------
#define INTERVAL 1
//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
void next_player (int *current_player, int num_players);
void big_pass (int *current_player, PLAYER_T *players);
void toggle_pause (void);
int next_generation (int *current_player, PLAYER_T *players, int num_players);
void disp_paused (void);
void disp_resumed (void);
void disp_next_gen (int *current_player, PLAYER_T *players);

//------------------------- STATIC DATA & CONSTANTS ---------------------------
static unsigned long current_millis;
static long current_secs;
static long previous_secs;
static int first_player = 0;
static int generation = 1;
static boolean paused = false;
//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
int timer_run (int *current_player, PLAYER_T *players, int num_players)
{  
  key = keypad.getKey();
  current_millis = millis();
  current_secs = (signed long)(current_millis / 1000); 
  
  if ((current_secs - previous_secs) >= INTERVAL) 
  {
    previous_secs = current_secs;
    if (paused == false)
    {
      players[*current_player].cd_time = players[*current_player].cd_time - INTERVAL;
      disp_time(players[*current_player].color, players[*current_player].cd_time/60, players[*current_player].cd_time%60);
    }
  }
  if (paused == false) 
  {
    if (key == '#')
    {
      next_player(current_player, players, num_players);
    }
  
    if (key == '*')
    {
      big_pass(current_player, players, num_players);
    }
  }

  if (key == '6')
  {
    toggle_pause();
  }   

  return 1;
}

void disp_time (char *color, int minutes, int seconds)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(color);
  lcd.setCursor(0,1);
  lcd.print(minutes);
  lcd.print(":");
  lcd.print(seconds);
}

//---------------------------- PRIVATE FUNCTIONS ------------------------------

void next_player (int *current_player, PLAYER_T *players, int num_players)
{
  do{
    *current_player = ((*current_player) + 1) % num_players;
  } while(players[*current_player].pass);

  led_set(players[*current_player].led_color[0], players[*current_player].led_color[1], players[*current_player].led_color[2]);
  
#ifndef DEBUG
  Serial.print("next player: ");
  Serial.println(players[*current_player].color);
#endif
}

void big_pass (int *current_player, PLAYER_T *players, int num_players)
{
  players[*current_player].pass = true;
  disp_player_big_pass(players[*current_player].color);
#ifndef DEBUG
    Serial.print("player: ");
    Serial.print(players[*current_player].color);
    Serial.print("  pass: ");
    Serial.println(players[*current_player].pass);
#endif

  int i;
  boolean passed = true;
  for(i = 0; (i < num_players) && passed; i++) 
  {
    passed &= players[i].pass;
  }

  if (passed)
  {
    next_generation(current_player, players, num_players);
  }
  else
  {
    next_player(current_player, players, num_players);
  }
}

void toggle_pause (void)
{
  if ( paused == false)
  {
    paused = true;
#ifndef DEBUG
    Serial.println("Timer stopped");
#endif
    disp_paused();
  }
  else
  {
    paused = false;
#ifndef DEBUG
    Serial.println("Timer resumed");
#endif
    disp_resumed();
  }
}

int next_generation (int *current_player, PLAYER_T *players, int num_players)
{
  led_off();
  for (ite = 0; ite < num_players; ite++)
  {
    players[ite].pass = false;
  }

  first_player++;
  generation++;

  *current_player = first_player % num_players;
  
#ifndef DEBUG
    Serial.print("Ready for next gen?   g:");
    Serial.print(generation);
    Serial.print("   p:");
    Serial.println(players[*current_player].color);
#endif

  disp_next_gen(current_player, players);
  led_set(players[*current_player].led_color[0], players[*current_player].led_color[1], players[*current_player].led_color[2]);
}


void disp_player_big_pass (char *color)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(color);
  lcd.setCursor(7,0);
  lcd.print("BIG PASS");
  
  lcd.setCursor(0,1);
  lcd.print("3");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("2");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("1");
  delay(1000);
}


void disp_paused (void)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PAUSED");
  lcd.setCursor(0,1);
  lcd.print("6 to resume");
}

void disp_resumed (void)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RESUMING IN");
  lcd.setCursor(0,1);
  lcd.print("3");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("2");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("1");
  delay(1000);
}

void disp_next_gen (int *current_player, PLAYER_T *players)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RDY NEXT GEN(");
  lcd.print(generation);
  lcd.print(")?");
  lcd.setCursor(0,1);
  lcd.print(players[*current_player].color);
  lcd.setCursor(15,1);
  lcd.print("#");
  while((key = keypad.getKey()) != '#');
}
//---------------------------- INTERRUPT HANDLERS -----------------------------
