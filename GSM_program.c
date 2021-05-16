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
