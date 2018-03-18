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
    int c; // number of test case
    int n; // number of pins

    int x, y;
    char input[1000];
    scanf("%d", &c);
    while (getchar() != '\n');
    while (getchar() != '\n');

    while(c--) {
        scanf("%d", &n);
        while (getchar() != '\n');

        make(n);
        ans = n;

        while(gets(input) && input[0] != '\0') {
            // create a stringstream class obj
            // sin => string input
            // separate the input 
            // what is sin wtf
            stringstream sin(input);
            while(sin >> x >> y) {
                // x--;
                // y--;
                Union(x, y);
            }
        }
        printf("%d\n", ans);
        ans = 0;
        if(c) printf("\n");
    }

    return 0;
}