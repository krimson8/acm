#include <cstdio>
#include <cmath>
#include <limits.h>
#include <vector>
#define MAX 10000000
using namespace std;

vector<int> prime;
vector<int>::iterator g;

bool is_prime(int n) {
    for(int i = 0; prime[i] * prime[i] <= n; i++) {
        if(n % prime[i] == 0) return false;
    }
    return true;
}

void make_prime() {
    prime.push_back(2);
    prime.push_back(3);
    for(int i = 5, gap = 2; i < MAX; i += gap, gap = 6 - gap)
        if(is_prime(i)) prime.push_back(i);
}

int main() {
    
    int c; // number of test case
    printf("wtf\n");
    long long U, L;
    long long k;
    int i, m = 0;
    make_prime();
    // for(i = 1; i < 10; i++) {
    //     printf("--%d\n", prime[i]);
    // }
    // printf("wtf\n");
    long long ans = 0, dis = 0, num, anum;

    scanf("%d", &c);
    printf("n is %d\n", c);
    while(c--) {

        scanf("%lld %lld", &L, &U);
        printf("L is %lld U is %lld\n", L, U);
        for(k = L; k < U + 1; k++) {
            m = 0;
            printf("wtf %lld\n", k);
            num = k;

            i = prime[m];

            while(k != i && i < sqrt(k)) {
                if(k % i == 0) {
                    k = k / i;
                    // printf("    %lld\n", i);
                }
                else {
                    m++;
                    i = prime[m];
                    dis++;
                }
            }
            if(dis > ans) {
                ans = dis;
                anum = num;
            }
            k = num;
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", L, U, anum, ans);
    
    }
}
