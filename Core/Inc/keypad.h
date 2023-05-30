#ifndef __KEYPAD__
#define __KEYPAD__

//#include "stm32f1xx_hal_def.h"

#define		ROW1_PIN		GPIO_PIN_7		//	PB7
#define  	ROW1_PORT		GPIOB

#define		ROW2_PIN		GPIO_PIN_8		//	PB8
#define  	ROW2_PORT		GPIOB

#define		ROW3_PIN		GPIO_PIN_9		//	PB9
#define  	ROW3_PORT		GPIOB

#define		ROW4_PIN		GPIO_PIN_10		//	PB10
#define  	ROW4_PORT		GPIOB

#define		COL1_PIN		GPIO_PIN_11		//	PB11
#define  	COL1_PORT		GPIOB

#define		COL2_PIN		GPIO_PIN_12		//	PB12
#define  	COL2_PORT		GPIOB

#define		COL3_PIN		GPIO_PIN_13		//	PB13
#define  	COL3_PORT		GPIOB

#define		COL4_PIN		GPIO_PIN_14		//	PB14
#define  	COL4_PORT		GPIOB

void keypad_init(void);
char keypad_read(void);
#endif
