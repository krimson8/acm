// A Blend of Springtime

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string q;
    cin >> q;

    int status = 0;

    for(int i = 1; i < q.length() - 1; i++) {
        if(q[i - 1] == '.' || q[i] == '.' || q[i + 1] == '.') {
            continue;
        }
        else if(q[i - 1] != q[i + 1] && q[i] != q[i + 1] && q[i] != q[i - 1]) {
            status = 1;
            break;
        }
    }

    if(status == 0) printf("No");
    else printf("Yes");
}