#include "mcp3202.h"
	
int mcp3202_getADCValue(mcp3202_SettingsTypeDef *mcp3202_InitStruct){
	global_mcp3202_InitStruct.phspi = mcp3202_InitStruct->phspi;
	global_mcp3202_InitStruct.GPIO_PORT = mcp3202_InitStruct->GPIO_PORT;
	global_mcp3202_InitStruct.GPIO_Pin = mcp3202_InitStruct->GPIO_Pin;
	
	int adc_value = 0;
	int temp = 0;
	
	uint8_t spi_tx_data [] = {0};
	uint8_t spi_rx_data [] = {0};
	
	spi_tx_data [0] = START;
	
	
	HAL_GPIO_WritePin(global_mcp3202_InitStruct.GPIO_PORT, global_mcp3202_InitStruct.GPIO_Pin, GPIO_PIN_SET);
	
	HAL_SPI_TransmitReceive(global_mcp3202_InitStruct.phspi, spi_tx_data, spi_rx_data, 1, HAL_MAX_DELAY);
	
	spi_tx_data [0] = CONTROL_BYTE;
	
	HAL_SPI_TransmitReceive(global_mcp3202_InitStruct.phspi, spi_tx_data, spi_rx_data, 1, HAL_MAX_DELAY);
	
	adc_value = spi_rx_data[0] & 0x0F;
	
	spi_tx_data [0] = 0x00; 

  	HAL_SPI_TransmitReceive(global_mcp3202_InitStruct.phspi, spi_tx_data, spi_rx_data, 1, HAL_MAX_DELAY);
	
	temp = spi_rx_data[0];
	
	HAL_GPIO_WritePin(global_mcp3202_InitStruct.GPIO_PORT, global_mcp3202_InitStruct.GPIO_Pin, GPIO_PIN_RESET);
	
	adc_value = (adc_value << 8) | temp; 
	
	return adc_value;

}
