//
// my_lcd_scan.h
//

#pragma once

#define MY_LCD_FONT_WIDTH 5
#define MY_LCD_FONT_HGAP  1
#define MY_LCD_MAX_HCHARS ( LCD_PAGE_LEN / ( MY_LCD_FONT_WIDTH + MY_LCD_FONT_HGAP ) )

#include "my_led_scan.h"

//------------------------------------------------------------------------------
// Typedefs
//------------------------------------------------------------------------------

typedef enum MyLcdControlMode {
  MyLcdControlMode_rotate_image = 0,
} MyLcdControlMode;

typedef struct MyLcdControl {
	MyLcdControlMode mode;
	uint8_t          amount;
	uint16_t         index;
} MyLcdControl;

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

void LCD_writeDisplayReg( uint8_t page, uint8_t *buffer, uint8_t len );
void my_LCD_set_str( const char* s, const uint8_t row, const uint8_t col );
void my_LCD_display_image( const uint8_t img_idx );
