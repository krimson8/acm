#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct edge {
    int a;
    int b;
    int weight;
}e[101*101];

bool cmp(edge A, edge B) {
    return A.weight > B.weight;
}

int p[101], r[101];

int Find(int x) {
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

int Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);

    if(X != Y) {
        if(r[X] > r[Y])
            r[X] += r[Y], p[Y] = X;
        else
            r[Y] += r[X], p[X] = Y;
        return 1;
    }
    return 0;
}


int main() {
    int C, c = 1;
    int c_num;
    int e_num;
    int a, b;

    int temp;
    scanf("%d", &C);
    while(C--) {
        scanf("%d %d", &c_num, &e_num);
        
        for(int i = 0; i < c_num + 1; i++) {
            p[i] = i; 
            r[i] = 1;
        }
        
        for(int i = 0; i < e_num; i++) {
            scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].weight);
        }

        sort(e, e + e_num, cmp);

        for(int i = 0, j = 0; i < e_num; i++) {
            j += Union(e[i].a, e[i].b);
            if(j == c_num - 1){
               printf("Case #%d: %d\n", c++, e[i].weight);
               break;
            }
        }
        
    }
}