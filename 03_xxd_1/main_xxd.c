#include <stdint.h>
#include <stdio.h>

#include "example_string.txt.xxd.h"
#include "example_binary.png.xxd.h"

void dump(const uint8_t arr[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        printf("%02X ", arr[i]);
    puts("...");
}

int main()
{
    printf("example_string[]: %zu bytes, content: %.*s ...\n", sizeof ___example_string_txt, 30, ___example_string_txt);
    printf("example_binary[]: %zu bytes, content: ", sizeof ___example_binary_png);
    dump(___example_binary_png, 10);
}
