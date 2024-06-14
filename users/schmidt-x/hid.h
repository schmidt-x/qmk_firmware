#pragma once

void hid_handle_ahk(uint8_t arg, bool *ahk_enabled);
void hid_handle_ping(uint8_t* data, uint8_t length);


enum raw_hid {
	RESERVED,
	HID_AHK,
	
	HID_PING = 255
};

