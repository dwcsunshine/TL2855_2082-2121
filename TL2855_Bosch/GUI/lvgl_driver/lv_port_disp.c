
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_disp.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void disp_init(void);

static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p);
#if LV_USE_GPU
static void gpu_blend(lv_color_t * dest, const lv_color_t * src, uint32_t length, lv_opa_t opa);
static void gpu_fill(lv_color_t * dest, uint32_t length, lv_color_t color);
#endif

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*-----------------------------
     * Create a buffer for drawing
     *----------------------------*/
//    /* Example for 1) */
//    static lv_disp_buf_t disp_buf_1;
//    static lv_color_t buf1_1[LV_HOR_RES_MAX * 10];                      /*A buffer for 10 rows*/
//    lv_disp_buf_init(&disp_buf_1, buf1_1, NULL, LV_HOR_RES_MAX * 10);   /*Initialize the display buffer*/

    /* Example for 2) */
	static lv_disp_buf_t disp_buf_2;
	static lv_color_t buf2_1[LV_HOR_RES_MAX * 40];                        /*A buffer for 10 rows*/
	static lv_color_t buf2_2[LV_HOR_RES_MAX * 40];                        /*An other buffer for 10 rows*/
	lv_disp_buf_init(&disp_buf_2, buf2_1, buf2_2, LV_HOR_RES_MAX * 40);   /*Initialize the display buffer*/

    /* Example for 3) */
//  static lv_disp_buf_t disp_buf_3;
//  static lv_color_t buf3_1[LV_HOR_RES_MAX * LV_VER_RES_MAX];            /*A screen sized buffer*/
//  static lv_color_t buf3_2[LV_HOR_RES_MAX * LV_VER_RES_MAX];            /*An other screen sized buffer*/
//  lv_disp_buf_init(&disp_buf_3, buf3_1, buf3_2, LV_HOR_RES_MAX * LV_VER_RES_MAX);   /*Initialize the display buffer*/


    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/

    lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/

    /*Set up the functions to access to your display*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Set a display buffer*/
    disp_drv.buffer = &disp_buf_2;

#if LV_USE_GPU
    /*Optionally add functions to access the GPU. (Only in buffered mode, LV_VDB_SIZE != 0)*/

    /*Blend two color array using opacity*/
    disp_drv.gpu_blend = gpu_blend;

    /*Fill a memory array with a color*/
    disp_drv.gpu_fill = gpu_fill;
#endif

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Initialize your display and the required peripherals. */
static void disp_init(void)
{
    /*You code here*/
}

void LCD_fill(lv_color_t * color_p)
{
//	lv_color_t * color_p = color_p;
    uint8_t data[2] = {0};  //color??16bit????????????????????????????????

    data[0] = color_p->full >> 8;
    data[1] = color_p->full;

	LCD_WR_DATA(data[0]);
	LCD_WR_DATA(data[1]);
}

u16 const table16[5]={0xff11,0x2233,0x3344,0x4455,0x5566};

void LCD_Color_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t *color)
{  
	uint16_t height,width;
	uint16_t i,j;
	width=ex-sx+1; 			//??????????????
	height=ey-sy+1;			//????
		LCD_WR_REG(0x2a);
		LCD_WR_DATA(0);   
		LCD_WR_DATA(sx);   
		LCD_WR_REG(0x2b);
		LCD_WR_DATA((sy+i)>>8);   
		LCD_WR_DATA((sy+i)&0xff);   //???????????? 
		LCD_WR_REG(0x2c);     //????????GRAM
		g_transfer_complete = 0;
		R_DMAC_Reset (&g_transfer_ctrl,((u8 *)color)+1, &g_spi0_ctrl.p_regs->SPDR_BY,width*2-1);
		TFT_CS = 0;
		TFT_WR = 1;	
		g_spi0_ctrl.p_regs->SPDR_BY = color[0]&0xff;
		color_gloable+=width;	  
}

/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished. */
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

//    int32_t x;
//    int32_t y;
//    for(y = area->y1; y <= area->y2; y++) {
//        for(x = area->x1; x <= area->x2; x++) {
//            /* Put a pixel to the display. For example: */
//		put_px(x, y, &color_p);
//            /* put_px(x, y, *color_p)*/
//            color_p++;
//        }
//    }
	disp_drv_gloable = disp_drv;
	color_gloable = color_p;
	//area_gloable = area;
	area_gloable.x1 = area->x1;
	area_gloable.x2 = area->x2;
	area_gloable.y1 = area->y1;
	area_gloable.y2 = area->y2;
	LCD_Color_Fill(area->x1,area->y1,area->x2,area->y2,(uint16_t*)color_p);
	
    /* IMPORTANT!!!
     * Inform the graphics library that you are ready with the flushing*/
//   lv_disp_flush_ready(disp_drv);
	
}



/*OPTIONAL: GPU INTERFACE*/
#if LV_USE_GPU

/* If your MCU has hardware accelerator (GPU) then you can use it to blend to memories using opacity
 * It can be used only in buffered mode (LV_VDB_SIZE != 0 in lv_conf.h)*/
static void gpu_blend(lv_disp_drv_t * disp_drv, lv_color_t * dest, const lv_color_t * src, uint32_t length, lv_opa_t opa)
{
    /*It's an example code which should be done by your GPU*/

    uint32_t i;
    for(i = 0; i < length; i++) {
        dest[i] = lv_color_mix(dest[i], src[i], opa);
    }
}

/* If your MCU has hardware accelerator (GPU) then you can use it to fill a memory with a color
 * It can be used only in buffered mode (LV_VDB_SIZE != 0 in lv_conf.h)*/
static void gpu_fill_cb(lv_disp_drv_t * disp_drv, lv_color_t * dest_buf, lv_coord_t dest_width,
                    const lv_area_t * fill_area, lv_color_t color);
{
    /*It's an example code which should be done by your GPU*/
    uint32_t x, y;
    dest_buf += dest_width * fill_area->y1; /*Go to the first line*/

    for(y = fill_area->y1; y < fill_area->y2; y++) {
        for(x = fill_area->x1; x < fill_area->x2; x++) {
            dest_buf[x] = color;
        }
        dest_buf+=dest_width;    /*Go to the next line*/
    }
}

#endif  /*LV_USE_GPU*/

#else /* Enable this file at the top */

/* This dummy typedef exists purely to silence -Wpedantic. */
typedef int keep_pedantic_happy;
#endif
