#include <cstdio>
#include <cmath>

#define PI 3.141592653589793238462643383

int main() {
    double b, h;

    int n; // number of test cases
    double ans;
    scanf("%d", &n);
    // http://programming-study-notes.blogspot.tw/2014/02/uva-375-inscribed-circles-and-isosceles.html
    // 先算 b×R×0.5 等於下面的一個小等腰三角形
    // 然後剩下左右兩邊的三角形 2*0.5×斜邊t×R
    // 加總 等於 0.5×bh

    // 全部越減 得 t*R*2 + b*R = b*h
    while(n--) {
        scanf("%lf %lf", &b, &h);
        ans = 0;
        while(1) {
            // hypotenuse 斜邊
            double t = hypot(b/2, h);
            double R = (b * h) / (2 * t + b);
            if(R < 0.000001) break;

            ans += (2 * PI * R);

            // 相似三角形原理 計算下一組h 和 b
            double next_h = h - 2 * R;
            double next_b = b * (next_h / h);

            h = next_h;
            b = next_b;
        }

        printf("%13.6f\n", ans);
        if(n) printf("\n");
    }

    return 0;
}