#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 35;
const int MAX = (1<<24) + 5;

int bit[MAX];
int cache[35];

int n;

char op[10];
int ans[N], vis[MAX], now;

int lowbit(int in) {
    return in & (-in);
}

int get_sum(int index) {
    int ans = 0;
    while(index > 0) {
        ans += bit[index];
        index -= lowbit(index);
    }
    return ans;
}

void change(int index, int delta) {
    for(int i = index; i <= MAX; i+= lowbit(i))
        bit[i] += delta;
}


int get_sum(int l, int r) {
    return get_sum(r) - get_sum(l - 1);
}

void tra(int num) {
    if (vis[num]) {
        int len = get_sum(vis[num], now);
        for (int i = 0; i < n; i++) {
            if (cache[i] >= len) break;
            ans[i]++;
        }
        
        change(vis[num], -1);
    }
    else {
        for (int i = 0; i < n; i++)
            ans[i]++;
    }
    change(vis[num] = ++now, 1);
}
 

 
int main() {
    int x, b, y, nn;

    while (~scanf("%d", &n)) {
        now = 0;
        memset(bit, 0, sizeof(bit));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        scanf("%d", &cache[i]);

        while(scanf("%s", op)) {
            if(op[0] == 'E') 
                break;
            
            if(op[0] == 'S') {
                for (int i = 0; i < n; i++)
                printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
                memset(ans, 0, sizeof(ans));
            }
            if(op[0] == 'A') {
                scanf("%d", &x);
                tra(x);
            }
            if(op[0] == 'R') {
                scanf("%d%d%d", &b, &y, &nn);
                for (int i = 0; i < nn; i++)
                tra(b + y * i);
            }
        }
    }
    return 0;
}