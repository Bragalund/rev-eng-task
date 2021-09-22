#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
	if(argc != 2){
	printf("Need only one argument\n");
	return -1;
	}

	char** correct="password123";

	if(strncmp(argv[1], correct, strlen(correct))){
		printf("No %s is not correct.\n ", argv[1]);
		return 1;
	}
	else{
		printf("Yes, %s is correct.\n ", argv[1]);
		return 0;
	}
}
