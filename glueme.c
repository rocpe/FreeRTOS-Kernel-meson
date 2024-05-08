/* 
 * To use libopencm3 with FreeRTOS on Cortex-M3 platform, we must
 * define three interlude routines. If you don't use libopencm3 then
 * you have to change this file so that it works with FreeRTOS.
 */
#include "FreeRTOS.h"
#include "task.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/nvic.h>

extern void vPortSVCHandler() __attribute__ (( naked ));
extern void xPortPendSVHandler() __attribute__ (( naked ));
extern void xPortSysTickHandler();

void sv_call_handler() 
{
	vPortSVCHandler();
}

void pend_sv_handler() 
{
	xPortPendSVHandler();
}

void sys_tick_handler() 
{
	xPortSysTickHandler();
} 
