// havent done need to fix map
#include <stdio.h>
#include <map>

using namespace std;

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
        
        map<float, int> q;
        i = 0;
        l = m;
        while(l--) {
            scanf("%d %d", &day, &fine);
            tf[i] = (float)fine / day;
            printf("-- %f\n", tf[i]);
            q[tf[i]] = i + 1;
            i++;
        }
        for(int i = m - 1; i > 0; i-- ) {
            for(int j = 0; j < i; j++ ) {
                if(tf[j] < tf[j + 1]) {
                    t = tf[j];
                    tf[j] = tf[j + 1];
                    tf[j + 1] = t;
                }
            }
        }

        for(int k = 0; k < m; k++) {
            printf("%d ", q[tf[k]]);
        }
        printf("\n");
    }
}
