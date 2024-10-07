#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "buffers.h"
#include "machine.h"


i32 compile(i8 *file_path) 
{
    FILE *in_file;
    FILE *out_file;

    in_file = fopen(file_path, "r");
    out_file = fopen("main.ceo", "wb");

    if (in_file == NULL || out_file == NULL)
        return 1;

    //
    CharBuffer * buffer = newCharBuffer(256);

    u64 current_stage = 0;
    i8 current_char = 0;

    while ((current_char = fgetc(in_file)) != EOF) {
        switch(current_char) {
        case 10:  // New line
            current_stage = 0;
            clearCharBuffer(buffer);
            break;
        
        case 32:  // Space
            switch (current_stage) {
            case 0:  // Selecting the operation

                current_stage++;
                break;
            
            case 1:
                break;
            
            default:
                break;
            }

            clearCharBuffer(buffer);
            break;

        default:
            pushCharBuffer(buffer, current_char);
        }
    }

    //
    fclose(in_file);
    fclose(out_file);
    free(buffer);

    return 0;
}


i32 main(i32 argc, i8 *argv[]) 
{
    if (argc == 3)
        if (!strcmp(argv[1], "--compile") || !strcmp(argv[1], "-c"))
            return compile(argv[2]);

    return 0;
}
