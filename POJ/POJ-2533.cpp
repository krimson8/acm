#include <cstdio>

int num[1001];
int LIS[1001];

int N;

void Find_LIS() {
    int i, j;
    for(i = 0; i < N; i++) {
        LIS[i] = 1;
        for(j = 0; j < i; j++) {
            if(num[j] < num[i] && LIS[j] + 1 > LIS[i])
                LIS[i] = LIS[j] + 1;
        }
    }
}

int main() {
    int max = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    // for(int i = 0; i < N; i++) {
    //     printf("%d ", num[i]);
    // }
    // puts("");

    Find_LIS();
    for(int i = 0; i < N; i++) {
        if(LIS[i] > max) max = LIS[i];
    }
    printf("%d\n", max);
}