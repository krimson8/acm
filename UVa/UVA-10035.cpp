#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char x[15];
    char y[15];

    while(1) {
        scanf("%s %s", x, y);
        if(x[0] == '0' && y[0] == '0' && strlen(x) == 1 && strlen(y) == 1) break;

        int count = 0;
        int carry = 0;
        int j, k, i, l;
        // if(strlen(y) > strlen(x)) len = strlen(x);
        // else len = strlen(y);

        for(i = strlen(x) - 1, l = strlen(y) - 1; i > -1 && l > -1; i--, l--) {
            j = x[i] - '0';
            k = y[l] - '0';
            // printf("count: %d j: %d k: %d", count, j, k);
            // printf(" j + k + c= %d\n", j + k + carry);
            if(j + k + carry >= 10) {
                carry = (j + k + carry) / 10;
                count++;
            }
            else {
                carry = 0;
            }
        }
        // printf("%d %d\n", i, l);
        // printf("lol\n");
        if(carry > 0) {
            if(i == -1 && l != -1) {
                while(l > -1 && carry > 0) {
                    k = y[l] - '0' + carry;
                    if(k >= 10) {
                        count++;
                        carry = k / 10;
                        l--;
                    }
                    else {
                        l--;
                        carry = 0;
                    }
                    
                }
            }
            if(l == -1 && i != -1) {
                while(i > -1 && carry > 0) {
                    
                    j = x[i] - '0' + carry;
                    // printf("j = %d\n", j);
                    if(j >= 10) {
                        count++;
                        carry = j / 10;
                        i--;
                    }
                    // printf("%d %d -- cary = %d\n", i, l, carry);
                    else {
                        i--;
                        carry = 0;
                    }
                }
            }
        }

        if(count == 0) printf("No carry operation.\n");
        else if(count == 1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n", count);
        count = 0;
        j = 0;
        k = 0;
    }

    return 0;
}