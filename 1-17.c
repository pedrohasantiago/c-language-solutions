/* Write a program to print all input lines longer than 80 charactes.
 */
#include <stdio.h>
#define MAX_LINE_LEN 1000
#define THRESHOLD 80

int getLineLen(char line[], int maxline);

// main: print the longest input line
int main() {
    int currLineLen;
    char currLine[MAX_LINE_LEN];

    while ((currLineLen = getLineLen(currLine, MAX_LINE_LEN)) > 0) {
        if (currLineLen > THRESHOLD)
            printf("%s", currLine);
    }
    return 0;
}

// getLineLen: read a line from input into s, return length
int getLineLen(char line[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
