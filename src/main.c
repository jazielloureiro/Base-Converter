#include <stdio.h>
#include <string.h>

#include "validate.h"

void help(){
	puts("Syntax:\n\t./bc [OPTION] [NUMBER]");
}

int main(int argc, char **argv){
	if(argc > 3)
		puts("You've entered too many arguments.");
	else if(argc == 1 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
		help();
	else if(strncmp(argv[1], "bin", 3) == 0){
		validate_bin(argv[2]);
	}else if(strncmp(argv[1], "oct", 3) == 0){
		validate_oct(argv[2]);
	}else if(strncmp(argv[1], "dec", 3) == 0){
		validate_dec(argv[2]);
	}else if(strncmp(argv[1], "hex", 3) == 0){
		validate_hex(argv[2]);
	}else
		puts("You've entered an invalid option.");

	return 0;
}
