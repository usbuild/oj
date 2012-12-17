#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char* calc(const char *oa, const char *ob)
{

    char *a = strdup(oa);
    char *b = strdup(ob);

    char *pa = strchr(a, '.');
    int lena = 0, lenb = 0;
    if(pa) {
        lena = strlen(a) - (pa - a) - 1;
        char *tmp = pa;
        while(*tmp) {
            *tmp = *(tmp + 1);
            tmp++;
        }
    }
    char *pb = strchr(b, '.');
    if(pb) {
        lenb = strlen(b) - (pb - b) - 1;
        char *tmp = pb;
        while(*tmp) {
            *tmp = *(tmp + 1);
            tmp++;
        }
    }
    int point_pos = lena + lenb;

    int total_len = strlen(a) + strlen(b);
    char *o = (char*) calloc(sizeof(char), total_len + 2);
    int i, j, k;
    int offset = 1;
    j = 0;
    for (j = strlen(b) - 1; j >= 0; --j) {
        char *r = (char*) calloc(sizeof(char), total_len + 1);
        k = total_len - offset;
        ++offset;
        for (i = strlen(a) - 1; i >= 0; --i) {
            char d = a[i] - '0';
            char e = b[j] - '0';
            char res = d * e + r[k];
            r[k] = res % 10;
            char m = r[k] + o[k];
            o[k] = m % 10;

            r[--k] = res / 10;
            o[k] += m / 10;
        }
        o[k] += r[k];
    }

    for(i = 0; i < total_len; ++i){
        if(i != 0) {
            if( i >= 10) {
                char m = i;
                o[i] = m % 10;
                o[i - 1] = m / 10;
            }
            break;
        }
    }

    if(point_pos > 0) {
        for(i = total_len; total_len - i != point_pos; --i) {
            o[i] = o[i - 1];
        }
        o[i] = '.' - '0';
    }
    int t;
    for (t = 0; t < total_len; ++t)  {
        o[t] += '0';
    }

    if(point_pos > 0) o[t] += '0';
    
    while(*o == '0' && *o != '.' && ++o);
    char *tmp = o + strlen(o) - 1;

    if(point_pos > 0) {
        while(*tmp == '0') {
            *tmp = 0;
            --tmp;
        }
        if(*tmp == '.') *tmp = 0;
    }
    return o;
}

char* 
recur(const char *s, int n) {
    if(n == 0) return strdup("1");
    else if(n == 1) return calc(s, "1");
    else return calc(recur(s, n / 2), recur(s, n - n / 2));
}

int main(int argc, const char *argv[])
{
    char s[8];
    memset(s, 0, 8);
    int n;
    while(scanf("%s%d",s,&n)==2) {
        char *o = recur(s, n);
        if(*o == 0) o ="0";
        puts(o);
    }
    return 0;
}
