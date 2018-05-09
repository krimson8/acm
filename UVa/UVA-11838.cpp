#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

int dfn[2001], low[2001];
int ans;
int dfsn;

// struct edge_s {
//     int next;
//     int to;
// }edge[105];

vector<int> edge[2001];
bool in_stk[2001];
stack<int> stk;

void DFS(int cur) {
    
    int top = 0;
    low[cur] = dfn[cur] = ++dfsn;
    stk.push(cur);
    in_stk[cur] = true;

    for(int i = 0; i < edge[cur].size(); i++) {
        if(!dfn[edge[cur][i]]) {
            DFS(edge[cur][i]);
            low[cur] = min(low[cur], low[edge[cur][i]]);
        } else if(in_stk[edge[cur][i]])
            low[cur] = min(low[cur], dfn[edge[cur][i]]);
    }

    if(dfn[cur] == low[cur]) {
        do {
            top = stk.top();
            stk.pop();
            in_stk[top] = false;
        } while(top != cur);
        ++ans;
    }
}

int main() {
    int n, m;
    int v, w, p;
    string line;
    while(1) {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;

        dfsn = 0;
        ans = 0;

        while(!stk.empty()) stk.pop();

        for(int i = 0; i < n + 1; i++) {
            edge[i].clear();
            dfn[i] = 0;
            low[i] = 0;
        }

        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &v, &w, &p);
            if(p == 1) edge[v].push_back(w);
            else if(p == 2) {
                edge[v].push_back(w);
                edge[w].push_back(v);
            }
        }

        for (int i = 1; i < n + 1; i++)
            if (!dfn[i] && ans <= 1) DFS(i);

        printf("%d\n", ans == 1 ? 1 : 0);

    }
}