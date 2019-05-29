#ifndef STACK_VAL_H
#define STACK_VAL_H

#include <stddef.h>
#include <stdint.h>

// TODO: Maybe these should be placed elsewhere?
#define INTVAL   0
#define STRVAL   1
#define FLOATVAL 2

typedef struct _stack_val {
  uint8_t type;
  union {
    uint64_t  int_val;
    uint8_t   *str_val;
    float     float_val;
  };
} stack_val;

size_t parse_stack_val(stack_val *in, uint8_t *data);
void free_stack_val(stack_val *val);

#endif // STACK_VAL_H

