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

void hid_handle_ping(uint8_t* data, uint8_t length) {
	uint8_t hours   = data[1];
	uint8_t minutes = data[2];
	uint8_t seconds = data[3];
	bool is_pm = (bool)data[4];
	
	printf("hid_ping at: %02d:%02d:%02d %s\n", hours, minutes, seconds, is_pm ? "PM" : "AM");
	
	uint8_t response[length];
	memset(response, 0, length);
	
	response[0] = HID_PING;
	raw_hid_send(response, length);
}