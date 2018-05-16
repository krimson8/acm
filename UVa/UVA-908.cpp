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
    return A.weight < B.weight;
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
    int C;
    int c_num;
    int e_num;
    int k, m;
    int a, b, weight, flag = 0;

    while(scanf("%d", &c_num) != EOF) {
        
        for(int i = 0; i < c_num + 1; i++) {
            p[i] = i; 
            r[i] = 1;
        }
        
        int initial_cost = 0;
        
        for(int i = 0; i < c_num - 1; i++) {
            scanf("%d %d %d", &a, &b, &weight);
            initial_cost += weight;
        }
        if(flag) puts("");
		flag = 1;

        e_num = 0;
        scanf("%d", &k); // new line
        for(int i = 0; i < k; i++) {
            scanf("%d %d %d", &e[e_num].a, &e[e_num].b, &e[e_num].weight);
            e_num++;
        }

        scanf("%d", &m); // new line
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &e[e_num].a, &e[e_num].b, &e[e_num].weight);
            e_num++;
        }

        sort(e, e + e_num, cmp);

        int new_cost = 0;
        for(int i = 0, j = 0; i < e_num; i++) {
            if(Union(e[i].a, e[i].b)) {
                new_cost += e[i].weight;
                j++;
            }
            if(j == c_num - 1){
               break;
            }
        }
        printf("%d\n%d\n", initial_cost, new_cost);
    }
}