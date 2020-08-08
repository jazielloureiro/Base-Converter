#include <stdio.h>
#include <math.h>

#define END_BINARY_NUMBER 0
#define LIMIT_BINARY_NUMBER 64
#define ERROR_INVALID_CHARACTER -1

void clear_input_buffer(){
	char buffer;

	while((buffer = getchar()) != '\n' && buffer != EOF);
}

int convert(unsigned long long int *decimal, short int exponent){
	char binary = getchar();
	
	if(binary == '\n')
		return END_BINARY_NUMBER;
	else if(exponent >= LIMIT_BINARY_NUMBER){
		clear_input_buffer();
		return END_BINARY_NUMBER;
	}else if(binary != '1' && binary != '0'){
		clear_input_buffer();
		return ERROR_INVALID_CHARACTER;
	}
	
	exponent = convert(decimal, exponent + 1);
		
	if(exponent == ERROR_INVALID_CHARACTER) 
		return ERROR_INVALID_CHARACTER;
	
	*decimal += pow(2, exponent++) * (binary - '0');
	
	return exponent;
}

void converter(){
	unsigned long long int decimal = 0;
	short int exponent = 0;

	printf("\nEnter with a binary number: ");
	
	exponent = convert(&decimal, exponent + 1);
	
	if(exponent == END_BINARY_NUMBER)
		puts("You have not entered any number!");
	else if(exponent == ERROR_INVALID_CHARACTER)
		puts("You have entered an invalid character!");
	else
		printf("Decimal value: %llu\n", decimal);
}

int main(){
	char convert_again;
	
	do{
		converter();
		
		puts("\nDo you want to convert another binary number? [y/n]");
		
		do{
			convert_again = getchar();
			clear_input_buffer();
		}while(convert_again != 'y' && convert_again != 'n');
	}while(convert_again == 'y');

	return 0;
}
