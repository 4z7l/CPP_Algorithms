#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m, k, s;
	cin >> n >> m;

	int problem[101];
	int dp[10001] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> k >> s;
		problem[k] = s;
		for (int j = m; j >= k; j--) {
			dp[j] = max(dp[j], dp[j - k] + s);
		}
	}
	cout << dp[m];
	return 0;
}