//
// my_led_scan.c
//

//------------------------------------------------------------------------------
/**
   Concatenate two strings.
   Append `src` string to `dst` string.
   @param[in,out] dst 
   @param[in]     src 
*/
//------------------------------------------------------------------------------

void my_LED_strcat( char* dst, const char* src ) {
  uint8_t i, len = 0;

  while ( dst[len] ) len++;
  for ( i = 0; src[i]; i++ ) dst[ len + i ] = src[i];
  dst[ len + i ] = '\0';
} // my_LED_strcat

//------------------------------------------------------------------------------
/**
   Reverse a string.
   @param[in,out] s A string to reverse.
*/
//------------------------------------------------------------------------------

void my_LED_reverse( char* s ) {
  uint8_t i, j, len = 0;
  char c;

  while ( s[len] ) len++;
  for ( i = 0, j = len - 1; i < j; i++, j-- ) {
    c    = s[i];
    s[i] = s[j];
    s[j] = c;
  }
} // my_LED_reverse

//------------------------------------------------------------------------------
/**
   Convert an integer into a string.
   @param[in]  n An interger. It must be between 0 and 255.
   @param[out] s String representation of the integer, `n`.
*/
//------------------------------------------------------------------------------

void my_LED_itoa( uint8_t n, char* s ) {
  uint8_t i = 0;

  do {
    s[i++] = n % 10 + '0';
  } while ( ( n /= 10 ) > 0 );
  s[i] = '\0';
  my_LED_reverse( s );
} // my_LED_itoa

//------------------------------------------------------------------------------
// Function: my_LED_get_reg - unused
//------------------------------------------------------------------------------
/*
void my_LED_get_reg( char* buf, uint8_t line ) {
  char s[3];

  switch ( line ) {
  case 0:
    my_LED_strcat( buf, "ISSI Registers" );
    my_LED_strcat( buf, "|MODE" );  my_LED_itoa( mode, s );  my_LED_strcat( buf, s );
    break;
  case 1:
    my_LED_strcat( buf, "PFS"  );  my_LED_itoa( pfs,  s );  my_LED_strcat( buf, s );
    my_LED_strcat( buf, "|IC " );  my_LED_itoa( ic,   s );  my_LED_strcat( buf, s );
    my_LED_strcat( buf, "|BE " );  my_LED_itoa( be,   s );  my_LED_strcat( buf, s );
    my_LED_strcat( buf, "|BPT" );  my_LED_itoa( bpt,  s );  my_LED_strcat( buf, s );
    break;
  case 2:
    my_LED_strcat( buf, "FS "  );  my_LED_itoa( fs,   s );  my_LED_strcat( buf, s );
    my_LED_strcat( buf, "|CNS" );  my_LED_itoa( cns,  s );  my_LED_strcat( buf, s );
    my_LED_strcat( buf, "|FNS" );  my_LED_itoa( fns,  s );  my_LED_strcat( buf, s );
    my_LED_strcat( buf, "|FDT" );  my_LED_itoa( fdt,  s );  my_LED_strcat( buf, s );
    break;
  case 3:
    my_LED_strcat( buf, "BEN"  );  my_LED_itoa( b_en, s );  my_LED_strcat( buf, s );
    my_LED_strcat( buf, "|FIT" );  my_LED_itoa( fit,  s );  my_LED_strcat( buf, s );
    my_LED_strcat( buf, "|FOT" );  my_LED_itoa( fot,  s );  my_LED_strcat( buf, s );
    my_LED_strcat( buf, "|ET"  );  my_LED_itoa( et,   s );  my_LED_strcat( buf, s );
    break;
  }
}
*/
//------------------------------------------------------------------------------
/**
   Write the specified brightness-definition array to an LED page buffer.
   @param[in] brightness Array of brightness definition (8-bit unsigned integer).
   @param[in] len        Length of the array.
   @param[in] page       LED page number. Must be between 0 and 7.
 */
//------------------------------------------------------------------------------

void my_LED_write_page( uint8_t *brightness, uint8_t len, uint8_t page ) {
  LED_sendPage( brightness, len, page );
  delay( 30 ); // wait 30[ms]
} // my_LED_write_page

//------------------------------------------------------------------------------
/**
   Set the brightness of all LEDs as specified.
   @param[in] amount Brightness to be set.
 */
//------------------------------------------------------------------------------

void my_LED_set_all_brightness( uint8_t amount ) {
  LedControl led_ctrl;

  led_ctrl.mode   = LedControlMode_brightness_set_all;
  led_ctrl.amount = amount;
  led_ctrl.index  = 0x00; // dummy
  LED_control( &led_ctrl );
} // my_LED_set_all_brightness

//------------------------------------------------------------------------------
/**
   Write the current **mode** and **fs** values to the Configuration Register.
   The layout of LED register display on the LCD:

       :            111111111122
       :   123456789012345678901
       :   ---------+---------+-
       : 1 ISSI Registers|MOD#
       : 2 PFS#|IC #|BE #|BPT#
       : 3 FS #|CNS#|FNS#|FDT##
       : 4 BEN#|FIT#|FOT#|ET #
 */
//------------------------------------------------------------------------------

void my_LED_write_Configuration_Reg() {
  uint8_t mode_fs;
  char s[3];

  mode_fs = ( mode << 3 ) | fs;
  LED_writeReg( 0x00, mode_fs, 0x0B ); // Configuration Register (0x00)
  my_LED_itoa( mode, s ); my_LCD_set_str( s, 1, 19 );
  my_LED_itoa(   fs, s ); my_LCD_set_str( s, 3,  4 );
  my_LCD_display_image( 3 );
} // my_LED_write_Configuration_Reg

//------------------------------------------------------------------------------
/**
   Write the current **pfs** value to the Picture Display Register.
*/
//------------------------------------------------------------------------------

void my_LED_write_Picture_Display_Reg() {
  char s[3];

  LED_writeReg( 0x01, pfs, 0x0B ); // Picture Display Register (0x01)
  my_LED_itoa( pfs, s );
  my_LCD_set_str( s, 2, 4 );
  my_LCD_display_image( 3 );
} // my_LED_write_Picture_Display_Reg

//------------------------------------------------------------------------------
/**
   Write the current **cns** and **fns** values to the Auto Play Control Register 1.
*/
//------------------------------------------------------------------------------

void my_LED_write_Auto_Play_Control_Reg1() {
  uint8_t cns_fns;
  char s[3];

  cns_fns = ( cns << 4 ) | fns;
  LED_writeReg( 0x02, cns_fns, 0x0B ); // Auto Play Control Register (0x02)
  my_LED_itoa( cns, s ); my_LCD_set_str( s, 3,  9 );
  my_LED_itoa( fns, s ); my_LCD_set_str( s, 3, 14 );
  my_LCD_display_image( 3 );
} // my_LED_write_Auto_Play_Control_Reg1

//------------------------------------------------------------------------------
/**
   Write the current **fdt** value to the Auto Play Control Register 2.
*/
//------------------------------------------------------------------------------

void my_LED_write_Auto_Play_Control_Reg2() {
  char s[3];

  LED_writeReg( 0x03, fdt, 0x0B ); // Auto Play Control Register (0x03)
  my_LED_itoa( fdt, s );
  my_LCD_set_str( s, 3, 19 );
  my_LCD_display_image( 3 );
} // my_LED_write_Auto_Play_Control_Reg2

//------------------------------------------------------------------------------
/**
   Write the current **ic**, **be**, and **bpt** values to the Display Option Register.
*/
//------------------------------------------------------------------------------

void my_LED_write_Display_Option_Reg() {
  uint8_t ic_be_bpt;
  char s[3];

  ic_be_bpt = ( ic << 5 ) | ( be << 3 ) | bpt;
  LED_writeReg( 0x05, ic_be_bpt, 0x0B ); // Display Option Register (0x05)
  my_LED_itoa(  ic, s ); my_LCD_set_str( s, 2,  9 );
  my_LED_itoa(  be, s ); my_LCD_set_str( s, 2, 14 );
  my_LED_itoa( bpt, s ); my_LCD_set_str( s, 2, 19 );
  my_LCD_display_image( 3 );
} // my_LED_write_Display_Option_Reg

//------------------------------------------------------------------------------
/**
   Write the current **fot** and **fit** values to the Breath Control Register 1.
*/
//------------------------------------------------------------------------------

void my_LED_write_Breath_Control_Reg1() {
  uint8_t fot_fit;
  char s[3];

  fot_fit = ( fot << 4 ) | fit;
  LED_writeReg( 0x08, fot_fit, 0x0B ); // Breath Control Register 1 (0x08)
  my_LED_itoa( fot, s ); my_LCD_set_str( s, 4, 14 );
  my_LED_itoa( fit, s ); my_LCD_set_str( s, 4,  9 );
  my_LCD_display_image( 3 );
} // my_LED_write_Breath_Control_Reg1

//------------------------------------------------------------------------------
/**
   Write the current **b_en** and **et** values to the Breath Control Register 2.
*/
//------------------------------------------------------------------------------

void my_LED_write_Breath_Control_Reg2() {
  uint8_t b_en_et;
  char s[3];

  b_en_et = ( b_en << 4 ) | et;
  LED_writeReg( 0x09, b_en_et, 0x0B ); // Breath Control Register 2 (0x09)
  my_LED_itoa( b_en, s ); my_LCD_set_str( s, 4,  4 );
  my_LED_itoa(   et, s ); my_LCD_set_str( s, 4, 19 );
  my_LCD_display_image( 3 );
} // my_LED_write_Breath_Control_Reg2

//------------------------------------------------------------------------------
/**
   Set the brightness of all LEDs to the highest.
 */
//------------------------------------------------------------------------------

void my_LED_turn_all_on() {
  my_LED_set_all_brightness( 0xff );
} // my_LED_turn_all_on

//------------------------------------------------------------------------------
/**
   Turn off all LEDs.
 */
//------------------------------------------------------------------------------

void my_LED_turn_all_off() {
  my_LED_set_all_brightness( 0x00 );
} // my_LED_turn_all_off

//------------------------------------------------------------------------------
/**
   Play all pages infinitely in the auto play mode.
   Set FIT=26ms, FDT=99ms, FOT=26ms, ET=3.5ms, and no breathing.

       :     FDT
       :     <->   ET
       :     ___  <->  __
       :    /   \     /
       : __/     \___/
       :   <-> <->
       :   FIT FOT
 */
//------------------------------------------------------------------------------

void my_LED_play_all_pages_infinitely() {

  // Restore the page 0 as it might have been modified.

  my_LED_write_page( (uint8_t*)My_LED_Brightness0, sizeof( My_LED_Brightness0 ), 0 );

  cns  = 0; // infinite
  fns  = 0; // use all frames
  fdt  = 9; // 99ms
  fit  = 0; // 26ms
  fot  = 0; // 26ms
  b_en = 0; // no breathing
  et   = 0; // 3.5ms
  mode = 1; // auto play mode
  fs   = 0; // starting frame 1
  my_LED_write_Auto_Play_Control_Reg1(); // cns, fns
  my_LED_write_Auto_Play_Control_Reg2(); // fdt
  my_LED_write_Breath_Control_Reg1();    // fot, fit
  my_LED_write_Breath_Control_Reg2();    // b_en, et
  my_LED_write_Configuration_Reg();      // mode, fs
} // my_LED_play_all_pages_infinitely

//------------------------------------------------------------------------------
/**
   Main LED control function.
*/
//------------------------------------------------------------------------------

void my_LED_control( MyLedControl *control ) {
  uint8_t send_page = 0;
  //  LedControl led_ctrl;

  switch ( control->mode ) {

  case MyLedControlMode_rotate_MODE:
    mode += control->amount;
    mode &= 0x3;
    if ( mode == 3 ) mode = 0;
    my_LED_write_Configuration_Reg();
    break;

  case MyLedControlMode_rotate_FS:
    fs += control->amount;
    fs &= 0x7;
    my_LED_write_Configuration_Reg();
    break;

  case MyLedControlMode_rotate_PFS:
    pfs += control->amount;
    pfs &= 0x7;
    my_LED_write_Picture_Display_Reg();
    break;

  case MyLedControlMode_rotate_CNS:
    cns += control->amount;
    cns &= 0x7;
    my_LED_write_Auto_Play_Control_Reg1();
    break;

  case MyLedControlMode_rotate_FNS:
    fns += control->amount;
    fns &= 0x7;
    my_LED_write_Auto_Play_Control_Reg1();
    break;

  case MyLedControlMode_rotate_FDT:
    fdt += control->amount;
    fdt &= 0x3F;
    my_LED_write_Auto_Play_Control_Reg2();
    break;

  case MyLedControlMode_rotate_IC: 
    ic += control->amount;
    ic &= 0x1;
    my_LED_write_Display_Option_Reg();
    break;

  case MyLedControlMode_rotate_BE:
    be += control->amount;
    be &= 0x1;
    my_LED_write_Display_Option_Reg();
    break;

  case MyLedControlMode_rotate_BPT:
    bpt += control->amount;
    bpt &= 0x7;
    my_LED_write_Display_Option_Reg();
    break;

  case MyLedControlMode_rotate_AE: break;

  case MyLedControlMode_rotate_FOT:
    fot += control->amount;
    fot &= 0x7;
    my_LED_write_Breath_Control_Reg1();
    break;

  case MyLedControlMode_rotate_FIT:
    fit += control->amount;
    fit &= 0x7;
    my_LED_write_Breath_Control_Reg1();
    break;

  case MyLedControlMode_rotate_B_EN:
    b_en += control->amount;
    b_en &= 0x1;
    my_LED_write_Breath_Control_Reg2();
    break;

  case MyLedControlMode_rotate_ET:
    et += control->amount;
    et &= 0x7;
    my_LED_write_Breath_Control_Reg2();
    break;

  case MyLedControlMode_rotate_SSD:  break;
  case MyLedControlMode_rotate_AGCM: break;
  case MyLedControlMode_rotate_AGC:  break;
  case MyLedControlMode_rotate_AGS:  break;
  case MyLedControlMode_rotate_AAR:  break;

    /*
  case MyLedControlMode_exec_key_func:
    led_ctrl.mode   = LedControlMode_brightness_increase;
    led_ctrl.amount = 0x80;
    led_ctrl.index  = control->index;
    LED_control( &led_ctrl );
    break;
    */

  case MyLedControlMode_set_picture_frame:
    pfs  = control->amount;
    pfs &= 0x7; // 3-bits
    my_LED_write_Picture_Display_Reg();
    break;

  case MyLedControlMode_increase_picture_frame:
    pfs += control->amount;
    pfs &= 0x7; // 3-bits
    my_LED_write_Picture_Display_Reg();
    break;

  case MyLedControlMode_rotate_demo:
    switch ( demo_id ) {
    case 0:
      my_LED_turn_all_off();
      break;
    case 1:
      my_LED_turn_all_on();
      break;
    case 2:
      my_LED_play_all_pages_infinitely();
      break;
    }
    demo_id += control->amount;
    demo_id &= 0x3;
    break;
  }

  if ( send_page ) { // Sync LED buffer with ISSI chip buffer; currently unused
    LED_pageBuffer.i2c_addr = 0xE8; // Chip 1
    LED_pageBuffer.reg_addr = 0x24; // Brightness section
    my_LED_write_page( (uint8_t*)&LED_pageBuffer, sizeof( LED_Buffer ), 0 );
  }
} // my_LED_control

//------------------------------------------------------------------------------
// Function: my_LED_control_capability
//------------------------------------------------------------------------------

void my_LED_control_capability( uint8_t state, uint8_t stateType, uint8_t *args ) {
  if ( stateType == 0xFF && state == 0xFF ) return;
  if ( stateType == 0x00 && state == 0x02 ) return; // on hold
  if ( stateType == 0x00 && state == 0x03 ) return; // on release

  uint8_t currentTime = (uint8_t)systick_millis_count;
  int8_t compare = (int8_t)(currentTime - LED_control_timer) & 0x7F;
  if ( compare < 30 ) {
      return;
  }
  LED_control_timer = currentTime;

  MyLedControl *control = (MyLedControl*)args;

  // Interconnect broadcasting
#if defined(ConnectEnabled_define)
  //  uint8_t send_packet = 0;
  uint8_t ignore_node = 0;

  // By default send to the *next* node, which will determine where to go next
  extern uint8_t Connect_id; // connect_scan.c
  //  uint8_t addr = Connect_id + 1;

  /*
  switch ( control->mode ) {
  case MyLedControlMode_exec_key_func:
  case MyLedControlMode_increase_picture_frame:
  case MyLedControlMode_set_auto_frame_play_mode:
    break;
  }
  */
  // Only send interconnect remote capability packet if necessary
  /*
  if ( send_packet ) {
      // generatedKeymap.h
      extern const Capability CapabilitiesList[];

      // Broadcast layerStackExact remote capability (0xFF is the broadcast id)
      Connect_send_RemoteCapability(
				    addr,
				    LED_control_capability_index,
				    state,
				    stateType,
				    CapabilitiesList[ LED_control_capability_index ].argCount,
				    args
				    );
    }
  */
  if ( ignore_node ) return; // If there is nothing to do on this node, ignore
#endif
  
  my_LED_control( control ); // Modify led state of this node
} // my_LED_control_capability
