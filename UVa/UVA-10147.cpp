#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct city {
    int x;
    int y;
}c[751];

struct edge {
    int a;
    int b;
    double weight;
}e[751*751];

bool cmp(edge A, edge B) {
    return A.weight < B.weight;
}

int p[751];
int built_new = 0;

int Find(int x) {
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

bool Union(int x, int y, double weight) {
    int X = Find(x);
    int Y = Find(y);

    if(X != Y) {
        p[X] = Y;
        return true;
    }
    return false;
}

bool Union_new(int x, int y, double weight) {
    int X = Find(x);
    int Y = Find(y);

    if(X != Y) {
        p[X] = Y;
        built_new = 1;
        printf("%d %d\n", x + 1, y + 1);
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
    scanf("%d", &C);

    while(C--) {
        scanf("%d", &c_num);
        for(int i = 0; i < c_num; i++) {
            scanf("%d %d", &c[i].x, &c[i].y);   
            p[i] = i; 
        }
        int e_exist[751][751] = {0};
        
        scanf("%d", &e_num);
        for(int i = 0; i < e_num; i++) {
            scanf("%d %d", &a, &b);
            double X = (c[a].x - c[b].x);
            X = X * X;
            double Y = (c[a].y - c[b].y);
            Y = Y * Y;
            
            double weight = sqrt(X + Y);
            e_exist[a][b] = 1;
            Union(a, b, weight);
        }
        temp = e_num;
        e_num = 0;
        for(int i = 0; i < c_num; i++) {
            for(int j = i + 1; j < c_num; j++) {
                if(e_exist[i][j] == 1) continue;
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

        for(int i = 0, j = 0; j != c_num - 1 - temp; i++) {
            // if(e_exist[e[i].a][e[i].b] == 0)
            if(Union_new(e[i].a, e[i].b, e[i].weight)) j++;
        }

        if(built_new == 0) printf("No new highways need.\n\n");
    }
}