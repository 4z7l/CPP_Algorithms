#include <stdio.h>

void special_sort(int n, int* arr) {
	int temp;
	for (int i = n-1; i >=0; i--) {
		for (int j = 0; j < i ; j++) {
			if (arr[j] * arr[j + 1] < 0 && arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int n, arr[100];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	special_sort(n, arr);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
