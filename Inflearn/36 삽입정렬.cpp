#include <stdio.h>

void insertion_sort(int n, int* arr) {
	int ind, temp, j;
	for (int i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > temp) {
				arr[j + 1] = arr[j];
			}
			else break;
		}
		arr[j + 1] = temp;
	}
}


int main() {
	int n, arr[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	insertion_sort(n, arr);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
