/*
� [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef WINDOWALARM_H
#define	WINDOWALARM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "MLX90392.h"
    
    typedef struct {
        int8_t x;           //Compressed X
        int8_t y;           //Compressed Y
        int8_t z;           //Compressed Z
        
#ifdef MAGNETOMETER_ANGLE_CHECK
        //Ratios of X/Y, X/Z, Y/Z. Tan([Angle]) = <Ratio>
        int16_t xyAngle;     //X/Y
        int16_t xzAngle;     //X/Z
        int16_t yzAngle;     //Y/Z
#endif
        
        uint32_t r2;        //Vector Sum of Compressed Values
    } MLX90392_NormalizedResults8;
    
#define RTC_PIT_FAST_TIMING RTC_PERIOD_CYC128_gc
    
#define RTC_PIT_NORMAL_TIMING RTC_PERIOD_CYC2048_gc
    
    //Init the Magnetometer and related parameters
    void windowAlarm_init(bool safeStart);
    
    //Loads settings for window alarm
    //If nReset = false, settings are reset to defaults
    void windowAlarm_loadSettings(bool nReset);
    
    //Tries to load constants from EEPROM - called by windowAlarm_init
    //Returns true if successful, or false if EEPROM is invalid
    bool windowAlarm_loadFromEEPROM(bool safeStart);
    
    //When called - calibration will be marked as bad in EEPROM.
    void windowAlarm_eraseCalibration(void);
    
    //Starts a calibration sequence, but does NOT interrupt it.
    void windowAlarm_requestCalibration(void);
    
    //Internal function for setting the trigger thresholds (calibration)
    void windowAlarm_runCalibration(MLX90392_RawResult16* result, MLX90392_NormalizedResults8* normResults);
    
    //Checks to see if the alarm should be triggered or not
    bool windowAlarm_compareResults(MLX90392_NormalizedResults8* normResults);
    
    //Process Data from Magnetometer and trigger alarm, if needed
    void windowAlarm_compareAndProcessResults(MLX90392_NormalizedResults8* results);
    
    //Returns true if the alarm is ready to print a message
    bool windowAlarm_getResultStatus(void);
    
    //Prints the state of the alarm
    void windowAlarm_printResults(void);
    
    //Prints calibration constants to UART
    void windowAlarm_printCalibration(void);
    
    //If called, the next data processed will be printed to the RN4870
    void windowAlarm_requestRawPrint(void);
    
    //Converts raw results into a normalized compressed value
    void windowAlarm_createNormalizedResults(MLX90392_RawResult16* raw, MLX90392_NormalizedResults8* results);
    
    //Returns true if a magnetic overflow has occurred
    bool windowAlarm_isMagneticOverflow(MLX90392_RawResult16* raw);
    
    //Saves current thresholds.
    bool windowAlarm_saveThresholds(void);
    
    //Returns true if calibration is good
    bool windowAlarm_isCalGood(void);
    
    //Returns true if the alarm is OK, false if the alarm was tripped
    bool windowAlarm_isAlarmOK(void);
        
    //Run the Finite State Machine for the Magnetometer
    void windowAlarm_FSM(void);
    
    //Updates the pushbutton state to prevent calibration when waking up
    void windowAlarm_maskButton(void);
    
    //Run this ISR if the MVIO changes readiness
    void _windowAlarm_onMVIOChange(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* WINDOWALARM_H */

