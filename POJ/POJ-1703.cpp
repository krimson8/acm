#include <cstdio>
#include <sstream>

using namespace std;

int p[100000*2];

int Find(int x) {
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);

    if(X != Y) {
        p[X] = Y;
    }
}

void make(int c) {
    for(int i = 0; i < c + 1; i++) {
        p[i] = i;
    }
}

int main() {
    int c; // number of test case
    int n; // number of criminals
    int m; // number of query
    int x, y;
    char input;

    
    scanf("%d", &c);

    while(c--) {
        scanf("%d %d", &n, &m);
        make(n);

        for(int i = 0; i < m; i++) {
            scanf("%c %d %d", &input, &x, &y);
            if(input == 'A') {

            }
            else if(input == 'D') {
                Union(x, y);
            }
        }
    }

    return 0;
}