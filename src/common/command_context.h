#include <stdint.h>
#include <string.h>

#ifndef PROJEKT2_COMMAND_CONTEXT_H
#define PROJEKT2_COMMAND_CONTEXT_H

#define COMMAND_LEN 0 // This has to be increased with every command in array!

#define CONTEXT_NORMAL 1

void decode_command(char *cmd);

void switch_context(uint8_t ctx);

#endif //PROJEKT2_COMMAND_CONTEXT_H
