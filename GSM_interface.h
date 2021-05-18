/****************************************************************/
/* Author    : Mohamed Ashraf                                   */
/* Version   : V01                                              */
/****************************************************************/
#ifndef GSM_INTERFACE_H
#define GSM_INTERFACE_H


struct GSM_Responses
{
    u8* 
};

typedef enum{
    echo_mode,
     

}GSM_AT;


/********************************************
 Function name: GSM_u8Init
 Function: sending the basic command <AT> and Stop ECHO
 Formal parameter: None
 Return value:  0 -> initialization faild   
                1-> initialization done
 Remarks: None
*********************************************/
u8 GSM_u8Init(void);


/********************************************
 Function name: GSM_u8ValidateCmd
 Function: Recieve Response and Check if ok
 Formal parameter: None
 Return value: 1 -> if ok
 Remarks: None
*********************************************/
u8 GSM_u8ValidateCmd(void);

/**
 * @brief sending command to GSM module
 *
 *  Given a command as pointer to characters and its length, sending the command via UART to the module
 *
 * @param command   pointer to the string command
 * @param len        Length of the command
 *
 * @return answer from the module
 */
void GSM_sendCommand(const u8 *command , u16 len);

#endif