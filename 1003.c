#include <stdio.h>
#define     MAX     277
void prepare(double *store){
    int i = 1;
    double sum = 0;
    for(; i < MAX; ++i) {
        sum += 1.0 / (i + 1);
        if(store[i - 1] == 0) {
            store[i - 1] = sum;
        }
    }
}

int calc(double input, double *store) {
    int i = 0;
    for(; i < MAX; ++i) {
        if(store[i] > input) 
            return i + 1;
    }
    return i + 1;
}

int main(const int argc, const char *argv[]) {
    double input;
    double store[521] = {0};
    prepare(store);
    for(; ;) {
        scanf("%lf", &input);
        if(input == 0) {
            break;
        }
        printf("%d card(s)\n", calc(input, store));
    }
    return 0;
}
