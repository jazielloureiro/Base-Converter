#include <stdio.h>

#define UNEXPECTED_ERROR -2
#define ERROR_INVALID_CHARACTER -1
#define END_BINARY_NUMBER 0
#define CALC_SUCCESSFULLY 1
#define LIMIT_BINARY_NUMBER 64

void clear_input_buffer(){
	char buffer;

	while((buffer = getchar()) != '\n' && buffer != EOF);
}

unsigned long long int pot2(short int counter){
	static unsigned long long int result = 1;
	
	if(counter != 0)
		result *= 2;
	else
		result = 1;
		
	return result;
}

short int convert(unsigned long long int *decimal, short int counter){
	char binary = getchar();
	
	if(binary == '\n')
		return END_BINARY_NUMBER;
	else if(counter > LIMIT_BINARY_NUMBER){
		clear_input_buffer();
		return END_BINARY_NUMBER;
	}else if(binary != '1' && binary != '0'){
		clear_input_buffer();
		return ERROR_INVALID_CHARACTER;
	}
	
	counter = convert(decimal, counter + 1);
	
	if(counter == CALC_SUCCESSFULLY || counter == END_BINARY_NUMBER){
		*decimal += pot2(counter) * (binary - '0');
		return CALC_SUCCESSFULLY;
	}else if(counter == ERROR_INVALID_CHARACTER) 
		return ERROR_INVALID_CHARACTER;
	else
		return UNEXPECTED_ERROR;
}

void converter(){
	unsigned long long int decimal = 0;
	short int counter = 0;

	printf("\nEnter a binary number: ");
	
	counter = convert(&decimal, counter + 1);
	
	if(counter == CALC_SUCCESSFULLY)
		printf("Decimal value: %llu\n", decimal);
	else if(counter == END_BINARY_NUMBER)
		puts("You have not entered any numbers!");
	else if(counter == ERROR_INVALID_CHARACTER)
		puts("You have entered an invalid character!");
	else{
		puts("An unexpected error has occurred.");
		puts("Please, contact me: https://github.com/jazielloureiro/Bin2Dec");
	}
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
