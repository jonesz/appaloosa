# bytecode
the bytecode format is structured as follows:

  ```
  struct data {
    u8 data_type;
    union {
      uint64_t integer_val;
      uint8_t  *string_val;
      float    float_val;
  }
  ```
  
  * `u8 clen`      - code length.
  * `u8[clen]`     - a sequence of instructions.
  * `data *data`   - a sequence of data.

## assembler
there's a simple library based assembler in assembler.h
that can be used to produce bytecode.
