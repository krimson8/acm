#include <cstdio>
#define INF 99999999

struct edge {
    int from;
    int to;
} E[5000];

int dis[101];
int N;
int S;
int number = 0;

void relax(int u, int v) {
    if(dis[u] - 1 < dis[v])
        dis[v] = dis[u] - 1;
}

void BellmanFord() {
    for(int i = 1; i < N + 1; i++) {
        dis[i] = INF;
    }
    dis[S] = 0; 
    // put after INF initial because dunno which is S

    for(int j = 0; j < N - 1; j++) {
        for(int i = 0; i < number; i++) {
            relax(E[i].from, E[i].to);
        }
    }
}

int main() {
    int c = 1;

    while(1) {
        scanf("%d", &N);
        if(N == 0) break;

        scanf("%d", &S);

        number = 0;
        while(1) {
            scanf("%d %d", &E[number].from, &E[number].to);
            if(E[number].from == 0 && E[number].to == 0)
                break;
            number++;
        }

        BellmanFord();

        int min = 0;
        int pos = 0;

        for(int i = 1; i < N + 1; i++) {
            if(dis[i] < min) {
                min = dis[i];
                pos = i;
            }
        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", c++, S, -min, pos);
    }
}