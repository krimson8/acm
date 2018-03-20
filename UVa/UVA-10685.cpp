#include <stdio.h>
#include <map>

using namespace std;

int p[65536];
int r[65536]; // added tail number
int ans = 0;

int Find(int x) {
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);

    if(X != Y) {
        p[X] = Y;
        r[Y] += r[X];
    }
}

void make(int c) {
    for(int i = 0; i < c + 1; i++) {
        p[i] = i;
        r[i] = 1;
    }
}

int main() {
    int m; // number of test case
    int n; // number of names
    int count = 1;
    int x, y;
    char input[1000];
    char name[30];
    
    while(1) {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;

        make(n);
        int g = n;
        ans = 0;

        map<string, int> q;
        int k = 0;
        while(n--) {
            scanf("%s", name);
            q[name] = k;
            k++;
        }
        while(m--) {
            scanf("%s", name);
            x = q[name];
            scanf("%s", name);
            y = q[name];
            Union(x, y);
        }

        for(int i = 0; i < g + 1; i++) {
            if(r[i] > ans) ans = r[i];
        }
        
        printf("%d\n", ans);
        ans = 0;
    }

    return 0;
}
