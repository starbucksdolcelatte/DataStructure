#include <stdio.h>

void dp_fibo(int n, int * f) {
	f[1] = 0;
	f[2] = 1;
	printf("%d %d ", f[1], f[2]);
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		printf("%d ", f[i]);
	}
	printf("\n");
	return;
}

int main() {
	int num = 15;
	int* fibArr;
	fibArr = (int*)malloc(sizeof(int)*(num + 1));
	for (int i = 0; i <= num; i++)
		fibArr[i] = 0;
	dp_fibo(num, fibArr);
	return 0;
}
