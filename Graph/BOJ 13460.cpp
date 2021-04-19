#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
* 구현 문제라도 BFS로 풀 수 있는지 확인..
* visit 배열 꼭 일차/이차원 아니어도 됨.
* 너무어렵다.. 꼭 복습하자
*/

struct info {
	int rx, ry, bx, by, cnt;
};

int n, m, res = 100;
vector<string> board(10);
bool visit[10][10][10][10] = { false, };

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void move(int& x, int& y, int d) {
	while (0 <= x + dx[d] && x + dx[d] < 10
		&& 0 <= y + dy[d] && y + dy[d] < 10
		&& board[x + dx[d]][y + dy[d]] != '#' && board[x][y] != 'O') {
		x += dx[d];
		y += dy[d];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int rx = 0, ry = 0, bx = 0, by = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				rx = i; ry = j;
				board[i][j] == '.';
			}
			else if (board[i][j] == 'B') {
				bx = i; by = j;
				board[i][j] == '.';
			}
		}
	}

	queue<info> Q;
	Q.push({ rx,ry,bx,by,1 });
	visit[rx][ry][bx][by] = true;

	while (!Q.empty()) {
		rx = Q.front().rx; ry = Q.front().ry;
		bx = Q.front().bx; by = Q.front().by;
		cnt = Q.front().cnt;
		Q.pop();

		if (cnt > 10) break;

		for (int d = 0; d < 4; d++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			move(nrx, nry, d);
			move(nbx, nby, d);

			if (board[nbx][nby] == 'O') continue;
			if (board[nrx][nry] == 'O') {
				res = min(res, cnt);
				break;
			}
			if (nrx == nbx && nry == nby) {
				int rd = abs(rx - nrx) + abs(ry - nry);
				int bd = abs(bx - nbx) + abs(by - nby);
				if (rd < bd) { nbx -= dx[d]; nby -= dy[d]; }
				else { nrx -= dx[d]; nry -= dy[d]; }
			}

			if (!visit[nrx][nry][nbx][nby]) {
				visit[nrx][nry][nbx][nby] = true;
				Q.push({ nrx,nry,nbx,nby,cnt + 1 });
			}
		}
	}

	if (res != 100) cout << res;
	else cout << -1;

	return 0;
}