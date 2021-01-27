#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> arr(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	int left = 1, right = sum, mid;
	int partial_sum, min=sum, partial_cnt;


	while (left <= right) {
		mid = (left + right) / 2;
		partial_sum = 0;
		partial_cnt = 1;

		for (int i = 0; i < n; i++) {
			if (partial_sum + arr[i] <= mid) {
				partial_sum += arr[i];
			}
			else {
				partial_sum = arr[i];
				partial_cnt++;
			}
		}

		if (partial_cnt <= m) {
			min = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%d\n", min);

	return 0;
}
