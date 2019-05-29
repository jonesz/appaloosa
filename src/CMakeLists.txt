project(appaloosa)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_FLAGS "-g")

set(APPALOOSA_SRC
  assembler.c
  interpreter.c
  runtime.c
  stack_val.c
)

set(APPALOOSA_HDR
  assembler.h
  interpreter.h
  opcode.h
  runtime.h
  stack_val.h
)

add_executable(appaloosa main.c ${APPALOOSA_SRC} ${APPALOOSA_HDR})
add_executable(test_01 tests/test_01.c ${APPALOOSA_SRC} ${APPALOOSA_HDR})
add_executable(test_02 tests/test_02.c ${APPALOOSA_SRC} ${APPALOOSA_HDR})
