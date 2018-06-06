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
    int n, s, t, c, m, Case = 1;
    int a, b, band;

    scanf("%d", &c);
    while(c--) {
        scanf("%d %d", &n, &m);
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(pa, 0, sizeof(pa));
        
        t = n + m + 1;
        int k, ki;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &k);
            while(k--) {
                scanf("%d", &ki);
                cap[i][n + ki]++;
            }
        }

        for (int i = n + 1; i <= n + m; i++)
            cap[i][t] = 1;
            
        for (int i = 2; i <= n; i++) {
            for (int j = n + 1; j <= n + m; j++) {
                if (cap[i][j]) --cap[i][j];
                else cap[j][i] = 1;
            }
        }
        
        printf("Case #%d: %d\n", Case++, FordFulkerson(1, t, t));
    
    }

    return 0;
}