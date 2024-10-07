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
} Operations;  // 4 bits

typedef struct {
    Operations type;
    u8 mode;

    // An instruction can have 3 values (e.g.: `ADD 0 RA, 2, 2` or `3 0 0 2 2` or ADD into Register A the sum of 2 and 2)
    u64 value1;
    u64 value2;
    u64 value3;
} Instruction;  // 4 bits + 4 bits + 3 * 8 bytes = 25 bytes

typedef struct {
    Instruction instruction_list[INSTRUCTIONS_MAX_SIZE];  // Instructions (.code or .text memory area)
    u64 stack[STACK_MAX_SIZE];  // stack memory area
    u64 heap[HEAP_MAX_SIZE];  // heap memory area

    // Registers
    u64 stack_pointer;
    u64 current_instruction;
    u64 last_operation_value;
    u64 register_A;
    u64 register_B;
    u64 register_C;
} Machine;

#endif
