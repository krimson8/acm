#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int c;
    long long a, b;
    scanf("%d", &c);

    while(c--) {
        scanf("%lld %lld", &a, &b);
        long long rem = a % b;
        if(rem % 2 == 1) printf("ODD\n");
        else printf("EVEN\n");
    }
    return 0;
}