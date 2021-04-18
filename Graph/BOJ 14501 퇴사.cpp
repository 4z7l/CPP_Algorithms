#include <iostream>
#include <vector>

using namespace std;

int n;
int cost[16];
int T[16];
int P[16];
int res = 0;

void dfs(int level, int sum) {
	if (level == n + 1) {
		if (res < sum) res = sum;
	}
	else {
		if (level + T[level] <= n + 1) {
			//현재 날짜에 상담을 하는 경우
			dfs(level + T[level], sum + P[level]);
		}
		//현재 날짜에 상담을 하지 않는 경우
		dfs(level + 1, sum);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}

	dfs(1, 0);

	cout << res;

	return 0;
}