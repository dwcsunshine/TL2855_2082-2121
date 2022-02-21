/* generated configuration header file - do not edit */
#ifndef BSP_CLOCK_CFG_H_
#define BSP_CLOCK_CFG_H_
#define BSP_CFG_CLOCKS_SECURE (0)
#define BSP_CFG_CLOCKS_OVERRIDE (0)
#define BSP_CFG_XTAL_HZ (24000000) /* XTAL 24000000Hz */
#define BSP_CFG_HOCO_FREQUENCY (2) /* HOCO 20MHz */
#define BSP_CFG_PLL_SOURCE (BSP_CLOCKS_SOURCE_CLOCK_HOCO) /* PLL Src: HOCO */
#define BSP_CFG_PLL_DIV (BSP_CLOCKS_PLL_DIV_3) /* PLL Div /3 */
#define BSP_CFG_PLL_MUL BSP_CLOCKS_PLL_MUL_30_0 /* PLL Mul x30.0 */
#define BSP_CFG_PLL2_SOURCE (BSP_CLOCKS_SOURCE_CLOCK_HOCO) /* PLL2 Src: HOCO */
#define BSP_CFG_PLL2_DIV (BSP_CLOCKS_PLL_DIV_1) /* PLL2 Div /1 */
#define BSP_CFG_PLL2_MUL BSP_CLOCKS_PLL_MUL_11_0 /* PLL2 Mul x11.0 */
#define BSP_CFG_CLOCK_SOURCE (BSP_CLOCKS_SOURCE_CLOCK_PLL) /* Clock Src: PLL */
#define BSP_CFG_CLKOUT_SOURCE (BSP_CLOCKS_SOURCE_CLOCK_MOCO) /* CLKOUT Src: MOCO */
#define BSP_CFG_UCK_SOURCE (BSP_CLOCKS_CLOCK_DISABLED) /* UCLK Disabled */
#define BSP_CFG_OCTA_SOURCE (BSP_CLOCKS_CLOCK_DISABLED) /* OCTASPICLK Disabled */
#define BSP_CFG_ICLK_DIV (BSP_CLOCKS_SYS_CLOCK_DIV_1) /* ICLK Div /1 */
#define BSP_CFG_PCLKA_DIV (BSP_CLOCKS_SYS_CLOCK_DIV_2) /* PCLKA Div /2 */
#define BSP_CFG_PCLKB_DIV (BSP_CLOCKS_SYS_CLOCK_DIV_4) /* PCLKB Div /4 */
#define BSP_CFG_PCLKC_DIV (BSP_CLOCKS_SYS_CLOCK_DIV_4) /* PCLKC Div /4 */
#define BSP_CFG_PCLKD_DIV (BSP_CLOCKS_SYS_CLOCK_DIV_2) /* PCLKD Div /2 */
#define BSP_CFG_BCLK_DIV (BSP_CLOCKS_SYS_CLOCK_DIV_4) /* BCLK Div /4 */
#define BSP_CFG_BCLK_OUTPUT (1) /* BCLK */
#define BSP_CFG_FCLK_DIV (BSP_CLOCKS_SYS_CLOCK_DIV_4) /* FCLK Div /4 */
#define BSP_CFG_CLKOUT_DIV (BSP_CLOCKS_SYS_CLOCK_DIV_2) /* CLKOUT Div /2 */
#define BSP_CFG_UCK_DIV (BSP_CLOCKS_USB_CLOCK_DIV_3) /* UCLK Div /3 */
#define BSP_CFG_OCTA_DIV (BSP_CLOCKS_OCTA_CLOCK_DIV_1) /* OCTASPICLK Div /1 */
#endif /* BSP_CLOCK_CFG_H_ */
