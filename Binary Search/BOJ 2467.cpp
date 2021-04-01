#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int liquid[100'000];

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> liquid[i];
	}

	int lt = 0, rt = n - 1, x = liquid[lt], y = liquid[rt];
	int min = 2'000'000'000;
	int sum = 0;
	while (lt < rt) {
		sum = liquid[lt] + liquid[rt];
		if (min > abs(sum)) {
			min = abs(sum);
			x = liquid[lt];
			y = liquid[rt];
		}
		if (sum < 0) lt++;
		else rt--;
	}

	cout << x << ' ' << y;

	return 0;
}