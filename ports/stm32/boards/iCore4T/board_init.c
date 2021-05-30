#include "py/mphal.h"

#include "i2c.h"
#include "axp152.h"
#define ARM_LED_Pin GPIO_PIN_10
#define ARM_LED_GPIO_Port GPIOA

extern GPIO_InitTypeDef   GPIO_uInitStructure;

#define LED_ON  HAL_GPIO_WritePin(ARM_LED_GPIO_Port, ARM_LED_Pin, GPIO_PIN_RESET)
#define LED_OFF HAL_GPIO_WritePin(ARM_LED_GPIO_Port, ARM_LED_Pin, GPIO_PIN_SET)

#define LED_OUT  GPIO_uInitStructure.Pin = ARM_LED_Pin;\
  GPIO_uInitStructure.Mode = GPIO_MODE_OUTPUT_PP;\
  GPIO_uInitStructure.Pull = GPIO_PULLUP;\
  GPIO_uInitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;\
  HAL_GPIO_Init(ARM_LED_GPIO_Port, &GPIO_uInitStructure);\

void iCore4T_board_early_init(void) {
    mp_hal_pin_output(LAN_nRST);
    mp_hal_pin_low(LAN_nRST);
    mp_hal_delay_ms(100);
    mp_hal_pin_high(LAN_nRST);

    LED_OUT;
    LED_OFF;
    i2c.initialize();
	if(axp152.initialize()<0){

        LED_ON;
        while(1){}
    }
	axp152.set_dcdc1(3500);//[ARM & FPGA BK1/2/6 &OTHER]
	axp152.set_dcdc2(1200);//[FPGA INT & PLL D]
	axp152.set_aldo1(2500);//[FPGA PLL A]
	axp152.set_dcdc4(3300);//[POWER_OUTPUT]
	axp152.set_dcdc3(3300);//[FPGA BK4][Adjustable]
	axp152.set_aldo2(3300);//[FPGA BK3][Adjustable]
	axp152.set_dldo1(3300);//[FPGA BK7][Adjustable]
	axp152.set_dldo2(3300);//[FPGA BK5][Adjustable]
	mp_hal_delay_ms(200);
}
