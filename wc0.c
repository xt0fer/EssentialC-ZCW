#include <stdio.h>
#define IN 1  /* inside a word */
#define OUT 1 /* outside a word */

/* $ cc -o wc0 wc0.c 
   $ ./wc0 <wc0.c 
   26 309 529
*/

/* count lines, words, and characters in input*/
int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}