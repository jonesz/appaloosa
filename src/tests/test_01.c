#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../interpreter.h"

// Test basic interpreter functionality.

int main(int argc, char **argv) {
  // 8-bit code len, 4 8-bit opcodes, 2 8-bit types, 2 64-bit integers.
  size_t bytecode_len = sizeof(uint8_t) + sizeof(uint8_t) * 4 +
                        sizeof(uint8_t) * 2 + sizeof(uint64_t) * 2;

  uint8_t *bytecode = malloc(bytecode_len);
  uint8_t *bc = bytecode; 

  // Instructions
  *bc = 4;
  bc++;
  *bc = 0; // PUSH
  bc++;
  *bc = 0; // PUSH
  bc++;
  *bc = 3; // ADD
  bc++;
  *bc = 2; // RETURN
  bc++;

  // Data
  *bc = 0; // INT;
  bc++;
  *(uint64_t *)bc = 210203;
  bc += sizeof(uint64_t);
  *bc = 0; // INT
  bc++;
  *(uint64_t *)bc = 123483;
  bc += sizeof(uint64_t);

  printf("bytecode: ");
  for (int i = 0; i < bytecode_len; i++)
    printf("%x ", bytecode[i]);
  printf("\n");

  stack_ctx *stack = stack_init();
  execute(stack, bytecode);
  return 0;
}
