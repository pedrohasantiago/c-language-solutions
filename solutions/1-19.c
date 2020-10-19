/* Reverses input lines one at a time */

#include <stdio.h>
#define MAX_LINE_LEN 1000

int getInputLen(char input[], int limit);
void reverse(char input[], int inputLen, char output[]);

int main() {
    char currLine[MAX_LINE_LEN];
    char reversedLine[MAX_LINE_LEN];
    int len, i;
    while ((len = getInputLen(currLine, MAX_LINE_LEN)) > 0) {
        reverse(currLine, len, reversedLine);
        for (i = 0; i < len; ++i)
            putchar(reversedLine[i]);
    }
}

int getInputLen(char input[], int limit) {
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        input[i] = c;
    if (c == '\n') {
        input[i] = c;
        ++i;
    }
    input[i] = '\0';
    return i;
}

void reverse(char input[], int inputLen, char output[]) {
    int i, j;
    j = 0;
    for (i = inputLen - 2; i >= 0; --i) {
        output[j] = input[i];
        ++j;
    }
    output[j] = '\n';
}
