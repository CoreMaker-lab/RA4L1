/* generated HAL source file - do not edit */
#include "hal_data.h"
slcdc_instance_ctrl_t g_slcdc0_ctrl;
const slcdc_cfg_t g_slcdc0_cfg =
{ .slcdc_clock = SLCDC_CLOCK_LOCO,
  .slcdc_clock_setting = SLCDC_CLK_DIVISOR_LOCO_256,
  .bias_method = SLCDC_BIAS_3,
  .time_slice = SLCDC_SLICE_4,
  .waveform = SLCDC_WAVE_A,
  .drive_volt_gen = SLCDC_VOLT_INTERNAL,
  .contrast = SLCDC_CONTRAST_0,
  .ref_volt_sel = (slcdc_ref_volt_sel_t) SLCDC_REF_INTERNAL_VL1_CAPACITOR_VCC_EXTERNAL };

/* Instance structure to use this module. */
const slcdc_instance_t g_slcdc0 =
{ .p_ctrl = &g_slcdc0_ctrl, .p_cfg = &g_slcdc0_cfg, .p_api = &g_slcdc_on_slcdc };
void g_hal_init(void)
{
    g_common_init ();
}
