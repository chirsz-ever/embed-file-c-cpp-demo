#include <stdint.h>
#include <stdio.h>

const char example_string[] = {
#embed "../example_string.txt" suffix(, '\0')
};

const uint8_t example_binary[] = {
#embed "../example_binary.png"
};

void dump(const uint8_t arr[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        printf("%02X ", arr[i]);
    puts("...");
}

int main()
{
    printf("example_string[]: %zu bytes, content: %.*s ...\n", sizeof example_string, 30, example_string);
    printf("example_binary[]: %zu bytes, content: ", sizeof example_binary);
    dump((const uint8_t *)example_binary, 10);
}
