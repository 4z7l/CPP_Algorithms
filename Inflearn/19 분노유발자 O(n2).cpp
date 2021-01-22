#include <stdio.h>

int main() {
	int n;
	int students[100];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &students[i]);
	}

	int cnt = 0, bunno=0;
	for (int i = 0; i < n-1; i++) {
		bunno = 0;
		for (int j = i + 1; j < n; j++) {
			if (students[i] > students[j]) bunno++;
		}
		if (bunno == n - i - 1) cnt++;
	}

	printf("%d", cnt);


	return 0;
}