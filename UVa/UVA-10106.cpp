#include <cstdio>
#include <cstring>

int main() {
    char x[251];
    char y[251];

    int index, t;
    int i, j, k, l;

    while(~scanf("%s", x)) {
        scanf("%s", y);

        char ans[502] = {'0'};
        int gg[502] = {0};
        index = 0;

        int xlen = strlen(x);
        int ylen = strlen(y);
        
        if(xlen > ylen) {
            char z[251];
            strcpy(z, x);
            strcpy(x, y);
            strcpy(y, z);

            int len;
            len = xlen;
            xlen = ylen;
            ylen = len;
        }
        // printf("-- %d -- %d --\n", xlen, ylen);
        
        // printf("debug\n");
        for(i = xlen - 1; i > -1; i--) {
            t = index;
            for(j = ylen - 1; j > -1; j--) {
                // printf("-- %d -- %d --\n", (x[i] - '0'), (y[j] - '0'));
                k = (x[i] - '0') * (y[j] - '0');
                // printf("k is %d\n", k);
                gg[index] += k;
                if(gg[index] >= 10) {
                    int rem = gg[index] / 10;
                    gg[index + 1] += rem;
                    gg[index] %= 10;
                }
                
                index++;
            }
            l = index;
            index = t + 1;
        }
        if(gg[l] > 0) l++;
        if(gg[l + 1] > 0) l += 2;
        // printf("index = %d\n", l);
        if(gg[l - 1] == 0) printf("0");
        else {
            for(i = l - 1; i > -1; i--) {
                printf("%d", gg[i]);
            }
        }
        
        printf("\n");
    }
}