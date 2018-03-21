#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, k; // n = number of data, k= number of queries
    int i, j;
    int a[100001];
    char lol[3];
    scanf("%d", &n);
    for(i = 0; i < n ; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%s", lol);
    stable_sort(a, a + n);

    // for(i = 0; i < n ; i++) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");

    scanf("%d", &k);
    for(i = 0; i < k ; i++) {
        scanf("%d", &j);
        printf("%d\n", a[j - 1]);
    }

    return 0;
}