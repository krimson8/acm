#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define INF 99999999
#define N 200006

using namespace std;

int s[50050];
int ans[N], temp[N][2];

struct Node {
    int minimum;
    int maximum;

    Node *l, *r;

    void update(int update_val) {
        maximum = update_val;
    }

    void pull() {
        maximum = max(l->maximum, r->maximum);
    }
};

Node *build(int L, int R) {
    Node *now = new Node();

    if(L == R) {
        now->update(s[L]);
        return now;
    }

    int mid = (L + R) >> 1;

    now->l = build(L, mid);
    now->r = build(mid + 1, R);

    now->pull();
    return now;
}


int query_max(Node *now, int L, int R, int x, int y) {
    if(x > R || y < L) {
        return -INF;
    }

    if(x <= L && y >= R) {
        return now->maximum;
    }

    int mid = (L + R) >> 1;
    return max(query_max(now->l, L, mid, x, y), query_max(now->r, mid + 1, R, x, y));
}


int main() {
    int n;
    int x, y;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d%d", &temp[i][0], &temp[i][1]);
    }

    for(int i=n-1; i>=0; i--) {
        ans[query(1, temp[i][0] + 1)]=temp[i][1];
    } 

    Node *list = build(1, N);

    

    return 0;
}