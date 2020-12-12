/* Replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing
 */

#include <stdio.h>

#define TAB_STOP_SIZE 10
#define MAX_LINE_SIZE 1000
#define DEBUG 0

int getLine(char[], int);
void entab(char[], char[]);
void addToString(char[], int, int, char);

int main() {
    int i, inputLen, c;
    char inputLine[MAX_LINE_SIZE];
    char outputLine[MAX_LINE_SIZE];
    while ((inputLen = getLine(inputLine, MAX_LINE_SIZE)) != 0) {
        entab(inputLine, outputLine);
        for (i = 0; (c = outputLine[i]) != '\0'; ++i) {
            putchar(c);
        }
    }
}

int getLine(char output[], int limit) {
    int i, c;
    for (i = 0; (c = getchar()) != '\n' && c != EOF && i <= limit; ++i) {
        output[i] = c;
    }
    if (c == '\n') {
        output[i] = '\n';
        ++i;
    }
    output[i] = '\0';
    return i;
}

void entab(char input[], char output[]) {
    int i, j, c, numOfSpaces, numOfTabs;
    int outputPos = 0;
    int consecutiveSpaces = 0;
    for (i = 0; (c = input[i]) != '\0'; ++i) {
        if (c == ' ') {
            ++consecutiveSpaces;
        } else if (consecutiveSpaces) {
            numOfTabs = consecutiveSpaces / TAB_STOP_SIZE;
            numOfSpaces = consecutiveSpaces % TAB_STOP_SIZE;
            addToString(output, outputPos, numOfTabs, '\t');
            outputPos += numOfTabs;
            addToString(output, outputPos, numOfSpaces, ' ');
            outputPos += numOfSpaces;
            output[outputPos] = c;
            ++outputPos;
            consecutiveSpaces = 0;
        } else {
            if (DEBUG) printf("outputPos %d\n", outputPos);
            output[outputPos] = c;
            ++outputPos;
        }
    }
    output[outputPos] = '\0';
}

void addToString(char string[], int initialPos, int timesToAdd, char charToAdd) {
    int j;
    for (j = 0; j < timesToAdd; ++j) {
        if (DEBUG) printf("initialPos + j %d\n", initialPos + j);
        string[initialPos + j] = charToAdd;
    }
}
