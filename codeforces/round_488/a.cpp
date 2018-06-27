// Fingerprints

#include <cstdio>

int main() {
    int n, m;
    int input[10][2];
    int temp;
    int first = 0;

    scanf("%d %d", &n ,&m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &input[i][0]);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &temp);
        for(int i = 0; i < n; i++) {
            if(input[i][0] == temp) {
                input[i][1] = 1;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(input[i][1] == 1) {
            if(first == 0) {
                first = 1;
                printf("%d", input[i][0]);
            }
            else {
                printf(" %d", input[i][0]);
            }
        }
    }
    printf("\n");

}