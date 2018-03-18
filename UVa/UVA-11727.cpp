#include <stdio.h>

int main() {
	int t, tc, a, b, c, cs = 1;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d %d %d\n", &a, &b, &c);
		if(a > b) {
			t = a;
			a = b;
			b = t;
		}
		if(b > c) {
			t = b;
			b = c;
			c = t;

		}
		if(a > b) {
			t = a;
			a = b;
			b = t;
		}
		printf("Case %d: %d\n", cs++, b);
	}
}
