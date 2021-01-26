#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());

	int a = 0, b = n - 1, mid = (a + b) / 2;

	while (a <= b) {
		if (arr[mid] == m) break;
		else if (m <= arr[mid]) b = mid - 1;
		else a = mid + 1;
		mid = (a + b) / 2;
	}

	printf("%d", mid + 1);

	return 0;
}
