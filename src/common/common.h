#ifndef PROJEKT2_COMMON_H
#define PROJEKT2_COMMON_H

#define sbi(port, bit) (port |= (1<<bit))
#define cbi(port, bit) (port &= ~(1<<bit))
#define tbi(port, bit) (port ^= (1<<bit))

#endif //PROJEKT2_COMMON_H
