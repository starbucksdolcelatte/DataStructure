#include <stdio.h>

void hanoiMove(int num, char from, char by, char to) {
	if (num == 1) { // 이동할 원반 수 1개 (재귀 탈출 조건)
		printf("원반 1을 %c 에서 %c 로 이동\n", from, to);
	}
	else {
		hanoiMove(num - 1, from, to, by);
		printf("원반 %d를(을) %c 에서 %c 로 이동\n", num, from, to);
		hanoiMove(num - 1, by, from, to);
	}
}

int main() {
	// 막대 A의 원반 3개를 막대 B를 경유하여 막대 C로 옮기기
	hanoiMove(3, 'A', 'B', 'C');
	return 0;
}