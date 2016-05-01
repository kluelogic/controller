//
// my_led_scan.c
//

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

  MyLedControlMode_exec_key_func            = 20,
  MyLedControlMode_increase_picture_frame   = 21,
  MyLedControlMode_set_auto_frame_play_mode = 22,
} MyLedControlMode;

typedef struct MyLedControl {
	MyLedControlMode mode;
	uint8_t          amount;
	uint16_t         index;
} MyLedControl;

//------------------------------------------------------------------------------
// Function: my_LED_sendPage
//------------------------------------------------------------------------------

void my_LED_sendPage( uint8_t *buffer, uint8_t len, uint8_t page ) {
  LED_sendPage( buffer, len, page );
  delay( 30 ); // wait 30[ms]
}

//------------------------------------------------------------------------------
// Function: my_LED_control
//------------------------------------------------------------------------------

void my_LED_control( MyLedControl *control ) {
  uint8_t mode_fs;
  uint8_t cns_fns;
  uint8_t ic_be_bpt;
  uint8_t fot_fit;
  uint8_t b_en_et;

  uint8_t send_page = 0;
  LedControl led_ctrl;

  switch ( control->mode ) {

  case MyLedControlMode_rotate_MODE:
    mode += control->amount;
    mode &= 0x3;
    if ( mode == 3 ) mode = 0;
    mode_fs = ( mode << 3 ) | fs;
    LED_writeReg( 0x00, mode_fs, 0x0B ); // Configuration Register (0x00)
    break;

  case MyLedControlMode_rotate_FS:
    fs += control->amount;
    fs &= 0x7;
    mode_fs = ( mode << 3 ) | fs;
    LED_writeReg( 0x00, mode_fs, 0x0B ); // Configuration Register (0x00)
    break;

  case MyLedControlMode_rotate_PFS:
    pfs += control->amount;
    pfs &= 0x7;
    LED_writeReg( 0x01, pfs, 0x0B ); // Picture Display Register (0x01)
    break;

  case MyLedControlMode_rotate_CNS:
    cns += control->amount;
    cns &= 0x7;
    cns_fns = ( cns << 4 ) | fns;
    LED_writeReg( 0x02, cns_fns, 0x0B ); // Auto Play Control Register (0x02)
    break;

  case MyLedControlMode_rotate_FNS:
    fns += control->amount;
    fns &= 0x7;
    cns_fns = ( cns << 4 ) | fns;
    LED_writeReg( 0x02, cns_fns, 0x0B ); // Auto Play Control Register (0x02)
    break;

  case MyLedControlMode_rotate_FDT:
    fdt += control->amount;
    fdt &= 0x3F;
    LED_writeReg( 0x03, fdt, 0x0B ); // Auto Play Control Register (0x03)
    break;

  case MyLedControlMode_rotate_IC: 
    /*
    ic += control->amount;
    ic &= 0x1;
    ic_be_bpt = ( ic << 5 ) | ( be << 3 ) | bpt;
    LED_writeReg( 0x05, ic_be_bpt, 0x0B ); // Display Option Register (0x05)
    */
    break;

  case MyLedControlMode_rotate_BE:
    be += control->amount;
    be &= 0x1;
    ic_be_bpt = ( ic << 5 ) | ( be << 3 ) | bpt;
    LED_writeReg( 0x05, ic_be_bpt, 0x0B ); // Display Option Register (0x05)
    break;

  case MyLedControlMode_rotate_BPT:
    bpt += control->amount;
    bpt &= 0x7;
    ic_be_bpt = ( ic << 5 ) | ( be << 3 ) | bpt;
    LED_writeReg( 0x05, ic_be_bpt, 0x0B ); // Display Option Register (0x05)
    break;

  case MyLedControlMode_rotate_AE: break;

  case MyLedControlMode_rotate_FOT:
    fot += control->amount;
    fot &= 0x7;
    fot_fit = ( fot << 4 ) | fit;
    LED_writeReg( 0x08, fot_fit, 0x0B ); // Breath Control Register 1 (0x08)
    break;

  case MyLedControlMode_rotate_FIT:
    fit += control->amount;
    fit &= 0x7;
    fot_fit = ( fot << 4 ) | fit;
    LED_writeReg( 0x08, fot_fit, 0x0B ); // Breath Control Register 1 (0x08)
    break;

  case MyLedControlMode_rotate_B_EN:
    b_en += control->amount;
    b_en &= 0x1;
    b_en_et = ( b_en << 4 ) | et;
    LED_writeReg( 0x09, b_en_et, 0x0B ); // Breath Control Register 2 (0x09)
    break;

  case MyLedControlMode_rotate_ET:
    et += control->amount;
    et &= 0x7;
    b_en_et = ( b_en << 4 ) | et;
    LED_writeReg( 0x09, b_en_et, 0x0B ); // Breath Control Register 2 (0x09)
    break;

  case MyLedControlMode_rotate_SSD: break;
  case MyLedControlMode_rotate_AGCM: break;
  case MyLedControlMode_rotate_AGC: break;
  case MyLedControlMode_rotate_AGS: break;
  case MyLedControlMode_rotate_AAR: break;

  case MyLedControlMode_exec_key_func:
    led_ctrl.mode   = LedControlMode_brightness_increase;
    led_ctrl.amount = 0x80;
    led_ctrl.index  = control->index;
    LED_control( &led_ctrl );
    break;

  case MyLedControlMode_increase_picture_frame:
    pfs += control->amount;
    pfs &= 0x7; // 3-bits
    LED_writeReg( 0x01, pfs, 0x0B ); // Picture Display Register
    break;

  case MyLedControlMode_set_auto_frame_play_mode:
    mode_fs = control->amount;

    my_LED_sendPage( (uint8_t*)LED_defaultBrightness1, sizeof( LED_defaultBrightness1 ), 0 ); // restore the page 0

    //     FDT
    //     <->   ET
    //     ___  <->  __
    //    /   \     /
    // __/     \___/
    //   <-> <->
    //   FIT FOT

    /*
      LED_writeReg( 0x02, 0x10, 0x0B );    // Auto Play Control Register 1; CNS=1, FNS=0 (all)
      LED_writeReg( 0x03, 0x00, 0x0B );    // Auto Play Control Register 2; FDT=0 (704ms)
      LED_writeReg( 0x08, 0x55, 0x0B );    // Breath    Control Register 1; FOT=5 (832ms), FIT=5 (832ms)
      LED_writeReg( 0x09, 0x17, 0x0B );    // Breath    Control Register 2; B_EN=1, ET=7 (448ms)
    */
    LED_writeReg( 0x02, 0x70, 0x0B );    // Auto Play Control Register 1; CNS=7, FNS=0 (all)
    LED_writeReg( 0x03, 0x09, 0x0B );    // Auto Play Control Register 2; FDT=9 (99ms)
    LED_writeReg( 0x08, 0x00, 0x0B );    // Breath    Control Register 1; FOT=0 (26ms), FIT=0 (26ms)
    LED_writeReg( 0x09, 0x00, 0x0B );    // Breath    Control Register 2; B_EN=0, ET=0 (3.5ms)

    LED_writeReg( 0x00, mode_fs, 0x0B ); // Configuration     Register;
    break;
  }

  if ( send_page ) { // Sync LED buffer with ISSI chip buffer
    LED_pageBuffer.i2c_addr = 0xE8; // Chip 1
    LED_pageBuffer.reg_addr = 0x24; // Brightness section
    my_LED_sendPage( (uint8_t*)&LED_pageBuffer, sizeof( LED_Buffer ), 0 );
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
  uint8_t send_packet = 0;
  uint8_t ignore_node = 0;

  // By default send to the *next* node, which will determine where to go next
  extern uint8_t Connect_id; // connect_scan.c
  uint8_t addr = Connect_id + 1;

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
