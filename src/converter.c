#include <stdint.h>

#define UPPERCASE 55
#define LOWERCASE 87

uint8_t get_int(char number) {
	if(number <= '9')
		return number - '0';
	else if(number < 'a')
		return number - UPPERCASE;
	else
		return number - LOWERCASE;
}
