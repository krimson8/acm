#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 99999999

int dis[120][120];
int C, S, Q;

void floyd_warshall() {
    // initialization done in main
    for(int k = 1; k < C + 1; k++) {
        for(int i = 1; i < C + 1; i++) {
            for(int j = 1; j < C + 1; j++) {
                if(max(dis[i][k], dis[k][j]) < dis[i][j])
                    dis[i][j] = max(dis[i][k], dis[k][j]);
            }
        }
    }
}

int main() {
    int a, b, sound;
    int c = 1;

    while(1) {
        scanf("%d %d %d", &C, &S, &Q);
        if(C == 0 && S == 0 && Q == 0) break;

        for(int i = 1; i < C + 1; i++) {
            for(int j = 1; j < C + 1; j++) {
                if(i == j) dis[i][j] = 0;
                else dis[i][j] = INF;
            }
        }

        for(int i = 0; i < S; i++) {
            scanf("%d %d %d", &a, &b, &sound);
            dis[a][b] = sound;
            dis[b][a] = sound;
        }

        floyd_warshall();

        if (c != 1) printf("\n");
        printf("Case #%d\n", c++);

        for(int i = 0; i < Q; i++) {
            scanf("%d %d", &a, &b);
            if(dis[a][b] == INF) printf("no path\n");
            else printf("%d\n", dis[a][b]);
        }
    }
    
}
