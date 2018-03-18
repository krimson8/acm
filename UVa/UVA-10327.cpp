#include <stdio.h>

int main() {
    int n;
    int m;
    int t;
    int arr[1000];

    while(scanf("%d", &n) != EOF) {
        m = 0;
        for(int i = 0; i < n; i++ ) {
            scanf("%d", &arr[i]);
        }
        
        for(int i = n - 1; i > 0; i-- ) {
            for(int j = 0; j < i; j++ ) {
                if(arr[j] > arr[j + 1]) {
                    m++;
                    t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
            }
        }

        printf("Minimum exchange operations : %d\n", m);
    }   
}
