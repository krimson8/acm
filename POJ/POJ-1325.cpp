#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map <int, vector<int>> edg;
int llink[105], rlink[105];
bool used[105];


bool DFS(int now) {
    int next;

    for(int i = 0; i < (int)edg[now].size(); i++) {
        next = edg[now][i];

        if(!used[next]) {
            used[next] = true;

            if(rlink[next] == -1 || DFS(rlink[next])) {
                llink[now] = next;
                rlink[next] = now;
                return true;
            }
        }
    }

    return false;
}

int Bipartite(int nL, int nR) {
    int ans = 0;

    memset(llink, -1, nL * sizeof(int));
    memset(rlink, -1, nR * sizeof(int));

    for(int i = 0; i < nL; i++) {
        memset(used, false, nR * sizeof(bool));
        if(DFS(i)) ans++;
    }

    return ans;
}

int main() {
    int n, m, k;
    int i, x, y;
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;

        edg.clear();
        scanf("%d %d", &m, &k);

        for(int j = 0; j < k; j++) {
            scanf("%d %d %d", &i, &x, &y);
            if (!x || !y) continue;
            edg[x].push_back(y);
        }

        printf("%d\n", Bipartite(n, m));
    }

    return 0;
}