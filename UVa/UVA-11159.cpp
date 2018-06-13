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

struct Point{
    double x;
    double y;
} gopher[105], hole[105];

int n, m, s, v;

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
    int c, count = 1;
    int n, m;
    int na[105], nb[105];

    scanf("%d", &c);
    while(c--) {
        edg.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &na[i]);
        
        scanf("%d", &m);
        for(int i = 0; i < m; i++) scanf("%d", &nb[i]);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((na[i] && nb[j] % na[i] == 0) || !nb[j])
                    edg[i].push_back(j);
            }
        }

        printf("Case %d: %d\n", count++, Bipartite(n, m));
    }

    return 0;
}