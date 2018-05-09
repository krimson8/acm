#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
#include <map>

using namespace std;

int dfn[30], low[30];
int ans;
int dfsn;

// struct edge_s {
//     int next;
//     int to;
// }edge[105];

vector<int> edge[30];
bool in_stk[30];
vector<int> stk;
vector<int> scc_ans[30];
string numToStr[30];
map<string, int> Map;

void DFS(int cur) {
    int top;
    low[cur] = dfn[cur] = ++dfsn;
    stk.push_back(cur);
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
            top = stk.back();
            scc_ans[ans].push_back(top);
            stk.pop_back();
            in_stk[top] = false;
        } while(top != cur);
        ++ans;
    }
}

int main() {
    int n, m;
    // int v, w, p;
    int C = 1;

    string n1, n2;

    while(1) {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;

        Map.clear();
        stk.clear();

        dfsn = 0;
        ans = 0;

        for(int i = 0; i < n + 1; i++) {
            edge[i].clear();
            scc_ans[i].clear();
            dfn[i] = 0;
            low[i] = 0;
            in_stk[i] = false;
        }

        for (int i = 0, index = 1; i < m; ++i) {
            cin >> n1 >> n2;
            if (!Map[n1]) {
                Map[n1] = index; 
                numToStr[index++] = n1;
            }
            if (!Map[n2]) {
                Map[n2] = index; 
                numToStr[index++] = n2;
            }

            edge[Map[n1]].push_back(Map[n2]);
        }


        for (int i = 1; i < n + 1; i++)
            if (!dfn[i]) DFS(i);

        if (C != 1) printf("\n");
        printf("Calling circles for data set %d:\n", C++);

        for (int i = 0; i < ans; i++) {
            for (int j = 0; j < scc_ans[i].size() - 1; j++)
                cout << numToStr[scc_ans[i][j]] << ", ";
            cout << numToStr[scc_ans[i].back()] << endl;
        }

    }
}