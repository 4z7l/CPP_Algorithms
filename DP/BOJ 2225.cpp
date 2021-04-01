#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <limits.h>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int dp[201][201];

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int i = 1; i <= k; i++) {
		dp[i][0] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1'000'000'000;
		}
	}

	cout << dp[k][n]% 1'000'000'000;

	return 0;
}