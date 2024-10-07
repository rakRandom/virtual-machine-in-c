#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "compile.h"


i32 main(i32 argc, i8 *argv[]) 
{
    if (argc == 3)
        if (!strcmp(argv[1], "--compile") || !strcmp(argv[1], "-c"))
            return compile(argv[2]);

    return 0;
}
