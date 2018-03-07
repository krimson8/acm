#include <stdio.h>

int main() {
    double t = 0, f = 0;
    while(scanf("%lf\n", &f) == 1) {
        t += f;
    }
    printf("$%.2lf\n", t /= 12);
}