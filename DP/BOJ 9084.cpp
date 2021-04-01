#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int t, n,m, temp;
	cin >> t;

	int coin[20], dp[10001];

	while (t > 0) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
		}
		cin >> m;
		for (int i = 1; i <= m; i++) {
			dp[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			temp = coin[i];
			dp[temp] += 1;
			for (int j = temp+1; j <=m ; j++) {
				dp[j] += dp[j - temp];
			}
		}
		cout << dp[m]<<'\n';
		t--;
	}


	return 0;
}