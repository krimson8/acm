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

bool DFS(int cur, int t, int n) {
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

int FordFulkerson(int s, int t, int n) {
    int ret = 0;

    while(1) {
        memset(v, 0, sizeof(v));
        if(!DFS(s, t, n)) break;
        ret += FindFlow(s, t, n);
    }

    return ret;
}

int main() {
    int n, s, t, c, Case = 1;
    int a, b, band;

    while (1) {
        scanf("%d", &n);
        if(n == 0) break;
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(pa, 0, sizeof(pa));
        
        scanf("%d %d %d", &s, &t, &c);
        
        while(c--) {
            scanf("%d %d %d", &a, &b, &band);
            cap[b][a] += band;
            cap[a][b] += band;
        }

        printf("Network %d\n", Case++);
        printf("The bandwidth is %d.\n\n", FordFulkerson(s, t, n));
    
    }

    return 0;
}