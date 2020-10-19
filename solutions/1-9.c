/* A program to copy its input to its output, replacing each string of one or more blanks by a single blank */

#include <stdio.h>

#define INBLANK 1
#define OUTBLANK 0

main() {
	int c, state;
	state = OUTBLANK;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			state = INBLANK;
		else if (state == INBLANK) {
			printf(" %c", c);
			state = OUTBLANK;
		} else
			printf("%c", c);
	}
}
