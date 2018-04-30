#include <cstdio>

#define INF 99999999

struct edge{
    int from;
    int to;
    int weight;
}E[2001];

int dis[1001];
int T, N;

void relax(int u, int v, int weight) {
    if(dis[u] + weight < dis[v])
        dis[v] = dis[u] + weight;

    // can be bidirectional so do comparison twice
    if(dis[v] + weight < dis[u])
        dis[u] = dis[v] + weight;
}

void BellmanFord() {
    // in this case N is the source
    // final dest is 1

    dis[N] = 0;
    for(int i = 1; i < N; i++) {
        dis[i] = INF;
    }

    for(int j = 0; j < N - 1; j++) {
        for(int i = 0; i < T; i++) {
            relax(E[i].from, E[i].to, E[i].weight);
        }
        
        // for(int i = 1; i < N + 1; i++) {
        //     printf("%d-%d --", i, dis[i]);
        // }
        // printf("\n");
    }

    
}

int main() {
    scanf("%d %d", &T, &N);
    for(int i = 0; i < T; i++) {
        scanf("%d %d %d", &E[i].from, &E[i].to, &E[i].weight);
    }

    BellmanFord();

    printf("%d\n", dis[1]);

}