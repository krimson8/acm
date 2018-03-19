#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // char A[24];
    // A[0] = 2;
    // for(int i = 1, j = 2; i < 24; i++) {
    //     if(i % 3 == 0) j++;
    //     A[i] = j;
    // }

    char key[128];
	key['A'] = key['B'] = key['C'] = 2;
	key['D'] = key['E'] = key['F'] = 3;
	key['G'] = key['H'] = key['I'] = 4;
	key['J'] = key['K'] = key['L'] = 5;
	key['M'] = key['N'] = key['O'] = 6;
	key['P'] = key['R'] = key['S'] = 7;
	key['T'] = key['U'] = key['V'] = 8;
	key['W'] = key['X'] = key['Y'] = 9;

    int n;
    int i, j, k;
    char input[128], standard[128];

    int duplicate = 0;
    map<string, int> q;

    scanf("%d\n", &n);
    while(n--) {
        
        scanf("%s", input);

        for(i = 0, k = 0; input[i]; i++) {

            if(isdigit(input[i])) 
                standard[k++] = input[i];
            if(isupper(input[i]))
                standard[k++] = key[input[i]] + '0';
            
            //on third place add dash
            if(k == 3) standard[k++] = '-';
        }
        // end string with '\0'
        standard[k] = '\0';
        q[standard]++;
    }

    map<string, int>::iterator it;

    for(it = q.begin(); it != q.end(); it++ )
    {
        if(it->second > 1) {
            printf("%s %d\n", it->first.c_str(), it->second);
            duplicate = 1;
        }
    }
    // for(auto const& item : q) {
    //     if(item.second > 1) {
    //         printf("%s %d\n", item.first.c_str(), item.second);
    //         duplicate = 1;
    //     }
    // }

    if(duplicate == 0) printf("No duplicates.");

    return 0;
}