#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/scb.h>

#include "core/system.h"
#include "core/timer.h"

#define BOOTLOADER_SIZE (0x8000U)


#define LED_PORT (GPIOG)
#define LED_PIN (GPIO13)

static void vector_setup(void) {
  SCB_VTOR = BOOTLOADER_SIZE;
}

static void gpio_setup(void) {
  rcc_periph_clock_enable(RCC_GPIOG);
  gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN);
  //gpio_set_af(LED_PORT, GPIO_AF1, LED_PIN);
}

int main(void) {

  vector_setup();
  system_setup();
  gpio_setup();

  while (true) {
      gpio_toggle(GPIOG, GPIO13);  // Toggle onboard LED (red)
      for (volatile int i = 0; i < 1000000; ++i);  // crude delay
  }
  //timer_setup();

  /*uint64_t start_time = system_get_ticks();
  float duty_cycle = 0.0f;

  timer_pwm_set_duty_cycle(duty_cycle);


  while (true) {
    if (system_get_ticks() - start_time >= 5) { 
      duty_cycle += 1.0f;
      if (duty_cycle > 150.0f) {
        duty_cycle = 0.0f;
      }
      timer_pwm_set_duty_cycle(duty_cycle);
      start_time = system_get_ticks();
    }
  }
  */
  // he do be looping
  return 0;
}
