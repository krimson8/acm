#include <cstdio>

int p[200001];
int sum[200001];
int num[200001];

int Find(int x) {
    if (x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void init(int n) {
    for (int i = 1; i < n + 1; i++) {
        p[i] = i + n;
        p[i + n] = i + n;
        sum[i + n] = i;
        num[i + n] = 1;
    }
}

int main() {
    int n, m;
    int op, P, Q;
    while (scanf("%d %d", &n, &m) != EOF) {
        init(n);
        
        while (m--) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d %d", &P, &Q);
                int x = Find(P);
                int y = Find(Q);
                if (x != y) {
                    p[x] = y;
                    sum[y] += sum[x];
                    num[y] += num[x];
                }
            } 
            else if (op == 2) {
                scanf("%d %d", &P, &Q);
                int x = Find(P);
                int y = Find(Q);
                if (x != y) {
                    p[P] = y;
                    sum[x] -= P;
                    sum[y] += P;
                    num[x]--;
                    num[y]++;
                }
            } else {
                scanf("%d", &P);
                int x = Find(P);
                printf("%d %d\n", num[x], sum[x]);
            }
        }
    }
    return 0;
}