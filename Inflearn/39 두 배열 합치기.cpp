#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n, m;

	scanf("%d", &n);
	vector<int> first(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &first[i]);
	}

	scanf("%d", &m);
	vector<int> second(m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &second[i]);
	}

	vector<int> merged(n+m);

	int ind1 = 0, ind2 = 0, mind=0;
	while (ind1 < n && ind2 < m) {
		if (first[ind1] < second[ind2]) {
			merged[mind++] = first[ind1++];
		}
		else {
			merged[mind++] = second[ind2++];
		}
	}
	while (ind1 < n) {
		merged[mind++] = first[ind1++];
	}
	while (ind2 < m) {
		merged[mind++] = second[ind2++];
	}

	for (int i = 0; i < n + m; i++) {
		printf("%d ", merged[i]);
	}

	return 0;
}
