/* Count blanks, tabs, and newlines */

#include <stdio.h>

main() {
	int nb, nt, nnl;
	int c;
	nb = nt = nnl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nnl;
	}
	printf("Blanks: %d; Tabs: %d; Newlines: %d\n", nb, nt, nnl);
}
