#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct city {
    int x;
    int y;
}c[755];

struct edge {
    int a;
    int b;
    double weight;
}e[755*755];

bool cmp(edge A, edge B) {
    return A.weight < B.weight;
}

int p[755], r[755];
int built_new = 0;

int Find(int x) {
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

bool Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);

    if(X != Y) {
        if(r[X] > r[Y])
            r[X] += r[Y], p[Y] = X;
        else
            r[Y] += r[X], p[X] = Y;
        return true;
    }
    return false;
}


int main() {
    int C;
    int c_num;
    int e_num;
    int a, b;

    int temp;

    while(scanf("%d", &c_num) != EOF) {
        for(int i = 1; i < c_num + 1; i++) {
            scanf("%d %d", &c[i].x, &c[i].y);   
        }
        for(int i = 0; i < c_num + 1; i++) {
            p[i] = i; 
            r[i] = 1;
        }
        
        int cnt = 0;
        scanf("%d", &e_num);
        for(int i = 0; i < e_num; i++) {
            scanf("%d %d", &a, &b);
            if(Union(a, b)) cnt++;
        }

        
        e_num = 0;
        for(int i = 1; i < c_num + 1; i++) {
            for(int j = i + 1; j < c_num + 1; j++) {
                double X = (c[i].x - c[j].x);
                X = X * X;
                double Y = (c[i].y - c[j].y);
                Y = Y * Y;

                e[e_num].a = i;
                e[e_num].b = j;
                e[e_num].weight = sqrt(X + Y);
                e_num++;
            }
        }

        sort(e, e + e_num, cmp);
        double ans = 0;

        for(int i = 0; i < e_num; i++) {
            if(Union(e[i].a, e[i].b)) {
                //printf("%d %d\n", e[i].a, e[i].b);
                ans += e[i].weight;
            }
        }

        printf("%.2lf\n", ans);
        
    }
}