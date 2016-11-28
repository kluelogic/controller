//
// my_LED_setup.c
//

my_LED_sendPage( (uint8_t*)LED_ledEnableMask1, sizeof( LED_ledEnableMask1 ), 1 /*page*/ );
my_LED_sendPage( (uint8_t*)LED_ledEnableMask1, sizeof( LED_ledEnableMask1 ), 2 );
my_LED_sendPage( (uint8_t*)LED_ledEnableMask1, sizeof( LED_ledEnableMask1 ), 3 );
my_LED_sendPage( (uint8_t*)LED_ledEnableMask1, sizeof( LED_ledEnableMask1 ), 4 );
my_LED_sendPage( (uint8_t*)LED_ledEnableMask1, sizeof( LED_ledEnableMask1 ), 5 );
my_LED_sendPage( (uint8_t*)LED_ledEnableMask1, sizeof( LED_ledEnableMask1 ), 6 );
my_LED_sendPage( (uint8_t*)LED_ledEnableMask1, sizeof( LED_ledEnableMask1 ), 7 );

//my_LED_sendPage( (uint8_t*)My_LED_Brightness0, sizeof( My_LED_Brightness0 ), 0 );
my_LED_sendPage( (uint8_t*)My_LED_Brightness1, sizeof( My_LED_Brightness1 ), 1 );
my_LED_sendPage( (uint8_t*)My_LED_Brightness2, sizeof( My_LED_Brightness2 ), 2 );
my_LED_sendPage( (uint8_t*)My_LED_Brightness3, sizeof( My_LED_Brightness3 ), 3 );
my_LED_sendPage( (uint8_t*)My_LED_Brightness4, sizeof( My_LED_Brightness4 ), 4 );
my_LED_sendPage( (uint8_t*)My_LED_Brightness5, sizeof( My_LED_Brightness5 ), 5 );
my_LED_sendPage( (uint8_t*)My_LED_Brightness6, sizeof( My_LED_Brightness6 ), 6 );
my_LED_sendPage( (uint8_t*)My_LED_Brightness7, sizeof( My_LED_Brightness7 ), 7 );

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
