#include <cstdio>

long long int arr[10001];
int len;
int ans;

void ts() {
    bool done = false;
    long long int temp;
    while(done == false) {
        done = true;
        for(int i = 0; i < len - 2; i++) {
            if(arr[i] > arr[i + 2]) {
                done = false;
                temp = arr[i];
                arr[i] = arr[i + 2];
                arr[i + 2] = temp;
            }
        }
    }
}

bool check() {
    for(int i = 0; i < len - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            ans = i;
            return false;
        }
    }
    return true;
}

int main() {
    int c;
    int n = 1;
    scanf("%d", &c);
    while(c--) {
        scanf("%d", &len);
        for(int i = 0; i < len; i++) {
            scanf("%lld", &arr[i]);
        }
        ts();
        if(check() == false) {
            printf("Case #%d: %d\n", n++, ans);
        } 
        else {
            printf("Case #%d: OK\n", n++);
        }
    }
}