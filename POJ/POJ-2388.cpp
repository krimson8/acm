#include <cstdio>
#include <algorithm>

int main() {
    int i;
    int n; //number of cows
    int a[10001];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    std::sort(a, a + n);
    printf("%d\n", a[n / 2]);
}