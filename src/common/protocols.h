#include <stdint.h>

#ifndef MSSY_GATEWAY_PROTOCOLS_H
#define MSSY_GATEWAY_PROTOCOLS_H

#define COMMAND_CONNECT 128
#define COMMAND_DISCONNECT 64
#define COMMAND_DISCOVERY_REQUEST 32
#define COMMAND_DISCOVERY_RESPONSE 16
#define COMMAND_READ_REQUEST 8
#define COMMAND_WRITE 4
#define COMMAND_READ_RESPONSE 2
#define COMMAND_DESCRIPTION_REQUEST 1
#define COMMAND_DESCRIPTION_RESPONSE 3

#define DEVICE_TYPE_KEYBOARD 255
#define DEVICE_TYPE_OLED 128
#define DEVICE_TYPE_MAGNETIC_CONTACT 64
#define DEVICE_TYPE_RELAY 32
#define DEVICE_TYPE_THERMO_REGULATOR 16
#define DEVICE_TYPE_TEMP 10
#define DEVICE_TYPE_PRESSURE 8
#define DEVICE_TYPE_HUMIDITY 6
#define DEVICE_TYPE_MOTOR 4
#define DEVICE_TYPE_SLEEP 2
#define DEVICE_TYPE_TIMER 1

struct command_t {
    uint8_t command_id,
    size_t len,
    void *data
};

struct device_t {
    uint8_t device_type,
    uint8_t r_w,
    uint8_t device_id,
    uint8_t len,
    void *data
};

#endif //PROJEKT2_COMMAND_CONTEXT_H
