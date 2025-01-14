#include <cstddef>
#include <stdint.h>
#include <stdio.h>
#include <QFile>

void dump(const uint8_t arr[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        printf("%02X ", arr[i]);
    puts("...");
}

int main()
{
    QFile example_string_file(":/example_string.txt");
    example_string_file.open(QIODevice::ReadOnly);
    QByteArray example_string = example_string_file.readAll();

    QFile example_binary_file(":/example_binary.png");
    example_binary_file.open(QIODevice::ReadOnly);
    QByteArray example_binary = example_binary_file.readAll();

    printf("example_string[]: %zu bytes, content: %.*s ...\n", (size_t)example_string.size(), 30, example_string.constData());
    printf("example_binary[]: %zu bytes, content: ", (size_t)example_binary.size());
    dump((const uint8_t*)example_binary.constData(), 10);
}
