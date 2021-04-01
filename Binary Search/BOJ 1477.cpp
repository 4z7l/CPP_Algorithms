#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m, L, x;
	cin >> n >> m >> L;

	vector<int> restarea = { 0,L };
	for (int i = 0; i < n; i++) {
		cin >> x;
		restarea.push_back(x);
	}

	sort(restarea.begin(), restarea.end());

	int lt = 0, rt = L, mid = 0, res = 0;
	while (lt <= rt) {
		mid = (lt + rt) / 2;

		int cnt = 0, dist;
		for (int i = 0; i < restarea.size() - 1; i++) {
			dist = restarea[i + 1] - restarea[i];
			if (dist > mid) {
				if (dist % mid == 0) cnt += dist / mid - 1;
				else cnt += dist / mid;
			}
		}
		if (cnt <= m) {
			rt = mid - 1;
			res = mid;
		}
		else lt = mid + 1;
	}

	cout << res;
	return 0;
}
