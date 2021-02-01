#include <stdio.h>

int array[10] = { 8,5,3,7,10,2,1,6,4,9 };
int temp[10];

void merge(int left, int mid, int right) {
	int p1, p2, p3;

	p1 = left; p2 = mid + 1; p3 = left;

	while (p1 <= mid && p2 <= right) {
		if (array[p1] < array[p2]) temp[p3++] = array[p1++];
		else  temp[p3++] = array[p2++];
	}
	while (p1 <= mid)  temp[p3++] = array[p1++];
	while (p2 <= right)  temp[p3++] = array[p2++];

	for (int i = left; i <= right; i++) {
		array[i] = temp[i];
	}
}

void mergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main() {

	for (int i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");

	mergeSort(0, 9);


	for (int i = 0; i < 10; i++)
		printf("%d ", array[i]);

	return 0;
}