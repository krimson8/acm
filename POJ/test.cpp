#include <cstdio>
using namespace std;
#define Inf 99999999

struct Edge{
    int x;
    int y;
    int Len;
}E[3000];
int Dis[1001];

void Initial(const int &N);
bool BellmanFord(const int &N, const int &M, const int &W);
bool Relax(const Edge &E, bool Double);

int main()
{
    int Case, N, M, W;
    scanf("%d", &Case);
    while (Case--){
        scanf("%d %d %d", &N, &M, &W);
        Initial(N);
        for (int i = 0; i < M; ++i)
            scanf("%d %d %d", &E[i].x, &E[i].y, &E[i].Len);
        for (int i = M; i < M + W; ++i){
            scanf("%d %d %d", &E[i].x, &E[i].y, &E[i].Len);
            E[i].Len *= -1;
        }
        if (BellmanFord(N, M, W)) puts("NO");
        else puts("YES");
    }
}
void Initial(const int &N)
{
    Dis[N] = 0;
    for (int i = 1; i < N; ++i)
        Dis[i] = Inf;
}
bool BellmanFord(const int &N, const int &M, const int &W)
{
    for (int times = 0; times < N; ++times){
        bool NotOK = 0;
        for (int i = 0; i < M + W; ++i)
            if (Relax(E[i], i < M)) NotOK = 1;
        if (!NotOK) return true;
    }
    return false;
}
bool Relax(const Edge &E, bool Double)
{
    bool change = 0;
    if (Dis[E.x] + E.Len < Dis[E.y]){
        Dis[E.y] = Dis[E.x] + E.Len;
        change = 1;
    }
    if (Double && Dis[E.y] + E.Len < Dis[E.x]){
        Dis[E.x] = Dis[E.y] + E.Len;
        change = 1;
    }
    return change;
}