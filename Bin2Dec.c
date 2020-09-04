#include <stdio.h>

#define ERROR_INVALID_CHARACTER -1
#define END_BINARY_NUMBER 0
#define LIMIT_BINARY_NUMBER 64

void clear_input_buffer(){
	char buffer;

	while((buffer = getchar()) != '\n' && buffer != EOF);
}

unsigned long long int pot2(char counter){
	unsigned long long int result = 1;
	
	while(counter--)
		result *= 2;
		
	return result;
}

char convert(unsigned long long int *decimal, char counter){
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
	
	if(counter == ERROR_INVALID_CHARACTER)
		return ERROR_INVALID_CHARACTER;
	else{
		*decimal += pot2(counter++) * (binary - '0');
		return counter;
	}
}

void converter(){
	unsigned long long int decimal = 0;
	char counter = 0;

	printf("\nEnter a binary number: ");
	
	counter = convert(&decimal, counter + 1);
	
	if(counter == END_BINARY_NUMBER)
		puts("You have not entered any numbers!");
	else if(counter == ERROR_INVALID_CHARACTER)
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
