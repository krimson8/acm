#include <cstdio>
using namespace std;

int Set[1000001];  // Set[i]= x, x表示i的father, 最上層root的father還是自己

void MakeSet(int n);
int FindSetRoot(int x);
void Union(int x, int y);

int main()
{
//    freopen("input.txt","rt",stdin);
    int Case, C;
    char line[100];
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d ", &C);

        MakeSet(C);

        char Type;
        int A, B;
        int nOfSuccess = 0, nOfUnSuccess = 0;

        while (gets(line)) {
            if (line[0] == '\0') break;
            sscanf(line, "%c %d %d", &Type, &A, &B);

            if (Type == 'c') {
                Union(A,B);
            }
            else {
                if (FindSetRoot(A) == FindSetRoot(B)) //如果同一個root表示在同一個Set
                    ++nOfSuccess;
                else
                    ++nOfUnSuccess;
            }
        }
        printf("%d,%d\n", nOfSuccess, nOfUnSuccess);
        if (Case) putchar('\n');
    }
    return 0;
}
void MakeSet(int n) // 一開始每個數字都是一個set,自己就是root
{
    for (int i = 0; i <= n; ++i)
        Set[i] = i;
}
int FindSetRoot(int x)  // 一直往上找到root
{
    if (Set[x] == x)
        return x;
    return Set[x] = FindSetRoot(Set[x]); // 前面等號賦値的用意是讓Set深度不要太深
}                                        // 加速之後尋找速度
void Union(int x, int y)  //將x所屬的Set和y所屬的Set合併成一個Set
{
    x = FindSetRoot(x);
    y = FindSetRoot(y);

    if (x != y) {
        Set[y] = x;
    }
}