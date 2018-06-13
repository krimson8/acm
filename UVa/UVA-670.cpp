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
    int x;
    int y;
} bob_route[105], interest[105];

int n, m;

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
    int L;
    double distance, x, y;
    double gap, gap1, gap2;
    scanf("%d", &L);
    
    while(L--) {
        scanf("%d %d", &n, &m);
        edg.clear();

        for(int i = 0; i < n; i++) 
            scanf("%d %d", &bob_route[i].x, &bob_route[i].y);
        for(int i = 0; i < m; i++) 
            scanf("%d %d", &interest[i].x, &interest[i].y);


        for(int i = 0; i < n - 1; ++i){
            x = bob_route[i].x - bob_route[i + 1].x;
            y = bob_route[i].y - bob_route[i + 1].y;
            gap = sqrt(x * x + y * y);
            gap *= 2;
            for(int j = 0; j < m; ++j) {
                x = bob_route[i].x - interest[j].x;
                y = bob_route[i].y - interest[j].y;
                gap1 = sqrt(x * x + y * y);

                x = bob_route[i + 1].x - interest[j].x;
                y = bob_route[i + 1].y - interest[j].y;
                gap2 = sqrt(x * x + y * y);

                if(gap1 + gap2 <= gap) edg[i].push_back(j);
            }
        }
        
        printf("%d\n", Bipartite(n, m) + n);
        for(int i = 0; i < n; i++) {
            if(i != 0) printf(" ");
            printf("%d %d", bob_route[i].x, bob_route[i].y);
            if(llink[i] != -1)
                printf(" %d %d", interest[llink[i]].x, interest[llink[i]].y);
        }
        if(L != 0) printf("\n");
        printf("\n");
    }

    return 0;
}