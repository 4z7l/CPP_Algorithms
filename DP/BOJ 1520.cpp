#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int n, m, h = 0;
int map[500][500];
int dp[500][500] = { 0, };

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	int nx, ny;
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1) continue;
		if (map[x][y] > map[nx][ny]) {
			dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0);
	return 0;
}