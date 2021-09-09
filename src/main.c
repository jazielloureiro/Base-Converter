#include <stdint.h>
#include <stdio.h>

#include "converter.h"

int main(int argc, char **argv) {
	uint64_t temp = to_decimal("1111111111111111111111111111111111111111111111111111111111111111", 2);
	char out[OUT_MAX_SIZE];

	to_radix(temp, 36, out);

	printf("%lu : %s\n", temp, out);

	return 0;
}
