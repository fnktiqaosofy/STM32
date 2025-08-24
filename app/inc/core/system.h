#ifndef SYSTEM_H
#define SYSTEM_H

#include "common-defines.h"

#define CPU_FREQ (168000000)
#define SYSTICK_FREQ (1000)

void system_setup(void);

uint64_t system_get_ticks(void);

#endif /* SYSTEM_H */
