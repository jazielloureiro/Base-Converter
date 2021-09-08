#include <stdint.h>
#include <stdio.h>

#include "converter.h"

int main(int argc, char **argv) {
	printf("%ld\n", to_decimal("f", 16));
	printf("%ld\n", to_decimal("ff", 16));

	return 0;
}
