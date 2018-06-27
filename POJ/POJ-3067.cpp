#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 1000100

using namespace std;

int s[MAX];
int level[MAX];
int m;

struct node{  
    int x, y;
}r[MAX];  

bool cmp(const node &a, const node &b){  
    if(a.x == b.x)  
        return a.y < b.y;
    return a.x < b.x;
}  

int lowbit(int in) {
    return in & (-in);
}

int get_sum(int index) {
    long long ans = 0;
    while(index > 0) {
        ans += s[index];
        index -= lowbit(index);
    }
    return ans;
}

void change(int index, int delta) {
    for(int i = index; i <= m; i+= lowbit(i))
        s[i] += delta;
}

int main()  
{  
    int c, n, k, num = 1;  
    long long ans; 

    scanf("%d", &c);  
    while(c--) {  
        memset(s, 0, sizeof(s));  
        scanf("%d %d %d", &n, &m, &k);  
        for(int i = 0; i < k; i++) {  
            scanf("%d %d", &r[i].x, &r[i].y);  
        }  

        sort(r, r+k, cmp);  
        ans = 0;  
        
        for(int i = 0; i < k; i++) {  
            ans += i - get_sum(r[i].y);  
            change(r[i].y, 1);  
        }  
        printf("Test case %d: %lld\n", num++, ans);  
    }  
    return 0;  
}  