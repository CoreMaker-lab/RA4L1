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





        /* FIXME: Since this is a temporary process, so re-create a waiting process yourself. */
        R_BSP_SoftwareDelay(TOUCH_SCAN_INTERVAL_EXAMPLE, BSP_DELAY_UNITS_MILLISECONDS);
    }
}


