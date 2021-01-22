#include <stdio.h>

void selection_sort(int n, int* arr) {
	int ind = 0, temp;
	for (int i = 1; i <= n; i++) {
		ind = i;
		for (int j= i+1; j<= n; j++) {
			if (arr[j] > arr[ind]) {
				ind = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[ind];
		arr[ind] = temp;
	}
}

int main() {
	int n, arr[101];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	selection_sort(n, arr);

	int ind = 1;
	for (int i = 1; i < n-1; i++) {
		if (arr[i] > arr[i+1]) ind++;
		if (ind == 3) {
			printf("%d", arr[i+1]);
			break;
		}
	}

	return 0;
}
