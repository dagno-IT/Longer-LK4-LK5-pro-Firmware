/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Alphawise Longer LGT V1.1 motherboard pin assigment*
 *
 */


#if NOT_TARGET(, __AVR_ATmega1280__, __AVR_ATmega2560__)
  #error "Oops! Select 'Arduino/Genuino Mega or Mega 2560' in 'Tools > Board.'"
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME "LGT"
#endif



//#define LK1_Pro_Autobed


//
// Servos
//


#ifndef LK1_Pro_AutoBed
		#define SERVO0_PIN       7 // Servo0 pin for BLtouch connected to J18 LGT motherboard connector (D7 / Gnd / 5V)
#endif // !LK1_Pro_AutoBed
	

//
// Limit Switches
//
#define X_MIN_PIN           3
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define SD_DETECT_PIN   49
#ifndef FIL_RUNOUT_PIN
	#define FIL_RUNOUT_PIN  2
#endif


#ifdef LK1_Pro_AutoBed
	#define Z_MIN_PIN          11
	#define Z_MAX_PIN          37
#else //LK4_Pro & U30 pro
	#define Z_MIN_PIN          35
	#define Z_MAX_PIN          37
#endif


//
// Steppers
//
#define X_STEP_PIN         54		//54 -> A0 pin
#define X_DIR_PIN          55		//55 -> A1 pin
#define X_ENABLE_PIN       38		//D38


#define Y_STEP_PIN         60		//60 -> A6 pin
#define Y_DIR_PIN          61		//61 -> A7 pin
#define Y_ENABLE_PIN       56		//56 -> A2 pin


#define Z_STEP_PIN         46		//D46 pin
#define Z_DIR_PIN          48		//D48 pin
#define Z_ENABLE_PIN       62		//62 -> A8 pin


#define E0_STEP_PIN        26		//D26 pin
#define E0_DIR_PIN         28		//D26 pin
#define E0_ENABLE_PIN      24		//D26 pin
#


//
// Temperature Sensors
//
#define TEMP_0_PIN         13   // Analog Input A13
#define TEMP_BED_PIN       14   // Analog Input A14




//
// Heaters / Fans
//
#ifndef MOSFET_D_PIN
  #define MOSFET_D_PIN     -1
#endif
#ifndef RAMPS_D8_PIN
  #define RAMPS_D8_PIN      8
#endif
#ifndef RAMPS_D9_PIN
  #define RAMPS_D9_PIN      9
#endif
#ifndef RAMPS_D10_PIN
  #define RAMPS_D10_PIN    10
#endif

#define HEATER_0_PIN       	RAMPS_D10_PIN
#define HEATER_BED_PIN     	RAMPS_D8_PIN
#define FAN_PIN				RAMPS_D9_PIN


//
// Misc. Functions
//
#define SDSS               53
#define LED_PIN            13

#ifndef FILWIDTH_PIN
  #define FILWIDTH_PIN      5   // Analog Input on AUX2
#endif


#ifndef PS_ON_PIN
  #define PS_ON_PIN        12
#endif

#if ENABLED(CASE_LIGHT_ENABLE) && !defined(CASE_LIGHT_PIN) && !defined(SPINDLE_LASER_ENABLE_PIN)
  #if NUM_SERVOS <= 1 // try to use servo connector first
    #define CASE_LIGHT_PIN    6   // MUST BE HARDWARE PWM
  #elif !(ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL) \
      && (ENABLED(PANEL_ONE) || ENABLED(VIKI2) || ENABLED(miniVIKI) || ENABLED(MINIPANEL) || ENABLED(REPRAPWORLD_KEYPAD)))  // try to use AUX 2
    #define CASE_LIGHT_PIN   44   // MUST BE HARDWARE PWM
  #endif
#endif

//
// M3/M4/M5 - Spindle/Laser Control
//
#if ENABLED(SPINDLE_LASER_ENABLE) && !PIN_EXISTS(SPINDLE_LASER_ENABLE)
  #if !defined(NUM_SERVOS) || NUM_SERVOS == 0 // try to use servo connector first
    #define SPINDLE_LASER_ENABLE_PIN  4   // Pin should have a pullup/pulldown!
    #define SPINDLE_LASER_PWM_PIN     6   // MUST BE HARDWARE PWM
    #define SPINDLE_DIR_PIN           5
  #elif !(ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL) \
      && (ENABLED(PANEL_ONE) || ENABLED(VIKI2) || ENABLED(miniVIKI) || ENABLED(MINIPANEL) || ENABLED(REPRAPWORLD_KEYPAD)))  // try to use AUX 2
    #define SPINDLE_LASER_ENABLE_PIN 40   // Pin should have a pullup/pulldown!
    #define SPINDLE_LASER_PWM_PIN    44   // MUST BE HARDWARE PWM
    #define SPINDLE_DIR_PIN          65
  #endif
#endif


