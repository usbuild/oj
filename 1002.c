#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN    9
#define MAX_LEN 100

static int
cmpstringp(const void *p1, const void *p2)
{
    return strcmp((char *) p1, (char *) p2);
}

int main(int argc, const char **argv) {
    char *dialMap = "2223334445556667-77888999-";

    int total;
    scanf("%d\n", &total);

    char *input = (char*) malloc(sizeof(char) * total * LEN);
    char *cur = input;
    int j;
    char line[MAX_LEN];

    for(j = 0; j < total; ++j) {
        gets(line);
        int filled = 0, i;
        for (i = 0; i < MAX_LEN; ++i)
        {
            if(filled == LEN - 1 ) break;

            if(filled == 3) cur[filled++] = '-';

            if(line[i] <= '9' && line[i] >= '0') {
                cur[filled++] = line[i];
                continue;
            }
            if(line[i] < 'Z' && line[i] >= 'A') {
                char t = dialMap[line[i] - 'A'];
                if(t <= '9' && t >= '0') {
                    cur[filled++] = t;
                }
            }
        }
        cur[LEN - 1] = 0;
        cur += LEN;
    }

    cur = input;

    qsort(input, total, LEN, cmpstringp);


    char *s = "";
    int count = 1;
    int print = 0;

    int i;
    for(i = 0; i < total; ++i) {
        char *after = input + i * LEN;
        if(strcmp(s, after) == 0) {
            ++count;
        }

        if(strcmp(s, after) != 0 ||  i == total - 1) {
            if(count > 1) {
                print = 1;
                printf("%s %d\n", s, count);
            }
            count = 1;
        }
        s = after;
    }

    if(print == 0) {
         puts("No duplicates.");
    }
}
