#include <stdio.h>
#include <sstream>

using namespace std;

int p[65536];
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
        ans--;
    }
}

void make(int c) {
    for(int i = 0; i < c + 1; i++) {
        p[i] = i;
    }
}

int main() {
    int m; // number of test case
    int n; // number of pins
    int count = 1;
    int x, y;
    char input[1000];
    
    while(scanf("%d %d", &n, &m) != EOF) {
        if(n == 0 && m == 0) break;
        make(n);
        ans = n;

        while(m--) {
            scanf("%d %d", &x, &y);
            Union(x, y);
        }

        
        printf("Case %d: %d\n", count++, ans);
        ans = 0;
    }

    return 0;
}
