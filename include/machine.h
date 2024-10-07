#ifndef MACHINE_H
#define MACHINE_H

#include "types.h"

// ==================== Constants ====================

#define INSTRUCTIONS_MAX_SIZE 1024
#define STACK_MAX_SIZE 1024
#define HEAP_MAX_SIZE 1024


// ==================== Operations ====================

typedef enum {
    OP_PUSH,
    OP_POP,
    OP_MOV,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_POW,
    OP_PUT,
    OP_GET,
    OP_JMPZ,
    OP_JMPL,
    OP_JMP,
    OP_ALC,
    OP_FREE,
    OP_HALT,
} Operations;

typedef struct {
    u8 mode;
    i64 value;
} Value;

typedef struct {
    Operations type;
    Value values[3];  // An instruction can have 3 values (e.g.: `ADD 0 RA, 2, 2` or `3 0 0 2 2` or ADD into Register A the sum of 2 and 2)
} Instruction;  // 1 byte + 3 * 9 bytes = 28 bytes

typedef struct {
    Instruction instruction_list[INSTRUCTIONS_MAX_SIZE];  // Instructions (.code or .text memory area)
    i64 stack[STACK_MAX_SIZE];  // stack memory area
    i64 heap[HEAP_MAX_SIZE];  // heap memory area

    // Registers
    u64 stack_pointer;
    u64 current_instruction;
    i64 last_operation_value;
    i64 register_A;
    i64 register_B;
    i64 register_C;
} Machine;

#endif
