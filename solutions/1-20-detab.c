/* Replaces tabs in the input with the proper number of blanks
 * to space to the next tab stop.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000
#define TAB_STOP_SIZE 10 // Size in columns for each tab stop
#define DEBUG 0

int detab(char[], int, char[]);
int getLine(char[], int);

int main() {
    char currLine[MAX_LINE_LEN];
    char detabbedLine[MAX_LINE_LEN];
    int len, i;
    while (getLine(currLine, MAX_LINE_LEN) > 0) {
        len = detab(currLine, TAB_STOP_SIZE, detabbedLine);
        for (i = 0; i < len; ++i)
            putchar(detabbedLine[i]);
    }
}

int detab(char input[], int tabStopSize, char output[]) {
    int i, c, j, toAdd, outputPos;
    int extraSpaces = 0;
    for (i = 0; (c = input[i]) != '\0'; ++i) {
        outputPos = i + extraSpaces;
	/* if (DEBUG) printf("i %d outputPos %d extraSpaces %d\n", i, outputPos, extraSpaces); */
        if (c == '\t') {
            toAdd = outputPos / tabStopSize * tabStopSize + tabStopSize - outputPos;
	    if (DEBUG) printf("Replacing \\tab with %d spaces\n", toAdd);
            for (j = 0; j < toAdd; ++j) {
	        if (DEBUG) printf("%d is whitespace\n", j + outputPos);
                output[j + outputPos] = ' ';
                if (j > 0)
                    ++extraSpaces;
            }
        } else
	    if (DEBUG) printf("%d is char %c\n", outputPos, c);
            output[outputPos] = c;
    }
    return outputPos + 1;
}

int getLine(char output[], int limit) {
    int c, i;
    for (i = 0; (i < (limit - 1)) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
        output[i] = c;
    if (c == '\n') {
        output[i] = c;
        ++i;
    }
    output[i] = '\0';
    return i;
}
