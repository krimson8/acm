// #include <cstdio>
// #include <cmath>

// int main() {
//     long long n = 5;
//     long long m = 0;
//     int count = 5;
//     long long i;
//     int a[3] = {2, 3, 5};
//     while(1) {
//         m = n;
//         while(n % 2 == 0) {
//             n /= 2;
//         }
//         while(n % 3 == 0) {
//             n /= 3;
//         }
//         while(n % 5 == 0) {
//             n /= 5;
//         }

//         if(n == 1) {
//             if(count == 1500) {
//                 printf("%d: %lld\n", count, m);
//                 break;
//             }
//             count++;
//         }
        
//         n = m;
//         n++;
//     } 
// }

// this method is too slow ,will tle
// use dynamic programming(from morris blog)

#include<cstdio>

int main() {
	int list[1500] = {1};
    int t2 = 0, t3 = 0, t5 = 0;
    int tmp, i;
	for(i = 1; i < 1500; i++) {
        // start from array[0]
        // 記錄2， 3， 5 每一次乘到哪裏
        // 位於n 的un 一定是 n -1 》 0 的位子的某個數 × 2,3,5

		while(list[t2]*2 <= list[i-1])	t2++;
		while(list[t3]*3 <= list[i-1])	t3++;
		while(list[t5]*5 <= list[i-1])	t5++;

        // 找出最小的那個即可
		tmp = list[t2]*2;
		if(list[t3]*3 < tmp)	tmp = list[t3]*3;
		if(list[t5]*5 < tmp)	tmp = list[t5]*5;
		list[i] = tmp;
	}
	printf("The 1500'th ugly number is %d.\n", list[1499]);
    return 0;
}