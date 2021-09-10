#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "converter.h"

void usage() {
	puts("Usage:\n"
	     "  basec <input base> <output base> <number>\n"
	     "  basec [-h | --help]");
}

int main(int argc, char **argv) {
	if(argc == 1)
		usage();
	else if(argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
		usage();
	else if(argc == 4) {
		char out[OUT_MAX_SIZE];
		uint8_t in_base = atoi(argv[1]), out_base = atoi(argv[2]);

		base_convert(argv[3], in_base, out, out_base);

		puts(out);
	}

	return 0;
}
