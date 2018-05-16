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
    int weight;
    int enable;
}e[100*100];

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
    scanf("%d", &C);
    while(C--) {
        scanf("%d %d", &c_num, &e_num);
        
        for(int i = 0; i < c_num + 1; i++) {
            p[i] = i; 
            r[i] = 1;
        }
        
        for(int i = 0; i < e_num; i++) {
            scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].weight);
            e[i].enable = 0;
        }

        sort(e, e + e_num, cmp);
        
        int ans = 0;
        int ans2 = 0;
        int connected[c_num + 1];
        int index = 0;
        int cnt = 0;

        for(int i = 0; i < e_num; i++) {
            if(Union(e[i].a, e[i].b)) {
                ans += e[i].weight;
                connected[index++] = i;
            }
        }

        int min = 9999999;
        for(int i = 0; i < index; i++) {
            ans2 = 0;
            e[connected[i]].enable = 1;
            for(int i = 0; i < c_num + 1; i++) {
                p[i] = i; 
                r[i] = 1;
            }
            cnt = 0;
            for(int j = 0; j < e_num; j++) {
                if(e[j].enable == 0 && Union(e[j].a, e[j].b)) {
                    ans2 += e[j].weight;
                    cnt++;
                }
            }
            e[connected[i]].enable = 0;
            if(min > ans2 && cnt == c_num - 1) 
                min = ans2;
        }
        // for(int i = 0, j = 0; j != c_num; i++) {
        //     if(Union(e[i].a, e[i].b)) {
        //         ans += e[i].weight;
        //         j++;
        //     }
        //     if(j == c_num) {
        //         ans2 = ans - e[0].weight;
        //         ans -= e[i].weight;
        //     }
        // }
        printf("%d %d\n", ans, min);
        // for(int i = c_num - 1; ; i++) {
        //     if(Union(e[i].a, e[i].b)) {
        //         ans2 += e[i].weight;
        //         break;
        //     }
        // }
        // ans2 += ans;
        // ans2 -= e[0].weight;
        // printf("%d\n", ans);
        
    }
}