/***********************************************************************
*
* FILE : qe_touch_sample.c
* DESCRIPTION : Main Program for RA
*
* NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "qe_touch_config.h"
#define TOUCH_SCAN_INTERVAL_EXAMPLE (20)    /* milliseconds */

void qe_touch_main(void);



uint64_t button_status;
#if (TOUCH_CFG_NUM_SLIDERS != 0)
uint16_t slider_position[TOUCH_CFG_NUM_SLIDERS];
#endif
#if (TOUCH_CFG_NUM_WHEELS != 0)
uint16_t wheel_position[TOUCH_CFG_NUM_WHEELS];
#endif





int i=0;


void qe_touch_main(void)
{
    fsp_err_t err;




    /* Open Touch middleware */
    err = RM_TOUCH_Open(g_qe_touch_instance_config01.p_ctrl, g_qe_touch_instance_config01.p_cfg);
    if (FSP_SUCCESS != err)
    {
        while (true) {}
    }





    /* Main loop */
    while (true)
    {


        /* for [CONFIG01] configuration */
        err = RM_TOUCH_ScanStart(g_qe_touch_instance_config01.p_ctrl);
        if (FSP_SUCCESS != err)
        {
            while (true) {}
        }
        while (0 == g_qe_touch_flag) {}
        g_qe_touch_flag = 0;

        err = RM_TOUCH_DataGet(g_qe_touch_instance_config01.p_ctrl, &button_status, NULL, NULL);
        if (FSP_SUCCESS == err)
        {
            /* TODO: Add your own code here. */
            if(button_status & (0b1 ) )
             {
                 R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_06_PIN_09, BSP_IO_LEVEL_HIGH);
             }
             else
             {
                 R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_06_PIN_09, BSP_IO_LEVEL_LOW);
             }

             if(button_status & (0b10) )
             {
                 R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_06_PIN_10, BSP_IO_LEVEL_HIGH);
             }
             else
             {
                 R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_06_PIN_10, BSP_IO_LEVEL_LOW);
             }
        }

        if(i==0)
        {
        //清空0-41段
          uint8_t segment_data_num_off[41+1] ;
          for(int i=0;i<=41;i++)
              segment_data_num_off[i]=0;
          R_SLCDC_Write(&g_slcdc0_ctrl, 0, segment_data_num_off, sizeof(segment_data_num_off));
//          R_BSP_SoftwareDelay (2000, BSP_DELAY_UNITS_MILLISECONDS);
          R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_06_PIN_01, BSP_IO_LEVEL_LOW);
        }
        else if(i==40)
        {
          //全部点亮
          uint8_t segment_data_num_on[41+1] ;
          for(int i=0;i<=41;i++)
              segment_data_num_on[i]=0xf;
          R_SLCDC_Write(&g_slcdc0_ctrl, 0, segment_data_num_on, sizeof(segment_data_num_on));
//          R_BSP_SoftwareDelay (2000, BSP_DELAY_UNITS_MILLISECONDS);
        }
        else if(i==60)
        {
            R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_06_PIN_01, BSP_IO_LEVEL_HIGH);
        }
        else if(i==80)
        {
          //准备并写入段显示数据,第一个数码管显示1
          R_SLCDC_Modify(&g_slcdc0_ctrl, 3, 0x0, 0xF);
          R_SLCDC_Modify(&g_slcdc0_ctrl, 11, 0x6, 0xF);

          //准备并写入段显示数据,第二个数码管显示2
          R_SLCDC_Modify(&g_slcdc0_ctrl, 15, 0xE, 0xF);
          R_SLCDC_Modify(&g_slcdc0_ctrl, 16, 0x3, 0xF);

          //准备并写入段显示数据,第三个数码管显示3
          R_SLCDC_Modify(&g_slcdc0_ctrl, 22, 0xA, 0xF);
          R_SLCDC_Modify(&g_slcdc0_ctrl, 23, 0x7, 0xF);

          //准备并写入段显示数据,第四个数码管显示4
          R_SLCDC_Modify(&g_slcdc0_ctrl, 24, 0x3, 0xF);
          R_SLCDC_Modify(&g_slcdc0_ctrl, 29, 0x6, 0xF);

          //准备并写入段显示数据,第五个数码管显示5
          R_SLCDC_Modify(&g_slcdc0_ctrl, 30, 0xB, 0xF);
          R_SLCDC_Modify(&g_slcdc0_ctrl, 39, 0x5, 0xF);

          //准备并写入段显示数据,第六个数码管显示6
          R_SLCDC_Modify(&g_slcdc0_ctrl, 40, 0xF, 0xF);
          R_SLCDC_Modify(&g_slcdc0_ctrl, 41, 0x5, 0xF);
//          R_BSP_SoftwareDelay (2000, BSP_DELAY_UNITS_MILLISECONDS);
        }
        else if(i==120)
        {
            i=-1;
        }

        i++;





        /* FIXME: Since this is a temporary process, so re-create a waiting process yourself. */
        R_BSP_SoftwareDelay(TOUCH_SCAN_INTERVAL_EXAMPLE, BSP_DELAY_UNITS_MILLISECONDS);
    }
}


