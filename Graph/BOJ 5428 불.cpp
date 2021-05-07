#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int board[1000][1000];
bool visit[1000][1000] = { false, };
int sx, sy;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
// . ºó, #º®, * ºÒ

struct info {
	int x, y, time;
	bool operator<(const info& i)const {
		return time > i.time;
	}
};

void fire() {
	queue<pair<int, int>> Q;
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] > 0) {
				Q.push({ i,j });
				visit[i][j] = true;
			}
		}
	}

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1 || visit[nx][ny]) continue;
			if (board[nx][ny] == 0) {
				board[nx][ny] = board[x][y] + 1;
				Q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}

int move_sanggun() {
	queue<info> Q;
	memset(visit, false, sizeof(visit));

	Q.push({ sx,sy,1 });
	visit[sx][sy] = true;

	int x, y, time;
	while (!Q.empty()) {
		x = Q.front().x;
		y = Q.front().y;
		time = Q.front().time;
		Q.pop();

		//cout << x << ',' << y << ':' << time << '\n';

		if (x == 0 || y == 0 || x==N-1 || y==M-1) {
			return time;
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1 || visit[nx][ny] || board[nx][ny]==-1) continue;
			if (board[nx][ny]==0 || board[nx][ny] > time+1) {
				Q.push({ nx,ny,time + 1 });
				visit[nx][ny] = true;
			}
		}
	}

	return -1;
}

void print_board() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int TC;
	cin >> TC;

	for (int tc = 0; tc < TC; tc++) {
		cin >> M >> N;
		memset(board, 0, sizeof(board));

		char input;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> input;
				switch (input) {
				case '@': sx = i; sy = j; board[i][j] = 0; break;
				case '.': board[i][j] = 0; break;
				case '#': board[i][j] = -1; break;
				case '*': board[i][j] = 1; break;
				}
			}
		}

		fire();
		//print_board();
		int ret = move_sanggun();
		if (ret == -1) cout << "IMPOSSIBLE\n";
		else cout << ret << '\n';
	}

	return 0;
}