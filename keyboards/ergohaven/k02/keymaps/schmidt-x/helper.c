#include "helper.h"
#include "action_layer.h"
#include "action_util.h"

bool layer_is_default(void) {
  return !layer_state;
}

bool layer_is_not_default(void) {
	return layer_state;
}

bool no_mods(void) {
	return !get_mods();
}