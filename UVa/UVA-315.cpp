#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int dfn[105], low[105];
int ans;
int dfsn;

// struct edge_s {
//     int next;
//     int to;
// }edge[105];

vector<int> edge[105];

void DFS(int prev, int cur) {
    bool cut = false;
    int child = 0;
    low[cur] = dfn[cur] = ++dfsn;

    for(int i = 0; i < edge[cur].size(); i++) {
        if(!dfn[edge[cur][i]]) {
            DFS(cur, edge[cur][i]);
            low[cur] = min(low[cur], low[edge[cur][i]]);
            if(low[edge[cur][i]] >= dfn[cur])
                cut = true;
            ++child;
        } else if(edge[cur][i] != prev)
            low[cur] = min(low[cur], dfn[edge[cur][i]]);
    }
    if((child > 1 || prev != -1) && cut) 
        ans++;
}

int main() {
    int n;
    int a, b;
    string line;
    while(1) {
        scanf("%d ", &n);
        if(n == 0) break;

        dfsn = 0;
        ans = 0;

        for(int i = 0; i < n + 1; i++) {
            edge[i].clear();
            dfn[i] = 0;
            low[i] = 0;
        }

        while (getline(cin, line)) {
            stringstream ss(line);
            ss >> a;
            if (!a) break;
            while (ss >> b) {
                edge[a].push_back(b);
                edge[b].push_back(a);
            }
        }

        DFS(-1, 1);
        printf("%d\n", ans);

    }
}