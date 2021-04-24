#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 6:24 ~ 7:3

// ↑, ↖, ←, ↙, ↓, ↘, →, ↗
int res = 0;
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };

struct fish {
	int id = 0, x = 0, y = 0, dir = 0;
	bool dead = false;
};

void solve(int sx, int sy, int ate, vector<fish> fishes, vector<vector<int>> board) {
	// 1. 물고기 먹고 이동방향 가지기
	int sdir;
	int feed = board[sx][sy];

	board[sx][sy] = 0;
	fishes[feed].dead = true;
	ate += feed;
	sdir = fishes[feed].dir;

	if (res < ate) { res = ate; }

	// 2. 물고기 이동
	for (int i = 1; i <= 16; i++) {
		if (fishes[i].dead) continue;

		int x, y, nx, ny, dir;
		x = fishes[i].x;
		y = fishes[i].y;
		dir = fishes[i].dir;

		for (int d = 0; d < 8; d++) {
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (nx < 0 || nx>3 || ny < 0 || ny>3 || (nx == sx && ny == sy))
				dir = dir == 8 ? 1 : dir + 1;
			else break;
		}

		if (nx < 0 || nx>3 || ny < 0 || ny>3 || (nx == sx && ny == sy)) continue;

		if (board[nx][ny] == 0) {
			board[nx][ny] = i;
			board[x][y] = 0;

			fishes[i].x = nx;
			fishes[i].y = ny;
			fishes[i].dir = dir;
		}
		else {
			int tempFishId = board[nx][ny];
			board[nx][ny] = i;
			board[x][y] = tempFishId;

			fishes[tempFishId].x = x;
			fishes[tempFishId].y = y;

			fishes[i].x = nx;
			fishes[i].y = ny;
			fishes[i].dir = dir;

		}

	}


	// 상어 이동
	int snx, sny;
	for (int i = 1; i < 4; i++) {
		snx = sx + dx[sdir] * i;
		sny = sy + dy[sdir] * i;

		if (snx < 0 || snx>3 || sny < 0 || sny>3 || board[snx][sny] == 0) continue;
		solve(snx, sny, ate, fishes, board);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int a, b;

	vector<fish> fishes(17);
	vector<vector<int>> board(4, vector<int>(4));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			fishes[a] = { a, i,j,b, false };
			board[i][j] = a;
		}
	}

	solve(0, 0, 0, fishes, board);

	cout << res;

	return 0;
}