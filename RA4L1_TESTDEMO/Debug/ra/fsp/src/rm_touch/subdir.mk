################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/rm_touch/rm_touch.c 

C_DEPS += \
./ra/fsp/src/rm_touch/rm_touch.d 

OBJS += \
./ra/fsp/src/rm_touch/rm_touch.o 

SREC += \
RA4L1_TESTDEMO.srec 

MAP += \
RA4L1_TESTDEMO.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/rm_touch/%.o: ../ra/fsp/src/rm_touch/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CM33 -D_RA_ORDINAL=1 -DQE_TOUCH_CONFIGURATION -I"C:/Users/a8456/e2_studio/workspace_5.8/RA4L1_TESTDEMO/src" -I"." -I"C:/Users/a8456/e2_studio/workspace_5.8/RA4L1_TESTDEMO/ra/fsp/inc" -I"C:/Users/a8456/e2_studio/workspace_5.8/RA4L1_TESTDEMO/ra/fsp/inc/api" -I"C:/Users/a8456/e2_studio/workspace_5.8/RA4L1_TESTDEMO/ra/fsp/inc/instances" -I"C:/Users/a8456/e2_studio/workspace_5.8/RA4L1_TESTDEMO/ra/arm/CMSIS_6/CMSIS/Core/Include" -I"C:/Users/a8456/e2_studio/workspace_5.8/RA4L1_TESTDEMO/ra_gen" -I"C:/Users/a8456/e2_studio/workspace_5.8/RA4L1_TESTDEMO/ra_cfg/fsp_cfg/bsp" -I"C:/Users/a8456/e2_studio/workspace_5.8/RA4L1_TESTDEMO/ra_cfg/fsp_cfg" -I"C:/Users/a8456/e2_studio/workspace_5.8/RA4L1_TESTDEMO/qe_gen" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

