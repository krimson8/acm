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

inline void match(char *A, char *B, int *pi) {
    int lenA = strlen(A);
    int lenB = strlen(B);
    for(int i=1, cur_pos=-1; i<lenA; ++i) {
        while(cur_pos != -1 && A[i]!=B[cur_pos+1])
            cur_pos = pi[cur_pos];
        if(A[i]==B[cur_pos+1]) ++cur_pos;
        if(cur_pos+1==lenB) {
            /* Match!! */
            cur_pos = pi[cur_pos];
        }
    }
} 

int main() {
    int c;
    char input[81];
    scanf("%d", &c);

    while(c--) {
        scanf("%s", input);
        int s = strlen(input);
        int pi[s];

        memset(pi, -1, sizeof(-1));
        fail(input, pi);

        if(s % (s - pi[s - 1] - 1) == 0) {
            printf("%d\n", s - pi[s - 1] - 1);
        }
        else {
            printf("%d\n", s);
        }

        if(c) puts("");
    }

}