#include <cstdio>
#include <iostream>
#include <cstring>

#define MAX 32010

using namespace std;

int s[MAX];
int level[MAX];

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
    scanf("%d", &n);
    
    memset(level, 0, sizeof(level));  
    memset(s, 0, sizeof(s));  
    
    for(int i = 0; i < n; ++i) {  
        scanf("%d %d", &x, &y);  
        x++; 
        level[get_sum(x)]++; 
        change(x, 1); 
    }  
    for(int i = 0; i < n; ++i)  
        printf("%d\n", level[i]);  
    
    return 0;  
}  