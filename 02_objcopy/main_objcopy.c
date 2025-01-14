#include <stdint.h>
#include <stdio.h>

extern const char binary____example_string_txt_start[];
extern size_t binary____example_string_txt_size;

extern const uint8_t binary____example_binary_png_start[];
extern size_t binary____example_binary_png_size;

void dump(const uint8_t arr[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        printf("%02X ", arr[i]);
    puts("...");
}

int main()
{
    printf("example_string[]: %zu bytes, content: %.*s ...\n", binary____example_string_txt_size, 30, binary____example_string_txt_start);
    printf("example_binary[]: %zu bytes, content: ", binary____example_binary_png_size);
    dump(binary____example_binary_png_start, 10);
}
