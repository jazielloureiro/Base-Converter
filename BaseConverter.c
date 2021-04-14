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

bool is_oct_valid(char *oct){
	for( ; *oct != '\0'; oct++)
		if(*oct < '0' || *oct > '7')
			return false;

	return true;
}

bool is_dec_valid(char *dec){
	for( ; *dec != '\0'; dec++)
		if(*dec < '0' || *dec > '9')
			return false;

	return true;
}

bool is_hex_valid(char *hex){
	for( ; *hex != '\0'; hex++){
		if(*hex >= 'a' && *hex <= 'f')
			*hex -= 32;
		if(*hex < '0' || *hex > '9' && *hex < 'A' || *hex > 'F')
			return false;
	}

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
	}else if(strncmp(argv[1], "oct", 3) == 0){
		if(!is_oct_valid(argv[2]))
			exit(EXIT_FAILURE);
	}else if(strncmp(argv[1], "dec", 3) == 0){
		if(!is_dec_valid(argv[2]))
			exit(EXIT_FAILURE);
	}else if(strncmp(argv[1], "hex", 3) == 0){
		if(!is_hex_valid(argv[2]))
			exit(EXIT_FAILURE);
	}else
		puts("You've entered an invalid option.");

	return 0;
}
