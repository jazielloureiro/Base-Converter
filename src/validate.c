#include <stdio.h>
#include <stdlib.h>

#include "validate.h"

void validate_bin(char *bin){
	for( ; *bin != '\0'; bin++){
		if(*bin != '0' && *bin != '1'){
			puts("You've entered an invalid binary.");
			exit(EXIT_FAILURE);
		}
	}
}

void validate_oct(char *oct){
	for( ; *oct != '\0'; oct++){
		if(*oct < '0' || *oct > '7'){
			puts("You've entered an invalid octal.");
			exit(EXIT_FAILURE);
		}
	}
}

void validate_dec(char *dec){
	for( ; *dec != '\0'; dec++){
		if(*dec < '0' || *dec > '9'){
			puts("You've entered an invalid decimal.");
			exit(EXIT_FAILURE);
		}
	}
}

void validate_hex(char *hex){
	for( ; *hex != '\0'; hex++){
		if(*hex >= 'a' && *hex <= 'f')
			*hex -= 32;
		else if(*hex < '0' || *hex > '9' && *hex < 'A' || *hex > 'F'){
			puts("You've entered an invalid hexadecimal.");
			exit(EXIT_FAILURE);
		}
	}
}
