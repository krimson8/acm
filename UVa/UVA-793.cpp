#include <stdio.h>
#include <cstring>

int p[10000];


int Find(int x) {
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);

    p[X] = Y;
}

void make(int c) {
    for(int i = 0; i < c + 1; i++) {
            p[i] = i;
        }
}
int main() {
    int n; //number of cases
    int c; //number of total computer
    char input[100];

    char q;
    int a, b;
    int s = 0, us = 0;

    scanf("%d\n", &n);
    // printf("n = %d\n", n);

    while(n--) {
        scanf("%d\n\n", &c);
        // printf("c = %d\n", c);

        make(c);
        
        while(1) {
            gets(input);
            // if (input[0] == '\0') break;
            if(strcmp(input, "") == 0 || feof(stdin)) break;

            sscanf(input, "%c %d %d", &q, &a, &b);
            // printf("-- %c %d %d\n", q, a, b);

            if(q == 'c') {
                Union(a, b);
            }
            else {
                if(Find(a) == Find(b)) s++;
                else us++;
            }
        }
        printf("%d,%d\n", s, us);
        s = 0;
        us = 0;
        if(n) printf("\n");
    }

    return 0;
}
