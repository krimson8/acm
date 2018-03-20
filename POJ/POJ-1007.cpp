#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct node
{
    int num;
    string p;
}a[101];

bool cmp(struct node a,struct node b) 
{
    return a.num<b.num; 
}

int main() {
    int length = 0, c = 0;
    char input[51];
    int count[101], large = 0;
    int i, k, j, m;

    // map<int, string> q;

    scanf("%d %d\n", &length, &c);
    k = c;
    m = 0;

    while(c--) {
        scanf("%s", input);
        int counter = 0;

        for(i = 0; i < length; i++) {
            for(j = i + 1; j < length; j++) {
                if(input[i] > input[j]) counter++;
                else if(input[i] == input[j]) continue;
                // else break;
            }
        }

        // count[m++] = counter;
        // if(q[counter] != "") q[counter] = q[counter] + "\n" + input;
        // else q[counter] = input;
        a[m].p = input;
        a[m].num = counter;
        // cout << "wtf " << a[m].p << endl;
        m++;
        // printf("%d\n", m);
    }

    // for(i = 0; i < m; i++) {
    //     // printf("%s\n", q[count[i]].c_str());
    //     printf("%d\n", count[i]);
    // }
    // printf("\n");
    sort(a, a + m, cmp);

    for(i = 0; i < m; i++) {
        // printf("%d\n", i);
        cout << a[i].p << endl;
    }
        // printf("%s\n", a[i].p.c_str());

    // map<int, string>::iterator it;

    // for(i = 0; i < m; i++) {
    //     if(count[i] != 0 && count[i] == count[i - 1]) continue;
    //     printf("%s\n", q[count[i]].c_str());
    //     // printf("%d\n", count[i]);
    // }

    // while(k--) {
    //     for(it = q.begin(); it != q.end(); it++ )
    //     {
    //         large = 0;
    //         // if(it->second > 1) {
    //         //     printf("%s %d\n", it->first.c_str(), it->second);
    //         //     duplicate = 1;
    //         // }
    //         if(it->second > large) large = it->second;
    //     }
    // }
}
