#include <cstdio>
#include <map>

using namespace std;

int main() {
    int c;
    double probability;
    double n, a, b;
    double input;

    scanf("%d", &c);

    while(c--) {
        map<double, double> list;
        scanf("%lf %lf %lf", &n, &a, &b);

        for(int i = 0; i < n; i++) {
            scanf("%lf", &input);
            list[input]++;
        }

        probability = (list[a] * list[b]) / (n * n);
        printf("%.10lf\n", probability);
    }
}