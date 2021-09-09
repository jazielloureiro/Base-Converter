#include <stdint.h>
#include <string.h>

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

uint64_t power(uint8_t base, uint8_t exp) {
	return exp == 0? 1 : base * power(base, exp - 1);
}

uint64_t to_decimal(char *input, int radix) {
	uint64_t decimal = 0;

	for(int16_t i = strlen(input) - 1, e = 0; i >= 0; i--, e++)
		decimal += get_int(input[i]) * power(radix, e);
	
	return decimal;
}

char get_radix_char(uint8_t decimal) {
	return decimal + (decimal <= 9? '0' : LOWERCASE);
}
