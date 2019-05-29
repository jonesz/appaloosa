/* interpreter.h
 * 2019, Ethan Jones <etn.jones@gmail.com>. */

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdint.h>
#include "stack_val.h"

#define STACK_SIZE 512

typedef struct _stack_ctx {
  stack_val *stack[STACK_SIZE];
  uint64_t stack_ptr;
} stack_ctx;

stack_ctx *stack_init();
int execute(stack_ctx *ctx, uint8_t *code);

#endif // INTERPRETER_H

