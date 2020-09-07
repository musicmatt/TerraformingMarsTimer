
//--------------------------------- INCLUDES ----------------------------------
#include "bsp.h"
//---------------------------------- MACROS -----------------------------------
#define LED_PIN_RED     6
#define LED_PIN_BLUE    9
#define LED_PIN_GREEN   10
//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------

//------------------------- STATIC DATA & CONSTANTS ---------------------------

//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------

void led_init (void)
{
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_BLUE, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);

  led_off();
}

void led_off (void)
{
  analogWrite(LED_PIN_RED, 0);
  analogWrite(LED_PIN_BLUE, 0);
  analogWrite(LED_PIN_GREEN, 0);
}

void led_set (int red_val, int blue_val, int green_val)
{
  analogWrite(LED_PIN_RED, red_val);
  analogWrite(LED_PIN_BLUE, blue_val);
  analogWrite(LED_PIN_GREEN, green_val);
}
//---------------------------- PRIVATE FUNCTIONS ------------------------------

//---------------------------- INTERRUPT HANDLERS -----------------------------
