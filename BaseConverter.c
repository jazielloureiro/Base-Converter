#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	}

	return 0;
}
