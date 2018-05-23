#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std; 

int main() {
    int c;
    string input;
    scanf("%d\n\n", &c);

    while(c--) {
        map<string, int> M;

        int n = 0;
        while(getline(cin, input)) {
            if(input == "") break;
            n++;
            M[input]++;
        }

        map<string, int>::iterator i;

        for(i = M.begin(); i != M.end(); i++) {
            cout << i->first << " ";
            printf("%.4lf\n", i->second * 100.0 / n);
        }

        if(c) puts("");
    }

    return 0;
}