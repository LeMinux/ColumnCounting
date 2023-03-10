#include <stdio.h>
#include <stdlib.h>

char* dynamicString(FILE* inStream , char* message, int maxSize){
	char* string;
	char iterate;
	int length = 0;
	
	string = realloc(NULL, sizeof(*string)*256);
	if(!string)
		return string;
	
	printf("%s", message);
	while(EOF != (iterate=fgetc(inStream)) && iterate != '\n'){
		string[length++] = iterate;
		if(length == maxSize) return string;
	}
	string[length++] = '\0';
	
	return realloc(string, sizeof(*string)*length);
}


int main(void){

	//method 1 large buffer
	char test1 [256];
	printf("Enter anything you want ");
	fgets(test1, 256, stdin);
	printf("%s\n", test1);
	
	//method 2 reading per character through stdin
	char* test2 = dynamicString(stdin, "Enter anything you want ", 256);
	printf("%s\n", test2);
	free(test2);
	return 0;
}
