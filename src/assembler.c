#define DEBUG 1
#include "assembler.h"
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#include <stdio.h>
#endif 

#include "opcode.h"
#include "stack_val.h" // INTVAL, STRVAL, etc.

assemble_ctx *assemble_init() {
  assemble_ctx *ctx  = malloc(sizeof(assemble_ctx));
  ctx->opcode_length = 0;
  ctx->data_length   = 0;
  return ctx;
}

void op_push_int(assemble_ctx *ctx, uint64_t i) {
  ctx->opcode_length++;
  // 8-bit, 64-bit.
  ctx->opcodes = realloc(ctx->opcodes, ctx->opcode_length);
  ctx->opcodes[ctx->opcode_length - 1] = PUSH;

  ctx->data    = realloc(ctx->data, ctx->data_length);
  ctx->data_length += sizeof(uint8_t) + sizeof(uint64_t);
  ctx->data[ctx->data_length - sizeof(uint64_t) - sizeof(uint8_t)] = INTVAL;
  *(uint64_t *)&ctx->data[ctx->data_length - sizeof(uint64_t)] = i;
}

void op_push_float(assemble_ctx *ctx, float i) {
  // TODO
}

void op_push_string(assemble_ctx *ctx, uint8_t *i) {
  // TODO
}

void op_return(assemble_ctx *ctx) {
  ctx->opcode_length++;
  ctx->opcodes = realloc(ctx->opcodes, ctx->opcode_length);
  ctx->opcodes[ctx->opcode_length - 1] = RETURN;
}

void op_add(assemble_ctx *ctx) {
  ctx->opcode_length++;
  ctx->opcodes = realloc(ctx->opcodes, ctx->opcode_length);
  ctx->opcodes[ctx->opcode_length - 1] = ADD;
}

uint8_t *assemble_finish(assemble_ctx *ctx, size_t *size) {

#ifdef DEBUG
  printf("opcodes: %d ", ctx->opcode_length);
  for (int i = 0; i < ctx->opcode_length; i++)
    printf("%x ", ctx->opcodes[i]);
  printf("\ndata: ");
  for (int i = 0; i < ctx->data_length; i++)
    printf("%x ", ctx->data[i]);
  printf("\n");
#endif

  uint8_t *ret = malloc(ctx->opcode_length + ctx->data_length);
  uint8_t *b = ret;
  *b = ctx->opcode_length;
  b++;
  memcpy(b, ctx->opcodes, ctx->opcode_length);
  b += ctx->opcode_length;
  memcpy(b, ctx->data, ctx->data_length);
  b + ctx->data_length;

#ifdef DEBUG
  for (int i = 0; i < ctx->opcode_length + 1; i++)
    printf("%x ", ret[i]);
#endif
  *size = ctx->opcode_length + ctx->data_length + 1;
  return ret;
}

