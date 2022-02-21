/***********************************************************************
*
* FILE : qe_sample_main.c
* DATE : 2020-09-10
* DESCRIPTION : Main Program
*
* NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "qe_touch_config.h"
#define TOUCH_SCAN_INTERVAL_EXAMPLE (0)    /* milliseconds */


void qe_touch_Init(void);
uint8_t qe_getvalue(void);
void qe_Touch_close(void);
uint8_t qe_getvalueInit(void);


#if (TOUCH_CFG_NUM_SLIDERS != 0)
uint16_t slider_position[TOUCH_CFG_NUM_SLIDERS];
#endif
#if (TOUCH_CFG_NUM_WHEELS != 0)
uint16_t wheel_position[TOUCH_CFG_NUM_WHEELS];
#endif



void qe_Touch_close(void)
{
	fsp_err_t err;
	RM_TOUCH_Close(g_qe_touch_instance_config01.p_ctrl);
//	err = RM_TOUCH_Open(g_qe_touch_instance_config01.p_ctrl, g_qe_touch_instance_config01.p_cfg);
//    if (FSP_SUCCESS != err)
//    {
//        while (true) {}
//    }
}

volatile uint32_t tmp1,tmp2;
static uint16_t   g_touch_button_countvaluelast[TOUCH_CFG_NUM_BUTTONS];
static uint16_t   g_touch_button_referencelast[TOUCH_CFG_NUM_BUTTONS];

static uint16_t Timeout[TOUCH_CFG_NUM_BUTTONS]= {0};
static uint16_t Timeout1[TOUCH_CFG_NUM_BUTTONS]= {0};
static uint16_t Timeout2[TOUCH_CFG_NUM_BUTTONS]= {0};
void qe_touch_Init(void)
{
	fsp_err_t err;

	err=RM_TOUCH_Close(g_qe_touch_instance_config01.p_ctrl);
	/* Open Touch middleware */
	err = RM_TOUCH_Open(g_qe_touch_instance_config01.p_ctrl, g_qe_touch_instance_config01.p_cfg);
	if (FSP_SUCCESS != err)
	{
		while (true) {}
	}
	memset(&g_touch_button_countvaluelast[0],0,TOUCH_CFG_NUM_BUTTONS*sizeof(uint16_t));
	memset(&g_touch_button_referencelast[0],0,TOUCH_CFG_NUM_BUTTONS*sizeof(uint16_t));
	memset(&Timeout1[0],0,TOUCH_CFG_NUM_BUTTONS*sizeof(uint16_t));
	memset(&Timeout[0],0,TOUCH_CFG_NUM_BUTTONS*sizeof(uint16_t));
	memset(&Timeout2[0],0,TOUCH_CFG_NUM_BUTTONS*sizeof(uint16_t));
}
static uint16_t cnt = 600;
uint8_t qe_getvalueInit(void)
{
	fsp_err_t err;
	err = RM_TOUCH_ScanStart(g_qe_touch_instance_config01.p_ctrl);
	if (FSP_SUCCESS != err)
	{
		while (true) {}
	}
	while (0 == g_qe_touch_flag) {}
	g_qe_touch_flag = 0;

	button_status = 0;
	err = RM_TOUCH_DataGet(g_qe_touch_instance_config01.p_ctrl, &button_status, NULL, NULL);
	return (uint8_t)button_status;
}

uint8_t qe_getvalue(void)
{

	fsp_err_t err;
	uint8_t i =0;
	if(g_qe_touch_flag==0)
	{

		err = RM_TOUCH_ScanStart(g_qe_touch_instance_config01.p_ctrl);

		if (FSP_SUCCESS != err)
		{
			while (true) {}
		}
		g_qe_touch_flag = 2;
	}
//    while (0 == g_qe_touch_flag) {}

	if(g_qe_touch_flag==1)
	{
		button_status = 0;
		err = RM_TOUCH_DataGet(g_qe_touch_instance_config01.p_ctrl, &button_status, NULL, NULL);
		if (FSP_SUCCESS == err)
		{
			for(i=0; i<TOUCH_CFG_NUM_BUTTONS; i++)
			{
				tmp1+= g_touch_button_reference[i];
			}
			for(i=0; i<TOUCH_CFG_NUM_BUTTONS; i++)
			{
				tmp2+= g_touch_button_countvalue[i];
			}
			if(tmp1<(12000*TOUCH_CFG_NUM_BUTTONS) || tmp2<(12000*TOUCH_CFG_NUM_BUTTONS)) //只要按键基准值或者检测值不正常 就重新初始化按键
			{
				qe_touch_Init();
			}
			else
			{
				for(i=0; i<0; i++)
				{
					if(g_touch_button_reference[i]>g_touch_button_countvalue[i])
						Timeout1[i]+=1;
					else
						Timeout1[i]=0;
					if(Timeout1[i]>=2000) // 当基准值一直大于检测值 保持5S
					{
						qe_touch_Init() ;//
						break;
					}
				}

				for(i=0; i<TOUCH_CFG_NUM_BUTTONS; i++)
				{
					if(i<TOUCH_CFG_NUM_BUTTONS)
					{
						if(g_touch_button_countvaluelast[i] != g_touch_button_countvalue[i])
						{
							g_touch_button_countvaluelast[i]= g_touch_button_countvalue[i];
							Timeout[i] = 0;
						}
						else
						{
							Timeout[i]+=1;

						}
					}
					if(Timeout[i]>=5000)  //连续30S按键的任意一个键值不改变 则进行初始化
					{
						qe_touch_Init();//
						break;
					}
				}

				for(i=0; i<TOUCH_CFG_NUM_BUTTONS; i++)
				{
					if(g_touch_button_referencelast[i] != g_touch_button_reference[i])
					{
						g_touch_button_referencelast[i] = g_touch_button_reference[i];
						Timeout2[i] = 0;
					}
					else
					{
						Timeout2[i]+=1;

					}
					if(Timeout2[i]>=10000)  //连续60S基准值无变化
					{
						qe_touch_Init();//
						break;
					}
				}

				//				if(button_status==0) //当按键没有按下
				//				{
				//					for(i=0;i<6;i++)
				//					{
				//						if(i<3)
				//						{
				//							if(g_touch_button_countvaluelast[i]>14800)
				//							{
				//								g_touch_button_countvaluelast[i]= g_touch_button_countvalue[i];
				//								Timeout1[i] = 0;
				//							}
				//							else
				//							{
				//								Timeout1[i]+=1;
				//
				//							}
				//						}
				//						else
				//						{
				//							if(g_touch_button_referencelast[i-3] >14800)
				//							{
				//								Timeout1[i] = 0;
				//							}
				//							else
				//							{
				//								Timeout1[i]+=1;
				//							}
				//						}
				//						if(Timeout1[i]>=1000)  //任意按键小于14800基准值 则重新初始化 连续5S
				//						{
				//							 qe_touch_Init();//
				//							 break;
				//						}
				//					}
				//
				//				}
				//				else
				//				{
				//					memset(&Timeout1[0],0,6);
				//				}
			}

			/* TODO: Add your own code here. */
		}
		g_qe_touch_flag = 0;

		return (uint8_t)button_status;
	}





	/* FIXME: Since this is a temporary process, so re-create a waiting process yourself. */
//    R_BSP_SoftwareDelay(TOUCH_SCAN_INTERVAL_EXAMPLE, BSP_DELAY_UNITS_MILLISECONDS);


}
