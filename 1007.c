#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int num;
    char str[51];
} DNA;
int calc(char *str) {
    int i, j, len = strlen(str), count = 0;
    for(i = 0; i < len; ++i) {
        for(j = i + 1; j < len; ++j) {
            if(str[j] < str[i]) ++count;
        }
    }
    return count;
}

int main(int argc, const char *argv[])
{
    int char_len, count;
    scanf("%d %d", &char_len, &count);
    DNA *input = (DNA*)calloc(sizeof(DNA),  count);
    int i, j;
    for(i = 0; i < count; ++i) {
        scanf("%s", input[i].str);
        input[i].num = calc(input[i].str);
    }
    for(i = 0; i < count; ++i) {
        for(j = i + 1; j < count; ++j) {
            if(input[i].num > input[j].num){
                DNA tmp;
                memcpy(&tmp, &input[i], sizeof(DNA));
                memcpy(&input[i], &input[j], sizeof(DNA));
                memcpy(&input[j], &tmp, sizeof(DNA));
            }
        }
    }
    for(i = 0; i < count; ++i) {
        puts(input[i].str);
    }
    return 0;
}
