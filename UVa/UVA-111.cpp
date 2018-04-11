#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, c, ans[22], num[22];
int LCS[22][22] = {0};

// Warning: Read carefully the description and consider 
// the difference between ’ordering’ and ’ranking’.

// Input = ranking of event : 4 2 3 1
// what to compare = order of event : e4 e2 e2 e1
int main() {
    int answer;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &c);
        ans[c] = i;
    }

    while (scanf("%d", &c) != EOF) {
        num[c] = 1;
        for (int i = 2; i <= N; ++i) {
            scanf("%d", &c);
            num[c] = i;
        }

        answer = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(ans[i] == num[j])
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                else
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);

                if(LCS[i][j] > answer) answer = LCS[i][j];
            }
        }

        printf("%d\n", answer);
    }
}