/****************************************************************/
/* Author    :                                       */
/* Date      :                                      */
/* Version   : V01                                              */
/****************************************************************/





u8 GSM_u8Init(void)
{
	u8 Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		MUSART1_voidTransmit("ATE0\r\n");
		Local_u8Result = GSM_u8ValidateCmd();
	}

	Local_u8Result = 0;

	// sending basic command <at> to check the module
	while(Local_u8Result == 0)
	{
		u8 Local_u8Response[100] = {0};
		MUSART1_voidTransmit("AT\r\n");
		// expected response \r\nOK\r\n 
		for(u8 i=0; i<6; i++){
			Local_u8Response[i] = MUSART1_u8Receive();
		}
		if (Local_u8Response[0] == '\r' 
			&& Local_u8Response[1] == '\n'
			&& Local_u8Response[1] == 'O'
			&& Local_u8Response[1] == 'K'
			&& Local_u8Response[1] == '\r'
			&& Local_u8Response[1] == '\n'	)
		{
			Local_u8Result = 1;
		}
	}

	return Local_u8Result;

}




u8 GSM_u8ValidateCmd(void)
{
	u8 Local_u8Response[100] = {0};
	u8 i = 0;
	u8 Dummy = 0;
	u8 Result = 0;
	
	while (Dummy != 255)
	{
		Dummy = MUSART1_u8Receive();
		Local_u8Response[i] = Dummy;
		i++;
	}
	
	/* Check if Ok */
	if (Local_u8Response[0] == 'O' && Local_u8Response[1] == 'K')
	{
		Result = 1;
	}
	
	return Result;
}



void GSM_sendCommand(const u8 *command , u16 len){
	u8 cmd_arr[len];
	for(u16 i=0 ; i<len ; i++){
		cmd_arr[i] = *(command+i);
	}
	cmd_arr[len+0] = '\r'
	cmd_arr[len+1] = '\n'
	MUSART1_voidTransmit(cmd_arr);

}



void GSM_sendSMS(u8 *msg, u8 *num){
	//1-Set SMS system into text mode, as opposed to PDU mode
		// cmd : AT+CMGF=1
		GSM_sendCommand("AT+CMGF=1",9);
		// response : OK



		//counts the msg and put it in a form that can be used in my func.
		u8 my_msg[100];
		u16 msg_len =0
		for(u16 i=0 ; msg[i]!='\0' ; i++){
		my_msg[i] = *(msg+i);
		msg_len++;
	}

	
	u8 num_cmd[23]= "AT+CMGS=\""
		for(u16 i=0 ; i<=13 ; i++){
		num_cmd[i+9] = *(num+i);
		
	}
	num_cmd[23] = '\"';

	//2- style of the text mode command
		// cmd : AT+CMGS="+85291234567"<CR>It is easy to send text messages.<Ctrl+z>
		GSM_sendCommand(num_cmd,23);
		GSM_sendCommand(my_msg, msg_len);

}