#include <cstdio>
#include <vector>

using namespace std;

// int map[5][5] = {
//     {0,1,1,0,1},
//     {1,0,1,0,1},
//     {1,1,0,1,1},
//     {0,0,1,0,1},
//     {1,1,1,1,0}
//     };

int ans[9];
bool visit[6][6] = {0};
vector<int> toNxt[6] = {{}, {2,3,5}, {1,3,5}, {1,2,4,5}, {3,5}, {1,2,3,4}};

void backtrack(int digit, int index) {

    for(int i : toNxt[index]) {
        if(visit[i][index] == false && visit[index][i] == false) {
            visit[i][index] = true;
            visit[index][i] = true;
            ans[digit] = i;

            backtrack(digit + 1, i);

            visit[i][index] = false;
            visit[index][i] = false;
        }
    }
    // printf("--%d ", digit);
    if(digit == 9) {
        // printf("%d", ans[0]);
        for(int i = 0; i < 9; i++)
            printf("%d", ans[i]);
        puts("");
    }

    
    return;
}

int main() {
    ans[0] = 1;
    backtrack(1, 1);
}