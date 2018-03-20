// havent done need to fix map
#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

struct node
{
    double tf;
    int num;
}a[1000];

bool cmp(struct node a,struct node b) 
{
    return a.tf > b.tf; 
}

int main() {
    // map<float, int> q
    // q[float key] = int value
    int n; // number of cases
    int m; // number of job(time, fine)
    int i = 0, l = 0;
    int day, fine;
    float tf[1001];
    float t;

    scanf("%d\n", &n);

    while(n--) {
        scanf("%d\n", &m);
        
        // map<float, int> q;
        i = 0;
        l = m;
        while(l--) {
            scanf("%d %d", &day, &fine);
            a[i].tf = (double)fine / day;
            a[i].num = i + 1;
            // tf[i] = (float)fine / day;
            // printf("-- %f\n", tf[i]);
            // q[tf[i]] = i + 1;
            i++;
        }
        
        stable_sort(a, a + i, cmp);

        printf("%d", a[0].num);
        for(int k = 1; k < m; k++) {
            printf(" %d", a[k].num);
            // printf("%d ", q[tf[k]]);
        }
        printf("\n");
        if(n) printf("\n");
    }
}
