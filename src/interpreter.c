#include "interpreter.h"
#include <stdio.h>
#include <stdlib.h>
#include "opcode.h"
#include "runtime.h"

#define STACK_PUSH(val, ctx) \
  ctx->stack[ctx->stack_ptr++] = val;
#define STACK_POP(val, ctx) \
  val = ctx->stack[--ctx->stack_ptr];

#define DEBUG 1

static runtime_ctx runtime;

stack_ctx *stack_init() {
  stack_ctx *stack = malloc(sizeof(stack_ctx));
  stack->stack_ptr = 0;
  return stack;
}

int execute(stack_ctx *ctx, uint8_t *bytecode) {
  uint8_t opcode_length = *bytecode;
  uint8_t *bc   = bytecode;
  uint8_t *data =
      bytecode + opcode_length + 1; // +1 - the initial opcode_length.
  bc++; // Step to first instruction.

  while (1) {
    uint8_t instr = *bc;
    switch(instr) {

    case PUSH: {
#ifdef DEBUG
      printf("PUSH opcode\n");
#endif
      stack_val *a = malloc(sizeof(stack_val));
      data += parse_stack_val(a, data);
      STACK_PUSH(a, ctx);
      break;
    }

    case POP: {
#ifdef DEBUG
      printf("POP opcode\n");
#endif
      stack_val *a;
      STACK_POP(a, ctx);
      free_stack_val(a);
      break;
    }

    case RETURN: {
#ifdef DEBUG
      printf("RETURN opcode\n");
#endif
      stack_val *a;
      STACK_POP(a, ctx);
      switch(a->type) {
        case INTVAL:
          printf("Return: %d\n", a->int_val);
          break;
        default:
          printf("Error!\n");
      }
      return 0;
    }

    case ADD: {
#ifdef DEBUG
      printf("ADD opcode\n");
#endif
      stack_val *a, *b;
      STACK_POP(a, ctx);
      STACK_POP(b, ctx);
      uint8_t type[2] = { a->type, b->type };
      profile(&runtime, instr, type);
      stack_val *c = malloc(sizeof(stack_val));
      if (a->type == INTVAL && b->type == INTVAL) {
        c->type = INTVAL;
        c->int_val = a->int_val + b->int_val;
      } else {
        // TODO: other types.
        printf("TODO: ADD polymorphism: ");
        printf("a->type: %d, b->type: %d\n", a->type, b->type);
        return -1;
      }
      STACK_PUSH(c, ctx);
      break;
    }

    default:
      return -1;
    }

    bc += 1;
  }

  return 1;
}

