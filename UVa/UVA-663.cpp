#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map <int, vector<int>> edg;
int llink[1050], rlink[1050];
bool used[1050];

struct Point{
    int min;
    int max;
} x[1050], y[1050];

// add u v to search
bool DFS(int now, int u, int v) {
    int next;

    for(int i = 0; i < (int)edg[now].size(); i++) {
        next = edg[now][i];
        if (now == u && next == v) continue;

        if(!used[next]) {
            used[next] = true;

            if(rlink[next] == -1 || DFS(rlink[next], u, v)) {
                llink[now] = next;
                rlink[next] = now;
                return true;
            }
        }
    }

    return false;
}

// when doing checking
// u and v means the edge was forbidded to use
// will break the search in DFS
int Bipartite(int nL, int nR, int u, int v) {
    int ans = 0;

    memset(llink, -1, nL * sizeof(int));
    memset(rlink, -1, nR * sizeof(int));

    for(int i = 0; i < nL; i++) {
        memset(used, false, nR * sizeof(bool));
        if(DFS(i, u, v)) ans++;
    }

    return ans;
}

int main() {
    int n;
    int c = 1;
    int X, Y;
    int pair;
    int ans[1000];
    bool answer = false;

    while(1) {
        scanf("%d", &n);
        if(n == 0) break;

        edg.clear();
        answer = false;

        for(int i = 0; i < n; i++)
            scanf("%d %d %d %d", &x[i].min, &x[i].max, &y[i].min, &y[i].max);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &X, &Y);
            for(int j = 0; j < n; j++) {
                if(x[j].min <= X && X <= x[j].max && y[j].min <= Y && Y <= y[j].max) {
                    edg[j].push_back(i);
                }
            }
        }

        pair = Bipartite(n, n, -1, -1);
        

        for(int i = 0; i < n; i++) ans[i] = llink[i];

        printf("Heap %d\n", c++);

        for(int i = 0; i < n; i++) {
            if(Bipartite(n, n, i, ans[i]) < pair) {
                if(answer == true) {
                    printf(" (%c,%d)", i + 'A', ans[i] + 1);
                }
                else {
                    printf("(%c,%d)", i + 'A', ans[i] + 1);
                }
                
                answer = true;
            }
        }
        if(!answer)
            printf("none");
        printf("\n\n");
    }
    
}