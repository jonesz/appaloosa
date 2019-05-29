#ifndef RUNTIME_H
#define RUNTIME_H

#include <stdint.h>
#include "opcode.h"

typedef struct _type_profile {
  uint8_t a; // int
  uint8_t b; // string
  uint8_t c; // float
} type_profile;

typedef struct _runtime_ctx {
  type_profile record[OPCODE_NUM];
} runtime_ctx;

void profile(runtime_ctx *ctx, uint8_t opcode, uint8_t *type);

#endif // RUNTIME_H

