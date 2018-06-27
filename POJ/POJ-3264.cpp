#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define INF 99999999

using namespace std;

int s[50050];

struct Node {
    int minimum;
    int maximum;

    Node *l, *r;

    void update(int update_val) {
        minimum = update_val;
        maximum = update_val;
    }

    void pull() {
        maximum = max(l->maximum, r->maximum);
        minimum = min(l->minimum, r->minimum);
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

// void cover(Node *now, int L, int R, int pos, int delta) {
//     if(L == R) {
//         now->update(now->val + delta);
//         return;
//     }

//     int mid = (L + R) >> 1;

//     if(pos <= mid) {
//         cover(now->l, L, mid, pos, delta);
//     }
//     else {
//         cover(now->r, mid + 1, R, pos, delta);
//     }

//     now->pull();
// }

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

int query_min(Node *now, int L, int R, int x, int y) {
    if(x > R || y < L) {
        return INF;
    }

    if(x <= L && y >= R) {
        return now->minimum;
    }

    int mid = (L + R) >> 1;
    return min(query_min(now->l, L, mid, x, y), query_min(now->r, mid + 1, R, x, y));
}



int main() {
    int N, Q;
    int x, y;
    scanf("%d %d", &N, &Q);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &s[i]);
    }

    Node *list = build(1, N);

    for(int i = 0; i < Q; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", query_max(list, 1, N, x, y) - query_min(list, 1, N, x, y));
    }

    return 0;
}