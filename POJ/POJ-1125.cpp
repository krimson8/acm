#include <cstdio>

#define INF 99999999

int dis[120][120];
int N;

void floyd_warshall() {
    // initialization done in main
    for(int k = 1; k < N + 1; k++) {
        for(int i = 1; i < N + 1; i++) {
            for(int j = 1; j < N + 1; j++) {
                if(dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
}

int main() {
    while(1) {
        scanf("%d", &N);
        if(N == 0) break;

        for(int i = 1; i < N + 1; i++) {
            for(int j = 1; j < N + 1; j++) {
                if(i == j) dis[i][j] = 0;
                else dis[i][j] = INF;
            }
        }

        for(int i = 1; i < N + 1; i++) {
            int x, a, b;
            scanf("%d", &x); // number of pair of integers
            while(x--) {
                scanf("%d %d", &a, &b);
                dis[i][a] = b;
            }
        }

        floyd_warshall();

        int min = INF;
        int min_pos;
        int max;  
        bool Reachable = true;
        bool Disjoint = true;

        for (int i = 1; i <= N; ++i) {
            max = 0;
            Reachable = true;
            for (int j = 1; j <= N; ++j) {
                if (dis[i][j] == INF) {
                    Reachable = false;
                    break;
                }
                else if (dis[i][j] > max)
                    max = dis[i][j];
            }
            if (Reachable == true) {
                Disjoint = false;
                if (max < min) {
                    min = max;
                    min_pos = i;
                }
            }
        }
        // Output
        if (Disjoint) puts("disjoint");
        else printf("%d %d\n", min_pos, min);
    }
    
}
