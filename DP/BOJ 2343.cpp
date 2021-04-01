#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <limits.h>

using namespace std;

int lesson[100001];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, sum = 0, bluerayMax = INT_MIN;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> lesson[i];
		sum += lesson[i];
		// 최대 레슨 길이보다 블루레이가 커야함
		bluerayMax = max(bluerayMax, lesson[i]);
	}

	int lt = 1, rt = sum, mid, res = 0;
	int partial_cnt = 0, partial_sum = 0;
	while (lt <= rt) {
		mid = (lt + rt) / 2;
		partial_cnt = 1, partial_sum = 0;
		for (int i = 0; i < n; i++) {
			if (partial_sum + lesson[i] > mid) {
				partial_cnt++;
				partial_sum = lesson[i];
			}
			else {
				partial_sum += lesson[i];
			}
		}

		if (mid >= bluerayMax && partial_cnt <= m) {
			res = mid;
			rt = mid - 1;
		}
		else {
			lt = mid + 1;
		}
	}

	cout << res;

	return 0;
}