#include <stdio.h>
#include <limits.h>

long long int ans = 0;
int ary[500001]; //n < 500000 
int buf[500001];

int count = 0;

void Merge(int low, int high) {
    int combined[500001];
    int k = 0, mid = (low + high) / 2;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high) {
        if (ary[j] < ary[i]) {
            combined[k++] = ary[j++];
        }
        else
            combined[k++] = ary[i++];
    }

    while (i <= mid)
        combined[k++] = ary[i++];
    while (j <= high)
        combined[k++] = ary[j++];
    for(k = 0; low <= high; low++)
        ary[low] = combined[k++];
    // for (i = low, j = 0; i <= high; i++, j++)
    //     ary[i] = combined[j];
}

void Mergesort(int low, int high) {
    if(high > low) {
        Mergesort(low, (low + high) / 2);
        Mergesort((low + high) / 2 + 1, high);
        Merge(low, high);
    }
}

int main() {
    int n = 0;
    int i = 0;
    while(scanf("%d", &n) != EOF) {
        // if(n == 0) return 0;
        // for(int i = 0; i < n; i++) {
        //     scanf("%d", &ary[i]);
        // }
        ary[i] = n;

        Mergesort(0, i);

        if(i % 2 == 0) {
            if(i >= 2) {
                printf("%d\n", ary[i / 2]);
            }
            else printf("%d\n", ary[0]);
        }
        else {
            if(i >= 3) printf("%d\n", (ary[i/2] + ary[i/2 + 1]) / 2);
            else printf("%d\n", (ary[i] + ary[i - 1]) / 2);
        }
        // for(int j = 0; j < i + 1; j++) {
        //     printf("%d", ary[j]);
        // }
        // printf("\n");
        i++;
    }
}
