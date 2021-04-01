#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int map[1000][1000];
bool isVisited[1000][1000][2];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

struct wall {
	int x, y, dist, isWallBroken;
};

int bfs() {
	int x = 0, y = 0, dist = 1, isWallBroken = 0, nx, ny;

	queue<wall> Q;
	Q.push({ x,y,dist, isWallBroken });
	isVisited[x][y][isWallBroken] = true;

	while (!Q.empty()) {
		x = Q.front().x;
		y = Q.front().y;
		dist = Q.front().dist;
		isWallBroken = Q.front().isWallBroken;
		Q.pop();

		if (x == n - 1 && y == m - 1) {
			return dist;
		}

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx<0 || nx>n - 1 || ny<0 || ny>m - 1) continue;

			if (map[nx][ny] == 0 && !isVisited[nx][ny][isWallBroken]) {
				Q.push({ nx,ny,dist + 1, isWallBroken });
				isVisited[nx][ny][isWallBroken] = true;
			}
			if (map[nx][ny] == 1 && isWallBroken == 0) {
				Q.push({ nx,ny,dist + 1, 1 });
				isVisited[nx][ny][isWallBroken + 1] = true;
			}
		}
	}

	return -1;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	int res = bfs();
	printf("%d", res);

	return 0;
}