#pragma once

#include "quantum.h"

bool layer_is_default(void);
bool l_sft_matrix_is_on(void);
bool r_sft_matrix_is_on(void);

#ifdef HRM_ENABLE
bool hrm(bool pressed, bool *is_mod, bool left, uint8_t mods);
#endif