#include <cstdio>
#include <cmath>

using namespace std;

double formula(double x, int p, int q, int r, int s, int t, int u) {
    double ans;
    ans = p * exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x, 2) + u;
    return ans;
}

int main() {
    int p, q, r, s, t, u;
    double ans = 100;
    double middle;
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        // printf("%d %d %d %d %d %d", p, q, r, s, t, u);
        double left = 0, right = 1;
        while(right - left > 0.000000000001) {
            middle = (left + right) / 2;
            ans = formula(middle, p, q, r, s, t, u);
            if(ans > 0) left = middle;
            else right = middle;
        }
        if(fabs(formula(middle, p, q, r, s, t, u) - 0) > 1e-10) 
            printf("No solution\n");
        else 
            printf("%.4lf\n", middle);
    }
}