#include "database.h"

uint8_t endpoint_exists(uint8_t endpoint);

struct row_t {
    uint8_t app_endpoint;
    struct device_header_t devices[DEVICE_COUNT];
    uint8_t is_free;
};

struct row_t rows[DEVICE_COUNT];

void init_database() {
    for (int i = 0; i < DEVICE_COUNT; i++) {
        struct row_t row = {
                .is_free = 1
        };
        rows[i] = row;
    }
}

uint8_t add_endpoint(uint8_t endpoint) {
    if (endpoint_exists(endpoint)) {
        return ERR_ENDPOINT_EXISTS;
    }

    for (int i = 0; i < DEVICE_COUNT; i++) {
        if (rows[i].is_free) {
            struct row_t row = {
                    .app_endpoint = endpoint,
                    .is_free = 0
            };
            rows[i] = row;
            return SUCCESS;
        }
    }
    return ERR_DB_FULL;
}

void print_devices() {
    printf("-- Registered devices -- \n");
    for (int i = 0; i < DEVICE_COUNT; i++) {
        if (!rows[i].is_free) {
            printf("Device endpoint id: %d\n", rows[i].app_endpoint);
        }
    }
}

uint8_t endpoint_exists(uint8_t endpoint) {
    for (int i = 0; i < DEVICE_COUNT; i++) {
        if (!rows[i].is_free && rows[i].app_endpoint == endpoint) {
            return ERR_ENDPOINT_EXISTS;
        }
    }
    return SUCCESS;
}