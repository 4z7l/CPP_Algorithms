#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> dp(n + 1, 987654321);
	vector<int> pre(n + 1, 0);

	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
				pre[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
				pre[i] = i / 2;
			}
		}
		if (dp[i] > dp[i - 1] + 1) {
			dp[i] = dp[i - 1] + 1;
			pre[i] = i - 1;
		}
	}

	cout << dp[n]<<'\n';
	while (n != 0) {
		cout << n << ' ';
		n = pre[n];
	}
	return 0;
}