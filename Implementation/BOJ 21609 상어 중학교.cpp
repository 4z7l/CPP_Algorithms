#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define x first
#define y second
#define BLANK -2

struct info {
	int x, y, cnt = 0, rainbowCnt = 0;
	bool operator<(const info& i) const {
		if (cnt == i.cnt) {
			if (rainbowCnt == i.rainbowCnt) {
				if (x == i.x) return y < i.y;
				else return x < i.x;
			}
			else return rainbowCnt < i.rainbowCnt;
		}
		else return cnt < i.cnt;
	}
};

int res = 0;
int N, M;
int board[20][20];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void input();
bool find_block();
void down();
void rotate();

int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	input(); 
	while (true) {
		int ret = find_block();
		if (!ret) break;
		down();
		rotate();
		down();
	}
	cout << res << '\n';

	return 0;
}

void input() {
	//freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}

bool find_block() {
	bool visit[20][20] = { false, };
	priority_queue<info> pQ;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > 0 && !visit[i][j]) {
				bool rainbowVisit[20][20] = { false, };
				queue<pair<int,int>> Q;
				Q.push({ i,j });
				visit[i][j] = true;

				int cnt = 1, rainbowCnt = 0;
				while (!Q.empty()) {
					int x = Q.front().x;
					int y = Q.front().y;
					Q.pop();

					for (int d = 0; d < 4; d++) {
						int nx = x + dx[d];
						int ny = y + dy[d];

						if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1
							|| visit[nx][ny] || rainbowVisit[nx][ny]) continue;

						if (board[nx][ny] == 0) {
							rainbowVisit[nx][ny] = true;
							Q.push({ nx,ny });
							cnt++;
							rainbowCnt++;
						}
						else if (board[i][j] == board[nx][ny]) {
							visit[nx][ny] = true;
							Q.push({ nx,ny });
							cnt++;
						}
					}
				}

				pQ.push({ i,j,cnt, rainbowCnt });
			}
		}
	}

	if (pQ.empty()) return false;

	int x = pQ.top().x;
	int y = pQ.top().y;
	int cnt = pQ.top().cnt;

	if (cnt < 2) return false;

	res += cnt * cnt;

	queue<pair<int, int>> Q;
	Q.push({x,y });
	int blockId = board[x][y];
	board[x][y] = BLANK;

	while (!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		Q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;

			if (board[nx][ny] == 0 ||  board[nx][ny]== blockId) {
				Q.push({ nx,ny });
				board[nx][ny] = BLANK;
			}
		}
	}

	return true;
}

void down() {
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j >= 0;j--) {
			if (board[j][i] == BLANK) {
				int x = j;
				int y = i;
				while (x > 0 && board[x][y]==BLANK) x--;
				if (board[x][y] == -1) continue;
				board[j][i] = board[x][y];
				board[x][y] = BLANK;
			}
		}
	}
}

void rotate() {
	int tempBoard[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tempBoard[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = tempBoard[j][N-1-i];
		}
	}
}