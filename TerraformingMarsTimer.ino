//--------------------------------- INCLUDES ----------------------------------
#include "main.h"
//---------------------------------- MACROS -----------------------------------

//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
void print_out_structs (int num_players, PLAYER_T *players);
//------------------------- STATIC DATA & CONSTANTS ---------------------------
static int ite = 0;
static int cd_minutes = 0;
//------------------------------- GLOBAL DATA ---------------------------------
int num_players = 1;
int current_player = 0;
PLAYER_T *players;

//------------------------------ PUBLIC FUNCTIONS -----------------------------

//---------------------------- PRIVATE FUNCTIONS ------------------------------
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.print("TerraformingMars");
  lcd.setCursor(0, 1);
  lcd.print("Timer     v01.00");
  
#ifndef DEBUG
  Serial.println("Press 0 to start");
#endif
  
  while(keypad.getKey() != '0');
  
  num_players = select_num_players(); // koliko igraca
  
  players = malloc (num_players * sizeof(PLAYER_T));
  
  for (ite = 0; ite < num_players; ite++)
  {
    players[ite].color = pick_color(ite);    // raspored boja
  }

  cd_minutes = countdown_timer_setup();
  Serial.print("minutes: ");
  Serial.println(cd_minutes);

  start_screen(num_players, cd_minutes, players);

  print_out_structs(num_players, players);
}

void loop() {
  timer_run(&current_player, players, num_players);
}


void print_out_structs (int num_players, PLAYER_T *players)
{
  for (ite = 0; ite < num_players; ite++)
  {
    Serial.print("player.color: ");
    Serial.print(players[ite].color);
    Serial.print("\t player.cd_time: ");
    Serial.println(players[ite].cd_time);
  } 
}



//---------------------------- INTERRUPT HANDLERS -----------------------------
