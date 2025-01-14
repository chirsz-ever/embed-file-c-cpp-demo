#include <stdint.h>
#include <stdio.h>
 
const char example_string[] =
#include "example_string.txt.raw.h"
;

int main()
{
    printf("example_string[]: %zu bytes, content: %.*s ...\n", sizeof example_string, 30, example_string);
}
