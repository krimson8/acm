#include <stdio.h>
#include <limits.h>

long long int ans = 0;
int ary[500001]; //n < 500000 
int buf[500001];

void Combine(int l,int mid,int r)
{
    int i,j,cnt;

    i = l;
    j = mid + 1;
    cnt = 0;

    while(i <= mid && j <= r) {
        if(ary[j] < ary[i]) {
            buf[cnt++] = ary[j++];
            ans += mid - i + 1;
        }
        else 
            buf[cnt++] = ary[i++];
    }

    while(i <= mid) buf[cnt++] = ary[i++];
    while(j <= r) buf[cnt++] = ary[j++];

    for(i = l; i <= r; i++)
        ary[i] = buf[i-l];

}

void MergeSort(int l,int r)
{
    if(l==r) return;

    int mid = (l + r) / 2;
    MergeSort(l, mid);
    MergeSort(mid + 1, r);
    Combine(l, mid, r);
}

int main() {
    int n = 0;
    while(scanf("%d", &n)) {
        if(n == 0) return 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &ary[i]);
        }
        
        ans = 0;
        MergeSort(0, n);
        for(int i = 0; i < n; i++) {
            printf("%d", ary[i]);
        }
        printf("\n%lld\n", ans);
    }
}
