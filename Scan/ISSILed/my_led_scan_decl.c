//
// my_led_scan_decl.c
//

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

const uint8_t My_LED_Brightness0[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	MyLedBrightness0_define
};
const uint8_t My_LED_Brightness1[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	MyLedBrightness1_define
};
const uint8_t My_LED_Brightness2[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	MyLedBrightness2_define
};
const uint8_t My_LED_Brightness3[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	MyLedBrightness3_define
};
const uint8_t My_LED_Brightness4[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	MyLedBrightness4_define
};
const uint8_t My_LED_Brightness5[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	MyLedBrightness5_define
};
const uint8_t My_LED_Brightness6[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	MyLedBrightness6_define
};
const uint8_t My_LED_Brightness7[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	MyLedBrightness7_define
};

//------------------------------------------------------------------------------
// Variables
//------------------------------------------------------------------------------

uint8_t mode; // Display Mode
uint8_t fs;   // Frame Start
uint8_t pfs;  // Picture Frame Selection
uint8_t cns;  // Number of Loops  Playing Selection
uint8_t fns;  // Number of Frames Playing Selection
uint8_t fdt;  // Frame Delay Time
uint8_t ic;   // Intensity Control
uint8_t be;   // Blink Enable
uint8_t bpt;  // Blink Period Time
uint8_t ae;   // Audio Synchronization Enable
uint8_t fot;  // Fade Out Time
uint8_t fit;  // Fade In  Time
uint8_t b_en; // Breath Enable
uint8_t et;   // Extinguish Time
uint8_t ssd;  // Shutdown Control
uint8_t agcm; // AGC Mode
uint8_t agc;  // AGC Enable
uint8_t ags;  // Audio Gain Selection
uint8_t aar;  // Audio ADC Rate

uint8_t demo_id;
