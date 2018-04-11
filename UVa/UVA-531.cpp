#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string a[102], b[102];
int LCS[101][101] = {0};
int pre[101][101];

int main() {
    //start with 1 !!
    int k = 1, l = 1;
    while(1) {
        while(cin >> a[k]) {
            if(a[k] == "#") break;
            k++;
        }
        while(cin >> b[l]) {
            if(b[l] == "#") break;
            l++;
        }

        if(k == 1) return 0;

        // start from 1 !
        int answer = 0;
        for(int i = 1; i < k; i++) {
            for(int j = 1; j < l; j++) {
                if(a[i] == b[j]) 
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                else
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            
                if(LCS[i][j] > answer) answer = LCS[i][j];
            }
        }

        for(int i = 1; i < k; i++) {
            for(int j = 1; j < l; j++) {
                if(a[i] == b[j]) 
                    pre[i][j] = 0;
                else if(LCS[i - 1][j] > LCS[i][j - 1]) 
                    pre[i][j] = 1;
                else if(LCS[i - 1][j] < LCS[i][j - 1])
                    pre[i][j] = 2;
            }
        }

        string ans[101];
        int g = answer;
        for(int i = k - 1, j = l - 1; i && j; ) {
            if(pre[i][j] == 0) {
                ans[g] = a[i];
                g--, i--, j--;
            }
            else if (pre[i][j] == 1)
                --i;
            else
                --j;
        }

        if(answer != 0) {
            cout << ans[0];
            for(int i = 1; i < answer + 1; i++) {
                cout << " " << ans[i];
            }
            printf("\n");
        }

    }
}