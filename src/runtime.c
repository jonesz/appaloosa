#define DEBUG 1
#include "runtime.h"

#ifdef DEBUG
#include <stdio.h>
#endif

#include "stack_val.h"


// TODO: Overflow issues in the type profile struct.
void profile(runtime_ctx *ctx, uint8_t opcode, uint8_t *type) {
  // TODO: As of now, we only profile for the ADD instruction,
  // which takes two types. This should be generalized for
  // opcodes that take variable amounts of inputs.
  for (int i = 0; i < 2; i++) {
    switch (type[i]) {
    case INTVAL:
      ctx->record[opcode].a += 1;
#ifdef DEBUG
      printf("runtime profiler: encountered INTVAL\n");
#endif
      break;
    case STRVAL:
      ctx->record[opcode].b += 1;
      break;
    case FLOATVAL:
      ctx->record[opcode].c += 1;
      break;
    }
  }
}
