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

inline bool match(char *A, char *B, int *pi) {
    int lenA = strlen(A);
    int lenB = strlen(B);
    int i, cur_pos;
    for(i=0, cur_pos=-1; i<lenA; ++i) {
        while(cur_pos != -1 && A[i]!=B[cur_pos+1])
            cur_pos = pi[cur_pos];
        if(A[i]==B[cur_pos+1]) ++cur_pos;
        if(cur_pos+1==lenB) {
            /* Match!! */
            cur_pos = pi[cur_pos];
            return true;
        }
    }

    return false;
} 

int main() {
    int c;
    char a[100001];
    char b[100001];

    scanf("%d", &c);

    while(c--) {
        scanf("%s", a);
        int n;
        scanf("%d", &n);

        while(n--) {
            scanf("%s", b);
            int s = strlen(b);
            int pi[s];
            memset(pi, -1, sizeof(-1));
            fail(b, pi);

            if(match(a, b, pi)) printf("y\n");
            else printf("n\n");
        }
        
    }

    return 0;
}