#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end());

	int left = 1, right = arr[n - 1] - arr[0], mid;
	int cnt, res = 0, pre = 0;

	while (left <= right) {
		mid = (left + right) / 2;

		cnt = 1;
		pre = 0;

		for (int i = 1; i < n; i++) {
			if (arr[i] - arr[pre] >= mid) {
				cnt++;
				pre = i;
			}
		}

		if (cnt >= m) {
			res = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	printf("%d", res);

	return 0;
}
