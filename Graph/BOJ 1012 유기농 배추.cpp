#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

/**
* x, y의 범위 확인하기
* 테스트케이스마다 배열 초기화하기
*/

#define CABBAGE 1
#define GROUND 0
#define VISITED true
#define NOT_VISITED false

using namespace std;

int farm[50][50] = {0,};
bool visited[50][50] = {false,};
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int n, m, k;

void dfs(int sx, int sy) {
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = sx + direction[i][0];
		ny = sy + direction[i][1];
		if (nx<0 || nx > n - 1 || ny<0 || ny>m - 1) continue;
		if (farm[nx][ny] == CABBAGE && visited[nx][ny] == NOT_VISITED) {
			visited[nx][ny] = VISITED;
			dfs(nx, ny);
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	int testcase;
	cin >> testcase;

	while (testcase > 0) {
		cin >> m >> n >> k;

		memset(farm, 0, sizeof(farm));
		memset(visited, false, sizeof(visited));

		/* get location of cabbage */
		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> y >> x;
			farm[x][y] = CABBAGE;
		}

		/* dfs */
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (farm[i][j] == CABBAGE && visited[i][j] == NOT_VISITED) {
					visited[i][j] = VISITED;
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
		testcase--;
	}

	return 0;
}