#ifndef UTILS_H
#define UTILS_H

#define LED_BULTIN 13

#define setbit(base, v) ((base) |= (1 << v))
#define clearbit(base, v) ((base) &= ~(1 << v))
#define readbit(base, v) ((base) & (1 << v))

#define SETORCLEAR(cond, addr, v)                                              \
    do {                                                                       \
        cond ? setbit(addr, v) : clearbit(addr, v);                            \
    } while (0)

#endif
