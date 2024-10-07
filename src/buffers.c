#include "buffers.h"

CharBuffer * newCharBuffer(u64 size) {
    CharBuffer *new = (CharBuffer*) malloc(sizeof(CharBuffer));
    new->buffer = (i8*) malloc(sizeof(i8) * size);
    new->size = size;
    new->index = 0;

    return new;
}

inline void clearCharBuffer(CharBuffer *buffer) {
    for (u64 i = 0; i < buffer->size; i++)
        buffer->buffer[i] = 0;
    buffer->index = 0;
}

inline void pushCharBuffer(CharBuffer *buffer, i8 ch) {
    buffer->buffer[buffer->index++] = ch;
}
