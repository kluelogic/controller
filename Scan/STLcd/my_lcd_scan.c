//
// my_lcd_scan.c
//

//------------------------------------------------------------------------------
// Function: my_LCD_set_char
//
// c:   ASCII character between ' ' (space) and '~'
// col: 1 to LCD_PAGE_LEN / ( MY_LCD_FONT_WIDTH + MY_LCD_FONT_HGAP )
// row: 1 to LCD_TOTAL_VISIBLE_PAGES
//
//     |---> col
// ----+--------------------------------+
//  |  |     |                          |
//  v  |     |                          |
// row |---- c                          |
//     |                                |
//     +--------------------------------+
//------------------------------------------------------------------------------

void my_LCD_set_char( char c, uint8_t row, uint8_t col ) {
  uint8_t page_idx;
  uint8_t char_idx;

  if ( c < ' ' || c > '~' ) return;
  if ( row < 1 || row > LCD_PAGE_LEN ) return;
  if ( col < 1 || col > MY_LCD_MAX_HCHARS ) return;

  char_idx = c - 0x20; // ASCII space is 0x20
  page_idx = LCD_TOTAL_VISIBLE_PAGES - row;
  for ( uint8_t p = 0; p < MY_LCD_FONT_WIDTH; p++ ) { // p: pixel
    uint16_t pixel_idx = LCD_PAGE_LEN * page_idx + ( MY_LCD_FONT_WIDTH + MY_LCD_FONT_HGAP ) * ( col - 1 ) + p;

    STLcdImage3[ pixel_idx ] = my_font5x7[ char_idx ][ p ];
  }
} // my_LCD_set_char

//------------------------------------------------------------------------------
// Function: my_LCD_set_str
//
// s:   ASCII string (it does not wrap around)
// col: 1 to LCD_PAGE_LEN / ( MY_LCD_FONT_WIDTH + MY_LCD_FONT_HGAP )
// row: 1 to LCD_TOTAL_VISIBLE_PAGES
//
//     |---> col
// ----+--------------------------------+
//  |  |     |                          |
//  v  |     |                          |
// row |---- sss                        |
//     |                                |
//     +--------------------------------+
//------------------------------------------------------------------------------

void my_LCD_set_str( char* s, uint8_t row, uint8_t col ) {
  uint8_t i;

  i = 0;
  while ( s[i] ) {
    my_LCD_set_char( s[i], row, col + i );
    i++;
  }
} // my_LCD_set_str

//------------------------------------------------------------------------------
// Function: my_LCD_writeDisplayRegs
//------------------------------------------------------------------------------

void my_LCD_writeDisplayRegs( uint8_t img_idx ) {
  for ( uint8_t page = 0; page < LCD_TOTAL_VISIBLE_PAGES; page++ ) {
    switch ( img_idx ) {
    case 0: LCD_writeDisplayReg( page, (uint8_t*)&STLcdDefaultImage[ page * LCD_PAGE_LEN ], LCD_PAGE_LEN ); break;
    case 1: LCD_writeDisplayReg( page, (uint8_t*)&STLcdImage1      [ page * LCD_PAGE_LEN ], LCD_PAGE_LEN ); break;
    case 2: LCD_writeDisplayReg( page, (uint8_t*)&STLcdImage2      [ page * LCD_PAGE_LEN ], LCD_PAGE_LEN ); break;
    case 3: LCD_writeDisplayReg( page, (uint8_t*)&STLcdImage3      [ page * LCD_PAGE_LEN ], LCD_PAGE_LEN ); break;
    }
  }
} // my_LCD_writeDisplayRegs

//------------------------------------------------------------------------------
// Function: my_LCD_display
//------------------------------------------------------------------------------

void my_LCD_display( MyLcdControl* control ) {
  switch ( control->mode ) {
  case MyLcdControlMode_rotate_image:
    image_idx += control->amount;
    if ( image_idx > 3 ) image_idx = 0;
    my_LCD_writeDisplayRegs( image_idx );
  }
} // my_LCD_display

//------------------------------------------------------------------------------
// Function: my_LCD_display_capability
//------------------------------------------------------------------------------

void my_LCD_display_capability( uint8_t state, uint8_t stateType, uint8_t *args ) {
  if ( stateType == 0xFF && state == 0xFF ) return;
  if ( stateType == 0x00 && state == 0x02 ) return; // on hold
  if ( stateType == 0x00 && state == 0x03 ) return; // on release

  MyLcdControl* control = ( MyLcdControl* ) args;

  my_LCD_display( control );
} // my_LCD_display_capability
