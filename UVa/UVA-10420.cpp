#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int n; // number of input
    char input[76]; //input line
    char *lol;
    int total = 0; // total number of country
    string country[2000];
    
    scanf("%d\n", &n);
    while(n--) {
        fgets(input, 76, stdin);
        lol = strtok(input, " ");
        if(total == 0) {
            country[total] = lol;
            total++;
            cout << country[total]; 
        }
    }
}
