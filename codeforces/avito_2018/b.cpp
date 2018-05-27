// Businessmen Problems
#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

int main() {
    //int a[10001][3];
    int m, n;
    int tempa, tempb;
    map<int, int> a;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &tempa, &tempb);
        a[tempa] = tempb;
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &tempa, &tempb);
        if(tempb > a[tempa]) a[tempa] = tempb;
    }

    map<int, int>::iterator it;
    long long total = 0;

    for(it = a.begin(); it != a.end(); it++) {
        total += it->second;
    }

    cout << total << endl;
}