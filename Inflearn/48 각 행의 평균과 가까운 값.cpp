#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int numbers[9][9];
	int sum[9] = { 0 };

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &numbers[i][j]);
			sum[i] += numbers[i][j];
		}
	}

	int diff=0, max;
	for (int i = 0; i < 9; i++) {
		sum[i] = sum[i] / 9.0 + 0.5;
		diff = sum[i];
		max = 0;
		for (int j = 0; j < 9; j++) {
			if (abs(sum[i] - numbers[i][j]) < diff) {
				if (diff == abs(sum[i] - numbers[i][j])) {
					max = max > numbers[i][j] ? max : numbers[i][j];
				}
				else {
					max = numbers[i][j];
					diff = abs(sum[i] - numbers[i][j]);
				}
			}
		}
		printf("%d %d\n", sum[i], max);
	}


	return 0;
}
