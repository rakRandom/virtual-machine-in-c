#ifndef BUFFERS_H
#define BUFFERS_H

#include "types.h"

typedef struct {
    i8 *buffer;
    u64 size;
    u64 index;
} CharBuffer;

CharBuffer * newCharBuffer(u64 size);

inline void clearCharBuffer(CharBuffer *buffer);

inline void pushCharBuffer(CharBuffer *buffer, i8 ch);

#endif
