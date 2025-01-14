#include <stdint.h>
#include <stdio.h>

// from https://www.zhihu.com/question/431645051/answer/1826562458
// only tested on MacOS M1
#define EMBED_STR(name, path)                  \
    extern const char name[];                  \
    extern const size_t name##_size;           \
    asm("_" #name ":\n"                        \
        ".incbin \"" path "\"\n"               \
        ".byte 0\n"                            \
        "_" #name "_end:\n"                    \
        "_" #name "_size:\n"                   \
        ".quad _" #name "_end - _" #name "\n");

#define EMBED_BYTES(name, path)                \
    extern const char name[];                  \
    extern const size_t name##_size;           \
    asm("_" #name ":\n"                        \
        ".incbin \"" path "\"\n"               \
        "_" #name "_end:\n"                    \
        "_" #name "_size:\n"                   \
        ".quad _" #name "_end - " #name "\n");

EMBED_STR(example_string, "../example_string.txt");
EMBED_STR(example_binary, "../example_binary.png");

void dump(const uint8_t arr[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        printf("%02X ", arr[i]);
    puts("...");
}

int main()
{
    printf("example_string[]: %zu bytes, content: %.*s ...\n", example_string_size, 30, example_string);
    printf("example_binary[]: %zu bytes, content: ", example_binary_size);
    dump((const uint8_t *)example_binary, 10);
}
