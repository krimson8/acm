#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct freckle {
    double x;
    double y;
}f[101];

struct edge {
    int a;
    int b;
    double weight;
}e[101 * 101];

int p[101];

int num_edge;
double ans;

bool cmp(edge A, edge B) {
    return A.weight < B.weight;
}

int Find(int x) {
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

bool Union(int x, int y, double weight) {
    int X = Find(x);
    int Y = Find(y);

    if(X != Y) {
        p[X] = Y; 
        ans += weight;
        return true;
    }
    return false;
}

int main() {
    int c;
    int num_freckles;
    scanf("%d", &c);

    while(c--) {
        scanf("%d", &num_freckles);
        for(int i = 0; i < num_freckles; i++) {
            scanf("%lf %lf", &f[i].x, &f[i].y);
            // initial disjoint set
            p[i] = i;
        }

        num_edge = 0;
        for(int i = 0; i < num_freckles; i++) {
            for(int j = i + 1; j < num_freckles; j++) {
                double X = (f[i].x - f[j].x);
                X = X * X;
                double Y = (f[i].y - f[j].y);
                Y = Y * Y;
                
                e[num_edge].a = i;
                e[num_edge].b = j;
                e[num_edge].weight = sqrt(X + Y);
                num_edge++;
            }
        }

        sort(e, e + num_edge, cmp);
        ans = 0;

        for(int i = 0, j = 0; j != num_freckles - 1; i++) {
            if(Union(e[i].a, e[i].b, e[i].weight)) j++;
        }

        printf("%.2lf\n", ans);
        if(c) printf("\n");
    }
}