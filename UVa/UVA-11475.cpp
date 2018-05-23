#include <cstdio>
#include <cstring>

inline void fail (char *B, int *pi) {
    int len = strlen(B);
    pi[0] = -1;
    for(int i=1, cur_pos=-1; i<len; ++i) {
        while(cur_pos != -1 && B[i]!=B[cur_pos+1])
            cur_pos = pi[cur_pos];
        if(B[i]==B[cur_pos+1]) ++cur_pos;
        pi[i] = cur_pos;
    }
} 

inline int match(char *A, char *B, int *pi) {
    int lenA = strlen(A);
    int lenB = strlen(B);
    int i, cur_pos;
    for(i=0, cur_pos=-1; i<lenA; ++i) {
        while(cur_pos != -1 && A[i]!=B[cur_pos+1])
            cur_pos = pi[cur_pos];
        if(A[i]==B[cur_pos+1]) ++cur_pos;
        // if(cur_pos+1==lenB) {
        //     /* Match!! */
        //     cur_pos = pi[cur_pos];
        // }
    }

    return cur_pos;
} 

int main() {
    int c;
    char a[100001];
    char b[100001];

    while(scanf("%s", a) != EOF) {
        int s = strlen(a);

        for(int i = 0, j = s - 1; i < s; i++, j--) {
            b[j] = a[i];
        }
        b[s] = '\0';

        int pi[s];

        memset(pi, -1, sizeof(-1));
        fail(b, pi);
        int j = match(a, b, pi);

        for(int i = s - 1; i > j; i--) {
            printf("%c", b[i]);
        }

        printf("%s\n", b);
    }
}