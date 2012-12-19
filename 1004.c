#include <stdio.h>
#define LEN 12
int main(const int argc, const char *argv[]) {
    double input;
    double sum = 0;

    int i = 0;
    for(i = 0; i < LEN; ++i) {
        scanf("%lf",&input);
        sum += input;
    }
    double result = sum / LEN;
    printf("$%.2f\n", result);    
    return 0;
}
