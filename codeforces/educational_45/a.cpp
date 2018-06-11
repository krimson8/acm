// Commentary Boxes

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    long long n, m, a, b;
    long long demolish_cost;
    long long build_cost;
    cin >> n >> m >> a >> b;

    if(n % m == 0) {
        printf("0\n");
    }
    else {
        demolish_cost = (n % m) * b;
        build_cost = (m - (n % m)) * a;
        if(build_cost > demolish_cost) cout << demolish_cost << endl;
        else cout << build_cost << endl;
    }
}