#include <stdint.h>
#include <stdio.h>
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



	return 0;
}
