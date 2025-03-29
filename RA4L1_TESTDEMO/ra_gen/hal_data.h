/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_slcdc.h"
FSP_HEADER
/** SLCDC Instance. */
extern const slcdc_instance_t g_slcdc0;

/** Access the SLCDC instance using these structures when calling API functions directly (::p_api is not used). */
extern slcdc_instance_ctrl_t g_slcdc0_ctrl;
extern const slcdc_cfg_t g_slcdc0_cfg;
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
