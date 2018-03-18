#include <stdio.h>

int main() {
	int tc, cs = 1;
	double f, c;
	scanf("%d\n", &tc);
	while(tc--) {
		scanf("%lf %lf\n", &c, &f);
		f = f * 5 / 9;
		c += f;
		printf("Case %d: %.2lf\n", cs++, c);
	}
}
