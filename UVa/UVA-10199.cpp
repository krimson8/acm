#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int dfn[101], low[101];
int ans;
int dfsn;

// struct edge_s {
//     int next;
//     int to;
// }edge[105];

vector<int> edge[101];
set<string> ansp;
map<string, int> Map;
string numToStr[105];

void DFS(int prev, int cur) {
    bool cut = false;
    int child = 0;
    low[cur] = dfn[cur] = ++dfsn;

    for(int nxt : edge[cur]) {
        if(!dfn[nxt]) {
            ++child;

            DFS(cur, nxt);
            low[cur] = min(low[cur], low[nxt]);
            
            if ((prev == -1 && child > 1) || (prev != -1 && low[nxt] >= dfn[cur]))
                ansp.insert(numToStr[cur]);
            
            
        } else if(nxt != prev)
            low[cur] = min(low[cur], dfn[nxt]);
    }
    
}

int main() {
    int n, r;
    int a, b;
    int c = 1;
    string n1, n2;

    while(1) {
        scanf("%d ", &n);
        if(n == 0) break;

        dfsn = 0;
        ans = 0;
        Map.clear();
        ansp.clear();

        for(int i = 0; i < n + 1; i++) {
            edge[i].clear();
            dfn[i] = 0;
            low[i] = 0;
        }

        //input
        for (int i = 1; i < n + 1; i++) {
            cin >> n1;
            Map[n1] = i;
            numToStr[i] = n1;
        }

        scanf("%d", &r);

        for (int i = 0; i < r; i++) {
            cin >> n1 >> n2;
            edge[Map[n1]].push_back(Map[n2]);
            edge[Map[n2]].push_back(Map[n1]);
        }

        for (int i = 1; i < n + 1; ++i)
            if (!dfn[i]) DFS(-1, i);

        if (c != 1) printf("\n");
        printf("City map #%d: %ld camera(s) found\n", c++, ansp.size());
        for (set<string>::iterator iter = ansp.begin(); iter != ansp.end(); ++iter)
            // printf("%s\n", *iter.c_str());
            cout << *iter << endl;

    }
}