#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 100010

using namespace std;

int s[MAX];
int level[MAX];

struct node{  
    int start, end;
    int id;  
}cow[MAX];  

bool cmp(const node &a, const node &b){  
    if(a.end == b.end)  
        return a.start < b.start;
    return a.end > b.end;
}  

int lowbit(int in) {
    return in & (-in);
}

int get_sum(int index) {
    int ans = 0;
    while(index > 0) {
        ans += s[index];
        index -= lowbit(index);
    }
    return ans;
}

void change(int index, int delta) {
    for(int i = index; i <= MAX; i+= lowbit(i))
        s[i] += delta;
}

int main()  
{  
    int x, y;  
    int n;
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;

        memset(level, 0, sizeof(level));  
        memset(s, 0, sizeof(s));  

        for(int i = 1; i <= n; ++i) {  
            scanf("%d %d", &cow[i].start, &cow[i].end);  
            cow[i].start++; 
            cow[i].id = i;
        }  

        sort(cow + 1, cow + n + 1, cmp);  

        for(int i = 1; i <= n; i++){  
            if(i > 1 && cow[i].start == cow[i - 1].start && cow[i].end == cow[i - 1].end) 
                level[cow[i].id]=level[cow[i - 1].id];  
            else  
                level[cow[i].id]=get_sum(cow[i].start);  

            change(cow[i].start, 1);  
        }  

        for(int i = 1; i <= n; i++)  
        {  
            if(i != 1)  
                printf(" ");  
            printf("%d",level[i]);  
        }  
        printf("\n");  
    }
}  