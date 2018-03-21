// MOO Volume
// #include <cstdlib>
// #include <cstdio>
// #include <cmath>
// #include <algorithm>
#include <stdio.h>
#include <math.h>

// using namespace std;

int main() {
    int arr[10001];
    int n; // number of cow
    long long int count = 0;
    int i, j, k;
    scanf("%d\n", &n);
    // while(n--) {
    //     scanf("%d", &arr[i++]);
    // }
    // sort(arr, arr + i);

    for(i = 0; i < n; i++) scanf("%d", &arr[i]);

    for(k = 0; k < i; k++) {
        for(j = k + 1; j < i; j++) {
            // printf("--%d --%d", k, abs(arr[j] - arr[k]));
            count += abs(arr[j] - arr[k]);
        }
        // printf("\n");
        // printf("%d ", arr[k]);
    }

    printf("%lld\n", count * 2);
}