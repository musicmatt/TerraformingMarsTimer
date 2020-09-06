#ifndef __SETUP_H__
#define __SETUP_H__

//--------------------------------- INCLUDES ----------------------------------
#include "bsp.h"
//---------------------------------- MACROS -----------------------------------

//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------

//------------------------- STATIC DATA & CONSTANTS ---------------------------

//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void phase_setup (void);
int select_num_players (void);
char* pick_color (int ite);
int countdown_timer_setup (void);
void start_screen (int num_players, int minutes, PLAYER_T *players);

//---------------------------- PRIVATE FUNCTIONS ------------------------------

//---------------------------- INTERRUPT HANDLERS -----------------------------
#endif
