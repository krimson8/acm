// Micro-World
// did not complete

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n][2];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i][0]);
    }


    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i][0]);
    }
    printf("\n");
}