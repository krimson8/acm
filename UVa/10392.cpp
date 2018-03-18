#include <stdio.h>
#include <vector>
#include <cmath>

#define MAX 10000000

using namespace std;

/* may use this to find prime numbers
 * not needed in this scenario
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
*/

int main() {
    long long n;
    long long i = 2;
    while(scanf("%lld", &n)) {
        i = 2;
        if(n < 0) return 0;
        while(n != i && i < sqrt(n)) {
            if(n % i == 0) {
                n = n / i;
                printf("    %lld\n", i);
                i--;
            }
            i++;
        }
        printf("    %lld\n\n", n);

    }
}
