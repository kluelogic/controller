//
// my_led_scan.h
//

#pragma once

#include "my_lcd_scan.h"

//------------------------------------------------------------------------------
// Typedefs
//------------------------------------------------------------------------------

typedef enum MyLedControlMode {
  MyLedControlMode_rotate_MODE = 0,
  MyLedControlMode_rotate_FS   = 1,
  MyLedControlMode_rotate_PFS  = 2,
  MyLedControlMode_rotate_CNS  = 3,
  MyLedControlMode_rotate_FNS  = 4,
  MyLedControlMode_rotate_FDT  = 5,
  MyLedControlMode_rotate_IC   = 6,
  MyLedControlMode_rotate_BE   = 7,
  MyLedControlMode_rotate_BPT  = 8,
  MyLedControlMode_rotate_AE   = 9,
  MyLedControlMode_rotate_FOT  = 10,
  MyLedControlMode_rotate_FIT  = 11,
  MyLedControlMode_rotate_B_EN = 12,
  MyLedControlMode_rotate_ET   = 13,
  MyLedControlMode_rotate_SSD  = 14,
  MyLedControlMode_rotate_AGCM = 15,
  MyLedControlMode_rotate_AGC  = 16,
  MyLedControlMode_rotate_AGS  = 17,
  MyLedControlMode_rotate_AAR  = 18,

  MyLedControlMode_set_picture_frame      = 20,
  MyLedControlMode_increase_picture_frame = 21,

  MyLedControlMode_rotate_demo = 30
} MyLedControlMode;

typedef struct MyLedControl {
	MyLedControlMode mode;
	uint8_t          amount;
	uint16_t         index;
} MyLedControl;

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//void my_LED_get_reg( char* buf, uint8_t line );
void    LED_sendPage( uint8_t *buffer, uint8_t len, uint8_t page );
void my_LED_sendPage( uint8_t *buffer, uint8_t len, uint8_t page );
