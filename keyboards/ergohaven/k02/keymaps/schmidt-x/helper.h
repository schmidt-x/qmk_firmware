#pragma once

#include "quantum.h"

bool layer_is_default(void);
bool l_sft_matrix_is_on(void);
bool r_sft_matrix_is_on(void);

#ifdef HRM_ENABLE
bool l_hrm(bool pressed, bool *is_mod, uint8_t mods);
bool r_hrm(bool pressed, bool *is_mod, uint8_t mods);
#endif