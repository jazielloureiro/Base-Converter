#include <stdint.h>
#include <stdio.h>

#include "converter.h"

int main(int argc, char **argv) {
	char out[OUT_MAX_SIZE];

	base_convert("1111", 2, out, 16);

	printf("%s\n", out);

	return 0;
}
