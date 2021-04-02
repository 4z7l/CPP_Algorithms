#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

struct pos { int id, dir; };

struct fish {
	int x, y, dir;
	bool isDead = false;
};

//↑, ↖, ←, ↙, ↓, ↘, →, ↗
int dx[9] = { 0, -1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0, 0,-1,-1,-1,0,1,1,1 };

int res = 0;

void dfs(int x, int y, int ate, int board[4][4], fish fishes[17]) {
	int temp_board[4][4];
	fish temp_fishes[17];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp_board[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 17; i++) {
		temp_fishes[i] = fishes[i];
	}

	//물고기 먹음
	int food_fish = temp_board[x][y];
	temp_board[x][y] = -1;
	temp_fishes[food_fish].isDead = true;

	ate += food_fish;
	res = max(res, ate);

	//방향 가짐
	int dir = temp_fishes[food_fish].dir;

	//물고기 이동
	for (int i = 1; i < 17; i++) {
		if (temp_fishes[i].isDead) continue;
		int fx = temp_fishes[i].x;
		int fy = temp_fishes[i].y;
		int fdir = temp_fishes[i].dir;

		int nx = fx + dx[fdir];
		int ny = fy + dy[fdir];

		while (nx < 0 || nx>3 || ny < 0 || ny>3 || (nx == x && ny == y)) {
			fdir = (fdir == 8) ? 1 : fdir + 1;
			nx = fx + dx[fdir];
			ny = fy + dy[fdir];
		}

		if (temp_board[nx][ny] != -1) {
			int subject_fish = temp_board[nx][ny];

			temp_fishes[i].x = nx;
			temp_fishes[i].y = ny;
			temp_fishes[i].dir = fdir;
			temp_fishes[subject_fish].x = fx;
			temp_fishes[subject_fish].y = fy;

			temp_board[nx][ny] = i;
			temp_board[fx][fy] = subject_fish;
		}
		else {
			temp_fishes[i].x = nx;
			temp_fishes[i].y = ny;
			temp_fishes[i].dir = fdir;
			temp_board[nx][ny] = i;
			temp_board[fx][fy] = -1;

		}
	}

	//상어 이동
	for (int i = 1; i <= 3; i++) {
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;
		if (nx < 0 || nx>3 || ny < 0 || ny>3) break;
		if (temp_board[nx][ny] != -1) {
			dfs(nx, ny, ate, temp_board, temp_fishes);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int board[4][4];
	fish fishes[17];

	int a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			board[i][j] = a;
			fishes[a] = { i,j,b, false };
		}
	}

	dfs(0, 0, 0, board, fishes);

	cout << res;

	return 0;
}