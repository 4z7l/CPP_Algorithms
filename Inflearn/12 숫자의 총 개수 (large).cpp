#include <stdio.h>

int main() {
	int x;

	scanf("%d", &x);

	// i �ڿ��� ���� 1,2,3...
	// inum ���ڰ� i�ڸ��� �ڿ��� ���� 9,90,900...
	// nine 9,99,999..
	int i, inum, nine, sum = 0;
	i = 1; inum = 9; nine = 9;

	while (x > nine) {
		sum += i * inum;
		i++; inum *= 10;
		nine = nine * 10 + 9;
	}
	sum += (x - nine / 10) * i;

	printf("%d", sum);


	return 0;
}