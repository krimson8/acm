#include <cstdio>

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
            ans += mid - i + 1;
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
    while(scanf("%d", &n)) {
        if(n == 0) return 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &ary[i]);
        }
        
        ans = 0;

        Mergesort(0, n - 1);

        // for(int i = 0; i < n; i++) {
        //     printf("%d", ary[i]);
        // }
        // printf("\n");
        printf("%lld\n", ans);
    }
}
