#include "stack_val.h"
#include <stdlib.h>

size_t parse_stack_val(stack_val *in, uint8_t *data) {
  uint8_t *d = data;
  in->type = *d++;
  if (in->type == INTVAL) {
    in->int_val = *(uint64_t *)d;
    return sizeof(uint64_t) + sizeof(uint8_t);
  } else if (in->type == FLOATVAL) {
    in->float_val = *(float *)d;
    return sizeof(uint64_t) + sizeof(uint8_t);
  } else if (in->type == STRVAL) {
    // TODO
  } else {
    return 0;
  }
}

// TODO
void free_stack_val(stack_val *val)
{
  if (val->type == STRVAL)
    free(val->str_val);
  free(val);
}

