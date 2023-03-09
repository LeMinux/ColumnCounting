/*
 * <student name>
 * <student email>
 * <lab section>
 */
#include <stdio.h>

struct Node {
	int a;
	struct Node *b;
	struct Node *c;
};

int main(void) {
	// initalization
	printf("Size of struct is %ld\n", sizeof(struct Node));
	struct Node nodeArray[5] = {{9, nodeArray + 4, NULL},
		{32, nodeArray + 2, nodeArray + 3},
		{16, NULL, nodeArray + 4},
		{41, nodeArray + 1, nodeArray},
		{81, nodeArray + 3, nodeArray + 1}};
	struct Node *nodePointer = nodeArray + 2;
	struct Node **nodePointerPointer = &nodeArray[1].b;

	puts("\nPrinting addresses of array");
	int i = 0;
	for (; i < 5; ++i)
		printf("[%d] = \t%p\n", i, &nodeArray[i]);

	puts("\nprinting variable pointers");
	printf("nodePointer = \t%p\nnodePointerPointer = %p\n", nodePointer,
			*nodePointerPointer);

	puts("\nPrinting the elements in each struct");
	int p = 0;
	for (; p < 5; ++p) {
		printf("[%d] a =\t%d b = \t%p c = %p\n", p, nodeArray[p].a, nodeArray[p].b,
				nodeArray[p].c);
	}

	puts("\nAll stuff with nodeArray");
	printf("nodeArray \t%p\n", nodeArray);
	printf("(*nodeArray).a\t%d\n", (*nodeArray).a);
	printf("nodeArray->a\t%d\n", nodeArray->a);
	printf("&nodeArray \t%p\n", &nodeArray);
	printf("&nodeArray->a \t%p\n", &nodeArray->a);

	puts("\nAll stuff with nodeArray[3]");
	printf("nodeArray[3].a\t%d\n", nodeArray[3].a);
	printf("nodeArray[3].c \t%p\n", nodeArray[3].c);
	printf("nodeArray[3].c->a\t%d\n", nodeArray[3].c->a);
	printf("nodeArray[3].b->b \t%p\n", nodeArray[3].b->b);
	printf("&nodeArray[3].a \t%p\n", &nodeArray[3].a);
	printf("&nodeArray[3].c \t%p\n", &nodeArray[3].c);
	printf("&nodeArray[3].c->a \t%p\n", &nodeArray[3].c->a);

	puts("\nAll stuff with nodePointer");
	printf("nodePointer \t%p\n", nodePointer);
	printf("nodePointer->a \t%d\n", nodePointer->a);
	printf("nodePointer->c->c->a\t%d\n", nodePointer->c->c->a);
	printf("&nodePointer \t%p\n", &nodePointer);
	printf("&nodePointer->a \t%p\n", &nodePointer->a);
	printf("&nodePointer->c->c->a \t%p\n", &nodePointer->c->c->a);

	puts("\nAll stuff with nodePointerPointer");
	printf("nodePointerPointer \t%p\n", nodePointerPointer);
	printf("*nodePointerPointer \t%p\n", *nodePointerPointer);
	printf("(*nodePointerPointer)->a\t%d\n", (*nodePointerPointer)->a);
	return 0;
}
