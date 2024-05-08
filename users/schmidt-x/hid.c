#include "hid.h"
#include "raw_hid.h"
#include "quantum.h"


void hid_handle_ahk(uint8_t arg, bool *ahk_enabled) {
	switch (arg) {
		case 0 ... 1:
			*ahk_enabled = (bool)arg;
			return;
		
		default:
			return;
	}
}

void hid_handle_ping(uint8_t length) {
	uint8_t response[length];
	memset(response, 0, length);
	
	response[0] = 255;
	raw_hid_send(response, length);
}