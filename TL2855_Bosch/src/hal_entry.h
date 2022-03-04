/***************************************************************
               ** File name: hal_entry.h
               ** Created & Modified by: DWC @HET Tech inc
               ** Date: 2022-1-5
 ***************************************************************/
/***************************************************************
               ** File name: hal_entry.h
               ** Created & Modified by: DWC @HET Tech inc
               ** Date: 2021-6-2
 ***************************************************************/
#ifndef __HAL_ENTRY_H
#define __HAL_ENTRY_H

/*
#include "lvgl.h"
#include "lv_conf.h"
#include "hal_entry.h"

*/
extern volatile bool g_transfer_complete;


#define CompleteData "Data:2022.03.04"
#define MainBoardVer "MainBoard Ver:0.0.1"
#define PCBVer "PCB Ver:3.0"



#define PM25LIB (1)
typedef uint8_t u8;
typedef uint16_t  u16;
typedef unsigned int  u32;

typedef int8_t s8;
typedef int16_t  s16;
typedef signed int  s32;

#define bit0 0x0001
#define bit1 0x0002
#define bit2 0x0004
#define bit3 0x0008
#define bit4 0x0010
/***************************************************************
                      ** End of hal_entry.h
***************************************************************/
#define bit5 0x0020
#define bit6 0x0040
#define bit7 0x0080
#define bit8 0x0100
#define bit9 0x0200
#define bit10 0x0400
#define bit11 0x0800
#define bit12 0x1000
#define bit13 0x2000
#define bit14 0x4000
#define bit15 0x8000

#define ERR_FAN bit0
#define ERR_HALL bit1
#define ERR_COMM bit2 // 从机报的通讯故障
#define ERR_PM25 bit3
#define ERR_TVOC bit4
#define ERR_HUMI bit5
#define ERR_COMM1 bit6 //主机报的通讯故障
#define ERR_Filterlock bit7

#define BigtoLittle32(A)   ((( (u32)(A) & 0xff000000) >> 24) | \
                                         (( (u32)(A) & 0x00ff0000) >> 8)   | \
                                         (( (u32)(A) & 0x0000ff00) << 8)   | \
                                         (( (u32)(A) & 0x000000ff) << 24))

#define BigtoLittle16(A)   ((( (u16)(A) & 0xff00) >> 8) | \
                                         (( (u16)(A) & 0x00ff) << 8) )


#define KEY_SPEED 0X20
#define KEY_POWER 0x04
#define KEY_AUTO 0X01
#define KEY_SLEEP 0X08
#define KEY_FILTER 0X02
#define KEY_TIMER 0X10
#define KEY_FACTORY (KEY_SPEED|KEY_AUTO)



#define KEY_FILTER_COUNT  3 //按键滤波延时值（对应时间长短为20乘调用一次间隔的时间=25ms）
#define KEY_LONG_COUNT    500 //长按判断计数延时值 3s
#define KEY_KEEP_COUNT    83 //长按保持时计时值 500ms
#define KEY_PULSE_FILTER_COUNT 3
#define KEY_Available  bit0
#define KEY_LongPress  bit1
#define KEY_LongOnce   bit2
#define KEY_Release    bit3
#define KEY_ShortPress bit4
#define KEY_LongPresskeep  bit5


#define TIMERCONFIRMCNT 30

#define TEST_PINP100 	R_PORT1->PODR_b.PODR0
#define TFT_CS 			R_PORT1->PODR_b.PODR12
#define TFT_WR  		R_PORT1->PODR_b.PODR10
#define TFT_RES 		R_PORT1->PODR_b.PODR13
#define TFT_LED 		R_PORT5->PODR_b.PODR0

#define TFT_CLK 		R_PORT1->PODR_b.PODR11

#define TFT_DATA 		R_PORT1->PODR_b.PODR9

#define Buz_En() 		R_PORT4->PODR_b.PODR1=1
#define Buz_Dis() 		R_PORT4->PODR_b.PODR1=0
#define Buz_Beep()  	{Sys.Buzcnt = 200;}






#define LED_RGB_ALLOFF() {LED_RGB_GREEN_OFF();LED_RGB_BLUE_OFF();LED_RGB_RED_OFF();}


#define LED_Key_auto_on() 	{R_PORT0->PODR_b.PODR4=1;}
#define LED_Key_auto_off() 	{R_PORT0->PODR_b.PODR4=0;}

#define LED_Key_filter_on() {R_PORT0->PODR_b.PODR3=1;}
#define LED_Key_filter_off(){R_PORT0->PODR_b.PODR3=0;}

#define LED_Key_sleep_on() 	{R_PORT0->PODR_b.PODR1=1;}
#define LED_Key_sleep_off() {R_PORT0->PODR_b.PODR1=0;}

#define LED_Key_speed_on() 	{R_PORT4->PODR_b.PODR0=1;}
#define LED_Key_speed_off() {R_PORT4->PODR_b.PODR0=0;}

#define LED_Key_power_on() 	{R_PORT0->PODR_b.PODR2=1;}
#define LED_Key_power_off() {R_PORT0->PODR_b.PODR2=0;}

#define LED_Key_timer_on() 	{R_PORT0->PODR_b.PODR0=1;}
#define LED_Key_timer_off() {R_PORT0->PODR_b.PODR0=0;}

#define  LED_key_all_on()  {R_PORT0->PODR|=0x1f;R_PORT4->PODR_b.PODR0=1;}
#define  LED_key_all_off()	{R_PORT0->PODR&=~0x1f;R_PORT4->PODR_b.PODR0=0;}
#define  LED_key_withoutpower_off()	{R_PORT0->PODR&=~0x1b;R_PORT4->PODR_b.PODR0=0;}
#define LED_RGB_RED_ON()  	{R_PORT1->PODR_b.PODR6=1;}			
#define LED_RGB_RED_OFF()  	{R_PORT1->PODR_b.PODR6=0;}


#define LED_RGB_BLUE_ON()  	{R_PORT3->PODR_b.PODR4=1;}
#define LED_RGB_BLUE_OFF()  {R_PORT3->PODR_b.PODR4=0;}


#define LED_RGB_GREEN_ON()  {R_PORT3->PODR_b.PODR3=1;}
#define LED_RGB_GREEN_OFF() {R_PORT3->PODR_b.PODR3=0;}
#define PWR_MOTOR_DIS() 	{R_PORT2->PODR_b.PODR8=0;}
#define PWR_MOTOR_EN()  	{R_PORT2->PODR_b.PODR8=1;}


#define PWR_WIFI_DIS() 		{R_PORT0->PODR_b.PODR15=0;}
#define PWR_WIFI_EN() 		{R_PORT0->PODR_b.PODR15=1;}

#define PWR_WIFI_RESETDIS() {R_PORT0->PODR_b.PODR14=0;}
#define PWR_WIFI_RESETEN() 	{R_PORT0->PODR_b.PODR14=1;}

#define Pin_CheckMotor   	(R_PORT2->PIDR_b.PIDR0)
#define SLEEP3S_CNT  3000
#define comm_data_cnt 50


extern uint16_t g_touch_button_countvalue[TOUCH_CFG_NUM_BUTTONS];
extern uint16_t g_touch_button_reference[TOUCH_CFG_NUM_BUTTONS];
extern uint64_t button_status;
extern volatile uint8_t g_qe_touch_flag;
//extern lv_disp_drv_t *disp_drv_gloable;
typedef struct lvglamo
{
	void (*Curpfunction)(); //当前函数指针 指向当前运行的函数
	void (*Lastpfunction)(); //函数上一个指针，指向之前运行的函数
	void (*Lastpfunction_InFilter)(); //滤网复位或者滤网状态下，指针缓存，指向之前运行的函数
	u16 cnt; // 动画计数
	u16 Filtercnt; //滤网技术
	u8 Initcomplete;
	u8 Taskcomplete;
	u8 Taskonce;
	u8 Startanimationflg;

} lvgldefdef;

typedef struct boardcomm
{
	u8 Rxindex;
	u8 Txindex;
	u8 Rxcommcnt;
	u8 RXtable[100];
	u8 TXtable[100];
} bordecommdef;



typedef struct  // 7.2变更为数组 【0】为计算需要的风速 【1】为实际所需要的风速值
{
	u32 Spd_Off[2];

	u32 Spd1[2];
	u32 Spd2[2];
	u32 Spd3[2];
	u32 Spd4[2];
	u32 Spd5[2];
	u32 Spd_Output[2];
	u32 Spd_Outputtmp[2]; //输出缓存

} Motor_str;

typedef enum
{
	emodeAuto=0,
	emodeManual,
	emodeSleep

} emode;

typedef enum
{
	espd1=0,
	espd2,
	espd3,
	espd4,
	espd5
} espd;
typedef struct
{
	espd gear; //风速档位
	espd gearreal; //风速档位 真实档位
	u8 TargetGear; // 目标档位
	u8 TargetGearBuf;
	u16 Target;//目标速度
	u16 TargetBuf;//目标速度缓存
	u16 Reference;//实际速度
	u16 FeedBack;//反馈速度
	s16 PrePutOut;//预输出 s16最大范围可达到30K，已经够了
	s16 PutOut;//实际应输出的数值
	s16 Delta;//应有转速和实际转速的差值
	s16 DeltaLast;//前一次的差值
	s16 Delta2;//上面差值的差值
	s32 P;//比例调节值
	s32 I;//积分调节值
	u8 ZeroState;//风机过零状态
	u16 StallHigh;  //风机转速高于设定转速阈值
	u16 StallLow;//风机转速低于设定转速阈值
} SPEED_DEF;

#define	PID_Kp 5
#define	PID_Ki 20//根据不同的情况酌情修改
#define	MaxPutOut  20000  //输出PWM 放大10倍
#define	MinPutOut  2800//上下限，需要酌情修改
#define SPDOFF  25000
#define FLASH_DF_BLOCK_0 0x08000000
#define FLASH_DF_BLOCK_1 0x08000000 +64


//	频率发生器(Frequency generator,FG)用于测量电机转速
typedef struct
{
	u16 CalCnt;
	u16 Cnt;//计数
//	u16 Buf[8];
//	u8 Index;//buf的索引
	u8 CycleCnt;//转一圈判断
	u8 State;//防重复计数
//	u8 Cnt_L;
//	u8 Cnt_H;
} FG_DEF;

//extern SPEED_DEF Speed;
extern FG_DEF FG;
#define Flowoff 16
#define Flowon 15
#define Flow_turnonTFT 10
#define Flow_turnring  0

typedef struct
{
	u8 flowcnt;
	u8 testflg;
	u8 flashsrc[50];
	u8 delaycnt;
	u8 power;
	u8 opmode;
	u8 opmodetmp;
	u8 LVDcheckflg;  // 低电压检测打开标志位
	u8 AQI_LEVEL; //AQI等级  默认全部关闭显示灯
	u8 AQI_DISABLE; //aqi开关
	u8 Factoryflg;    //长按电源和灯 组合键 15S进入	响2声
	u8 Factorysteps;  //工厂模式测试步骤
	u8 FilterTestFlg;   //长按组合按键 开关机和模式键 15S进入 响2声
	u16 FactoryDelaycnt; // 工厂模式下的延迟技术
	u16 Sleep3S_Cnt; //3S计数
	u8 eLight20S_Cnt; // 20s计数
	u16 Plugin_Cnt;  //上电时间计数
	u16 Warnup_Cnt;  //上电预热时间计数
	u16 Errcode;  // 故障代码
	u16 Wifitimeoutcnt; // wifi配置超时时间 一般按15分钟计算
	u16 WifiCommtimeoutcnt; //wifi模块和窜口通讯超时计数
	u8 Buzcnt;
	u8 softwareversion;
	u8 pm25softwareversion;
	u8 tvocversion;
	u8 pcbversion;
	SPEED_DEF Speed;
	struct
	{
		u16 timeoutcnt; //通讯超时
		u8 confirmcnt; //确认通讯成功计数  必须连续通讯4次才能显示 正常温湿度 不然显示0
		u8 steps;
		u8 rxindex; //接收索引
		u16 flowcnt; // 流程计数
		u8 rxcnt;  //接收时间计数
		u8 txdata[comm_data_cnt];
		u8 rxdata[comm_data_cnt];
		u8 rxdatasum;
	} comm;

	struct
	{
		u16 maxhour;     //最大工作时间
		u16 accumulatedhour;
		u16 calcnt;
		u8 percentage; // 滤网百分比
	} Filter;
	struct
	{
		u8 setflg;
		u8 settingflg;
		u8 hour;
		u8 setcnt; // 设定的时间 默认时间到则确认定时
		u16 excutecnt; //定时执行的计时
	} Timer;

	u8 childlock;
	u16 childlockcnt;
	u16 pm25value;
	u16 tvocvalue;
	s8 Tempvalue;
	u8 Humivalue;

} Sys_str;


#define FLASH_HP_DF_BLOCK_0               0x08000000U /*   64 B:  0x40100000 - 0x4010003F */
#define FLASH_HP_DF_BLOCK_1               0x08000040U /*   64 B:  0x40100040 - 0x4010007F */
#define FLASH_HP_DF_BLOCK_2               0x08000080U /*   64 B:  0x40100080 - 0x401000BF */
#define FLASH_HP_DF_BLOCK_3               0x080000C0U /*   64 B:  0x401000C0 - 0x401000FF */
#define FLASH_HP_DF_BLOCK_SIZE            (64)





#endif // End of define __HAL_ENTRY_H
/***************************************************************
                      ** End of hal_entry.h
***************************************************************/
