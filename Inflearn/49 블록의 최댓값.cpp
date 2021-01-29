#include <stdio.h>

using namespace std;

int main() {
	int n;
	int block[10][10];
	int right[10];
	scanf("%d", &n);

	int input;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		for (int j = 0; j < n; j++) {
			block[j][i] = input;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		scanf("%d", &right[i]);
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			block[i][j] = right[i] < block[i][j] ? right[i] : block[i][j];
			sum += block[i][j];
		}
	}

	printf("%d", sum);


	return 0;
}