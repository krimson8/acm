#include <cstdio>
#include <vector>
using namespace std;

vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41};
int n, ans[20] = {1};

bool check(int a) {
    for(int i = 0; i < prime.size(); i++)
        if (a == prime[i]) return true;

    return false;
}
void backtracking(int digit, bool visit[])
{
    if (digit == n) {
        if (!check(ans[n-1] + 1))
            return;

        printf("1");
        for (int i = 1; i < n; ++i)
            printf(" %d", ans[i]);
        printf("\n");
        
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (visit[i]) continue;
        if (check(i + ans[digit - 1])) {
            visit[i] = 1;
            ans[digit] = i;

            backtracking(digit + 1, visit);

            visit[i] = 0;
        }
    }
}
int main() {
    int c;
    while (scanf("%d", &n) != EOF) {
        if (c++) putchar('\n');
        printf("Case %d:\n", c);

        bool visit[20] = {0};
        backtracking(1, visit);
    }
}