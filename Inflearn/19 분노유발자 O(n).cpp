#include <stdio.h>

int main() {
	int n;
	int students[100];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &students[i]);
	}

	int cnt = 0, max = students[n - 1];
	for (int i = n - 1; i >= 0; i--) {
		if (max < students[i]) {
			max = students[i];
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}