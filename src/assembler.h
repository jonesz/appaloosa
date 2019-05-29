#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stddef.h>
#include <stdint.h>

typedef struct _assemble_ctx {
  uint8_t opcode_length;
  uint8_t *opcodes;
  uint64_t data_length;
  uint8_t *data;
} assemble_ctx;

assemble_ctx *assemble_init();
void op_push_int(assemble_ctx *ctx, uint64_t i);
void op_push_float(assemble_ctx *ctx, float i);
void op_push_string(assemble_ctx *ctx, uint8_t *i);
void op_pop(assemble_ctx *ctx);
void op_return(assemble_ctx *ctx);
void op_add(assemble_ctx *ctx);
uint8_t *assemble_finish(assemble_ctx *ctx, size_t *len);

#endif // ASSEMBLER_H

