#include <stdio.h>
#define PI  3.1415926

int main(const int argc, const char *argv[]) {
    int len;
    scanf("%d", &len);
    int i = 0;
    for(; i < len; ++i) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        int l = 1.0 / 2 * PI  * (x * x + y * y) / 50 + 1;
        printf("Property %d: This property will begin eroding in year %d.\n", i + 1, l);
    }
    puts("END OF OUTPUT.");
    return 0;
}
