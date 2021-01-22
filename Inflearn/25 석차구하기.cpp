#include <stdio.h>

int main() {
	int n, scores[101];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &scores[i]);
	}

	int rank = 1;
	for (int i = 1; i <= n; i++) {
		rank = 1;
		for (int j = 1; j <= n; j++) {
			if (scores[i] < scores[j])
				rank++;
		}
		printf("%d ", rank);
	}

	return 0;
}