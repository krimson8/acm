#include <cstdio>
#include <cmath>
#include <limits.h>
#include <vector>
#define MAX 10000000
using namespace std;

vector<int> prime;

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
    long long U, L;
    long long k; 

    make_prime();
    long long ans = 0, dis = 1, num, anum;

    scanf("%d", &c);
    // printf("n is %d\n", c);
    while(c--) {
        ans = 0;
        scanf("%lld %lld", &L, &U);
        // printf("L is %lld U is %lld\n", L, U);
        for(k = L; k < U + 1; k++) {
            num = k;

            // I dunno why but the code below was false
            /*
            i = prime[m];
            while(num != i && i < sqrt(num)) {
                if(num % i == 0) {
                    num = num / i;
                    // printf("    %lld\n", i);
                }
                else {
                    m++;
                    i = prime[m];
                    dis++;
                }
            }
            */

            for(int g = 0; g < prime.size() && prime[g] <= num; g++) {
                int e = 1;
                while(num % prime[g] == 0) {
                    num /= prime[g];
                    e++;
                }
                dis *= e;
            }
            if(num > 1) dis *= 2;

            if(dis > ans) {
                ans = dis;
                anum = k;
            }
            dis = 1;
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", L, U, anum, ans);
        ans = 0;
    }
}
