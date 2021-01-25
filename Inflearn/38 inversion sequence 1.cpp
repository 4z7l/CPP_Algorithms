#include <stdio.h>

int main() {
	int n;
	int inversion_sequence[101];
	int original_sequence[101];
	scanf("%d", &n);

	//inversion sequence �Է�
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inversion_sequence[i]);
	}

	//������������ ���� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		original_sequence[i] = n - i + 1;
	}

	int temp, move, position = 0;
	for (int i = n; i >= 1; i--) {
		temp = i;
		move = n - i - inversion_sequence[i];	//������ Ƚ��

		//������ ������ ��ġ ���ϱ�
		for (int j = 1; j <= n; j++) {
			if (original_sequence[j] == i) {
				position = j;
				break;
			}
		}

		while (move > 0) {
			original_sequence[position] = original_sequence[position - 1];
			position--;
			move--;
		}
		original_sequence[position] = temp;
	}

	for (int j = 1; j <= n; j++) {
		printf("%d ", original_sequence[j]);
	}

	return 0;
}
