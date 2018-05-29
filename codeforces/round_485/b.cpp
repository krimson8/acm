// High School； Become Human

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    
    if(x == y) printf("=\n");

    else if(x == 1) printf("<\n");
    else if(y == 1) printf(">\n");

    else if(y >= 3 && x > y) printf("<\n");
    else if(x >= 3 && y > x) printf(">\n");

    else if(x == 2 && y == 3) printf("<\n");
    else if(x == 2 && y == 4) printf("=\n");
    else if(x == 2 && y > 4) printf(">\n");

    else if(y == 2 && x == 3) printf(">\n");
    else if(y == 2 && x == 4) printf("=\n");
    else if(y == 2 && x > 4) printf("<\n");
   
}