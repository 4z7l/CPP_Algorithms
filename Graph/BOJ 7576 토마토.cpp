#include <iostream>
#include <queue>

using namespace std;

#define RIPE_TOMATO 1
#define TOMATO 0

int n, m;
int cnt = 0, maxx=0;
int tomatoes[1000][1000] = {0,};
int direction[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<pair<int,int>> Q;

void bfs() {
	int nx, ny, sx, sy;

	while (!Q.empty()) {
		sx = Q.front().first;
		sy = Q.front().second;
		Q.pop();

		if (maxx < tomatoes[sx][sy]) {
			maxx = tomatoes[sx][sy];
		}

		// 상하좌우 확인
		for (int k = 0; k < 4; k++) {
			nx = sx + direction[k][0];
			ny = sy + direction[k][1];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n
				&& tomatoes[nx][ny] == TOMATO) {

				tomatoes[nx][ny] = tomatoes[sx][sy] + 1;
				cnt++;
				Q.push({ nx ,ny });
			}
		}
	}

}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> n >> m;
	int total = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tomatoes[i][j];

			if (tomatoes[i][j] == RIPE_TOMATO) Q.push({i,j});
			else if (tomatoes[i][j] == TOMATO) total++;
		}
	}

	bfs();

	if (cnt != total) cout << "-1";
	else cout << maxx - 1;

	return 0;
}