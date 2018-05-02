#include <cstdio>

#define INF 99999999

struct edge{
    int from;
    int to;
    int weight;
};

int dis[1001];
int c, N, M, W;

void relax(int u, int v, int weight) {
    if(dis[u] + weight < dis[v]) 
        dis[v] = dis[u] + weight;
}

int main() {
    scanf("%d", &c);

    while(c--) {
        edge E[2001];
        N = 0;
        M = 0;
        scanf("%d %d", &N, &M);
    
        for(int i = 0; i < M; i++) {
            scanf("%d %d %d", &E[i].from, &E[i].to, &E[i].weight);
        }

        bool ans;

        // initialization
        dis[N] = 0;
        for(int i = 1; i < N; i++) {
            dis[i] = INF;
        }


        for(int j = 0; j < N; j++) {
            for(int i = 0; i < M; i++) {
                relax(E[i].from, E[i].to, E[i].weight);
            }
        }

        bool negative = false;
        for(int i = 0; i < M; i++){
            if( dis[E[i].from] + E[i].weight < dis[E[i].to] ){
                printf("possible\n");
                negative = true;
                break;
            }
        }
        if(!negative) printf("not possible\n");
    }

    return 0;
}