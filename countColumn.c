#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

//Tabs will represent 4 spaces, but this can be changed
//if needed 
#define TAB_COUNT 5

//Column limit can be strict at 80, but a leeway is recommended because of
//how students define their tabs personally
#define COLUMN_LIMIT 80
#define COUNT_DEFAULT 1
#define SEMICOLON_DEFAULT -1

//Comments are skipped because it isn't actual code; however, if wanted
//a flag can be passed to include comments in the count.
void skipSingleComments(FILE*);
void skipMultiComments(FILE*, int*, int*);
void executeWithComments(FILE*);
void executeWithoutComments(FILE*);

int main(int argc, char** argv){
	assert(argc == 2 || argc == 3);
	FILE* inFile = fopen(argv[argc - 1], "r");
	assert(inFile != NULL);
	void (*whichExecution)(FILE*) = &executeWithoutComments;
	if(argc == 3){
		assert(strcmp(argv[1], "-i") == 0);
		whichExecution = &executeWithComments;
	}

	(*whichExecution)(inFile);
	puts("Finished running");
	fclose(inFile);
	return 0;
}

void executeWithoutComments(FILE* inFile){
	int data = '\0';
	int lineNumber = 1;
	int columnCount = COUNT_DEFAULT;
	//the semicolon is checked because it isn't always next to \n
	int semiColonPos = SEMICOLON_DEFAULT;
	while((data = fgetc(inFile)) != EOF){
		switch(data){
			//new line indicates the end of that line
			case '\n':
				//columnCount will be off by one since it is at the \n
				--columnCount;
				if(columnCount > COLUMN_LIMIT && semiColonPos != SEMICOLON_DEFAULT && columnCount - semiColonPos != 0){
					//seeks back to check for whitespace
					fseek(inFile, SEEK_CUR, columnCount - semiColonPos);
					int count = 0;
					while(count <= columnCount - semiColonPos){
						if(isspace((data = fgetc(inFile))) != 0)
							--columnCount;

						++count;
					}
					fgetc(inFile);
				}//end of semicolon check

				if(columnCount > COLUMN_LIMIT){
					printf("Line number %d is over 80 characters. "
						  "It has %d characters\n",
						 lineNumber, columnCount);
				}
				//increment and reset for next line
				++lineNumber;
				columnCount = COUNT_DEFAULT;
				semiColonPos = SEMICOLON_DEFAULT;
			break;

			//skips the comments
			case '/':
				//increase count since it could just be '/'
				++columnCount;
				data = fgetc(inFile);
				switch(data){
					case '/':
						skipSingleComments(inFile);
						columnCount = COUNT_DEFAULT;
						semiColonPos = SEMICOLON_DEFAULT;
						++lineNumber;
					break;
					case '*':
						//increment incase it's on the same line
						++columnCount;
						skipMultiComments(inFile, &lineNumber, &columnCount);
						semiColonPos = SEMICOLON_DEFAULT;
					break;
					default: ++columnCount; break;
				}
			break;

			case ';':
				semiColonPos = columnCount++;
			break;

			//tabs count as multiple spaces
			case '\t':
				columnCount += TAB_COUNT;
			break;

			//return carriage warning
			case '\r':
				printf("WARNING: return carrage found at line %d\n", lineNumber);
			break;

			default: ++columnCount; break;
		}
	}
}

void executeWithComments(FILE* inFile){
	int data = '\0';
	int lineNumber = 1;
	int columnCount = COUNT_DEFAULT;
	//the semicolon is checked because it isn't always next to \n
	int semiColonPos = SEMICOLON_DEFAULT;
	while((data = fgetc(inFile)) != EOF){
		switch(data){
			//new line indicates the end of that line
			case '\n':
				//columnCount will be off by one since it is at the \n
				--columnCount;
				if(columnCount > COLUMN_LIMIT && semiColonPos != SEMICOLON_DEFAULT && columnCount - semiColonPos != 0){
					//seeks back to check for whitespace
					fseek(inFile, SEEK_CUR, columnCount - semiColonPos);
					int count = 0;
					while(count <= columnCount - semiColonPos){
						if(isspace((data = fgetc(inFile))) != 0)
							--columnCount;

						++count;
					}
					fgetc(inFile);
				}//end of semicolon check

				if(columnCount > COLUMN_LIMIT){
					printf("Line number %d is over 80 characters. "
						  "It has %d characters\n",
						 lineNumber, columnCount);
				}
				//increment and reset for next line
				++lineNumber;
				columnCount = COUNT_DEFAULT;
				semiColonPos = SEMICOLON_DEFAULT;
			break;

			case ';':
				semiColonPos = columnCount++;
			break;

			//tabs count as multiple spaces
			case '\t':
				columnCount += TAB_COUNT;
			break;

			//return carriage warning
			case '\r':
				printf("WARNING: return carrage found at line %d\n", lineNumber);
			break;

			default: ++columnCount; break;
		}
	}
}

void skipSingleComments(FILE* file){
	int data = '\0';
	while((data = fgetc(file)) != '\n' && data != EOF);
}

void skipMultiComments(FILE* file, int* lineAt, int* count){
	int data = '\0';
	while((data = fgetc(file)) != EOF){
		switch(data){
			case '\n':
				++(*lineAt);
				*count = COUNT_DEFAULT;
			break;

			case '*':
				++(*count);
				data = fgetc(file);
				if(data == '/'){
					++(*count);
					return;
				}

				if(data == '\n'){
					++(*lineAt);
					*count = COUNT_DEFAULT;
				}

				if(data == '\t'){
					*count = TAB_COUNT;
				}
			break;
			case '\t':
				*count += TAB_COUNT;
			break;
			default: ++(*count);
			break;
		}
	}
}
