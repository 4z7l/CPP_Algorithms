#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, s;
	cin >> n >> s;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int p1 = 0, p2 = 0, sum = 0, res = 2'147'000'000;
	while (p1 <= p2) {
		if (sum >= s) {
			res = min(res, p2 - p1);
			sum -= arr[p1++];
		}
		else if (p2 == n) break;
		else {
			sum += arr[p2++];
		}
	}

	if (res == 2'147'000'000) cout << 0;
	else cout << res;

	return 0;
}