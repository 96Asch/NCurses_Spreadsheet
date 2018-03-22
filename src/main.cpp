#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char s[512] = "Hello world";
//	puts("!!!Hello World!!!");
	printf("Message of the day: %s\n", s);
	return EXIT_SUCCESS;
}
