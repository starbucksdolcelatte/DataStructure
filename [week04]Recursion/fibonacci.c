#include <stdio.h>

int Fibo(int n) {
	if (n == 1) { //¿Á±Õ¿« ≈ª√‚¡∂∞«
		return 0;
	}
	else if (n == 2) { //¿Á±Õ¿« ≈ª√‚¡∂∞«
		return 1;
	}
	else {
		return Fibo(n - 1) + Fibo(n - 2);
	}
}
/*
int main(void) {
	int i;
	for (i = 1; i < 15; i++) {
		printf("%d ", Fibo(i));
	}
	printf("\n");
	return 0;
}
*/