#ifndef CONVERTER_H
#define CONVERTER_H

#define OUT_MAX_SIZE 65

uint64_t to_decimal(char *input, int radix);
void to_radix(uint64_t decimal, int radix, char *out);

#endif
