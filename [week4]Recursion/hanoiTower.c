#include <stdio.h>

void hanoiMove(int num, char from, char by, char to) {
	if (num == 1) { // �̵��� ���� �� 1�� (��� Ż�� ����)
		printf("���� 1�� %c ���� %c �� �̵�\n", from, to);
	}
	else {
		hanoiMove(num - 1, from, to, by);
		printf("���� %d��(��) %c ���� %c �� �̵�\n", num, from, to);
		hanoiMove(num - 1, by, from, to);
	}
}

int main() {
	// ���� A�� ���� 3���� ���� B�� �����Ͽ� ���� C�� �ű��
	hanoiMove(3, 'A', 'B', 'C');
	return 0;
}