#include <stdint.h>

#ifndef PRINTUTILITY_H
#define	PRINTUTILITY_H

#ifdef	__cplusplus
extern "C" {
#endif
    
//Disable String Messages for Data Plotting
//#define DISABLE_STRING_MESSAGES
        
#define PRINT_BUFFER_SIZE 255
    
    //Returns the Address of the character buffer
    char* USB_getCharBuffer(void);
    
    //Returns the size of the char buffer
    uint8_t USB_getCharBufferSize(void);
    
    //Prints the string on the UART
    void USB_sendBufferedString(void);
    
    //Prints the literal text to the string
    void USB_sendStringRaw(const char* text);
    
    //Prints a constant string to the UART, then appends \r\n
    void USB_sendStringWithEndline(const char* text);
    
    //Returns the Address of the character buffer
    char* BLE_getCharBuffer(void);
    
    //Returns the size of the char buffer
    uint8_t BLE_getCharBufferSize(void);
    
    //Prints the string on the UART
    void BLE_sendBufferedString(void);
    
    
    //Prints a constant string to the UART
    void BLE_sendStringRaw(const char* text);
    
    //Prints a constant string to the UART, then appends \r\n
    void BLE_sendStringWithEndline(const char* text);

    
    //Prints a constant string to the UART, then appends DELIM
    void BLE_printCommandString(const char* text, const char delim);
    
#ifdef	__cplusplus
}
#endif

#endif	/* PRINTUTILITY_H */

