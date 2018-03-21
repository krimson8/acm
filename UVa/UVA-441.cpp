#include <cstdio>

bool visit[1000];
int num[1000];
int ans[1000];
int n;

void backtrack(int digit, int index) {
    visit[index] = true;
    ans[digit] = num[index];

    for(int i = index + 1; i < n; i++) {
        if(visit[i] == false) {
            backtrack(digit + 1, i);
        }
    }
    // printf("--%d ", digit);
    if(digit == 5) {
        printf("%d", ans[0]);
        for(int i = 1; i < 6; i++)
            printf(" %d", ans[i]);
        puts("");
    }

    visit[index] = false;
    return;
}

int main() {
    int c;
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        if(c++) printf("\n");
        for(int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
            visit[i] = false;
            // printf("%d ", num[i]);
        }

        for(int i = 0; i < n; i++) {
            backtrack(0, i);
        }
        
        
    }
}