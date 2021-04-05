#include <vector>
#include <cstring>
#include <iostream>

#define MAX 2'147'000'000

using namespace std;

int n, m, res= MAX;
int memory[101], cost[101];
int dp[101][10001] = { 0, };

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> memory[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	// dp[i][j] : A[i]까지의 앱 중 j코스트로 얻을 수 있을 수 있는 최대 메모리
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			//앱을 비활성화 시킨 경우
			if (j - cost[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]] + memory[i]);

			//앱을 그대로 두는 경우
			dp[i][j] = max(dp[i][j], dp[i-1][j]);

			if (dp[i][j] >= m) res = min(res, j);
		}
	}

	cout << res;

	return 0;
}