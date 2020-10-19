/* Print output one word per line */

#include <stdio.h>

#define SKIPPINGLINES 1
#define NOTSKIPPINGLINES 0

main() {
	int c, state;
	state = NOTSKIPPINGLINES;
	while ((c = getchar()) != EOF) {
		if (state == NOTSKIPPINGLINES
		    && (c == ' ' || c == '\n' || c == '\t')) {
			state = SKIPPINGLINES;
			printf("\n");
		}
		else if (c != ' ' && c != '\n' && c != '\t') {
			state = NOTSKIPPINGLINES;
			printf("%c", c);
		}					
	}
}
