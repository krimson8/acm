#include <stdio.h>
#include <string.h>

int main() {
	char input1[100], input2[100];
	int data1 = 0, data2 = 0;
	int temp;
	double result;
	while(fgets(input1, 100, stdin)) {
		fgets(input2, 100, stdin);
		for(int i = 0; i < strlen(input1); i++) {
			if(input1[i] >= 97 && input1[i] <= 122) {
				data1 += input1[i] - 96;
			}
			else if(input1[i] >= 65 && input1[i] <= 90) {
				data1 += input1[i] - 64;
			}
		}
		// printf("%d ", data1);
		while(data1 >= 10) {
			temp = data1 % 10;
			data1 /= 10;
			data1 += temp;
		}
		// printf("%d ", data1);
		for(int i = 0; i < strlen(input2); i++) {
			if(input2[i] >= 97 && input2[i] <= 122) {
				data2 += input2[i] - 96;
			}
			else if(input2[i] >= 65 && input2[i] <= 90) {
				data2 += input2[i] - 64;
			}
		}
		// printf("%d ", data2);
		while(data2 >= 10) {
			temp = data2 % 10;
			data2 /= 10;
			data2 += temp;
		}
		// printf("%d ", data2);
		if(data2 < data1) {
			temp = data1;
			data1 = data2;
			data2 = temp;
		}
		result = (double)data1 * 100 / data2;
		printf("%.2lf %%\n", result);
		data1 = 0, data2 = 0;
	}
}
