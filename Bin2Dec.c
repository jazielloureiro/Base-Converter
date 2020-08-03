#include <stdio.h>
#include <math.h>

#define END_BINARY_NUMBER 0
#define ERROR_INVALID_CHARACTER -1

void clear_input_buffer(){
	char buffer;

	while((buffer = getchar()) != '\n' && buffer != EOF);
}

int convert(int *exponent){
	char binary = getchar();
	int decimal;
	
	if(binary == '\n')
		return END_BINARY_NUMBER;
	else if(binary != '1' && binary != '0')
		return ERROR_INVALID_CHARACTER;
		
	if((decimal = convert(exponent)) == ERROR_INVALID_CHARACTER) 
		return ERROR_INVALID_CHARACTER;
	
	decimal += pow(2, (*exponent)++) * (binary - '0');
	
	return decimal;
}

void pre_convert(){
	int decimal = 0, exponent = 0;

	printf("\nEnter with a binary number: ");
	
	if((decimal = convert(&exponent)) == ERROR_INVALID_CHARACTER)
		puts("You have entered with a invalid character!");
	else
		printf("Decimal value: %d\n", decimal);
}

int main(){
	char convert_again;
	
	do{
		pre_convert();
		
		puts("\nDo you want to convert another binary number? [y/n]");
		
		do{
			convert_again = getchar();
			clear_input_buffer();
		}while(convert_again != 'y' && convert_again != 'n');
	}while(convert_again == 'y');

	return 0;
}
