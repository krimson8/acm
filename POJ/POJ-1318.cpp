#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
    char dict[100][1000];
    char sdict[100][1000];
    char input[1000];
    int j, k, l;
    int i = 0;   
    map<string, string> q;
    while(scanf("%s", dict[i]) != EOF) {
        if(strcmp(dict[i], "XXXXXX") != 0) break;
        
        i++;
    }

    j = sizeof(dict)/sizeof(dict[0]);
    sort(dict, dict + j);

    for(k = 0; k < i; k++) {
        strcpy(sdict[k], dict[k]);
        sort(sdict[k], sdict[k] + strlen(sdict[k]));

        q[dict[k]] = sdict[k];
    }
    
    while(scanf("%s", input) != EOF) {
        int valid = 0;
        if(strcmp(input, "XXXXXX") != 0) break;
        sort(input, input + strlen(input));
        
        map<string, string>::iterator it;

        for(it = q.begin(); it != q.end(); it++ )
        {
            if(strcmp(input, it->first.c_str()) == 0) {
                valid = 1;
                printf("%s\n", it->first.c_str());
            }
        }
        if(valid == 0) printf("NOT A VALID WORD\n");
        printf("******\n");
    }
    
    return 0;
}