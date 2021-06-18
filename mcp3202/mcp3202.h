/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MCP3202_H
#define __MCP3202_H

#ifdef __cplusplus
 extern "C" {
#endif 


#include "stm32f1xx_hal.h"

#define START 0x01
#define CONTROL_BYTE 0xE0  //control byte, select channel 1 and MSB first data format
#define DUMMY_BYTE 0x00

typedef struct 
{
	SPI_HandleTypeDef *phspi;
	
	GPIO_TypeDef *GPIO_PORT;
	
	uint16_t GPIO_Pin;
	

} mcp3202_SettingsTypeDef;

static mcp3202_SettingsTypeDef global_mcp3202_InitStruct;

int mcp3202_getADCValue(mcp3202_SettingsTypeDef *mcp3202_InitStruct);




#ifdef __cplusplus
}
#endif

#endif /*  __MCP3202_LIB_H */
