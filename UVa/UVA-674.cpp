#include <cstdio>

int main() {
    // int dp[10000] = {0};
    int n;
    
    int v[5] = {1, 5, 10, 25, 50};
    
    while(~scanf("%d", &n)) {
        int dp[10000] = {0};
        dp[0] = 1;
        for(int k = 0; k < 5; k++) {
            for(int i = v[k]; i < n + 1; i++) {
            
                if(dp[i - v[k]] != 0)
                    dp[i] += dp[i - v[k]];
            }
        }

        // for(int i = 1; i < n + 1; i++) {
        //     printf("%d: %d |", i, dp[i]);
        // }
        printf("%d\n", dp[n]);
    }
    
}   