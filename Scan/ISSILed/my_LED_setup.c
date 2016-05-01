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

my_LED_sendPage( (uint8_t*)LED_defaultBrightness2, sizeof( LED_defaultBrightness2 ), 1 );
my_LED_sendPage( (uint8_t*)LED_defaultBrightness3, sizeof( LED_defaultBrightness3 ), 2 );
my_LED_sendPage( (uint8_t*)LED_defaultBrightness4, sizeof( LED_defaultBrightness4 ), 3 );
my_LED_sendPage( (uint8_t*)LED_defaultBrightness5, sizeof( LED_defaultBrightness5 ), 4 );
my_LED_sendPage( (uint8_t*)LED_defaultBrightness6, sizeof( LED_defaultBrightness6 ), 5 );
my_LED_sendPage( (uint8_t*)LED_defaultBrightness7, sizeof( LED_defaultBrightness7 ), 6 );
my_LED_sendPage( (uint8_t*)LED_defaultBrightness8, sizeof( LED_defaultBrightness8 ), 7 );

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
