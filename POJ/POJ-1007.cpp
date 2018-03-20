#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

int main() {
    int length = 0, c = 0;
    char input[51];
    int count = 0, large = 0;
    int i, k, j;

    map<string, int> q;

    scanf("%d %d\n", &length, &c);
    k = c;

    while(c--) {
        fgets(input, length, stdin);
        
        for(i = 0; i < length; i++) {
            count = 0;
            for(j = i + 1; j < length; j++) {
                if(input[i] > input[j]) count++;
                else break;
            }
            q[input] += count;
            if(q[input] > large) large = q[input];
        }
    }

    map<string, int>::iterator it;

    while(k--) {
        for(it = q.begin(); it != q.end(); it++ )
        {
            large = 0;
            // if(it->second > 1) {
            //     printf("%s %d\n", it->first.c_str(), it->second);
            //     duplicate = 1;
            // }
            if(it->second > large) large = it->second;
        }
    }
}
