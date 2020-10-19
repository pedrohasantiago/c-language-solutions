/* Remove trailing blanks and tabs from each line of input
 * and delete blank lines entirely
 */
#include <stdio.h>

#define MAX_LINE_LEN 1000
#define TRUE 1
#define FALSE 0

int getTrimmedLineLen(char output[], int limit);

int main() {
    char currLine[MAX_LINE_LEN];
    int currLineLen, i;
    while ((currLineLen = getTrimmedLineLen(currLine, MAX_LINE_LEN)) > -1)
        if (currLineLen > 0)
            for (i = 0; i <= currLineLen - 1; ++i)
                putchar(currLine[i]);
    return 0;
}

/* getTrimmedLineLen: return length of line in input (one at a time),
 * 0 if line is blank, or -1 if it is the end of the file.
 * Saves to output[] the input line, but trimmed of spaces and tabs.
 */
int getTrimmedLineLen(char output[], int limit) {
    int c, i, j, lineIsBlank;
    char input[limit];
    lineIsBlank = TRUE;
    // Get input while not \n; test for EOF to return earlier.
    for (i = 0; i < limit - 1 && (c = getchar()) != '\n'; ++i) {
        if (c == EOF)
            return -1;
        lineIsBlank = FALSE;
        input[i] = c;
    }
    if (!lineIsBlank) {
        // go back with i while the last char is ' ' or \t.
        // i will be the last written index + 1, so we have to read [i - 1].
        for (; input[i - 1] == ' ' || input[i - 1] == '\t'; --i)
            ;
        input[i] = c; // Adding \n
        ++i;
    }
    // Copy to output array only until i
    for (j = 0; j <= i; ++j)
        output[j] = input[j];
    return i;
}
