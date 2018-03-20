#include <iostream>
#include <algorithm>

using namespace std;
char str[101][51];

struct node
{
    int num;
    char *p;
}a[101];

bool lol(struct node a,struct node b) 
{
    return a.num<b.num; 
}

int main()
{
    int m,n;
    int i,j,k;
    while(cin>>n>>m)
    {
        for(i=0;i<m;i++)
        {
        cin>>str[i];
        a[i].p=str[i]; 
        a[i].num=0;
        for(j=0;j<n-1;j++)
            for(k=j+1;k<n;k++)
                if(str[i][j]>str[i][k])
                    a[i].num++;
    }

    sort(a,a+m,lol);
    for(i=0;i<m;i++)
        cout<<a[i].p<<endl;
    }
}