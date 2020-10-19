/* A program to copy its input to its output, replacing tabs by \t, backspaces by \b and backslashes by \\ */

#include <stdio.h>

main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			printf("%c", c);
	}
}
