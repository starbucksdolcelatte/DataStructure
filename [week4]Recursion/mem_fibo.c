#include <stdio.h>
#define ARR_LEN 15
int mem_fibo(int n, int * fibArr) {
	
	if (n == 1 || n == 2) {
		fibArr[n] = 1;
		for (int i = 1; i < ARR_LEN + 1; i++)
			printf("%d ", fibArr[i]);
		printf("\n");
		return 1;
	}
	else if (fibArr[n] > -1) {
		return fibArr[n];
	}
	else {
		fibArr[n] = mem_fibo(n - 2, fibArr) + mem_fibo(n - 1, fibArr);
		for (int i = 1; i < ARR_LEN+1; i++)
			printf("%d ", fibArr[i]); 
		printf("\n");
		return fibArr[n];
	}
}
/*
int main() {
	int num = 15;
	int *f;
	// �Ű����� n�� ���� �迭 ũ�� �Ҵ�
	f = (int *)malloc(sizeof(int) * ARR_LEN+1);
	for (int i = 0; i < ARR_LEN+1; i++)
		f[i] = -1; // -1�� �迭 ��� ��� �ʱ�ȭ
	mem_fibo(num, f);
}
*/