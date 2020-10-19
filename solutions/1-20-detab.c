/* Replaces tabs in the input with the proper number of blanks
 * to space to the next tab stop.
 */

#include <stdio.h>

#define MAX_LINE_LEN 1000
#define TAB_STOP_SIZE 10 // Size in columns for each tab stop

int detab(char input[], int tabStopSize, char output[]);
int getLine(char output[], int limit);

int main() {
    char currLine[MAX_LINE_LEN];
    char detabbedLine[MAX_LINE_LEN];
    int len, i;
    while (getLine(currLine, MAX_LINE_LEN) != 0) {
        len = detab(currLine, TAB_STOP_SIZE, detabbedLine);
        for (i = 0; i < len; ++i)
            putchar(detabbedLine[i]);
    }
}

int detab(char input[], int tabStopSize, char output[]) {
    int i, c, j, toAdd, extraSpaces, outputPos;
    for (i = 0; (c = input[i]) != '\0'; ++i) {
        outputPos = i + extraSpaces;
        if (c == '\t') {
            toAdd = outputPos / tabStopSize * tabStopSize + tabStopSize - outputPos;
            for (j = 0; j < toAdd - 1; ++j) {
                output[j + outputPos] = ' ';
                if (j > 0)
                    ++extraSpaces;
            }
        } else
            output[outputPos] = c;
    }
    printf("output len is %d\n", i);
    return outputPos + 1;
}

int getLine(char output[], int limit) {
    int c, i;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        output[i] = c;
    if (c == '\n') {
        output[i] = c;
        ++i;
    }
    output[i] = '\0';
    return i;
}
