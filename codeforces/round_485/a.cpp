// Infinity Gauntlet
#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int c;
    string input;
    scanf("%d", &c);

    int exist[6] = {0};
    map<int, string> list;
    list[0] = "Power";
    list[1] = "Time";
    list[2] = "Space";
    list[3] = "Soul";
    list[4] = "Reality";
    list[5] = "Mind";

    for(int i = 0; i < c; i++) {
        cin >> input;
        if(input == "purple") {
            exist[0] = 1;
        }
        else if(input == "green") {
            exist[1] = 1;
        }
        else if(input == "blue") {
            exist[2] = 1;
        }
        else if(input == "orange") {
            exist[3] = 1;
        }
        else if(input == "red") {
            exist[4] = 1;
        }
        else if(input == "yellow") {
            exist[5] = 1;
        }
    }
    cout << 6 - c << endl;

    for(int i = 0; i < 6; i++) {
        if(exist[i] == 0)
            cout << list[i] << endl;
    }

    return 0;
}