/* Print a histogram of the lengths of words in input */

#include <stdio.h>

#define MAXPOSSLEN 100

main() {
	int c, len, i;
	int currlen = 0;
	int alllens[MAXPOSSLEN];
	for (i = 0; i < MAXPOSSLEN; ++i)
		alllens[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t')
			++currlen;
		else {
			++alllens[currlen];
			currlen = 0;
		}
	}
	for (i = 1; i < MAXPOSSLEN; ++i) {
		if (len = alllens[i]) {
			printf("%3d char(s): ", i);
			for (int j = 0; j < len; ++j)
				printf("|");
			printf("\n");
		}
	}
}
