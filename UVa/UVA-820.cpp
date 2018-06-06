#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define INF 99999999

using namespace std;

int cap[101][101];
int flow[101][101];
int pa[101];
int v[101];

int FindFlow(int s, int t, int n) {
    int pre;
    int f = INF;

    for(int i = t; i != s; i = pa[i]) {
        pre = pa[i];

        if(cap[pre][i] - flow[pre][i] > 0) 
            f = min(f, cap[pre][i] - flow[pre][i]);
        else f = min(f, flow[i][pre]);
    }

    for(int i = t; i != s; i = pa[i]) {
        pre = pa[i];

        if(cap[pre][i] - flow[pre][i] > 0)
            flow[pre][i] += f;
        else flow[i][pre] -= f;
    }

    return f;
}

bool DFS(int cur, int n, int n) {
    v[cur] = 1;
    if(cur == t) return true;

    for(int i = 1; i <= n; i++) {
        if(v[i]) continue;

        if(cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0) {
            pa[i] = cur;
            if(DFS(i, t, n)) return true;
        }
    }

    return false;
}

int FordFulkerson(int n) {
    int ret = 0;

    while(1) {
        memset(v, 0, sizeof(v));
        if(!DFS(1, n, n)) break;
        ret += FindFlow(1, n, n);
    }

    return ret;
}

int main()
{
    int N, S, T, C, Case = 1;
    while (1) {
        scanf("%d", &N);
        if(N == 0) break;
        for (int i = 1; i <= N; ++i) {
            fill(cap[i], cap[i]+N+1, 0);
            fill(flow[i], flow[i]+N+1, 0);
        }
        scanf("%d %d %d", &S, &T, &C);
        int a, b, bandwidth;
        for (int i = 0; i < C; ++i) {
            scanf("%d %d %d", &a, &b, &bandwidth);
            cap[b][a] = (cap[a][b] += bandwidth);
        }
        printf("Network %d\n", Case++);
        printf("The bandwidth is %d.\n\n", bfs(N, S, T));
    
    }

    return 0;
}