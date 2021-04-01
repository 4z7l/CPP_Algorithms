#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct shark {
	int x, y, speed, direction, size;
};

int R, C, M;
vector<vector<int>> board(101, vector<int>(101, -1));
vector<shark> sharks;
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
int res = 0;

int change_direction(int dir) {
	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else return 3;
}

void fishing(int col) {
	for (int i = 1; i <= R; i++) {
		if (board[i][col] != -1) {
			int shark_id = board[i][col];
			res += sharks[shark_id].size;
			sharks[shark_id].x = 0;
			sharks[shark_id].y = 0;
			board[i][col] = -1;
			return;
		}
	}
}

void move_shark() {
	int nx, ny;

	for (int i = 0; i < M; i++) {
		// 이미 잡힌 상어 or 먹힌 상어
		if (sharks[i].x == 0 && sharks[i].y == 0) continue;

		board[sharks[i].x][sharks[i].y] = -1;
		// 상어 이동
		for (int s = 0; s < sharks[i].speed; s++) {
			nx = sharks[i].x + dx[sharks[i].direction];
			ny = sharks[i].y + dy[sharks[i].direction];
			if (nx<1 || nx>R || ny<1 || ny>C) {
				sharks[i].direction = change_direction(sharks[i].direction);
				nx = sharks[i].x + dx[sharks[i].direction];
				ny = sharks[i].y + dy[sharks[i].direction];
			}
			sharks[i].x = nx;
			sharks[i].y = ny;
		}
	}

	//상어 갱신
	for (int i = 0; i < M; i++) {
		nx = sharks[i].x;
		ny = sharks[i].y;
		if (board[nx][ny] == -1) board[nx][ny] = i;
		else {
			int existing_shark_id = board[nx][ny];
			int existing_shark_size = sharks[existing_shark_id].size;
			if (sharks[i].size > existing_shark_size) {
				sharks[existing_shark_id].x = 0;
				sharks[existing_shark_id].y = 0;
				board[nx][ny] = i;
			}
			else {
				sharks[i].x = 0;
				sharks[i].y = 0;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> R >> C >> M;

	int r, c, s, d, z;

	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		board[r][c] = i;
		if (d <= 2) s %= (2 * R - 2);
		else s %= (2 * C - 2);
		sharks.push_back({ r,c,s,d,z });
	}

	for (int i = 1; i <= C; i++) {
		// 1. 낚시왕 이동
		// 2. 상어 잡기
		fishing(i);

		// 3. 상어 이동
		move_shark();
	}

	cout << res;

	return 0;
}