/** Folds long input lines into two or more shorter lines
 * after the last non-blank character that occurs before
 * the n-th column of input.
 */
#include <stdio.h>

#define DEBUG 0
#define MAX_LINE_LEN 1000
#define MAX_COLUMN 10
#define TRUE 1
#define FALSE 0

int getLine(char[], int);
void fold(char[], char[], int);

int main() {
    int i, c;
    char inputLine[MAX_LINE_LEN];
    char outputLine[MAX_LINE_LEN];
    while (getLine(inputLine, MAX_LINE_LEN) != 0) {
        fold(inputLine, outputLine, MAX_LINE_LEN);
        for (i = 0; (c = outputLine[i]) != '\0'; ++i) {
            putchar(c);
        }
    }
    return 0;
}

void fold(char input[], char output[], int limit) {
    int i, c, outputPos, insideBlanks, j;
    int firstBlank = 0;
    int lastFold = 0;
    for (i = 0, outputPos = 0; (c = input[i]) != '\0' && i <= limit - 1; ++i) {
        if (DEBUG) printf("i %d c %c\n", i, c);
        if ((c == ' ' || c == '\t') && !insideBlanks) {
            insideBlanks = TRUE;
            firstBlank = i;
            if (DEBUG) printf("firstBlank %d\n", firstBlank);
        } else {
            insideBlanks = FALSE;
        }
        if (i - lastFold >= MAX_COLUMN) {
            if (DEBUG) printf("Adding a newline at %d\n", firstBlank);
            output[firstBlank] = '\n';
            ++outputPos;
            /* if (i - firstBlank == MAX_COLUMN) { */
            /*     output[outputPos] = c; */
            /*     continue; */
            /* } */
            if (DEBUG) printf("Backfilling from %d to %d\n", firstBlank + 1, i);
            for (j = 0; j <= i - firstBlank; ++j) {
                if ((c = input[firstBlank + j]) != ' ' && c != '\t') {
                    if (DEBUG) printf("firstblank + j %d receive %c\n", firstBlank + j, c);
                    output[firstBlank + j] = c;
                }
            }
            lastFold = i;
        } else {
            output[outputPos] = c;
            ++outputPos;
        }
    }
    output[outputPos + 1] = '\0';
}

int getLine(char output[], int limit) {
    int i, c;
    for (i = 0; (c = getchar()) != '\n' && c != EOF && i <= limit - 1; ++i) {
        output[i] = c;
    }
    if (c == '\n') {
        output[i] = '\n';
        ++i;
    }
    output[i] = '\0';
    return i;
}
