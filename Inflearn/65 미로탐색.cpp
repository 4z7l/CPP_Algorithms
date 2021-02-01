#include <stdio.h>

#define SIZE 7

int miro[9][9] = { 0 };
bool isVisited[9][9] = { false };
int cnt = 0;

// ╩С го аб ©Л
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void dfs(int x, int y) {
	if (x > SIZE || y > SIZE) return;
	if (x == SIZE && y == SIZE) {
		cnt++;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int nx, ny;
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx<1 || nx>SIZE || ny<1 || ny>SIZE) continue;
			if (miro[nx][ny] == 0 && !isVisited[nx][ny]) {
				isVisited[nx][ny] = true;
				dfs(nx, ny);
				isVisited[nx][ny] = false;
			}
		}
	}
}

int main() {
	for (int i = 1; i <= SIZE; i++) {
		for (int j = 1; j <= SIZE; j++) {
			scanf("%d", &miro[i][j]);
		}
	}
	isVisited[1][1] = true;
	dfs(1, 1);

	printf("%d", cnt);

	return 0;
}