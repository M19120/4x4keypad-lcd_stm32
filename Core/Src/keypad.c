#include "stm32f1xx_hal.h"
#include "keypad.h"

void keypad_init(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	
  GPIO_InitStruct.Pin 	= ROW1_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ROW1_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin 	= ROW2_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ROW2_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin 	= ROW3_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ROW3_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin 	= ROW4_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ROW4_PORT, &GPIO_InitStruct);
	
	HAL_GPIO_WritePin(ROW1_PORT, ROW1_PIN, GPIO_PIN_RESET);
	
  HAL_GPIO_WritePin(ROW2_PORT, ROW2_PIN, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(ROW3_PORT, ROW3_PIN, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(ROW4_PORT, ROW4_PIN, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin 	= COL1_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull 	= GPIO_PULLUP;
  HAL_GPIO_Init(COL1_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin 	= COL2_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull 	= GPIO_PULLUP;
  HAL_GPIO_Init(COL2_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin 	= COL3_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull 	= GPIO_PULLUP;
  HAL_GPIO_Init(COL3_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin 	= COL4_PIN;
  GPIO_InitStruct.Mode 	= GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull 	= GPIO_PULLUP;
  HAL_GPIO_Init(COL4_PORT, &GPIO_InitStruct);
		
}

char keypad_read(void){
	char letras[4][4]={	{'1','2','3','A'},
										{'4','5','6','B'},
										{'7','8','9','C'},
										{'*','0','#','D'}};
	int  i=0;
	char valor=0;


	for(i=0;i<4;i++){
		if(i==0){
			HAL_GPIO_WritePin(ROW2_PORT, ROW2_PIN,  GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW3_PORT, ROW3_PIN,	GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW4_PORT, ROW4_PIN,  GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW1_PORT, ROW1_PIN,  GPIO_PIN_RESET);
			
			HAL_Delay(10);
			while ( ( HAL_GPIO_ReadPin(COL1_PORT, COL1_PIN) ) == 0 ){valor=letras[0][0];}	//1
			while ( ( HAL_GPIO_ReadPin(COL2_PORT, COL2_PIN) ) == 0 ){valor=letras[0][1];}	//2
			while ( ( HAL_GPIO_ReadPin(COL3_PORT, COL3_PIN) ) == 0 ){valor=letras[0][2];}	//3
			while ( ( HAL_GPIO_ReadPin(COL4_PORT, COL4_PIN) ) == 0 ){valor=letras[0][3];}	//A
		}

		if(i==1){
			HAL_GPIO_WritePin(ROW1_PORT, ROW1_PIN,  GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW3_PORT, ROW3_PIN,	GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW4_PORT, ROW4_PIN,  GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW2_PORT, ROW2_PIN,  GPIO_PIN_RESET);

			HAL_Delay(10);
			while ( ( HAL_GPIO_ReadPin(COL1_PORT, COL1_PIN) ) == 0 ){valor=letras[1][0];}	//4
			while ( ( HAL_GPIO_ReadPin(COL2_PORT, COL2_PIN) ) == 0 ){valor=letras[1][1];}	//5
			while ( ( HAL_GPIO_ReadPin(COL3_PORT, COL3_PIN) ) == 0 ){valor=letras[1][2];}	//6
			while ( ( HAL_GPIO_ReadPin(COL4_PORT, COL4_PIN) ) == 0 ){valor=letras[1][3];}	//B
		}

		if(i==2){
			HAL_GPIO_WritePin(ROW1_PORT, ROW1_PIN,  GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW2_PORT, ROW2_PIN,	GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW4_PORT, ROW4_PIN,  GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW3_PORT, ROW3_PIN,  GPIO_PIN_RESET);
			
			HAL_Delay(10);
			while ( ( HAL_GPIO_ReadPin(COL1_PORT, COL1_PIN) ) == 0 ){valor=letras[2][0];}	//7
			while ( ( HAL_GPIO_ReadPin(COL2_PORT, COL2_PIN) ) == 0 ){valor=letras[2][1];}	//8
			while ( ( HAL_GPIO_ReadPin(COL3_PORT, COL3_PIN) ) == 0 ){valor=letras[2][2];}	//9
			while ( ( HAL_GPIO_ReadPin(COL4_PORT, COL4_PIN) ) == 0 ){valor=letras[2][3];}	//C
		}

		if(i==3){
			HAL_GPIO_WritePin(ROW1_PORT, ROW1_PIN,  GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW2_PORT, ROW2_PIN,	GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW3_PORT, ROW3_PIN,  GPIO_PIN_SET);
			HAL_GPIO_WritePin(ROW4_PORT, ROW4_PIN,  GPIO_PIN_RESET);
			
			HAL_Delay(10);
			while ( ( HAL_GPIO_ReadPin(COL1_PORT, COL1_PIN) ) == 0 ){valor=letras[3][0];}	//*
			while ( ( HAL_GPIO_ReadPin(COL2_PORT, COL2_PIN) ) == 0 ){valor=letras[3][1];}	//0
			while ( ( HAL_GPIO_ReadPin(COL3_PORT, COL3_PIN) ) == 0 ){valor=letras[3][2];}	//+
			while ( ( HAL_GPIO_ReadPin(COL4_PORT, COL4_PIN) ) == 0 ){valor=letras[3][3];}	//D
		}
	}
	
	return valor;
}



