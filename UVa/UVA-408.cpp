#include <stdio.h>

int gcd(int a, int b) {
    if(a == 0) return b;
    else return gcd(b % a, a);
}

int main() {
    int x, y;
    int res;
    while(scanf("%d %d", &x, &y) != EOF) {
        res = gcd(x, y);
        if(res == 1) 
            printf("%10d%10d    Good Choice\n\n", x, y);
        else
            printf("%10d%10d    Bad Choice\n\n", x, y);
    }
}
