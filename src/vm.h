#ifndef vm_h
#define vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
  Chunk*    chunk;
  uint8_t*  ip;
  Value     stack[STACK_MAX];
  Value*    stackTop;
  Obj*      objects;
} VM;

typedef enum {
  I_OK,
  I_COMPILE_ERROR,
  I_RUNTIME_ERROR,
} IResult;

extern VM vm;

void initVM();
void freeVM();

IResult interpret(const char* source);
void push(Value value);
Value pop();

#endif
