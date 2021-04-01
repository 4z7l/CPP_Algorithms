#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <limits.h>

using namespace std;

typedef struct pos {
	int x, y;
	int direction;
	int rotate;
	pos(int a, int b, int c, int d) {
		x = a; y = b;
		direction = c;
		rotate = d;
	}
}pos;

int n, m, res = INT_MAX;
int map[10][10];
int temp[10][10];
vector<pos> cctv;

int rotationLimit[6] = { 0, 4,2,4,4,1 };		// rotationLimit[n] : n번 CCTV를 돌릴 수 있는 횟수
int cctvDirectionLimit[6] = { 0, 1,2,2,3,4 };	// cctvDirectionLimit[n] : n번 CCTV가 볼 수 있는 방향의 갯수

// ↑	→	↓	←
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void monitor() {
	//초기 상태 복사
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = map[i][j];
		}
	}

	//CCTV 감시 후 상태 저장
	for (int k = 0; k < cctv.size(); k++) {
		int cctvDir = cctv[k].direction;
		int cctvRot = cctv[k].rotate;
		int x = cctv[k].x, y = cctv[k].y, nx, ny;

		int offset = 1;
		if (cctvDir == 2) offset = 2;

		for (int i = 0; i < cctvDirectionLimit[cctvDir]; i++) {
			nx = x + dx[cctvRot];
			ny = y + dy[cctvRot];
			while (true) {
				if (nx<1 || nx>n || ny<1 || ny>m || temp[nx][ny] == 6) break;
				if (temp[nx][ny] == 0) temp[nx][ny] = 7;
				nx += dx[cctvRot];
				ny += dy[cctvRot];
			}
			cctvRot = (cctvRot + offset) % 4;
		}
	}
}

void count() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (temp[i][j] == 0) cnt++;
		}
	}
	res = min(res, cnt);
}

void dfs(int cctvPos) {
	if (cctvPos == cctv.size()) {
		monitor(); // 2. cctv의 방향 다 정했으면(회전 다 했으면) 감시하기
		count(); // 3. 감시 다 했으면 사각지대 몇 개인지 세기
	}
	else {
		int dir = cctv[cctvPos].direction;
		int r = rotationLimit[dir];
		// 1. cctv가 볼 방향 정하기
		for (int i = 0; i < r; i++) {
			dfs(cctvPos + 1);
			cctv[cctvPos].rotate = (cctv[cctvPos].rotate + 1) % r;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (0 < map[i][j] && map[i][j] < 6)
				cctv.push_back(pos(i, j, map[i][j], 0));
		}
	}

	dfs(0);

	cout << res;

	return 0;
}