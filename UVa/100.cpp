#include <stdio.h>

int main() {
	int i, j, k, temp;
	int counts = 1;
	int maximum = 0;
	while(scanf("%d %d", &i, &j) != EOF) {
		printf("%d %d ", i, j);
		if(i > j) {
			temp = i;
			i = j;
			j = temp;
		}
		for(int m = i; m < j + 1; m++) {
			k = m;
			while(k > 1) {
				if(k % 2 == 1) k = (k << 1) + k + 1;
				else k = k >> 1;
				counts++;
			}
			if(counts > maximum) maximum = counts;
			counts = 1;
		}
		printf("%d\n", maximum);
		maximum = 0;
	}
}
