/* Replaces tabs in the input with the proper number of blanks
 * to space to the next tab stop.
 */

#include <stdio.h>

#define TAB_STOP_SIZE 10 // Size in columns for each tab stop
#define DEBUG 0

int main() {
    int i = 0;
    int c, blanksToAdd, j;
    while ((c = getchar()) != EOF) {
        if (DEBUG) printf("%d ", i);
        if (c == '\t') {
            blanksToAdd = i / TAB_STOP_SIZE * TAB_STOP_SIZE + TAB_STOP_SIZE - i;
            if (DEBUG) printf("is \\t. Adding %d blanks\n", blanksToAdd);
            for (j = 0; j < blanksToAdd; ++j) {
                putchar(' ');
                ++i;
            }
        } else if (c == '\n') {
            if (DEBUG) printf("is \\n\n");
            putchar(c);
            i = 0;
        } else {
            if (DEBUG) printf("is %c\n", c);
            putchar(c);
            ++i;
        }
    }
}
