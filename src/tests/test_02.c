#include "../interpreter.h"
#include "../assembler.h"
#include <stdio.h>

// Test basic interpreter functionality with assembled bytecode.

int main(int argc, char **argv) {
  assemble_ctx *a = assemble_init();
  op_push_int(a, 210203);
  op_push_int(a, 123483);
  op_add(a);
  op_return(a);

  size_t len;
  uint8_t *bytecode =  assemble_finish(a, &len);
  printf("bytecode: ");
  for (int i = 0; i < len; i++)
    printf("%x ", bytecode[i]);
  printf("\n");

  stack_ctx *stack = stack_init();
  execute(stack, bytecode);

  return 0;
}
