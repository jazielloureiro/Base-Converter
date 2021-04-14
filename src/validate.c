#include <stdbool.h>

#include "validate.h"

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
