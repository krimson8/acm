#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std; 

int main() {
    int n;
    string input;
    string temp;
    while(cin >> n >> input) {
        map<string, int> M;

        for(int i = 0; i < input.size() - n + 1; i++) {
            temp = input.substr(i, n);
            M[temp]++;
        }

        int max = 0;

        map<string, int>::iterator i;
        string ans;

        for(i = M.begin(); i != M.end(); i++) {
            if(i->second > max) {
                max = i->second;
                ans = i->first;
            }
        }

        cout << ans << endl;
    }

    return 0;
}