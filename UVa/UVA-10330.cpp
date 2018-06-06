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
    int n, m, s, t, c, Case = 1;
    int capacity;
    int a, b, band;

    while (scanf("%d", &n) != EOF) {
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(pa, 0, sizeof(pa));
        
        int node[n + 1];
        for(int i = 1; i < n+ 1; i++) {
            scanf("%d", &node[i]);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &band);

            capacity = min(node[a], node[b]);
            capacity = min(capacity, band);

            cap[a][b] += capacity;
        }

        scanf("%d %d", &s, &t);
        while(s--) {
            scanf("%d", &c);
            cap[0][c] = node[c];
        }
        while(t--) {
            scanf("%d", &c);
            cap[c][n + 1] = node[c];
        }

        printf("%d\n", FordFulkerson(0, n + 1, n + 1));
    
    }

    return 0;
}