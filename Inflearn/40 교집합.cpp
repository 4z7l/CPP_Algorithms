#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;

	scanf("%d", &n);
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	sort(A.begin(), A.end());

	scanf("%d", &m);
	vector<int> B(m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &B[i]);
	}
	sort(B.begin(), B.end());

	//find
	int p1 = 0, p2 = 0, size = 0, check=0;
	vector<int> intersection(n + m);
	while (p1 < n && p2 < m) {
		if (A[p1] == B[p2]) {
			if (check != A[p1]) {
				check = A[p1];
				intersection[size++] = A[p1];
			}
			p1++; p2++;
		}
		else if (A[p1] < B[p2]) p1++;
		else p2++;
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", intersection[i]);
	}

	return 0;
}
