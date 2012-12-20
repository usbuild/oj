#include <stdio.h>
#define LIMIT 21252
long first(long x, int step1, long y, int step2) {
    x %= step1;
    y %= step2;
    for(; ;) {
        while(x < y) x += step1;
        while(y < x) y += step2;
        if(x == y) return x;
    }
}

int main(int argc, const char *argv[])
{
    long x,y,z,t;
    int i = 0;
    for(;;) {
        long calc = LIMIT;
        scanf("%ld %ld %ld %ld", &x, &y, &z, &t);
        if(x == -1 && y == -1 && z == -1 && t == -1) break;
        calc = first(first(x, 23, y, 28), 23 * 28, z, 33);    
        if(calc <= t) calc += LIMIT;
        calc -= t;
        printf("Case %d: the next triple peak occurs in %ld days.\n", ++i, calc);
    }
    return 0;
}
