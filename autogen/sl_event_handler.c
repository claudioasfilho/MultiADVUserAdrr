#include "sl_event_handler.h"

#include "em_chip.h"
#include "sl_device_init_nvic.h"
#include "sl_board_init.h"
#include "sl_device_init_hfrco.h"
#include "sl_hfxo_manager.h"
#include "sl_device_init_hfxo.h"
#include "sl_device_init_lfxo.h"
#include "sl_device_init_clocks.h"
#include "sl_device_init_emu.h"
#include "pa_conversions_efr32.h"
#include "sl_rail_util_rf_path.h"
#include "sl_sleeptimer.h"
#include "app_log.h"
#include "sl_bluetooth.h"
#include "sl_iostream_init_instances.h"
#include "sl_iostream_stdlib_config.h"
#include "sl_iostream_init_usart_instances.h"
#include "sl_mbedtls.h"
#include "sl_mpu.h"
#include "nvm3_default.h"
#include "sl_power_manager.h"

void sl_iostream_init_instances(void)
{
  sl_iostream_usart_init_instances();
}

void sl_platform_init(void)
{
  CHIP_Init();
  sl_device_init_nvic();
  sl_board_preinit();
  sl_device_init_hfrco();
  sl_hfxo_manager_init_hardware();
  sl_device_init_hfxo();
  sl_device_init_lfxo();
  sl_device_init_clocks();
  sl_device_init_emu();
  sl_board_init();
  nvm3_initDefault();
  sl_power_manager_init();
}

void sl_driver_init(void)
{
}

void sl_service_init(void)
{
  sl_sleeptimer_init();
  sl_hfxo_manager_init();
  sl_iostream_init_instances();
  sl_iostream_stdlib_disable_buffering();
  sl_mbedtls_init();
  sl_mpu_disable_execute_from_ram();
}

void sl_stack_init(void)
{
  sl_rail_util_pa_init();
  sl_rail_util_rf_path_init();
  sl_bt_init();
}

void sl_internal_app_init(void)
{
  app_log_init();
}

void sl_platform_process_action(void)
{
}

void sl_service_process_action(void)
{
}

void sl_stack_process_action(void)
{
  sl_bt_step();
}

void sl_internal_app_process_action(void)
{
}
