/* Print a histogram of the frequencies of different characters in input */

#include <stdio.h>

#define CHARSINASCII 255

main() {
	int c, i, freq, j;
	int charsfreqs[255];
	for (i = 0; i < CHARSINASCII; ++i)
		charsfreqs[i] = 0;
	while ((c = getchar()) != EOF)
		++charsfreqs[c];
	for (i = 0; i < CHARSINASCII; ++i)
		if (freq = charsfreqs[i]) {
			printf("%c: ", i);
			for (j = 0; j < freq; ++j)
				printf("|");
			printf("\n");
		}
}
