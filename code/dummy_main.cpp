#include "linenoise.h"
#include <iostream>
#include <stdio.h>

int main()
{
    char* line = nullptr;
    while((line = linenoise("hello> ")) != NULL) {
        printf("You wrote: %s\n", line);
        linenoiseFree(line); /* Or just free(line) if you use libc malloc. */
        line = nullptr;
    }
}
