#include <stdbool.h>
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

uint64_t to_decimal(char *input, int base) {
	uint64_t decimal = 0;

	for(int16_t i = strlen(input) - 1, e = 0; i >= 0; i--, e++)
		decimal += get_int(input[i]) * power(base, e);
	
	return decimal;
}

char get_base_char(uint8_t decimal) {
	return decimal + (decimal <= 9? '0' : LOWERCASE);
}

void to_base(uint64_t decimal, char *out, int base) {
	char temp[65];
	int8_t temp_size = 0;

	do {
		temp[temp_size] = get_base_char(decimal % base);
		temp_size++;
		decimal /= base;
	} while(decimal != 0);

	out[temp_size] = '\0';
	temp_size--;

	for(uint8_t i = 0; temp_size >= 0; i++, temp_size--)
		out[i] = temp[temp_size];
}

bool is_input_valid(char *input, uint8_t base) {
	for( ; *input != '\0'; input++)
		if(get_int(*input) >= base)
			return false;

	return true;
}

void base_convert(char *in, uint8_t in_base, char *out, uint8_t out_base) {
	if(in_base >= 2 && in_base <= 36
	   && out_base >= 2 && out_base <= 36
	   && is_input_valid(in, in_base)
	) {
		uint64_t decimal = to_decimal(in, in_base);
		to_base(decimal, out, out_base);
	} else {
		strcpy(out, "");
	}
}
