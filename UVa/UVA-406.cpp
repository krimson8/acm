#include <vector>
#include <cstdio>

using namespace std;

int num;
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
    for(int i = 5, gap = 2; i < num + 1; i += gap, gap = 6 - gap)
        if(is_prime(i)) prime.push_back(i);
}

int main() {
    int center;
    
    while(scanf("%d %d", &num, &center) != EOF) {
        make_prime();
        prime.insert(prime.begin(), 1);
        // for(int i = 0; i < prime.size(); i++) {
        //     printf("%d ", prime[i]);
        // }
        // printf("\n");

        printf("%d %d:", num, center);
        if(num == 1) printf(" 1");
        else if(num == 2) {
            printf(" 1 2");
        }
        else if(2 * center - 1 >= prime.size()) {
            // prime.insert(prime.begin(), 1);
            for(int i = 0; i < prime.size(); i++) {
                printf(" %d", prime[i]);
            }
        }
        else if(prime.size() % 2 == 1) {
            int to = 2 * center - 1;
            int begin = prime.size() / 2 - center + 1;

            for(int i = begin; i < begin + to; i++) {
                printf(" %d", prime[i]);
            }
        }
        else {
            int to = 2 * center;
            int begin = prime.size() / 2 - center;

            for(int i = begin; i < begin + to; i++) {
                printf(" %d", prime[i]);
            }
        }
        printf("\n\n");
        vector<int> x;
        prime.swap(x);
        num = 0;
        center = 0;
        // prime.clear();
    }
    
}