#include <stdio.h>

int exGCD(int a, int b, int &X, int &Y) {
    if(b == 0) {
        X = 1;
        Y = 0;
        return a;
    }
    else {
        int g = exGCD(b, a % b, X, Y);
        int tmp = X;
        X = Y;
        Y = tmp - (a / b) * Y;
        return g;
    }
}

int main() {
    int x, y;
    int a, b;
    int g;
    while(scanf("%d %d", &a, &b) != EOF) {
        g = exGCD(a, b, x, y);
        printf("%d %d %d\n", x, y, g);
    }
}
