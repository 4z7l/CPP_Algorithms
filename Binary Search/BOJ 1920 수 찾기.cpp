#include <iostream>

using namespace std;

int A[100'000];
int temp[100'000];

void mergeSort(int* A, int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	mergeSort(A, left, mid);
	mergeSort(A, mid + 1, right);

	int p1 = left;
	int p2 = mid + 1;
	int p3 = left;

	while (p1 <= mid && p2 <= right) {
		if (A[p1] < A[p2]) temp[p3++] = A[p1++];
		else temp[p3++] = A[p2++];
	}
	while (p1 <= mid) temp[p3++] = A[p1++];
	while (p2 <= right) temp[p3++] = A[p2++];

	for (int i = left; i <= right; i++) A[i] = temp[i];
}

bool binary_search(int* A, int N, int x) {
	int left = 0;
	int right = N - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (A[mid] == x) return true;
		else if (A[mid] < x) left = mid + 1;
		else right = mid - 1;
	}
	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int N, M, X;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	mergeSort(A, 0, N - 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> X;
		cout << binary_search(A, N, X) << '\n';
	}

	return 0;
}