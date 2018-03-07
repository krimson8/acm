#include <stdio.h>

int main() {
	int tc, cs = 1, n, m;
	double result;
	scanf("%d\n", &tc);
	while(tc--) {
		scanf("%d %d\n", &n, &m);
		if(n % 2 == 1 && m % 2 == 1) result = n * m + 0.414;
		else result = n * m;
		printf("Scenario #%d:\n%.2lf\n\n", cs++, result);
	}
}
