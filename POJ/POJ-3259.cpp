#include <cstdio>

#define INF 99999999

struct edge{
    int from;
    int to;
    int weight;
}E[3000];

int dis[1001];
int c, N, M, W;

bool relax(int u, int v, int weight, int i) {
    bool changed = 0;
    if(dis[u] + weight < dis[v]) {
        dis[v] = dis[u] + weight;
        changed = 1;
    }
    
    // can be bidirectional so do comparison twice
    // in this question only when i < M is bidirectional
    if(i < M && dis[v] + weight < dis[u]){
        dis[u] = dis[v] + weight;
        changed = 1;
    }

    return changed;
}

bool BellmanFord() {
    // in this case N is the source
    // final dest is 1

    dis[N] = 0;
    for(int i = 1; i < N; i++) {
        dis[i] = INF;
    }

    for(int j = 0; j < N; j++) {
        bool changed = 0;
        for(int i = 0; i < M + W; i++) {
            if(relax(E[i].from, E[i].to, E[i].weight, i))
                changed = 1;
        }
        if(!changed) return true;
    }
    return false;

    // for(int i = 0; i < M + W; i++) {
    //     if(dis[E[i].from] + E[i].weight < dis[E[i].to])
    //         return true;
    //     if(dis[E[i].to] + E[i].weight < dis[E[i].from])
    //         return true;
    // }
    // return false;
    
}

int main() {
    scanf("%d", &c);

    while(c--) {
        scanf("%d %d %d", &N, &M, &W);
    
        for(int i = 0; i < M; i++) {
            scanf("%d %d %d", &E[i].from, &E[i].to, &E[i].weight);
        }

        // from M to M+W line 
        // single direction negative value (* -1)
        for(int i = M; i < M + W; i++) {
            scanf("%d %d %d", &E[i].from, &E[i].to, &E[i].weight);
            E[i].weight *= -1;
        }

        //bool ans = BellmanFord();

        if(BellmanFord()) printf("NO\n");
        else printf("YES\n");
    }
}