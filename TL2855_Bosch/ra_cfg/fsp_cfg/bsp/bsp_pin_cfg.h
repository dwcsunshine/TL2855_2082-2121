/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"
#define wifireset (IOPORT_PORT_00_PIN_14)
#define wifipower (IOPORT_PORT_00_PIN_15)
#define LEDR (IOPORT_PORT_01_PIN_06)
#define PWMMOT (IOPORT_PORT_02_PIN_05)
#define P15V (IOPORT_PORT_02_PIN_08)
#define LEDB (IOPORT_PORT_03_PIN_04)
#define BuzP (IOPORT_PORT_04_PIN_01)
#define BuzF (IOPORT_PORT_04_PIN_02)
#define TFT_LED (IOPORT_PORT_05_PIN_00)
extern const ioport_cfg_t g_bsp_pin_cfg; /* R7FA6M4AF3CFM.pincfg */

void BSP_PinConfigSecurityInit();
#endif /* BSP_PIN_CFG_H_ */
