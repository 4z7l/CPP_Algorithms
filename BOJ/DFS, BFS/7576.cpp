#include <iostream>
#include <queue>

using namespace std;

#define RIPE_TOMATO 1
#define TOMATO 0

int n, m;
int** tomatoes;
int direction[][2] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<int> Qx;
queue<int> Qy;

void bfs() {
	int nx, ny, sx, sy;

	while(!Qx.empty() && !Qy.empty()) {
		sx = Qx.front(); Qx.pop();
		sy = Qy.front(); Qy.pop();

		// 상하좌우 확인
		for (int k = 0; k < 4; k++) {
			nx = sx + direction[k][0];
			ny = sy + direction[k][1];

			if (nx>=0 && nx<m && ny>=0 && ny<n
				&& tomatoes[nx][ny] == TOMATO ) {

				tomatoes[nx][ny] = tomatoes[sx][sy]+1;
				Qx.push(nx);
				Qy.push(ny);
			}
		}
	}

}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

	cin >> n >> m;

	tomatoes = new int* [m];
	for (int i = 0; i < m; i++) {
		tomatoes[i] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tomatoes[i][j];

			if (tomatoes[i][j] == RIPE_TOMATO) {
				Qx.push(i);
				Qy.push(j);
			}
		}
	}

	bfs();

	int max = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (tomatoes[i][j] == TOMATO) {
				cout << "-1";
				return 0;
			}
			if (tomatoes[i][j] >max) {
				max = tomatoes[i][j];
			}
		}
	}

	cout << max-1;

	return 0;
}