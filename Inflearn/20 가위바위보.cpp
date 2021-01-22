#include <stdio.h>

int main() {
	int n, A[100], B[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
	}
	for (int i = 0; i < n; i++) {
		if (A[i] == B[i]) {
			printf("D\n");
		}
		else if (A[i] % 3 == (B[i] + 1) % 3) {
			printf("A\n");
		}
		else {
			printf("B\n");
		}
	}

	return 0;
}