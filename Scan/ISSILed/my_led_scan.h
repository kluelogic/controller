//
// my_led_scan.h
//

const uint8_t LED_defaultBrightness2[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	ISSILedBrightness2_define
};
const uint8_t LED_defaultBrightness3[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	ISSILedBrightness3_define
};
const uint8_t LED_defaultBrightness4[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	ISSILedBrightness4_define
};
const uint8_t LED_defaultBrightness5[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	ISSILedBrightness5_define
};
const uint8_t LED_defaultBrightness6[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	ISSILedBrightness6_define
};
const uint8_t LED_defaultBrightness7[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	ISSILedBrightness7_define
};
const uint8_t LED_defaultBrightness8[] = {
	0xE8, // I2C address
	0x24, // Starting register address
	ISSILedBrightness8_define
};

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

// function prototypes

void my_LED_sendPage( uint8_t *buffer, uint8_t len, uint8_t page );
