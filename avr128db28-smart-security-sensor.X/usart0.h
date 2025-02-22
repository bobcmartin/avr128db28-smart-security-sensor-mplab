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

#ifndef USART0_H
#define	USART0_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h> 
    
    //Init Peripheral
    void USART0_init(void);
        
    //Init Peripheral I/O
    void USART0_initIO(void);
    
    //Enable/Disable TX 
    void USART0_enableTX(void);
    void USART0_disableTX(void);
    
    //Enable/Disable RX
    void USART0_enableRX(void);
    void USART0_disableRX(void);
    
    //Sets the callback function for Data RX
    void USART0_setRXCallback(void (*function)(char));
    
    //Sends a byte of data. Returns false if buffer cannot accept data
    bool USART0_sendByte(char c);
    
    //Returns true if the peripheral can accept a new byte
    bool USART0_canTransmit(void);
    
    //Returns true if the TX shifter is running
    bool USART0_isBusy(void);
    
    //Returns true if data is being shifted in
    bool USART0_isRXActive(void);

#ifdef	__cplusplus
}
#endif

#endif	/* USART0_H */

