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
    double distance, x, y;

    while(scanf("%d %d %d %d", &n, &m, &s, &v) == 4) {
        edg.clear();

        for(int i = 0; i < n; i++) 
            scanf("%lf %lf", &gopher[i].x, &gopher[i].y);
        for(int i = 0; i < m; i++) 
            scanf("%lf %lf", &hole[i].x, &hole[i].y);

        for(int i = 0; i < n; ++i){ 
            for(int j = 0; j < m; ++j) {
                x = gopher[i].x-hole[j].x;
                y = gopher[i].y-hole[j].y;
                distance = sqrt(x * x + y * y);

                if(distance / v <= s)
                    edg[i].push_back(j);
            }
        }

        printf("%d\n", n - Bipartite(n, m));
    }
}