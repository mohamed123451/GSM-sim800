/****************************************************************/
/* Author    : Mohamed Ashraf                                   */
/* Version   : V01                                              */
/****************************************************************/
#ifndef GSM_INTERFACE_H
#define GSM_INTERFACE_H

/********************************************
 Function name: GSM_u8Init
 Function: sending the basic command <AT> and Stop ECHO
 Formal parameter: None
 Return value: 0 -> initialization faild   1-> initialization done
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

void GSM_sendSMS();

#endif