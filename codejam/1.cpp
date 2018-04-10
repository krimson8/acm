#include <cstdio>
#include <cstring>

using namespace std;
char input[31];

int dmg() {
    int damage = 1;
    int dmg_done = 0;
    for(int i = 0; i < (int)strlen(input); i++) {
        if(input[i] == 'S') dmg_done += damage;
        else if(input[i] == 'C') damage *= 2;
    }

    return dmg_done;
}

int main() {
    int c;
    int n = 1;
    long long int d = 0;

    bool changed = false;
    long long int counter = 0;

    // while(scanf("%d", &c) != EOF)
    scanf("%d", &c);
    while(c--) {
        scanf("%lld %s", &d, input);
        int k = strlen(input);

        long long int min = 0;
        for(int i = 0; i < k; i++) {
            if(input[i] == 'S') min++;
        }

        if(min > d) {
            printf("Case #%d: IMPOSSIBLE\n", n++);
            continue;
        }
        while(dmg() > d) {
            changed = false;
            for(int i = k - 2; i >= 0; i--) {
                if(input[i] == 'C' && input[i + 1] == 'S') {
                    input[i] = 'S';
                    input[i + 1] = 'C';
                    counter++;
                    break;
                }
            }
        }

        printf("Case #%d: %lld\n", n++, counter);
        counter = 0;
        
        fflush(stdout);
        // printf("Damage done = %d\n", dmg());
    }
}
