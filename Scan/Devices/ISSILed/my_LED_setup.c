//
// my_LED_setup.c
//

my_LED_write_page( (uint16_t*)&LED_ledEnableMask[0], sizeof( LED_EnableBuffer ) / 2, 1 /*page*/ );
my_LED_write_page( (uint16_t*)&LED_ledEnableMask[0], sizeof( LED_EnableBuffer ) / 2, 2 /*page*/ );
my_LED_write_page( (uint16_t*)&LED_ledEnableMask[0], sizeof( LED_EnableBuffer ) / 2, 3 /*page*/ );
my_LED_write_page( (uint16_t*)&LED_ledEnableMask[0], sizeof( LED_EnableBuffer ) / 2, 4 /*page*/ );
my_LED_write_page( (uint16_t*)&LED_ledEnableMask[0], sizeof( LED_EnableBuffer ) / 2, 5 /*page*/ );
my_LED_write_page( (uint16_t*)&LED_ledEnableMask[0], sizeof( LED_EnableBuffer ) / 2, 6 /*page*/ );
my_LED_write_page( (uint16_t*)&LED_ledEnableMask[0], sizeof( LED_EnableBuffer ) / 2, 7 /*page*/ );

my_LED_write_page( (uint16_t*)My_LED_Brightness1, sizeof( My_LED_Brightness1 ) / 2, 1 );
my_LED_write_page( (uint16_t*)My_LED_Brightness2, sizeof( My_LED_Brightness2 ) / 2, 2 );
my_LED_write_page( (uint16_t*)My_LED_Brightness3, sizeof( My_LED_Brightness3 ) / 2, 3 );
my_LED_write_page( (uint16_t*)My_LED_Brightness4, sizeof( My_LED_Brightness4 ) / 2, 4 );
my_LED_write_page( (uint16_t*)My_LED_Brightness5, sizeof( My_LED_Brightness5 ) / 2, 5 );
my_LED_write_page( (uint16_t*)My_LED_Brightness6, sizeof( My_LED_Brightness6 ) / 2, 6 );
my_LED_write_page( (uint16_t*)My_LED_Brightness7, sizeof( My_LED_Brightness7 ) / 2, 7 );

mode = 0; // Display Mode
fs   = 0; // Frame Start
pfs  = 0; // Picture Frame Selection
cns  = 0; // Number of Loops  Playing Selection
fns  = 0; // Number of Frames Playing Selection
fdt  = 0; // Frame Delay Time
ic   = 0; // Intensity Control
be   = 0; // Blink Enable
bpt  = 0; // Blink Period Time
ae   = 0; // Audio Synchronization Enable
fot  = 0; // Fade Out Time
fit  = 0; // Fade In  Time
b_en = 0; // Breath Enable
et   = 0; // Extinguish Time
ssd  = 0; // Shutdown Control
agcm = 0; // AGC Mode
agc  = 0; // AGC Enable
ags  = 0; // Audio Gain Selection
aar  = 0; // Audio ADC Rate

demo_id = 0;
