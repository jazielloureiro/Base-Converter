#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_bin_valid(char *bin){
	for( ; *bin != '\0'; bin++)
		if(*bin != '0' && *bin != '1')
			return false;

	return true;
}

void help(){
	puts("Syntax:\n\t./bc [OPTION] [NUMBER]");
}

int main(int argc, char **argv){
	if(argc > 3){
		puts("You've entered too many arguments.");
		exit(EXIT_FAILURE);
	}else if(argc == 1 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0){
		help();
		exit(EXIT_FAILURE);
	}else if(strncmp(argv[1], "bin", 3) == 0){
		if(!is_bin_valid(argv[2]))
			exit(EXIT_FAILURE);
	/*
	}else if(strncmp(argv[1], "oct", 3) == 0){
		if(!is_oct_valid(argv[2]))
			exit(EXIT_FAILURE);
	}else if(strncmp(argv[1], "dec", 3) == 0){
		if(!is_dec_valid(argv[2]))
			exit(EXIT_FAILURE);
	}else if(strncmp(argv[1], "hex", 3) == 0){
		if(!is_hex_valid(argv[2]))
			exit(EXIT_FAILURE);
	*/
	}else
		puts("You've entered an invalid option.");

	return 0;
}
